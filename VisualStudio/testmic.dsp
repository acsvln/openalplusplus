# Microsoft Developer Studio Project File - Name="testmic" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=testmic - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "testmic.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "testmic.mak" CFG="testmic - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "testmic - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "testmic - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "testmic - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\bin"
# PROP BASE Intermediate_Dir ".\testmic_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\bin"
# PROP Intermediate_Dir ".\testmic_Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /I "../include" /W3 /Ob1 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /GF /Gy /YX /Fp".\testmic___Win32_Release/testmic.pch" /Fo".\testmic___Win32_Release/" /Fd".\testmic___Win32_Release/" /FR /c /GX 
# ADD CPP /nologo /MD /I "../include" /W3 /Ob1 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /GF /Gy /YX /Fp".\testmic___Win32_Release/testmic.pch" /Fo".\testmic___Win32_Release/" /Fd".\testmic___Win32_Release/" /FR /c /GX 
# ADD BASE MTL /nologo /tlb".\testmic___Win32_Release\testmic.tlb" /win32 
# ADD MTL /nologo /tlb".\testmic___Win32_Release\testmic.tlb" /win32 
# ADD BASE RSC /l 1053 /d "NDEBUG" 
# ADD RSC /l 1053 /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo 
# ADD BSC32 /nologo 
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /out:"..\bin\$(ProjectName).exe" /incremental:no /libpath:"..\lib" /pdb:".\testmic___Win32_Release\testmic.pdb" /pdbtype:sept /subsystem:console /MACHINE:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /out:"..\bin\$(ProjectName).exe" /incremental:no /libpath:"..\lib" /pdb:".\testmic___Win32_Release\testmic.pdb" /pdbtype:sept /subsystem:console /MACHINE:I386

!ELSEIF  "$(CFG)" == "testmic - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\bin"
# PROP BASE Intermediate_Dir ".\testmic_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\bin"
# PROP Intermediate_Dir ".\testmic_Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /I "../include" /ZI /W3 /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" PRECOMP_VC7_TOBEREMOVED /Fp".\testmic___Win32_Debug/testmic.pch" /Fo".\testmic___Win32_Debug/" /Fd".\testmic___Win32_Debug/" /GZ /c /GX 
# ADD CPP /nologo /MDd /I "../include" /ZI /W3 /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" PRECOMP_VC7_TOBEREMOVED /Fp".\testmic___Win32_Debug/testmic.pch" /Fo".\testmic___Win32_Debug/" /Fd".\testmic___Win32_Debug/" /GZ /c /GX 
# ADD BASE MTL /nologo /tlb".\testmic___Win32_Debug\testmic.tlb" /win32 
# ADD MTL /nologo /tlb".\testmic___Win32_Debug\testmic.tlb" /win32 
# ADD BASE RSC /l 1053 /d "_DEBUG" 
# ADD RSC /l 1053 /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo 
# ADD BSC32 /nologo 
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /out:"..\bin\$(ProjectName)d.exe" /incremental:yes /libpath:"..\lib" /debug /pdb:".\testmic___Win32_Debug\testmic.pdb" /pdbtype:sept /subsystem:console /MACHINE:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /out:"..\bin\$(ProjectName)d.exe" /incremental:yes /libpath:"..\lib" /debug /pdb:".\testmic___Win32_Debug\testmic.pdb" /pdbtype:sept /subsystem:console /MACHINE:I386

!ENDIF

# Begin Target

# Name "testmic - Win32 Release"
# Name "testmic - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\tests\testmic.cpp
# End Source File
# End Group
# End Target
# End Project

