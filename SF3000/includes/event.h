#ifndef __3do_event_h__
#define __3do_event_h__

#include "graphics.h"

#define EventPortName "eventbroker"

enum EventBrokerFlavor
  {
   EB_NoOp               = 0,
   EB_Configure          = 1,
   EB_ConfigureReply     = 2,
   EB_EventRecord        = 3,
   EB_EventReply         = 4,
   EB_SendEvent          = 5,
   EB_SendEventReply     = 6,
   EB_Command            = 7,
   EB_CommandReply       = 8,
   EB_RegisterEvent      = 9,
   EB_RegisterEventReply = 10,
   EB_GetListeners       = 11,
   EB_GetListenersReply  = 12,
   EB_SetFocus           = 13,
   EB_SetFocusReply      = 14,
   EB_GetFocus           = 15,
   EB_GetFocusReply      = 16,
   EB_ReadPodData        = 17,
   EB_ReadPodDataReply   = 18,
   EB_WritePodData       = 19,
   EB_WritePodDataReply  = 20,
   EB_LockPod            = 21,
   EB_LockPodReply       = 22,
   EB_UnlockPod          = 23,
   EB_UnlockPodReply     = 24,
   EB_IssuePodCmd        = 25,
   EB_IssuePodCmdReply   = 26,
   EB_DescribePods       = 27,
   EB_DescribePodsReply  = 28,
   EB_MakeTable          = 29,
   EB_MakeTableReply     = 30
  };

enum ListenerCategory
  {
   LC_NoSeeUm         = 0,      /* Ignore all events */
   LC_FocusListener   = 1,      /* Receive events if I have focus       */
   LC_Observer        = 2,      /* Receive events regardless of focus   */
   LC_FocusUI         = 3       /* Receive UI events if I have focus    */
                                /* and other events regardless of focus */
  };

/*****
      The Event Broker includes the following header in every message it
      sends.  The header, followed by some amount of data (in many cases)
      can be accessed via the data pointer and size fields in the message
      header.

      If a listener sends the Event Broker a small (standard size, pass by
      reference) message, the Event Broker will transmit back a minimal reply...
      it will simply set the reply value in the message structure to {zero,
      or an Item number, or an error code} and send the message back with
      a null data pointer and size.  No header or data will be transmitted.

      If a listener sends the Event Broker a larger (pass by reference) message,
      the Broker mau send back a block of data in the message which consists
      of an EventBrokerHeader followed by [optional] information.  This reply
      data is not always present - the listener should check the data pointer
      and length to see if it was sent.

      Hence - if you want to send a message to the Event Broker and get back
      _any_ information other than success/failure/Item-number kinds of stuff,
      be sure to use CreateSizedItem to create the message, and make the
      message big enough to hold the amount of data you expect to receive!
*****/

typedef struct EventBrokerHeader {
  enum EventBrokerFlavor ebh_Flavor;
} EventBrokerHeader;

/*****   EB_Configure message

         Data transmitted from listener->Broker to [re]configure an event-listener
         port.

*****/

typedef struct ConfigurationRequest {
  EventBrokerHeader     cr_Header; /* { EB_Configure } */
  enum ListenerCategory cr_Category; /* focus, monitor, or hybrid */
  uint32                cr_TriggerMask[8]; /* events to trigger on */
  uint32                cr_CaptureMask[8]; /* events to capture */
  int32                 cr_QueueMax;  /* max # events in transit */
  uint32                rfu[8];            /* must be zero for now */
} ConfigurationRequest;

/*****   EB_EventRecord message

         Data transmitted from Broker->listener to report one or more events.
         Data consists of an EventBrokerHeader followed by one or more
         EventFrame structures (with ef_ByteCount > 0), followed by a
         degenerate EventFrame (ef_ByteCount == 0, remainder of frame not
         present or accounted for in the message data length).

         The same format is used in an EB_SendEvent message transmitted from
         a listener to the Event Broker.

*****/

