@echo off
echo Installing Spicetify...
PowerShell -Command "Start-Sleep -Seconds 5; iwr -useb https://raw.githubusercontent.com/spicetify/spicetify-cli/master/install.ps1 | iex"
PowerShell -Command "Start-Sleep -Seconds 5; iwr -useb https://raw.githubusercontent.com/spicetify/spicetify-marketplace/main/resources/install.ps1 | iex"

