#   File:       Star3000.make
#   Target:     Star3000
#   Sources:    Star3000.c
#               :SFlib:Bit_Control.c
#               :SFlib:Bonus_Control.c
#               :SFlib:PlayCPakStream.c
#               :SFlib:PrepareStream.c
#               :SFlib:Collision.s
#               :SFlib:Update_Frame.c
#               :SFlib:Draw_Frame.c
#               :SFlib:Draw_Land.c
#               :SFlib:Explosion.c
#               :SFlib:Ground_Control.c
#               :SFlib:Laser_Control.c
#               :SFlib:Maths_Stuff.s
#               :SFlib:Plot_Graphic.s
#               :SFlib:Plot_Land.s
#               :SFlib:Rotate_Land.c
#               :SFlib:Setup_Tables.c
#               :SFlib:SF_Access.c
#               :SFlib:SF_NVRam.c
#               :SFlib:SF_ARMAnim.s
#               :SFlib:SF_ARMBurn.s
#               :SFlib:SF_ARMCell.s
#               :SFlib:SF_ARMLink.s
#               :SFlib:SF_ARMSky.s
#               :SFlib:SF_ARMUtils.s
#               :SFlib:SF_Bonus.c
#               :SFlib:SF_Celutils.c
#               :SFlib:SF_Control.c
#               :SFlib:SF_Font.c
#               :SFlib:SF_Io.c
#               :SFlib:SF_Map.c
#               :SFlib:SF_Menu.c
#               :SFlib:SF_Message.c
#               :SFlib:SF_Music.c
#               :SFlib:SF_Palette.c
#               :SFlib:SF_Pyramid.c
#               :SFlib:SF_Screenutils.c
#               :SFlib:SF_Sound.c
#               :SFlib:SF_Status.c
#               :SFlib:SF_Utility.c
#               :SFlib:SF_Video.c
#               :SFlib:SF_War.c
#               :SFlib:Ship_Control.c
#               :SFlib:Smoke_Control.c
#               :SFlib:Sound_Control.c
#               :SFlib:Weapons.c
#               :SFlib:Collision_Update.c
#               :SFlib:Laser_Plot.s
#               :SFlib:Smoke_Plot.s
#               :SFlib:Ship_Command.c
#               :SFlib:Graphics_Set.c
#               :SFlib:bs_joystick.c
#               :SFlib:broker_shell.c
#               :SFlib:sf_joystick.c
#               :SFlib:test_prog.c
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

CFLAGS = -I SFLib -I includes

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
		SFlib/SF_Celutils.o \
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
		SFlib/Laser_plot.o \
		SFlib/Smoke_plot.o \
		SFlib/Ship_Command.o \
		SFlib/Graphics_Set.o \
		SFlib/bs_joystick.o \
		SFlib/broker_shell.o \
		SFlib/sf_joystick.o \
		SFlib/test_prog.o \
		"{3DOLibs}"cstartup.o

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
	$(CC) $(CFLAGS) $(OPTS) -c -o OBJECTS/$@ $<

#.s.o:	Ä	.s
#	{ASM} -i "{3DOIncludes}" -i "{StreamDir}" -i "{SubscriberDir}Includes:" {SOptions} -o {TargDir}{Default}.s.o {DepDir}{Default}.s
.s.o:
	echo "No asm yet"


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

#	{LINK} {LOptions} {LDebugOptions}
#		{OBJECTS}
#		{LIBS}
#		-o "{WorkingDisk}"{Targ}
#	SetFile "{WorkingDisk}"{Targ} -c 'EaDJ' -t 'PROJ'
#	modbin "{WorkingDisk}"{Targ} -stack {LStackSize} {ModbinDebugOptions}
#	stripaif "{WorkingDisk}"{Targ} -o {Targ} -s {Targ}.sym
#	duplicate -y {3DOAutodup} {Targ} "{3DORemote}"
#	duplicate -y {3DOAutodup} {Targ}.sym "{3DORemote}"


#####################################
#	Additional Target Dependencies
#####################################

#{ObjectDir}Star3000.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Bit_Control.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Bonus_Control.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:PlayCPakStream.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:PrepareStream.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Collision.s.o			Ä	{App}.make
#{ObjectDir}:SFlib:Draw_Frame.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Update_Frame.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Draw_Land.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Explosion.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Ground_Control.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Laser_Control.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Maths_Stuff.s.o			Ä	{App}.make
#{ObjectDir}:SFlib:Plot_Graphic.s.o			Ä	{App}.make
#{ObjectDir}:SFlib:Plot_Land.s.o			Ä	{App}.make
#{ObjectDir}:SFlib:Rotate_Land.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Setup_Tables.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Access.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_NVRam.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_ARMAnim.s.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_ARMBurn.s.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_ARMCell.s.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_ARMLink.s.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_ARMSky.s.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_ARMUtils.s.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Bonus.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Celutils.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Control.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Font.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Io.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Map.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Menu.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Message.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Music.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Palette.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Pyramid.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Screenutils.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Sound.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Status.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Utility.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_Video.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:SF_War.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Ship_Control.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Smoke_Control.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Sound_Control.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Weapons.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Collision_Update.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Laser_plot.s.o			Ä	{App}.make
#{ObjectDir}:SFlib:Smoke_plot.s.o			Ä	{App}.make
##{ObjectDir}:SFlib:Ship_Command.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:Graphics_Set.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:bs_joystick.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:broker_shell.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:sf_joystick.c.o			Ä	{App}.make
#{ObjectDir}:SFlib:test_prog.c.o			Ä	{App}.make
