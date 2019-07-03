@echo off

set version=%1
set releaseDate=%2

call powershell.exe -Command "(Get-Content Installer\config\config.xml) | Foreach-Object {$_ -replace 'VERSION-NUMBER', '%version%'} | Set-Content Installer\config\config.xml" || echo "Something went wrong when setting version"

call powershell.exe -Command "(Get-Content Installer\packages\ca.cidco.dump852_gui\meta\package.xml) | Foreach-Object {$_ -replace 'DATE<', '%releaseDate%<'} | Set-Content Installer\packages\ca.cidco.dump852_gui\meta\package.xml"
call powershell.exe -Command "(Get-Content Installer\packages\ca.cidco.imagenex852_cli\meta\package.xml) | Foreach-Object {$_ -replace 'DATE<', '%releaseDate%<'} | Set-Content Installer\packages\ca.cidco.imagenex852_cli\meta\package.xml"

call powershell.exe -Command "(Get-Content Installer\packages\ca.cidco.dump852_gui\meta\package.xml) | Foreach-Object {$_ -replace 'VERSION-NUMBER', '%version%'} | Set-Content Installer\packages\ca.cidco.dump852_gui\meta\package.xml"
call powershell.exe -Command "(Get-Content Installer\packages\ca.cidco.imagenex852_cli\meta\package.xml) | Foreach-Object {$_ -replace 'VERSION-NUMBER', '%version%'} | Set-Content Installer\packages\ca.cidco.imagenex852_cli\meta\package.xml"
