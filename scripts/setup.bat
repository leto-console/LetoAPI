@echo off
echo [LetoAPI] Собираем проект...
setlocal enabledelayedexpansion
cd /d "%~dp0" || exit /b !errorlevel!
call preset_setup.bat LetoAPI win-debug || exit /b !errorlevel!
call preset_setup.bat LetoAPI stm32f411xe-debug || exit /b !errorlevel!
endlocal
