//------------------------------------------------------------------------------

	#pragma hdrstop

//-----------------------------Librerias----------------------------------------

	#include "Metodos.h"
	#include "Variables.h"
	#include "Interfaz.h"
	#include "MatrizDispersaEstructura.h"
	#include <iostream>
	#include <string>
	#include <cstring>

	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//-----------------------------Variables----------------------------------------

	int VariablesMetodos::OpcionMenuAdministrador = 0;
	bool VariablesMetodos::ValidarDato = false;
	bool VariablesMetodos::ExisteUsuario = false;

//------------------------------M�todos-----------------------------------------

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

	string UpperCase(string Cadena)
	{
		int Contador = 0;
		string NuevoString = "";

		char String[Cadena.size() + 1];
		char Caracter;

		strcpy(String, Cadena.c_str());

		while(String[Contador])
		{
			Caracter = String[Contador];
			NuevoString += toupper(Caracter);
			Contador++;
		}

		return NuevoString;
    }

	string TrimCadena(string Cadena)
	{
		string Frase = "";

		for(int i = 0; Cadena[i] != 0; ++i)
		{
			if(Cadena[i] != 32)
			{
				Frase += Cadena[i];
			}
		}
		return Frase;
	}

	void VerificarUsuario(string Usuario, string Pass, string Departamento, string Empresa)
	{
		VariablesMetodos::ExisteUsuario = BuscarUsuarioMatrizDispersaU(Variables::MatrizDispersaUsuarios, Usuario, Empresa, Departamento);

		if(VariablesMetodos::ExisteUsuario)
		{
			if(Variables::PasswordUA == Pass)
			{
                if(Usuario == "Admin")
				{
					MenuAdministradorCiclo();
				}
				else
				{
					MenuUsuarioCiclo();
				}
			}
			else
			{
                Color(0, 4);
				Posicionar(13, -9);
				cout<< "La Contrase\244a Es Incorrecta" <<endl;
				system("pause > 0");
				MenuLoginCiclo();
			}
		}
		else
		{
		   Color(0, 4);
		   Posicionar(16, -9);
		   cout<< "No Existe El Nombre De Usuario Indicado" <<endl;
		   system("pause > 0");
		}
	}

	void MenuLoginCiclo()
	{
		 do
		 {
             system("cls");
			 Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
			 MenuLogin();
			 VerificarUsuario(Variables::UsuarioA, Variables::PasswordUA, Variables::DepartamentoUA, Variables::EmpresaUA);
		 }
		 while(!VariablesMetodos::ExisteUsuario);
	}

	void MenuAdministradorCiclo()
	{
		while(VariablesMetodos::OpcionMenuAdministrador != 10)
		{
			VariablesMetodos::ValidarDato = false;
			VariablesMetodos::OpcionMenuAdministrador = 0;

			do
			{
				system("cls");
				Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);

				MenuAdministrador();

				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					Color(0, 4);
					Posicionar(-3, -3);
					cout<< "Debe De Ingresar Un Numero" <<endl;
					system("pause > 0");
					VariablesMetodos::ValidarDato = false;
				}
				else
				{
					VariablesMetodos::ValidarDato = true;
				}
			}
			while(!VariablesMetodos::ValidarDato);

			switch(VariablesMetodos::OpcionMenuAdministrador)
			{
				case 1:
					system("cls");
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
					MenuRegistrarUsuario();

					VariablesMetodos::ExisteUsuario = InsertarUsuarioMatrizDispersaU(Variables::MatrizDispersaUsuarios, Variables::ArrayAux[1], Variables::ArrayAux[0], Variables::ArrayAux[2], Variables::ArrayAux[4], Variables::ArrayAux[3]);

					if(VariablesMetodos::ExisteUsuario == true)
					{
						Color(0, 10);
						Posicionar(12, 5);
						cout << "Usuario Agregado Con Exito!";
						system("pause > 0");
					}
					else
					{
						Color(0, 4);
						Posicionar(17, 5);
						cout << "El Usuario Indicado Ya Existe En El Sistema.";
						system("pause > 0");
					}
				break;

				case 2:
						ReporteUsuariosMatrizDispersaU(Variables::MatrizDispersaUsuarios);
						system("pause > 0");
				break;

				case 9:
					 MenuLoginCiclo();
					 VariablesMetodos::OpcionMenuAdministrador = 10;
				break;

				case 10:
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
					Color(0, 13);
					Posicionar(17, 17);
					cout<< "Gracias Por Usar Esta Aplicaion.. Vuelva Pronto...!";
					system("pause > 0");
					VariablesMetodos::OpcionMenuAdministrador = 10;
				break;

				default:
					//Nada
				break;
			}

            cout<<endl<<endl;
			system("cls");
        }
	}

	void MenuUsuarioCiclo()
	{
		while(VariablesMetodos::OpcionMenuAdministrador != 8)
		{
			VariablesMetodos::ValidarDato = false;
			VariablesMetodos::OpcionMenuAdministrador = 0;

			do
			{
				system("cls");
				Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);

				MenuUsuario();

				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					Color(0, 4);
					Posicionar(-3, -3);
					cout<< "Debe De Ingresar Un Numero" <<endl;
					system("pause > 0");
					VariablesMetodos::ValidarDato = false;
				}
				else
				{
					VariablesMetodos::ValidarDato = true;
				}
			}
			while(!VariablesMetodos::ValidarDato);

			switch(VariablesMetodos::OpcionMenuAdministrador)
			{
				case 1:
					system("cls");
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
					MenuCrearActivo();
				break;

				case 2:

				break;

				case 9:
					 MenuLoginCiclo();
					 VariablesMetodos::OpcionMenuAdministrador = 10;
				break;

				case 10:
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
					Color(0, 13);
					Posicionar(17, 17);
					cout<< "Gracias Por Usar Esta Aplicaion.. Vuelva Pronto...!";
					system("pause > 0");
					VariablesMetodos::OpcionMenuAdministrador = 10;
				break;

				default:
					//Nada
				break;
			}

            cout<<endl<<endl;
			system("cls");
		}
	}