typedef struct EventFrame {
  uint32         ef_ByteCount;         /* total size of EventFrame */
  uint32         ef_SystemID;          /* Opera machine ID, or zero=local */
  uint32         ef_SystemTimeStamp;   /* event-count timestamp */
  int32          ef_Submitter;         /* Item of event sender, or 0 */
  uint8          ef_EventNumber;       /* event code, [0,255] */
  uint8          ef_PodNumber;         /* CP pod number, or zero */
  uint8          ef_PodPosition;       /* CP position on daisychain, or zero */
  uint8          ef_GenericPosition;   /* Nth generic device of type, or 0 */
  uint8          ef_Trigger;           /* 1 for trigger, 0 for capture */
  uint8          rfu1[3];
  uint32         rfu2;
  uint32         ef_EventData[1];      /* first word of event data */
} EventFrame;


/*****   EB_DescribePods message,  EB_DescribePodsReply response

         Messages used to ask the Event Broker to describe the set of pods
         known to be attached to the Control Port.  The DescribePods message
         carries no data [but should be sent in a fairly large message, to
         provide space for the response].  The DescribePodsReply response
         contains a pod count, and array of pod descriptions.

*****/

typedef struct PodDescription {
  uint8          pod_Number;
  uint8          pod_Position;
  uint8          rfu[2];
  uint32         pod_Type;
  uint32         pod_BitsIn;
  uint32         pod_BitsOut;
  uint32         pod_Flags;
  uint8          pod_GenericNumber[16];
  Item           pod_LockHolder;
} PodDescription;

typedef struct PodDescriptionList {
  EventBrokerHeader    pdl_Header;
  int32                pdl_PodCount;
  PodDescription       pdl_Pod[1];
} PodDescriptionList;

/*****
      Important note - the leftmost 16 bits in the pod flags word are
      specially reserved - if the Nth-leftmost bit is set, then the
      device is a generic of type N and the Nth entry in the pod_GenericNumber
      table gives the device's ordinal position for devices of that
      generic type.  E.g. if the 0th bit is set, the device is a generic
      control pad, and pod_GenericNumber[0] contains 1 if it's the first
      generic control pad, 2 if it's the second, etc.

      Any flag bits not having to do with generic identity should go in the
      righthand 16 bits.
*****/

#define POD_IsControlPad        0x80000000
#define POD_IsMouse             0x40000000
#define POD_IsGun               0x20000000
#define POD_IsGlassesCtlr       0x10000000
#define POD_IsAudioCtlr         0x08000000
#define POD_IsKeyboard          0x04000000
#define POD_IsLightGun          0x02000000
#define POD_IsStick             0x01000000
#define POD_IsIRController      0x00800000



/*
  Specific event formats follow
*/

typedef struct ControlPadEventData {
  uint32         cped_ButtonBits;  /* left justified, zero fill */
} ControlPadEventData;


/*****
      By no coincidence whatsoever, the ordering of the bits in the generic
      Control Pad event data is identical to the ordering of these bits in
      the Control Port data sent by a standard 3DO Control Pad pod.  Only
      the shift offset has been changed to protect the guilty.
*****/

#define ControlDown          0x80000000
#define ControlUp            0x40000000
#define ControlRight         0x20000000
#define ControlLeft          0x10000000
#define ControlA             0x08000000
#define ControlB             0x04000000
#define ControlC             0x02000000
#define ControlStart         0x01000000
#define ControlX             0x00800000
#define ControlRightShift    0x00400000
#define ControlLeftShift     0x00200000


typedef struct StickEventData {
  uint32         stk_ButtonBits;        /* left justified, zero fill */
  int32          stk_HorizPosition;
  int32          stk_VertPosition;
  int32          stk_DepthPosition;
} StickEventData;

#define StickCapability      0x000C0000
#define Stick4Way            0x00080000
#define StickTurbulence      0x00040000
#define StickButtons         0xFFF00000
#define StickFire            0x80000000
#define StickA               0x40000000
#define StickB               0x20000000
#define StickC               0x10000000
#define StickUp              0x08000000
#define StickDown            0x04000000
#define StickRight           0x02000000
#define StickLeft            0x01000000
#define StickPlay            0x00800000
#define StickStop            0x00400000
#define StickLeftShift       0x00200000
#define StickRightShift      0x00100000

/*
  Event-number definitions.  Event numbers count from 1 to 256, and must
  correspond 1:1 with the event bits defined a bit further down.
*/

