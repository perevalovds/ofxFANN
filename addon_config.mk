meta:
	ADDON_NAME = ofxFANN
	ADDON_DESCRIPTION = Wrapper on FANN library for fast CPU working with neural networks in openFrameworks.
	ADDON_AUTHOR = Denis Perevalov
	ADDON_TAGS = "Machine Learning"
	ADDON_URL = https://github.com/perevalovds/ofxFANN

common:

	#ADDON_INCLUDES +=  libs/...

osx:
vs:	
	# x64
	#ADDON_LIBS += libs/realsense2/lib/x64/realsense2.lib
	#ADDON_DLLS_TO_COPY += libs/realsense2/lib/x64/realsense2.dll;libs/realsense2/lib/x64/Intel.Realsense.dll
	# Win32
	#ADDON_LIBS += libs/realsense2/lib/vs/Win32/realsense2.lib
	#ADDON_DLLS_TO_COPY += libs/realsense2/lib/Win32/realsense2.dll;libs/realsense2/lib/Win32/Intel.Realsense.dll
	
	
linux64:
linuxarmv6l:
linuxarmv7l:
msys2:
