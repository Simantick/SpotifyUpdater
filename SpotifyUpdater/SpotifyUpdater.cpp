#include <iostream>
#include <Windows.h>
#include <Lmcons.h>
#include <fstream>
#pragma warning(disable: 4996)

using namespace std;

class Spicetify {
public:
	void SetP() {
		PowCom = "@echo off\n";
		PowCom += "echo Installing Spicetify...\n";
		PowCom += "PowerShell -Command \"Start-Sleep -Seconds 5; iwr -useb https://raw.githubusercontent.com/spicetify/spicetify-cli/master/install.ps1 | iex\"\n";
		PowCom += "PowerShell -Command \"Start-Sleep -Seconds 5; iwr -useb https://raw.githubusercontent.com/spicetify/spicetify-marketplace/main/resources/install.ps1 | iex\"\n";
	}
	string GetPC() {
		return PowCom;
	}
	void StartSpotify() {
		appdata = getenv("APPDATA");
		command1 = appdata;
		command1 += "\\Spotify\\spotify.exe";
		wString = new wchar_t[4096];
		MultiByteToWideChar(CP_ACP, 0, command1.c_str(), -1, wString ,4096);
		cout << wString << endl;
		ShellExecute(NULL, L"open", wString, L"", L"C:\\", SW_NORMAL);
	}
private:
	string PowCom,command1, command2;
	char* appdata;
	wchar_t* wString;
};

int main(){
	Spicetify Sp;
	ofstream file;
	file.open("Updater.bat");
	Sp.SetP();
	file << Sp.GetPC()<< endl;
	file.close();
	Sp.StartSpotify();
	system("Updater.bat");
	remove("Updater.bat");
}

