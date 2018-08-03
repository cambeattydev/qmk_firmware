function Make-Load-KeyMap([string] $qmkPath = "$Env:USERPROFILE\Source\Repos\qmk_firmware",
        [string] $teensyPath = "$Env:USERPROFILE\Source\Repos\teensy_loader_cli_windows"){
    Make-KeyMap $qmkPath
    Load-KeyMap $qmkPath $teensyPath
}

function Make-KeyMap([string] $qmkPath = "$Env:USERPROFILE\Source\Repos\qmk_firmware"){
    Push-Location $qmkPath
    C:\msys32\msys2_shell.cmd -msys -l -i -c  "cd /c/Users//Cameron.Beatty/source/repos/qmk_firmware/ && make ergodox_ez:cbeatty"
    Pop-Location
}

function Load-KeyMap([string] $qmkPath = "$Env:USERPROFILE\Source\Repos\qmk_firmware",
        [string] $teensyPath = "$Env:USERPROFILE\Source\Repos\teensy_loader_cli_windows"){
    Push-Location $teensyPath
    ./teensy_loader_cli.exe -mmcu=atmega32u4 -w $qmkPath\ergodox_ez_cbeatty.hex -v
    Pop-Location
}
