//------------------------------------------------------------------------------

	#pragma hdrstop
	#pragma argsused

	#ifdef _WIN32
	#include <tchar.h>
	#else
		typedef char _TCHAR;
	#define _tmain main
	#endif

//-------------------------------Librerias--------------------------------------

	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <windows.h>
	#include <cstring>
	#include "Interfaz.h"

	using namespace std;

//----------------------------------Main----------------------------------------

	int _tmain(int argc, _TCHAR* argv[])
	{
		Resolucion();
		Fullscreen();
		system("cls");
		Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
		MenuLogin();
		getch();

		return 0;
	}
