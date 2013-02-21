call clear.bat
call _CopyDLLFilesHere_Debug.bat

@echo off

echo./*
echo.* Check VC++ environment...
echo.*/
echo.

if defined VS110COMNTOOLS (
    set VSVARS="%VS110COMNTOOLS%vsvars32.bat"
    set VC_VER=110
) else if defined VS100COMNTOOLS (
    set VSVARS="%VS100COMNTOOLS%vsvars32.bat"
    set VC_VER=100
)

if not defined VSVARS (
    echo Can't find VC2010 or VC2012 installed!
    goto ERROR
)

echo./*
echo.* Building FindingHome binary, please wait a while...
echo.*/
echo.

call %VSVARS%
if %VC_VER% == 110 (
    msbuild ..\proj.win32\FindingHome.sln /t:Clean
    msbuild ..\proj.win32\FindingHome.sln /p:Configuration="Debug" /m
    rem msbuild cocos2d-win32.vc2012.sln /p:Configuration="Release" /m
) else (
    echo Script error.
    goto ERROR
)



:ERROR
echo its done.
pause