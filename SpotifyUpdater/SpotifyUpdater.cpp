#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

int main(){	
	string PowCom;
	ofstream file;
	WinExec("C:\\Users\\maxim\\AppData\\Roaming\\Spotify\\Spotify.exe", 1);
	file.open("Updater.bat");
	PowCom = "@echo off\n";
	PowCom += "echo Installing Spicetify...\n";
	PowCom += "PowerShell -Command \"Start-Sleep -Seconds 5; iwr -useb https://raw.githubusercontent.com/spicetify/spicetify-cli/master/install.ps1 | iex\"\n";
	PowCom += "PowerShell -Command \"Start-Sleep -Seconds 5; iwr -useb https://raw.githubusercontent.com/spicetify/spicetify-marketplace/main/resources/install.ps1 | iex\"\n";
	PowCom += "echo Installation complete!\n";
	PowCom += "pause\n";
	file << PowCom << endl;
	file.close();
	system("Updater.bat");
	remove("Updater.bat");
}

