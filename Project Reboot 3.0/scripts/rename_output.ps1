param(
    [string]$InputPath,    # full path to built file (e.g. ...\Release\Project.dll)
    [string]$HeaderPath    # path to include\build_flags.h
)

if (-not (Test-Path $InputPath)) {
    Write-Host "Built file not found: $InputPath" -ForegroundColor Yellow
    exit 0
}

if (-not $HeaderPath) {
    # try to locate globals.h in project folder or parent folders
    $projDir = Split-Path $InputPath -Parent -Parent
    $candidates = @(
        Join-Path $projDir "globals.h",
        Join-Path $projDir "include\build_flags.h",
        Join-Path $projDir "include\globals.h",
        Join-Path (Split-Path $projDir -Parent) "globals.h"
    )

    foreach ($c in $candidates) {
        if (Test-Path $c) { $HeaderPath = $c; break }
    }

    if (-not $HeaderPath) {
        Write-Host "No header found (searched globals.h and include/build_flags.h)." -ForegroundColor Yellow
    }
}

$Above = $false
$ClientOnly = $false

if (Test-Path $HeaderPath) {
    $lines = Get-Content $HeaderPath -ErrorAction SilentlyContinue
    foreach ($l in $lines) {
        $trim = $l.Trim()
        if ($trim -match '^//#') { continue }
        if ($trim -match '^\/\/') { continue }
        # handle C-style comments simple case
        if ($trim -match '#\s*define\s+ABOVE_S20') { $Above = $true }
        if ($trim -match '#\s*define\s+CLIENT_ONLY') { $ClientOnly = $true }
    }
} else {
    Write-Host "Header not found: $HeaderPath" -ForegroundColor Yellow
}

$dir = Split-Path $InputPath -Parent
$ext = [IO.Path]::GetExtension($InputPath)

# Determine new name per rules
# Prefer ABOVE_S20 to signal S20+ builds. CLIENT_ONLY indicates a client build name.
if ($Above -and $ClientOnly) {
    # Both flags: produce the S20+ Client name (explicit short form)
    $newName = "S20+ Client$ext"
}
elseif ($Above) {
    # ABOVE_S20 only: produce the S20+ build name (user requested lowercase 'reboot')
    $newName = "reboot S20+$ext"
}
elseif ($ClientOnly) {
    # CLIENT_ONLY only: regular reboot client name
    $newName = "Reboot Client$ext"
}
else {
    Write-Host "No flags set; leaving output as-is." -ForegroundColor Green
    exit 0
}

$dest = Join-Path $dir $newName

# If destination already exists, overwrite
if (Test-Path $dest) {
    Remove-Item $dest -Force
}

Move-Item -Path $InputPath -Destination $dest
Write-Host "Renamed output to: $newName" -ForegroundColor Green
