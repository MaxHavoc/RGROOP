#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void WinMain()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	РГР::MyForm form;
	Application::Run(%form);
}
