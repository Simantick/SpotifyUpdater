#include <iostream>
#include <Windows.h>
#include <Lmcons.h>
#include <fstream>

using namespace std;

class Spicetify {
public:
	void SetP() {
		PowCom = "@echo off\n";
		PowCom += "echo Installing Spicetify...\n";
		PowCom += "PowerShell -Command \"Start-Sleep -Seconds 5; iwr -useb https://raw.githubusercontent.com/spicetify/spicetify-cli/master/install.ps1 | iex\"\n";
		PowCom += "PowerShell -Command \"Start-Sleep -Seconds 5; iwr -useb https://raw.githubusercontent.com/spicetify/spicetify-marketplace/main/resources/install.ps1 | iex\"\n";
		PowCom += "echo Installation complete!\n";
		PowCom += "pause\n";
	}
	string GetPC() {
		return PowCom;
	}
private:
	string PowCom;
};

int main(){
	Spicetify Sp;
	ofstream file;
	file.open("Updater.bat");
	Sp.SetP();
	file << Sp.GetPC()<< endl;
	file.close();
	system("Updater.bat");
	remove("Updater.bat");
}

