#   File:       Star3000.make
#   Target:     Star3000
#   Created:    Monday, June 5, 1995 8:10:02 pm
#
#   Copyright 3DO Company, 1993, 1994
#   All rights reserved.
#
#		Change History (most recent first):
#
#   		<>		---		Created by Create3DOMake 2.4

#####################################
#	Symbol definitions
#####################################

App			= Star3000
DebugFlag		= 0
SourceDir		= Sylvester:Andrew-C:SF3000:
ObjectDir		= :Objects:
CC			= gcc
ASM			= armasm
LINK			= gcc
WorkingDisk		= ''
StreamDir		= Sylvester:3DO:Streaming:2p1p2:DataStream:
SubscriberDir		= {StreamDir}Subscribers:


#####################################
#	Default compiler options
#####################################

COptions			= -fa -zps1 -za1 -zpj1 -zpm1 -zpz1
SOptions			= -bi
LOptions			= -aif -r -b 0x00
LStackSize			= 8192

CFLAGS = -I SFLib/ -I includes/ -I . -Wall

#####################################
#	Object files
#####################################

OBJECTS	=	Star3000.o \
		SFlib/Bit_Control.o \
		SFlib/Bonus_Control.o \
		SFlib/PlayCPakStream.o \
		SFlib/PrepareStream.o \
		SFlib/Collision.o \
		SFlib/Draw_Frame.o \
		SFlib/Update_Frame.o \
		SFlib/Draw_Land.o \
		SFlib/Explosion.o \
		SFlib/Ground_Control.o \
		SFlib/Laser_Control.o \
		SFlib/Maths_Stuff.o \
		SFlib/Plot_Graphic.o \
		SFlib/Plot_Land.o \
		SFlib/Rotate_Land.o \
		SFlib/Setup_Tables.o \
		SFlib/SF_Access.o \
		SFlib/SF_NVRam.o \
		SFlib/SF_ARMAnim.o \
		SFlib/SF_ARMBurn.o \
		SFlib/SF_ARMCell.o \
		SFlib/SF_ARMLink.o \
		SFlib/SF_ARMSky.o \
		SFlib/SF_ARMUtils.o \
		SFlib/SF_Bonus.o \
		SFlib/SF_CelUtils.o \
		SFlib/SF_Control.o \
		SFlib/SF_Font.o \
		SFlib/SF_Io.o \
		SFlib/SF_Map.o \
		SFlib/SF_Menu.o \
		SFlib/SF_Message.o \
		SFlib/SF_Music.o \
		SFlib/SF_Palette.o \
		SFlib/SF_Pyramid.o \
		SFlib/SF_Screenutils.o \
		SFlib/SF_Sound.o \
		SFlib/SF_Status.o \
		SFlib/SF_Utility.o \
		SFlib/SF_Video.o \
		SFlib/SF_War.o \
		SFlib/Ship_Control.o \
		SFlib/Smoke_Control.o \
		SFlib/Sound_Control.o \
		SFlib/Weapons.o \
		SFlib/Collision_Update.o \
		SFlib/Laser_Plot.o \
#		SFlib/Smoke_Plot.o \
		SFlib/Ship_Command.o \
		SFlib/Graphics_Set.o \
		SFlib/bs_joystick.o \
		SFlib/broker_shell.o \
		SFlib/SF_Joystick.o \
		SFlib/test_prog.o \
		SFlib/Global_2.o
#		"{3DOLibs}"cstartup.o

LIBS			=		"{SubscriberDir}subscriber.lib" \
					"{StreamDir}dataacq.lib" \
					"{StreamDir}ds.lib" \
					"{3DOLibs}codec.lib" \
					"{3DOLibs}Lib3DO.lib" \
					"{3DOLibs}audio.lib" \
					"{3DOLibs}music.lib" \
					"{3DOLibs}operamath.lib" \
					"{3DOLibs}filesystem.lib" \
					"{3DOLibs}graphics.lib" \
					"{3DOLibs}input.lib" \
					"{3DOLibs}clib.lib" \
					"{3DOLibs}swi.lib"

#####################################
#	Default build rules
#####################################

All: $(App)

#{ObjectDir}		Ä	:

.c.o:
	$(CC) $(CFLAGS) $(OPTS) -c -o $@ $<

#.s.o:	Ä	.s
#	{ASM} -i "{3DOIncludes}" -i "{StreamDir}" -i "{SubscriberDir}Includes:" {SOptions} -o {TargDir}{Default}.s.o {DepDir}{Default}.s
#.s.o:
#	@echo "$@ No asm yet"


#####################################
#	Target build rules
#####################################

#{App} Ä {App}.make {OBJECTS}
#	{LINK} {LOptions} {LDebugOptions}
#		{OBJECTS}
#		{LIBS}
#		-o "{WorkingDisk}"{Targ}
#	SetFile "{WorkingDisk}"{Targ} -c 'EaDJ' -t 'PROJ'
#	modbin "{WorkingDisk}"{Targ} -stack {LStackSize} {ModbinDebugOptions}
#	stripaif "{WorkingDisk}"{Targ} -o {Targ} -s {Targ}.sym
#	duplicate -y {3DOAutodup} {Targ} "{3DORemote}"
#	duplicate -y {3DOAutodup} {Targ}.sym "{3DORemote}"

$(App): $(OBJECTS)
	$(LINK) -o $@ $(OBJECTS)

clean:
	rm -f SFlib/*.o
	rm -f Star3000.o
	rm -f Star3000

#	{LINK} {LOptions} {LDebugOptions}
#		{OBJECTS}
#		{LIBS}
#		-o "{WorkingDisk}"{Targ}
#	SetFile "{WorkingDisk}"{Targ} -c 'EaDJ' -t 'PROJ'
#	modbin "{WorkingDisk}"{Targ} -stack {LStackSize} {ModbinDebugOptions}
#	stripaif "{WorkingDisk}"{Targ} -o {Targ} -s {Targ}.sym
#	duplicate -y {3DOAutodup} {Targ} "{3DORemote}"
#	duplicate -y {3DOAutodup} {Targ}.sym "{3DORemote}"



