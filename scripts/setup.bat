@echo off
echo [LetoAPI] Собираем проект...
setlocal 
cd /d "%~dp0"
call preset_setup.bat LetoAPI win-debug
call preset_setup.bat LetoAPI stm32f411xe-debug
endlocal
