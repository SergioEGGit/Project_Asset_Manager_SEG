//------------------------------------------------------------------------------

	#pragma hdrstop

//---------------------------------Librerias------------------------------------

	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <cstdlib>
	#include <fstream>
	#include "LIstaDobleCircularEstructura.h"
	#include "Interfaz.h"
	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos--------------------------------------

	//Mostar Rentados

        //Mostrar Activos

	int MostrarActivosListaDobleCircularT(ListaDCTrans &ListaDoble, string NombreUsuario, string NombreEmpresa, string NombreDepartamento, int Altura)
	{
		//Declaraciones

		ListaDCTrans AuxiliarLista = ListaDoble;
		int ContadorAux = 1;

		//Comienza Recorrer Lista

		if(ListaDoble != nullptr)
		{
			do
			{
				if(AuxiliarLista -> UsuarioRentador == NombreUsuario && AuxiliarLista -> EmpresaRentador == NombreEmpresa&& AuxiliarLista -> DepartamentoRentador == NombreDepartamento)
				{
					Posicionar(30, Altura);
					cout<< ContadorAux << ". Codigo Transaccion: " << AuxiliarLista -> CodigoANumericoTrans << " Codigo Activo: " << AuxiliarLista -> CodigoANumericoActivo << " Periodo Renta : " << AuxiliarLista -> PeriodoRenta <<endl;
					Altura = Altura - 2;
					ContadorAux++;
				}
                AuxiliarLista = AuxiliarLista -> Sgte;
			}
			while(AuxiliarLista != ListaDoble);
		}

		return Altura;
	}

	//Reportes

		//Generar Reporte Lista Circular

	void ReporteListaDobleCircularT(ListaDCTrans &ListaDoble)
	{
		//Declaraciones

		ofstream SalidaArchivo("C:\\ReportesEDD\\ReporteListaDobleCircularTransacciones.txt");
		ListaDCTrans AuxiliarListaDoble = ListaDoble;
        int Contador = 0;
		string Temp[1000];
		string Same = "";
		string Asc = "";
		string Desc = "";

		//Comienza Reporte

		SalidaArchivo<< "digraph ListaDobleCircular" <<endl;
		SalidaArchivo<< "{" <<endl;
		SalidaArchivo<< "graph[charset=latin1]" <<endl;
		SalidaArchivo<< "node[shape = box, style = rounded, fontcolor = darkslategrey, color = firebrick1];" <<endl;

		//Recorrer Lista

		if(ListaDoble != NULL)
		{
			do
			{
				SalidaArchivo<< "NodoLista" << Contador << " [label = " <<"\" Codigo Transaccion: " << AuxiliarListaDoble -> CodigoANumericoTrans << "\\lCodigo Activo: " << AuxiliarListaDoble -> CodigoANumericoActivo << "\\lUsuario Rentador: " << AuxiliarListaDoble -> UsuarioRentador << "\\lDepartamento: " << AuxiliarListaDoble -> DepartamentoRentador << "\\lEmpresa: " << AuxiliarListaDoble -> EmpresaRentador << "\\lFecha Actual: " << AuxiliarListaDoble -> FechaActual << "\\lPeriodo Renta: " << AuxiliarListaDoble -> PeriodoRenta << "\\l" <<"\"]" <<endl;
				Temp[Contador] = "NodoLista" + to_string(Contador);
				Contador++;
				AuxiliarListaDoble = AuxiliarListaDoble -> Sgte;
			}
			while(AuxiliarListaDoble != ListaDoble);

			for(int i = 0; i < Contador; i++)
			{
				Same = Same + Temp[i] + " ";

				if(i < Contador - 1)
				{
					Asc = Asc + Temp[i] + "->";
					Desc = Desc + Temp[Contador - i - 1] + "->";
				}
				else
				{
					Asc = Asc + Temp[i];
					Desc = Desc + Temp[Contador - i - 1];
				}
			}


			Asc = Asc + "->" + "NodoLista0" + "->" + "NodoLista" + to_string(Contador - 1);
			SalidaArchivo<< "{ rank = same " << Same << "}" << endl;
			SalidaArchivo<< Asc <<endl;
			SalidaArchivo<< Desc <<endl;
			SalidaArchivo<< " " <<endl;
			SalidaArchivo<< "}";
			SalidaArchivo.close();

			//Generar Imagen
			system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\ReportesEDD\\ReporteListaDobleCircularTransacciones.txt -o C:\\ReportesEDD\\ReporteListaDobleCircularTransacciones.png");
			//Abrir Imagen
			system("C:\\ReportesEDD\\ReporteListaDobleCircularTransacciones.png &" );
		}
		else
		{
			Color(0, 4);
			Posicionar(17, 9);
			cout<< "La Lista Circular Se Encuentra Vacia"<<endl;
		}
	}

		//Generar Reporte Por Usuario

	void ReporteUsuarioListaDobleCircularT(ListaDCTrans &ListaDoble, string NombreUsuario, string NombreEmpresa, string NombreDepartamento)
	{
		//Declaraciones

		ofstream SalidaArchivo("C:\\ReportesEDD\\ReporteListaUsuarioDobleCircularTransacciones.txt");
		ListaDCTrans AuxiliarListaDoble = ListaDoble;
		int Contador = 0;
		string Temp[1000];
		string Same = "";
		string Asc = "";
		string Desc = "";

		//Comienza Reporte

		SalidaArchivo<< "digraph ListaDobleCircular" <<endl;
		SalidaArchivo<< "{" <<endl;
		SalidaArchivo<< "graph[charset=latin1]" <<endl;
		SalidaArchivo<< "node[shape = box, style = rounded, fontcolor = darkslategrey, color = firebrick1];" <<endl;

		//Recorrer Lista

		if(ListaDoble != NULL)
		{
			do
			{
				if(AuxiliarListaDoble -> UsuarioRentador == NombreUsuario && AuxiliarListaDoble -> EmpresaRentador == NombreEmpresa && AuxiliarListaDoble -> DepartamentoRentador == NombreDepartamento)
				{
                    SalidaArchivo<< "NodoLista" << Contador << " [label = " <<"\" Codigo Transaccion: " << AuxiliarListaDoble -> CodigoANumericoTrans << "\\lCodigo Activo: " << AuxiliarListaDoble -> CodigoANumericoActivo << "\\lUsuario Rentador: " << AuxiliarListaDoble -> UsuarioRentador << "\\lDepartamento: " << AuxiliarListaDoble -> DepartamentoRentador << "\\lEmpresa: " << AuxiliarListaDoble -> EmpresaRentador << "\\lFecha Actual: " << AuxiliarListaDoble -> FechaActual << "\\lPeriodo Renta: " << AuxiliarListaDoble -> PeriodoRenta << "\\l" <<"\"]" <<endl;
					Temp[Contador] = "NodoLista" + to_string(Contador);
					Contador++;
                }
				AuxiliarListaDoble = AuxiliarListaDoble -> Sgte;
			}
			while(AuxiliarListaDoble != ListaDoble);

			for(int i = 0; i < Contador; i++)
			{
				Same = Same + Temp[i] + " ";

				if(i < Contador - 1)
				{
					Asc = Asc + Temp[i] + "->";
					Desc = Desc + Temp[Contador - i - 1] + "->";
				}
				else
				{
					Asc = Asc + Temp[i];
					Desc = Desc + Temp[Contador - i - 1];
				}
			}


			Asc = Asc + "->" + "NodoLista0" + "->" + "NodoLista" + to_string(Contador - 1);
			SalidaArchivo<< "{ rank = same " << Same << "}" << endl;
			SalidaArchivo<< Asc <<endl;
			SalidaArchivo<< Desc <<endl;
			SalidaArchivo<< " " <<endl;
			SalidaArchivo<< "}";
			SalidaArchivo.close();

			//Generar Imagen
			system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\ReportesEDD\\ReporteListaUsuarioDobleCircularTransacciones.txt -o C:\\ReportesEDD\\ReporteListaUsuarioDobleCircularTransacciones.png");
			//Abrir Imagen
			system("C:\\ReportesEDD\\ReporteListaUsuarioDobleCircularTransacciones.png &" );
		}
		else
		{
			Color(0, 4);
			Posicionar(17, 9);
			cout<< "La Lista Circular Se Encuentra Vacia"<<endl;
		}
	}

	//Ordenamientos

		//Ordenar Lista Ordenamiento Burbuja

	void OrdenarListaDobleCircularT(ListaDCTrans &ListaDoble, string Tipo)
	{
		//Declaraciones

		//Objeto Lista Doble Circular
		ListaDCTrans Primero;
		ListaDCTrans Segundo;

		//Variables Tipo String
		string CodigoAuxiliar;

		//Asignacion Variables

		Primero = ListaDoble;

		//Comienzo Primero Valor

		while(Primero -> Sgte != ListaDoble)
		{
			//Asignacion De Segundo

			Segundo = Primero -> Sgte;

			//Comienzo Valor A Comparar

			while(Segundo != ListaDoble)
			{
				//Seleccion Tipo De Ordenamiento

				if(Tipo == "Asc")
				{
					if(Primero -> CodigoANumericoTrans > Segundo -> CodigoANumericoTrans)
					{
						CodigoAuxiliar = Segundo -> CodigoANumericoTrans;
						Segundo -> CodigoANumericoTrans = Primero -> CodigoANumericoTrans;
						Primero -> CodigoANumericoTrans = CodigoAuxiliar;
					}
				}
				else if(Tipo == "Desc")
				{
					if(Primero -> CodigoANumericoTrans < Segundo -> CodigoANumericoTrans)
					{
						CodigoAuxiliar = Segundo -> CodigoANumericoTrans;
						Segundo -> CodigoANumericoTrans = Primero -> CodigoANumericoTrans;
						Primero -> CodigoANumericoTrans = CodigoAuxiliar;
					}
                }
				Segundo = Segundo -> Sgte;
			}
			Primero = Primero -> Sgte;
		}
	}

	//Inserci�n

		//Insertar Transicci�n

	void InsertarTransaccionListaDobleCircularT(ListaDCTrans &ListaDoble, string CodigoANumericoTrans, string CodigoANumericoActivo, string UsuarioRentador, string  EmpresaRentador, string DepartamentoRentador, string UsuarioRentado, string EmpresaRentado, string DepartamentoRentado, time_t FechaActual, int PeriodoRenta)
	{
		//Declaraciones

		//Objeto Tipo Lista Doble Circular

		ListaDCTrans AuxiliarTransicion = new ListaDobleCircularEstructura(CodigoANumericoTrans, CodigoANumericoActivo, UsuarioRentador, EmpresaRentador, DepartamentoRentador, UsuarioRentado, EmpresaRentado, DepartamentoRentado, FechaActual, PeriodoRenta);

		//Comineza Recorrido

		if(ListaDoble == nullptr)
		{
			//Lista Vacia

			AuxiliarTransicion -> Sgte = AuxiliarTransicion;
			AuxiliarTransicion -> Ante = AuxiliarTransicion;

			ListaDoble = AuxiliarTransicion;
		}
		else
		{
			//No Esta Vacia

			ListaDCTrans Ultimo = ListaDoble -> Ante;

			AuxiliarTransicion -> Sgte = ListaDoble;
			AuxiliarTransicion -> Ante = Ultimo;

			ListaDoble -> Ante = AuxiliarTransicion;
			Ultimo -> Sgte = AuxiliarTransicion;
		}
	}