#define EVENTNUM_ControlButtonPressed                1
#define EVENTNUM_ControlButtonReleased               2
#define EVENTNUM_ControlButtonUpdate                 3
#define EVENTNUM_ControlButtonArrived                4
#define EVENTNUM_MouseButtonPressed                  5
#define EVENTNUM_MouseButtonReleased                 6
#define EVENTNUM_MouseUpdate                         7
#define EVENTNUM_MouseMoved                          8
#define EVENTNUM_MouseDataArrived                    9
#define EVENTNUM_GunButtonPressed                   10
#define EVENTNUM_GunButtonReleased                  11
#define EVENTNUM_GunUpdate                          12
#define EVENTNUM_GunDataArrived                     13
#define EVENTNUM_KeyboardKeyPressed                 14
#define EVENTNUM_KeyboardKeyReleased                15
#define EVENTNUM_KeyboardUpdate                     16
#define EVENTNUM_KeyboardDataArrived                17
#define EVENTNUM_CharacterEntered                   18
#define EVENTNUM_GivingFocus                        19
#define EVENTNUM_LosingFocus                        20
#define EVENTNUM_LightGunButtonPressed              21
#define EVENTNUM_LightGunButtonReleased             22
#define EVENTNUM_LightGunUpdate                     23
#define EVENTNUM_LightGunFireTracking               24
#define EVENTNUM_LightGunDataArrived                25
#define EVENTNUM_StickButtonPressed                 26
#define EVENTNUM_StickButtonReleased                27
#define EVENTNUM_StickUpdate                        28
#define EVENTNUM_StickMoved                         29
#define EVENTNUM_StickDataArrived                   30
#define EVENTNUM_IRKeyPressed                       31
#define EVENTNUM_IRKeyReleased                      32

#define EVENTNUM_DeviceOnline                       64
#define EVENTNUM_DeviceOffline                      65
#define EVENTNUM_FilesystemMounted                  66
#define EVENTNUM_FilesystemOffline                  67
#define EVENTNUM_FilesystemDismounted               68
#define EVENTNUM_ControlPortChange                  69
#define EVENTNUM_PleaseSaveAndExit                  70
#define EVENTNUM_PleaseExitImmediately              71
#define EVENTNUM_EventQueueOverflow                 72


#define EVENTBIT0_StickButtonPressed                 0x00000040
#define EVENTBIT0_StickButtonReleased                0x00000020
#define EVENTBIT0_StickUpdate                        0x00000010
#define EVENTBIT0_StickMoved                         0x00000008
#define EVENTBIT0_StickDataArrived                   0x00000004

#define EVENTBIT2_ControlPortChange                  0x04000000

/***** Convenience interfaces

       The following set of functions provide a simple, convenient interface
       for applications which wish to monitor the state of a small number of
       generic Control Port devices (control pads and mouse-like devices).

       To use:  call InitEventUtility and specify the maximum number of
       control pads and mice you wish to be able to monitor.  Also specify
       whether you want to be an observer or a focus listener.

       Then: at will, call GetControlPad or GetMouse, and pass in the
       number of the control pad or mouse whose current position or state
       you wish to interrogate (the first pad is 1, not 0!).  You may
       specify whether you wish an immediate response, or whether you wish
       to wait for the next change in the control pad or mouse status
       before the value is returned.  These functions return 1 if an event
       has occured, 0 if no event occurred, and a negative error code if
       something went amiss.

       When you are done, call KillEventUtility to close down.

       If you init as a focus listener, you will not be told of any control pad
       or mouse changes when you do not have focus... and so you might
       "believe" that a mouse or control pad button is still down, long after
       it has been released.  So... if you are signing on as a focus listener
       through this interface, you'd probably want to call GetMouse and
       GetControlPad with wait=1, so that you would in effect "go to sleep"
       whenever you don't have the focus.

*/


Err InitEventUtility (int32 numControlPads, int32 numMice,
                      int32 focusListener);
Err GetControlPad(int32 padNumber, int32 wait, ControlPadEventData *data);

Err KillEventUtility(void);

#endif /* __3do_event_h__ */
