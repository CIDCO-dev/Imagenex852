
$CMD1='"C:\Program Files (x86)\Windows Kits\10\App Certification Kit\signtool" sign /debug /tr http://timestamp.digicert.com /td sha256 /fd sha256 /a build\bin\dump852.exe'
$CMD2='"C:\Program Files (x86)\Windows Kits\10\App Certification Kit\signtool" sign /debug /tr http://timestamp.digicert.com /td sha256 /fd sha256 /a build\bin\octave-dumper.exe'
$CMD3='"C:\Program Files (x86)\Windows Kits\10\App Certification Kit\signtool" sign /debug /tr http://timestamp.digicert.com /td sha256 /fd sha256 /a src\examples\Dump852\release\Dump852.exe'

Run("cmd.exe")
Sleep(2000)
Send($CMD1)
Send("{Enter}")
Sleep(8000)
Send(EnvGet("Sign_Password"))
Send("{Enter}")
Sleep(4000)

Sleep(2000)
Send($CMD2)
Send("{Enter}")
Sleep(8000)
Send(EnvGet("Sign_Password"))
Send("{Enter}")
Sleep(4000)

Sleep(2000)
Send($CMD3)
Send("{Enter}")
Sleep(8000)
Send(EnvGet("Sign_Password"))
Send("{Enter}")
Sleep(4000)

WinClose("C:\Windows\SYSTEM32\cmd.exe", "")
