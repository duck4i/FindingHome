echo off
echo Building editor and tools into zip file
echo off


REM remove old version
del SetupTools.zip /f /q

REM pack Bin directory
md Bin
xcopy ..\bin\FindingHome.win32.exe Bin\*.*
xcopy ..\bin\*.dll Bin\*.*

zip.exe -r -9 SetupTools.zip "Bin\*.*"
del bin\*.* /f /q
rd bin /S /Q

REM pack Resources
md Resources
xcopy /E ..\Resources\*.png Resources\*.*
xcopy /E ..\Resources\*.xml Resources\*.*
xcopy /E ..\Resources\*.json Resources\*.*
xcopy /E ..\Resources\*.vsh Resources\*.*
xcopy /E ..\Resources\*.fsh Resources\*.*

zip.exe -r -9 SetupTools.zip "Resources\*.*"
del Resources\*.* /f /q
rd Resources /S /Q

REM pack Docs
md Docs
xcopy ..\Docs\*.* Docs\*.*

zip.exe -r -9 SetupTools.zip "Docs\*.*"
del Docs\*.* /f /q
rd Docs /S /Q

REM pack Utils
md Utils
xcopy /E ..\Utils\*.exe Utils\*.*
xcopy /E ..\Utils\*.xnb Utils\*.*
xcopy /E ..\Utils\*.xml Utils\*.*
xcopy /E ..\Utils\*.jar Utils\*.*

zip.exe -r -9 SetupTools.zip "Utils\*.*"
del Utils\*.* /f /q
rd Utils /S /Q

