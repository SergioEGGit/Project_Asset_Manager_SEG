//------------------------------------------------------------------------------

	#ifndef VariablesH
	#define VariablesH

//-----------------------------Librerias----------------------------------------

	#include <iostream>
	#include <string>
	#include "MatrizDispersaEstructura.h"
	#include "LIstaDobleCircularEstructura.h"

	using namespace std;

//-----------------------------Variables----------------------------------------

	namespace Variables
	{
		extern int IdentificadorUA;
		extern string NombreCompletoUA;
		extern string UsuarioA;
		extern string PasswordUA;
		extern string DepartamentoUA;
		extern string EmpresaUA;
		extern MatrizDU MatrizDispersaUsuarios;
		extern MatrizDU ArbolAVLActivosUsuarioActual;
        extern ArbolAVLActivos ArbolAVLAuxiliar;
		extern int IdentificadorUsuario;
		extern string ArrayAux[9];
		extern bool Cabecera;
		extern bool Usuario;
		extern int NumerosDeNodosArbolAVL;
		extern int ContadorActivos;
		extern int ContadorAux;
		extern string IdentificadorAC;
		extern string NombreAC;
		extern string DescripcionAC;
		extern int Color;
		extern ListaDCTrans ListaDobleCircularTransaccion;
		extern string TipoOrdenamiento;
		extern string ReporteArbol;
		extern int TodosLosActivos;
		extern MatrizDU AuxiliarArbol;
	}

//------------------------------------------------------------------------------

	#endif


