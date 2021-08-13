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
	string VariablesMetodos::CodigoAlfaNumerico = "";
	ArbolAVLActivos NuevoActivo  = nullptr;
	string VariablesMetodos::AgregueActivo = "";
	string VariablesMetodos::ElimineActivo = "";
	int VariablesMetodos::ContadorAuxiliar = 0;

//------------------------------Métodos-----------------------------------------

	//Métodos Sobre Cadenas

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

	//Generar Codigo Aleatorio

	string GenerarCodigoAlfanumerico()
	{
		//Declaraciones
		string Cadena = "";
		char CaracterYDigitos[36] =
		{
			'A','B','C','D','E','F','G','H','I','J','K','L',
			'M','N','O','P','Q','R','S','T','U','V','W','X',
			'Y','Z',
			'0','1','2','3','4','5','6','7','8','9'
		};
		char CaracterDigito[15];

		//Numeros Aleatorios
		srand(time(NULL));

		//Comienzo Generar Código Aleatorio

		for(int i = 0; i < 15; i++)
		{
			CaracterDigito[i] = CaracterYDigitos[rand() % 35];
			Cadena += CaracterDigito[i];
		}

		return Cadena;
	}

	//Verificar Usuarios

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

	//Menú Ciclos

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
		//Declaraciones
		string NombreUsuario = "";

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

					AgregarUsuario(Variables::ArrayAux[0], Variables::ArrayAux[1], Variables::ArrayAux[2], Variables::ArrayAux[4], Variables::ArrayAux[3], Variables::MatrizDispersaUsuarios);

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

				case 3:
					Variables::ReporteArbol = "";
					Variables::NumerosDeNodosArbolAVL = 0;
                    system("cls");
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
					MenuReporteDepartamento();
					ReporteActivosPorDepartamentoMatrizDispersaU(Variables::MatrizDispersaUsuarios, Variables::ArrayAux[0]);
					system("pause > 0");
				break;

				case 4:
                    Variables::ReporteArbol = "";
					Variables::NumerosDeNodosArbolAVL = 0;
                    system("cls");
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
					MenuReporteEmpresa();
					ReporteActivosPorEmpresaMatrizDispersaU(Variables::MatrizDispersaUsuarios, Variables::ArrayAux[0]);
					system("pause > 0");
				break;

				case 5:
					ReporteListaDobleCircularT(Variables::ListaDobleCircularTransaccion);
					system("pause > 0");
				break;

				case 6:
					if(Variables::MatrizDispersaUsuarios -> Sgte != nullptr)
					{
						system("cls");
						Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);

						Variables::ContadorActivos = 7;

						MostrarUsuarios(Variables::MatrizDispersaUsuarios, Variables::ContadorActivos);

                        MenuReporteActivoPorUsuario();

						if(BuscarUsuarioMatrizDispersaU(Variables::MatrizDispersaUsuarios, Variables::ArrayAux[0], Variables::ArrayAux[1], Variables::ArrayAux[2]))
						{
							ReporteActivosUsuarioArbolAVLA(Variables::ArbolAVLAuxiliar);
							system("pause > 0");
						}
						else
						{
							Color(0, 4);
							Posicionar(17, 9);
							cout << "El Usuario No Existe En El Sistema.";
							system("pause > 0");
						}
					}
					else
					{
                        Color(0, 4);
						Posicionar(-13, -5);
						cout << "Aun No Existen Usuarios En El Sistema";
						system("pause > 0");
					}
				break;

				case 7:
                    if(Variables::MatrizDispersaUsuarios -> Sgte != nullptr)
					{
						system("cls");
						Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);

						Variables::ContadorActivos = 7;

						MostrarUsuarios(Variables::MatrizDispersaUsuarios, Variables::ContadorActivos);

                        MenuReporteActivoPorUsuario();

						if(BuscarUsuarioMatrizDispersaU(Variables::MatrizDispersaUsuarios, Variables::ArrayAux[0], Variables::ArrayAux[1], Variables::ArrayAux[2]))
						{
							ReporteUsuarioListaDobleCircularT(Variables::ListaDobleCircularTransaccion, Variables::ArrayAux[0], UpperCase(Variables::ArrayAux[1]), UpperCase(Variables::ArrayAux[2]));
							system("pause > 0");
						}
						else
						{
							Color(0, 4);
							Posicionar(17, 9);
							cout << "El Usuario No Existe En El Sistema.";
							system("pause > 0");
						}
					}
					else
					{
                        Color(0, 4);
						Posicionar(-13, -5);
						cout << "Aun No Existen Usuarios En El Sistema";
						system("pause > 0");
					}
				break;

				case 8:
                    system("cls");
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
					MenuOrdenamiento();
					OrdenarListaDobleCircularT(Variables::ListaDobleCircularTransaccion, Variables::TipoOrdenamiento);
					Color(0, 8);
					Posicionar(17, 9);
					cout<< "Lista Ordenada Con Exito!" <<endl;
                    system("pause > 0");
				break;

				case 9:
					 MenuLoginCiclo();
					 VariablesMetodos::OpcionMenuAdministrador = 10;
				break;

				case 10:
					system("cls");
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
		string Aux = "";
		time_t FechaActual;
		FechaActual = time(NULL);
		time(&FechaActual);
		int Altura = 0;

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

					VariablesMetodos::CodigoAlfaNumerico = GenerarCodigoAlfanumerico();

					VariablesMetodos::AgregueActivo = InsertarActvioArbolAVLANuevoActivo(Variables::ArbolAVLAuxiliar, VariablesMetodos::CodigoAlfaNumerico, Variables::ArrayAux[0], Variables::ArrayAux[1]);
					CalcularAlturaVoidArbolAVLA(Variables::ArbolAVLAuxiliar, *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario);

					if(VariablesMetodos::AgregueActivo == "Si")
					{
						Color(0, 10);
						Posicionar(12, 11);
						cout << "Activo Agregado Con Exito!";
						system("pause > 0");
					}
					else
					{
						Color(0, 4);
						Posicionar(19, 11);
						cout << "El Activo Indicado Ya Existe En El Sistema.";
						system("pause > 0");
					}
				break;

				case 2:
					system("cls");
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);

					MenuEliminarActivo();

					BuscarActivoArbolAVLA(Variables::ArbolAVLAuxiliar, *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario, Variables::ArrayAux[0]);

					VariablesMetodos::ElimineActivo = EliminarActivoArbolAVLA(Variables::ArbolAVLAuxiliar, *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario, Variables::ArrayAux[0]);

					if(VariablesMetodos::ElimineActivo == "Si")
					{
                        system("cls");
						Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
						MenuEliminado();
                        system("pause > 0");
					}
					else
					{
						Color(0, 4);
						Posicionar(-18, Variables::ContadorActivos);
						cout << "No Se Puede Eliminar El Activo Indicado.";
						system("pause > 0");
					}

				break;

				case 3:
					system("cls");
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);

					MenuModificarActivo();

					VariablesMetodos::ElimineActivo = "No";

					BuscarActivoArbolAVLA(Variables::ArbolAVLAuxiliar, *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario, UpperCase(Variables::ArrayAux[0]));

					if(VariablesMetodos::ElimineActivo == "Si")
					{
                        system("cls");
						Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
						MenuModificado();

						VariablesMetodos::ElimineActivo = "No";

						ModificarDescripcionActivoArbolAVLA(Variables::ArbolAVLAuxiliar, *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario, UpperCase(Variables::ArrayAux[0]), Variables::ArrayAux[1]);

						if(VariablesMetodos::ElimineActivo == "No")
						{
							Color(0, 4);
							Posicionar(17, 5);
							cout << "  No Se Puede Modificar El Activo " <<endl;
							system("pause > 0");
						}
					}
					else
					{
						Color(0, 4);
						Posicionar(-16, Variables::ContadorActivos);
						cout << "No Se Encuentra El Activo Indicado.";
						system("pause > 0");
					}
				break;

				case 4:
					system("cls");
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
                    Variables::TodosLosActivos = 15;
					MostrarActivosUsuarios(Variables::MatrizDispersaUsuarios, VariablesMetodos::ContadorAuxiliar);
					MenuRentarActivo();

					if(Variables::ArrayAux[0] == "Salir" || Variables::ArrayAux[0] == "salir")
					{
						//Nada
					}
					else
					{
                        BuscarArbolUsuarioMatrizDispersaU(Variables::MatrizDispersaUsuarios, Variables::ArrayAux[1], UpperCase(Variables::ArrayAux[2]), UpperCase(Variables::ArrayAux[3]));
						ModificarEstadoActivoArbolAVLA(Variables::ArbolAVLAuxiliar, *Variables::AuxiliarArbol -> ArbolAVLActivosUsuario, UpperCase(Variables::ArrayAux[0]));

						Aux = GenerarCodigoAlfanumerico();

						Aux = UpperCase(Aux);

						InsertarTransaccionListaDobleCircularT(Variables::ListaDobleCircularTransaccion, Aux, Variables::ArrayAux[0], Variables::UsuarioA, Variables::EmpresaUA, Variables::DepartamentoUA, Variables::ArrayAux[1], Variables::ArrayAux[2], Variables::ArrayAux[3], FechaActual, stoi(Variables::ArrayAux[4]));

						Posicionar(-10, Variables::TodosLosActivos);
						cout<< "Activo Rentado Con Exito! " <<endl;

						system("Pause > 0");
					}
				break;

				case 5:
                    system("cls");
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
					Color(0, 15);
					Posicionar(17, 17);
					cout<< "       Activos Rentados  " <<endl;
					Altura = MostrarActivosListaDobleCircularT(Variables::ListaDobleCircularTransaccion, Variables::UsuarioA, Variables::EmpresaUA, Variables::DepartamentoUA, 15);
					system("Pause > 0");
				break;

				case 6:
					system("cls");
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
					Color(0, 13);
					Posicionar(17, 17);
					cout<< "         Mis Activos Rentados " <<endl;
					Variables::ContadorActivos = 15;
					Variables::ContadorAux = 1;
					MostrarActivosRentados(Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario);
                    system("pause > 0");
				break;

				case 7:
					 MenuLoginCiclo();
					 VariablesMetodos::OpcionMenuAdministrador = 10;
				break;

				case 8:
					Marco(0, VariablesInterfaz::AnchoPantalla - 2, 0, VariablesInterfaz::AltoPantalla + 6);
					Color(0, 13);
					Posicionar(17, 17);
					cout<< "Gracias Por Usar Esta Aplicacion.. Vuelva Pronto...!";
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



