#ifndef __3do_event_h__
#define __3do_event_h__



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

enum ListenerCategory
  {
   LC_NoSeeUm         = 0,      /* Ignore all events */
   LC_FocusListener   = 1,      /* Receive events if I have focus       */
   LC_Observer        = 2,      /* Receive events regardless of focus   */
   LC_FocusUI         = 3       /* Receive UI events if I have focus    */
                                /* and other events regardless of focus */
  };

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
