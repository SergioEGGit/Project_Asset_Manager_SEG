//---------------------------------------------------------------------------

	#ifndef LIstaDobleCircularEstructuraH
	#define LIstaDobleCircularEstructuraH

//------------------------------Librerias---------------------------------------

	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <fstream>
	#include <cstring>
	using namespace std;

//-----------------------------Estructura---------------------------------------

	struct ListaDobleCircularEstructura
	{
		//Variables
		string CodigoANumericoTrans;
		string CodigoANumericoActivo;
		string UsuarioRentador;
		string EmpresaRentador;
		string DepartamentoRentador;
		string UsuarioRentado;
		string EmpresaRentado;
		string DepartamentoRentado;
		time_t FechaActual;
		int PeriodoRenta;
		//Apuntadores
		struct ListaDobleCircularEstructura *Sgte;
		struct ListaDobleCircularEstructura *Ante;

		//Constructor

		//Nueva Transacción

		ListaDobleCircularEstructura(string CodigoANumericoTrans, string CodigoANumericoActivo, string UsuarioRentador, string  EmpresaRentador, string DepartamentoRentador, string UsuarioRentado, string EmpresaRentado, string DepartamentoRentado, time_t FechaActual, int PeriodoRenta)
		{
			this -> CodigoANumericoTrans = CodigoANumericoTrans;
			this -> CodigoANumericoActivo = CodigoANumericoActivo;
			this -> UsuarioRentador = UsuarioRentador;
			this -> EmpresaRentador = EmpresaRentador;
			this -> DepartamentoRentador = DepartamentoRentador;
			this -> UsuarioRentado = UsuarioRentado;
			this -> EmpresaRentado = EmpresaRentado;
			this -> DepartamentoRentado = DepartamentoRentado;
			this -> FechaActual = FechaActual;
			this -> PeriodoRenta = PeriodoRenta;
			this -> Sgte = nullptr;
			this -> Ante = nullptr;
		}
	};

	typedef struct ListaDobleCircularEstructura *ListaDCTrans;


//-----------------------------Métodos------------------------------------------

    //Reportes

		//Generar Reporte Lista Circular

	void ReporteListaDobleCircularT(ListaDCTrans &Lista);

		//Generar Reporte Lista Circular

	void ReporteUsuarioListaDobleCircularT(ListaDCTrans &ListaDoble, string NombreUsuario, string NombreEmpresa, string NombreDepartamento);

	//Ordenamientos

		//Ordenar Lista Ordenamiento Burbuja

	void OrdenarListaDobleCircularT(ListaDCTrans &Lista, string Tipo);

	//Inserción

		//Insertar Transicción

	void InsertarTransaccionListaDobleCircularT(ListaDCTrans &Lista, string CodigoANumericoTrans, string CodigoANumericoActivo, string UsuarioRentador, string  EmpresaRentador, string DepartamentoRentador, string UsuarioRentado, string EmpresaRentado, string DepartamentoRentado, time_t FechaActual, int PeriodoRenta);

//---------------------------------------------------------------------------
#endif
