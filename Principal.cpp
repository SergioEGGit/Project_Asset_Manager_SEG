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
	#include "Variables.h"
	#include "Metodos.h"
	#include "MatrizDispersa.h"

	using namespace std;

//----------------------------------Main----------------------------------------

	int _tmain(int argc, _TCHAR* argv[])
	{
		Resolucion();
		Fullscreen();
		Variables::MatrizDispersaUsuarios = nullptr;
		Variables::MatrizDispersaUsuarios = new MatrizDispersa(Variables::IdentificadorUsuario, "Administrador", "Admin", "12345", "General", "General");
		MenuLoginCiclo();

		return 0;
	}
