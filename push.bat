@echo off

git add *

:numTP
	set /P num="TP numero : "
if %num% lss 0 goto numTP
	
set /P message="commit message : "

if %num% == 0 (
	git commit -m "%message%"
) else (
	git commit -m "TP%numero% - %message%"
)

git push

echo.
pause