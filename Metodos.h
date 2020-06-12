//------------------------------------------------------------------------------

	#ifndef MetodosH
	#define MetodosH

//-----------------------------Librerias----------------------------------------

	#include<iostream>
	#include<string>

	using namespace std;

//------------------------------Variables---------------------------------------

	namespace VariablesMetodos
	{
		extern int OpcionMenuAdministrador;
		extern bool ValidarDato;
		extern bool ExisteUsuario;
	}

//-------------------------------M�todos----------------------------------------

	string LowerCase(string Cadena);

	string UpperCase(string Cadena);

    string TrimCadena(string Cadena);

	void MenuLoginCiclo();

	void MenuAdministradorCiclo();

	void MenuUsuarioCiclo();

	void VerificarUsuario(string Usuario, char Pass[20], string Departamento, string Empresa);

//------------------------------------------------------------------------------

	#endif
