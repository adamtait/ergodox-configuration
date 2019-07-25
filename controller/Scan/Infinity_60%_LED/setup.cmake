###| CMake Kiibohd Controller Scan Module |###
#
# Written by Jacob Alexander in 2014,2016 for the Kiibohd Controller
#
# Released into the Public Domain
#
###


###
# Required Submodules
#

AddModule ( Scan ISSILed )
AddModule ( Scan MatrixARM )


###
# Module C files
#

set ( Module_SRCS
	scan_loop.c
)


###
# Compiler Family Compatibility
#
set ( ModuleCompatibility
	arm
)

