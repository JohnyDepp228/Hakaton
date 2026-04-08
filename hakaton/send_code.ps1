param(
[string]$To,
[string]$Body
)

$From = "plantguard.official@gmail.com"
$password = "xopltrgejjennrnl"
$Subject = "Code to confirm"

$SecurePassword = ConvertTo-SecureString $Password -AsPlainText -Force
$Creds = New-Object System.Management.Automation.PSCredential ($From, $SecurePassword)
Send-MailMessage -From $From -To $To -Subject $Subject -Body $Body `
    -SmtpServer "smtp.gmail.com" -Port 587 -UseSsl -Credential $Creds
