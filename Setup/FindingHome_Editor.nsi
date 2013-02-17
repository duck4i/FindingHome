!include "MUI2.nsh"

;General

	;Name and file
	Name "Finding Home Tools"
	OutFile "SetupEditor.exe"

	;Default installation folder
	InstallDir "$DESKTOP\FindingHomeTools"

	;Get installation folder from registry if available
	InstallDirRegKey HKCU "Software\FindingHomeTools" ""

	;Request application privileges for Windows Vista
	RequestExecutionLevel user
	
	;	set stronger compression
	SetCompressor /SOLID lzma
	

;--------------------------------
;Interface Settings
	!define MUI_ABORTWARNING
	
;--------------------------------
;Pages
	!insertmacro MUI_PAGE_WELCOME  
	!insertmacro MUI_PAGE_LICENSE "readme.txt"
	!insertmacro MUI_PAGE_INSTFILES

		;	Autostart game after install
		;!define MUI_FINISHPAGE_NOAUTOCLOSE
		!define MUI_FINISHPAGE_RUN
		!define MUI_FINISHPAGE_RUN_NOTCHECKED
		!define MUI_FINISHPAGE_RUN_TEXT "Play game now!"
		!define MUI_FINISHPAGE_RUN_FUNCTION "LaunchLink"	
		;	Read Me
		!define MUI_FINISHPAGE_SHOWREADME_CHECKED
		!define MUI_FINISHPAGE_SHOWREADME $INSTDIR\readme.txt
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
	File /r "..\Resources\*.png"
	File /r "..\Resources\*.xml"
	File /r "..\Resources\*.json"
	File /r "..\Resources\*.vsh"
	File /r "..\Resources\*.fsh"	
	
	SetOutPath "$INSTDIR\Utils\"
	File /r "..\Utils\*.*"

	;	copy EXE and DLL's
	SetOutPath "$INSTDIR"
	File "game.ico"
	File "readme.txt"

	;Store installation folder
	WriteRegStr HKCU "Software\FindingHomeTools" "" $INSTDIR

	;Create uninstaller
	WriteUninstaller "$INSTDIR\Uninstall.exe"
	
	;	write start menu
	SetOutPath "$INSTDIR\bin\"	
    CreateDirectory "$SMPROGRAMS\FindingHome"
	CreateShortCut "$SMPROGRAMS\FindingHome\Play.lnk" "$INSTDIR\bin\FindingHome.win32.exe" "" "$INSTDIR\game.ico" 0
	CreateShortCut "$SMPROGRAMS\FindingHome\ReadMe.lnk" "$INSTDIR\readme.txt"
    CreateShortCut "$SMPROGRAMS\FindingHome\Uninstall.lnk" "$INSTDIR\Uninstall.exe"
	
	;	write desktop
	CreateShortCut "$DESKTOP\Finding Home.lnk" "$INSTDIR\bin\FindingHome.win32.exe" "" "$INSTDIR\game.ico" 0
	
	SetOutPath "$INSTDIR\utils\"	
	CreateShortCut "$DESKTOP\Finding Home Editor.lnk" "$INSTDIR\Utils\gleed2d.exe" "" "$INSTDIR\game.ico" 0
	
	SetOutPath "$INSTDIR"
	
	;	now run game
	;ExecShell "" "$DESKTOP\Finding Home.lnk"
	

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
	
	;	Remove editor
	Delete "$INSTDIR\Utils\*.*"
	RMDir /r "$INSTDIR\Utils\"
	
	;	remove uninstaller
	Delete "$INSTDIR\Uninstall.exe"	
	Delete "$INSTDIR\Readme.txt"
	
	RMDir "$INSTDIR"

	DeleteRegKey /ifempty HKCU "Software\FindingHomeTools"
	
	;	remove icons
	Delete "$SMPROGRAMS\FindingHome\Uninstall.lnk"
	Delete "$SMPROGRAMS\FindingHome\Play.lnk"
	Delete "$SMPROGRAMS\FindingHome\ReadMe.lnk"
	RMDir /r "$SMPROGRAMS\FindingHome"
	
	Delete "$DESKTOP\Finding Home.lnk"
	Delete "$DESKTOP\Finding Home Editor.lnk"
	

SectionEnd

;	code to run game after install
Function LaunchLink
  ExecShell "" "$DESKTOP\Finding Home.lnk"
FunctionEnd
