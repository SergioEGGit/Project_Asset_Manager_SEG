//------------------------------------------------------------------------------

	#pragma hdrstop

//------------------------------Librerias---------------------------------------

	#include "Interfaz.h"
	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <windows.h>
	#include <stdio.h>
	#include "Variables.h"
	#include "Metodos.h"

	using namespace std;

//------------------------------Variables---------------------------------------

	int VariablesInterfaz::AnchoPantalla = 0;
	int VariablesInterfaz::AltoPantalla = 0;
	char Contrasena[20];

//-------------------------------M�todos----------------------------------------

	void Color(int Fondo, int Color)
	{
		HANDLE Consola = GetStdHandle(STD_OUTPUT_HANDLE);
		int NuevoColor = Color + (Fondo * 16);
		SetConsoleTextAttribute(Consola, NuevoColor);
	}

	void Fullscreen()
	{
		keybd_event(VK_MENU,
					   0x38,
						  0,
						  0);
		keybd_event(VK_RETURN,
						 0x1c,
							0,
							0);
		keybd_event(VK_RETURN,
						 0x1c,
			  KEYEVENTF_KEYUP,
							0);
		keybd_event(VK_MENU,
					   0x38,
			KEYEVENTF_KEYUP,
						  0);
		return;
	}

	void Resolucion()
	{
		VariablesInterfaz::AnchoPantalla = (GetSystemMetrics(SM_CXSCREEN) / 8) - 2;
		VariablesInterfaz::AltoPantalla = (GetSystemMetrics(SM_CYSCREEN) / 19) + 1;
	}

	void Posicionar(int x, int y)
	{
		COORD coord;
		coord.X = ((VariablesInterfaz::AnchoPantalla - 2)/2) - x;
		coord.Y = ((VariablesInterfaz::AltoPantalla - 2)/2) - y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void OcultarPassword(char Pass[])
	{
		int Contador = 0;
		cout.flush();

		do
		{
			Pass[Contador] = (unsigned char) getch();

			if(Pass[Contador] != 8)
			{
				cout << '*';
				Contador++;
			}
			else if(Contador > 0)
			{
				cout << (char)8 << (char)32 << (char)8;
				Contador--;
			}

			cout.flush();
		}
		while(Pass[Contador - 1] != 13);

		Pass[Contador - 1] = NULL;
	}

	void MenuLogin()
	{
		Color(0,12);
		Posicionar(17, 17);
		cout<< "Universidad De San Carlos De Guatemala" <<endl;
		Posicionar(9, 15);
		cout<< "Facultad De Ingenieria" <<endl;
		Posicionar(8, 13);
		cout<< "Estructuras De Datos" <<endl;
		Posicionar(3, 11);
		cout<< "Proyecto 1" <<endl;
		Color(0,1);
		Posicionar(14, 9);
		cout<< "Sergio Alexander Echigoyen Gomez" <<endl;
		Posicionar(3, 7);
		cout<< "201801628" <<endl;


		Color(0,11);
		Posicionar(16, 3);
		cout<< "Sistema SEG: Gestion Renta De Activos" <<endl;
		Posicionar(8, 1);
		cout<< "Ingreso De Usuarios" <<endl;
		Posicionar(16, -1);
		cout<< "Ingrese Su Nombre De Usuario: " <<endl;
		Posicionar(-14, -1);
		cin >> Variables::UsuarioA;
		Posicionar(16, -3);
		cout<< "Ingrese Su Empresa: " <<endl;
		Posicionar(-4, -3);
		cin.ignore();
		getline(cin, Variables::EmpresaUA);
		Posicionar(16, -5);
		cout<< "Ingrese Su Departamento: " <<endl;
		Posicionar(-9, -5);
		getline(cin, Variables::DepartamentoUA);
		Posicionar(16, -7);
		cout<< "Ingrese Su Contrase\244a: " <<endl;
		Posicionar(-7, -7);
        OcultarPassword(Contrasena);
		Variables::PasswordUA = Contrasena;
	}

	void MenuAdministrador()
	{
		Color(0,12);
		Posicionar(11, 17);
		cout<< "Menu Administrador : Bienvenido " << "Administrador" <<endl;
		Posicionar(17, 15);
		cout<< "1.Registrar Usuario." <<endl;
		Posicionar(17, 13);
		cout<< "2.Reporte Matriz Dispersa." <<endl;
		Posicionar(17, 11);
		cout<< "3.Reporte Activos Disponibles De Un Departamento." <<endl;
		Posicionar(17, 9);
		cout<< "4.Reporte Activos Disponibles De Una Empresa." <<endl;
		Posicionar(17, 7);
		cout<< "5.Reporte Transacciones." <<endl;
		Posicionar(17, 5);
		cout<< "6.Reporte Activos De Un Usuario." <<endl;
		Posicionar(17, 3);
		cout<< "7.Activos Rentados Por Un Usuario." <<endl;
		Posicionar(17, 1);
		cout<< "8.Ordenar Transacciones." <<endl;
		Posicionar(17, -1);
		cout<< "9.Log Out" <<endl;
		Posicionar(17, -3);
		cout<< "10.Salir" <<endl;

		Posicionar(7, -5);
		cout<< "Ingrese Una Opcion: " <<endl;
		Posicionar(-13, -5);
		cin >> VariablesMetodos::OpcionMenuAdministrador;
	}

	void MenuUsuario()
	{
        Color(0,12);
		Posicionar(12, 17);
		cout<< "Menu Usuario : Bienvenido " << Variables::UsuarioA <<endl;
		Posicionar(17, 15);
		cout<< "          1.Agregar Activo." <<endl;
		Posicionar(17, 13);
		cout<< "          2.Eliminar Activo." <<endl;
		Posicionar(17, 11);
		cout<< "          3.Modificar Activo." <<endl;
		Posicionar(17, 9);
		cout<< "          4.Rentar Activo." <<endl;
		Posicionar(17, 7);
		cout<< "          5.Activos Rentados." <<endl;
		Posicionar(17, 5);
		cout<< "          6.Mis Activos Rentados." <<endl;
		Posicionar(17, 3);
		cout<< "          7.Log out." <<endl;
		Posicionar(17, 1);
		cout<< "          8.Salir." <<endl;

		Posicionar(7, -1);
		cout<< "Ingrese Una Opcion: " <<endl;
		Posicionar(-13, -1);
		cin >> VariablesMetodos::OpcionMenuAdministrador;
    }

	void MenuRegistrarUsuario()
	{
		Color(0,14);
		Posicionar(10, 17);
		cout<< "  Registro De Usuarios" <<endl;
		Posicionar(17, 15);
		cout<< "Ingrese Nombre Completo: " <<endl;
		Posicionar(-8, 15);
		getline(cin, Variables::ArrayAux[0]);
		Posicionar(17, 13);
		cout<< "Ingrese Nombre De Usuario: " <<endl;
		Posicionar(-10, 13);
		cin>> Variables::ArrayAux[1];
		cin.ignore();
		Posicionar(17, 11);
		cout<< "Ingrese Contrase\244a: " <<endl;
		Posicionar(-3, 11);
		OcultarPassword(Contrasena);
		Variables::ArrayAux[2] = Contrasena;
		Posicionar(17, 9);
		cout<< "Ingrese Nombre De Empresa: "<<endl;
		Posicionar(-10, 9);
		getline(cin, Variables::ArrayAux[3]);
		Posicionar(17, 7);
		cout<< "Ingrese Nombre Departamento: " <<endl;
		Posicionar(-12, 7);
		getline(cin, Variables::ArrayAux[4]);
	}

	void MenuCrearActivo()
	{
        Color(0,14);
		Posicionar(10, 17);
		cout<< " Registro De Activos" <<endl;
		Posicionar(14, 15);
		cout<< "Ingrese Nombre: " <<endl;
		Posicionar(-2, 15);
		getline(cin, Variables::ArrayAux[0]);
		Posicionar(14, 13);
		cout<< "Ingrese Descripcion: " <<endl;
		Posicionar(-7, 13);
		getline(cin, Variables::ArrayAux[1]);
	}

	void MenuReporteActivoPorUsuario()
	{
		Color(0,15);
		Posicionar(14, 17);
		cout<< "Reporte De Activos Por Usuario" <<endl;
		Posicionar(16, 15);
		cout<< "Ingrese Nombre De Usuario: " <<endl;
		Posicionar(-11, 15);
		getline(cin, Variables::ArrayAux[0]);
		Posicionar(16, 13);
		cout<< "Ingrese Empresa: " <<endl;
		Posicionar(-1, 13);
		getline(cin, Variables::ArrayAux[1]);
		Posicionar(16, 11);
		cout<< "Ingrese Departamento: " <<endl;
		Posicionar(-6, 11);
		getline(cin, Variables::ArrayAux[2]);
	}

	void Marco(int Col1, int Col2, int Fil1, int Fil2)
	{
		Color(0,9);
		for(int Cols = Col1; Cols <= Col2; Cols++)
		{
			for(int Fils = Fil1; Fils <= Fil2; Fils++)
			{
				gotoxy(Cols,Fils);
				//Linea Vertical Derecha E Izquierda
				if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
				{
					cout << (char)186;
				}
				//Linea Horizontal Superior E Inferior
				else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
				{
					cout << (char)205;
				}
			}
		}

		//Esquina Superior Izquierda
		gotoxy(Col1,Fil1);
		cout << (char)201;
		//Esquina Inferior Izquierda
		gotoxy(Col1,Fil2);
		cout << (char)200;
		//Esquina Superior Derecha
		gotoxy(Col2,Fil1);
		cout << (char)187;
		//Esquina Inferior Derecha
		gotoxy(Col2,Fil2);
		cout << (char)188;
	}

//---------------------------------------------------------------------------

	#pragma package(smart_init)
