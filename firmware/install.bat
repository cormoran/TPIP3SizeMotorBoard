cd /d %~dp0

if "%PROCESSOR_ARCHITECTURE%" EQU "x86" (
	set ROOT_DIR="%ProgramFiles%\Arduino"
) else (
	set ROOT_DIR="%ProgramFiles(x86)%\Arduino"
)

rem hardware
set DEST="%ROOT_DIR%\hardware\RokkoOroshiTPIPMotorBoard"
rmdir "%DEST%"
mklink /D "%DEST%" "%cd%\RokkoOroshiTPIPMotorBoard"

rem examples

set DEST="%ROOT_DIR%\examples\RokkoOroshiTPIPMotorBoard"
rmdir "%DEST%"
mklink /D "%DEST%" "%cd%\examples"

rem externals

rem set DEST="%ROOT_DIR%\libraries\Adafruit-PWM-Servo-Driver-Library"
rem rmdir "%DEST%"
rem mklink /D "%DEST%" "%cd%\external_library\Adafruit-PWM-Servo-Driver-Library"

rem set DEST="%ROOT_DIR%\libraries\DHT-sensor-library-1.2.3"
rem rmdir "%DEST%"
rem mklink /D "%DEST%" "%cd%\external_library\DHT-sensor-library-1.2.3"

pause
