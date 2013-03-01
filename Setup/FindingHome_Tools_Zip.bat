echo off
echo Building editor and tools into zip file
echo off


REM remove old version
del FindingHomeTools.zip /f /q

REM pack Bin directory
md Bin
xcopy ..\bin\FindingHome.win32.exe Bin\*.*
xcopy ..\bin\*.dll Bin\*.*

zip.exe -r -9 FindingHomeTools.zip "Bin\*.*"
del bin\*.* /f /q
rd bin /S /Q

REM pack Resources
md Resources
xcopy /E ..\Resources\*.png Resources\*.*
xcopy /E ..\Resources\*.mp3 Resources\*.*
xcopy /E ..\Resources\*.wav Resources\*.*
xcopy /E ..\Resources\*.xml Resources\*.*
xcopy /E ..\Resources\*.json Resources\*.*
xcopy /E ..\Resources\*.vsh Resources\*.*
xcopy /E ..\Resources\*.fsh Resources\*.*

REM audio resources
xcopy /S ..\Resources\*.fdp Resources\*.*
xcopy /S ..\Resources\*.fev Resources\*.*
xcopy /S ..\Resources\*.fsb Resources\*.*

zip.exe -r -9 FindingHomeTools.zip "Resources\*.*"
del Resources\*.* /f /q
rd Resources /S /Q

REM pack Docs
md Docs
xcopy ..\Docs\*.* Docs\*.*

zip.exe -r -9 FindingHomeTools.zip "Docs\*.*"
del Docs\*.* /f /q
rd Docs /S /Q

REM pack Utils
md Utils
xcopy /E ..\Utils\*.exe Utils\*.*
xcopy /E ..\Utils\*.xnb Utils\*.*
xcopy /E ..\Utils\*.xml Utils\*.*
xcopy /E ..\Utils\*.jar Utils\*.*
xcopy /E ..\Utils\*.txt Utils\*.*

zip.exe -r -9 FindingHomeTools.zip "Utils\*.*"
del Utils\*.* /f /q
rd Utils /S /Q

REM add shortucts
xcopy ..\start.bat *.*
zip.exe -r -9 -D FindingHomeTools.zip start.bat
del start.bat /f /q

xcopy ..\start_forest_test.bat *.*
zip.exe -r -9 -D FindingHomeTools.zip start_forest_test.bat
del start_forest_test.bat /f /q

xcopy ..\start_fullscreen.bat *.*
zip.exe -r -9 -D FindingHomeTools.zip start_fullscreen.bat
del start_fullscreen.bat /f /q