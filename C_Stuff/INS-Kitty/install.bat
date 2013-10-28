::
:: Kitty 0.62
:: JP
:: 2012-JUL-16
::


xcopy "%~dp0install_files\*" "%PROGRAMFILES(x86)%\Kitty\" /E /Y /I
xcopy "%~dp0INS.lnk" "%PROGRAMDATA%\Microsoft\Windows\Start Menu\Programs" /Y /I