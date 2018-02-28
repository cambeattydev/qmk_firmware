param([string] $qmkPath = "$Env:USERPROFILE\Source\Repos\qmk_firmware",
        [string] $teensyPath = "$Env:USERPROFILE\Source\Repos\teensy_loader_cli_windows"
)
    Push-Location $qmkPath
    wsl make ergodox_ez:cbeatty
    Pop-Location
    Push-Location $teensyPath
    Write-Host $(pwd)
    ./teensy_loader_cli.exe -mmcu=atmega32u4 -w $qmkPath\ergodox_ez_cbeatty.hex 
    Pop-Location