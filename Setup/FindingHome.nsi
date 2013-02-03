!include "MUI2.nsh"

;General

	;Name and file
	Name "Finding Home DEMO"
	OutFile "Setup.exe"

	;Default installation folder
	InstallDir "$LOCALAPPDATA\FindingHomeDemo"

	;Get installation folder from registry if available
	InstallDirRegKey HKCU "Software\FindingHomeDemo" ""

	;Request application privileges for Windows Vista
	RequestExecutionLevel user

;--------------------------------
;Interface Settings
	!define MUI_ABORTWARNING
	
;--------------------------------
;Pages
	!insertmacro MUI_PAGE_WELCOME  
	!insertmacro MUI_PAGE_INSTFILES
	!insertmacro MUI_PAGE_FINISH

	!insertmacro MUI_UNPAGE_CONFIRM
	!insertmacro MUI_UNPAGE_INSTFILES
  
;--------------------------------
;Languages
 
  !insertmacro MUI_LANGUAGE "English"

;--------------------------------
;Installer Sections

Section "Install"

	;	copy binaries
	SetOutPath "$INSTDIR\bin\"
	File /r "..\bin\FindingHome.win32.exe"
	File /r "..\bin\*.dll"

	;	copy resources
	SetOutPath "$INSTDIR\Resources\"
	File /r "..\Resources\*.*"

	;	copy EXE and DLL's
	SetOutPath "$INSTDIR"
	File "game.ico"

	;Store installation folder
	WriteRegStr HKCU "Software\FindingHomeDemo" "" $INSTDIR

	;Create uninstaller
	WriteUninstaller "$INSTDIR\Uninstall.exe"
	
	;	write start menu
	SetOutPath "$INSTDIR\bin\"	
    CreateDirectory "$SMPROGRAMS\FindingHome"
	CreateShortCut "$SMPROGRAMS\FindingHome\Play.lnk" "$INSTDIR\bin\FindingHome.win32.exe" "" "$INSTDIR\game.ico" 0
    CreateShortCut "$SMPROGRAMS\FindingHome\Uninstall.lnk" "$INSTDIR\Uninstall.exe"
	
	;	write desktop
	CreateShortCut "$DESKTOP\Finding Home.lnk" "$INSTDIR\bin\FindingHome.win32.exe" "" "$INSTDIR\game.ico" 0
	
	SetOutPath "$INSTDIR"

SectionEnd

;--------------------------------
;Uninstaller Section

Section "Uninstall"
	;	remove icon
	Delete "$INSTDIR\game.ico"

	;	Remove resources
	Delete  "$INSTDIR\Resources\*.*"
	RMDir /r "$INSTDIR\Resources\"
	
	;	Remove binaries
	Delete  "$INSTDIR\bin\*.*"
	RMDir /r "$INSTDIR\bin\"
	
	;	remove uninstaller
	Delete "$INSTDIR\Uninstall.exe"	
	RMDir "$INSTDIR"

	DeleteRegKey /ifempty HKCU "Software\FindingHomeDemo"
	
	;	remove icons
	Delete "$SMPROGRAMS\FindingHome\Uninstall.lnk"
	Delete "$SMPROGRAMS\FindingHome\Play.lnk"
	RMDir "$SMPROGRAMS\FindingHome"
	
	Delete "$DESKTOP\Finding Home.lnk"
	

SectionEnd