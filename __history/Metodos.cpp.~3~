//------------------------------------------------------------------------------

	#pragma hdrstop

//-----------------------------Librerias----------------------------------------

	#include "Metodos.h"
	#include "Variables.h"
	#include <iostream>
	#include <string>
	#include <cstring>

	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//-----------------------------Variables----------------------------------------

	bool VariablesMetodos::EstoyRegistrado = false;

//------------------------------Métodos-----------------------------------------

	string LowerCase(string Cadena)
	{
		int Contador = 0;
		string NuevoString = "";

		char String[Cadena.size() + 1];
		char Caracter;

		strcpy(String, Cadena.c_str());

		while(String[Contador])
		{
			Caracter = String[Contador];
			NuevoString += tolower(Caracter);
			Contador++;
		}

		return NuevoString;
	}

	void VerificarUsuario(string Usuario, char Pass[20], string Departamento, string Empresa)
	{
		if(Usuario == "Admin")
		{
			cout<< "Menu Administrador" <<endl;
		}
		else
		{
			cout<< "Menu Usuario" <<endl;
		}
	}


