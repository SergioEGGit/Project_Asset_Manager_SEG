//------------------------------------------------------------------------------

	#pragma hdrstop

//-----------------------------Librerias----------------------------------------

	#include "Variables.h"
	#include<iostream>
	#include<string>

	using namespace std;

//-----------------------------Variables----------------------------------------

	int Variables::IdentificadorUA = 0;
	string Variables::NombreCompletoUA = "";
	string Variables::UsuarioA = "";
    string Variables::PasswordUA = "";
	string Variables::DepartamentoUA = "";
	string Variables::EmpresaUA = "";
	int Variables::IdentificadorUsuario = 0;
	MatrizDU Variables::MatrizDispersaUsuarios = nullptr;
	string Variables::ArrayAux[9];
	bool Variables::Cabecera = false;
	bool Variables::Usuario = false;

//------------------------------------------------------------------------------

	#pragma package(smart_init)


