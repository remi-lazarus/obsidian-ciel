# setup-claude.ps1
# Configure le profil PowerShell pour charger automatiquement le plugin obsidian
# (session-load / session-save) quand Claude Code est lancé depuis le vault.
#
# A exécuter une fois par machine après git clone.
# Usage : depuis PowerShell :
#   & "C:\chemin\vers\vault\Contexte\setup-claude.ps1"

$ErrorActionPreference = "Stop"

$vaultRoot  = Split-Path -Parent $PSScriptRoot
$skillsPath = Join-Path $vaultRoot "Contexte\Skills"

Write-Host ""
Write-Host "=== Setup Claude Code — Plugin obsidian ===" -ForegroundColor Cyan
Write-Host "Vault   : $vaultRoot"
Write-Host "Skills  : $skillsPath"
Write-Host ""

# Vérifier que le dossier Skills existe
if (-not (Test-Path $skillsPath)) {
    Write-Host "ERREUR : dossier Skills introuvable : $skillsPath" -ForegroundColor Red
    Write-Host "Vérifier que le vault est bien cloné et que le chemin est correct."
    exit 1
}

# Récupérer le chemin de l'exe claude
$claudeCmd = Get-Command claude -CommandType Application -ErrorAction SilentlyContinue
$claudeExe = if ($claudeCmd) { $claudeCmd.Source } else { "claude" }

# Bloc à insérer dans le profil
$profileBlock = @"

# Claude Code — chargement automatique du plugin obsidian pour le vault CIEL
`$_claudeExe = "$claudeExe"

function claude {
    `$vault = "$vaultRoot"
    if ((Get-Location).Path.StartsWith(`$vault)) {
        & `$_claudeExe --plugin-dir "$skillsPath" @args
    } else {
        & `$_claudeExe @args
    }
}
"@

$profilePath = $PROFILE

# Créer le dossier du profil si nécessaire
$profileDir = Split-Path -Parent $profilePath
if (-not (Test-Path $profileDir)) {
    New-Item -ItemType Directory -Path $profileDir -Force | Out-Null
}

# Vérifier si la fonction est déjà présente
if (Test-Path $profilePath) {
    $existing = Get-Content $profilePath -Raw -ErrorAction SilentlyContinue
    if ($existing -and $existing.Contains("plugin-dir")) {
        Write-Host "[OK] Profil PowerShell déjà configuré ($profilePath)" -ForegroundColor Green
    } else {
        Add-Content -Path $profilePath -Value $profileBlock -Encoding utf8
        Write-Host "[OK] Fonction claude ajoutée au profil : $profilePath" -ForegroundColor Green
    }
} else {
    Set-Content -Path $profilePath -Value $profileBlock.TrimStart() -Encoding utf8
    Write-Host "[OK] Profil PowerShell créé : $profilePath" -ForegroundColor Green
}

Write-Host ""
Write-Host "=== Configuration terminée ===" -ForegroundColor Cyan
Write-Host "Ouvrir un nouveau terminal PowerShell, puis lancer Claude Code depuis le vault."
Write-Host "Taper /session-load pour charger le contexte de la dernière session."
Write-Host ""
