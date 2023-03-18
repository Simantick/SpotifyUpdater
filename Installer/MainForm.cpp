#include "MainForm.h"
#include <iostream>
#include <Windows.h>
#include <Lmcons.h>
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;
int maine(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Installer::MainForm form;
	Application::Run(% form);
	return 0;
}