@echo off

set version=%1
call powershell.exe -Command "get-content Installer\config\config.xml | %{$_ -replace 'VERSION-NUMBER', '%version%'}" > Installer\config\config2.xml && move /Y Installer\config\config2.xml Installer\config\config.xml
call powershell.exe -Command "get-content Installer\config\config.xml | %{$_ -replace 'DATE', '%version%'}" > Installer\config\config2.xml && move /Y Installer\config\config2.xml Installer\config\config.xml
call powershell.exe -Command "get-content Installer\config\config.xml | %{$_ -replace 'VERSION-NUMBER', '%version%'}" > Installer\packages\*\meta\package2.xml && move /Y Installer\packages\*\meta\package2.xml Installer\packages\*\meta\package.xml
