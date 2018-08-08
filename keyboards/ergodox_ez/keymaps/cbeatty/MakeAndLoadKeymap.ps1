function NewAndImportKeyMap([string] $qmkPath = "$Env:USERPROFILE\Source\Repos\qmk_firmware",
        [string] $teensyPath = "$Env:USERPROFILE\Source\Repos\teensy_loader_cli_windows"){
    Make-KeyMap $qmkPath
    Load-KeyMap $qmkPath $teensyPath
}

function New-KeyMap([string] $qmkPath = "$Env:USERPROFILE\Source\Repos\qmk_firmware"){
    Push-Location $qmkPath
    $modifiedPath = $qmkPath -replace "\\", "/"
    Invoke-Expression "docker run -e keymap=cbeatty -e keyboard=ergodox_ez --rm -v $($modifiedPath):/qmk:rw edasque/qmk_firmware"
    Pop-Location
}

function Import-KeyMap([string] $qmkPath = "$Env:USERPROFILE\Source\Repos\qmk_firmware",
        [string] $teensyPath = "$Env:USERPROFILE\Source\Repos\teensy_loader_cli_windows"){
    Push-Location $teensyPath
    ./teensy_loader_cli.exe -mmcu=atmega32u4 -w $qmkPath\ergodox_ez_cbeatty.hex -v
    Pop-Location
}
