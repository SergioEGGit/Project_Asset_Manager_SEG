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
	MatrizDU Variables::ArbolAVLActivosUsuarioActual = nullptr;
	MatrizDU Variables::AuxiliarArbol = nullptr;
	ArbolAVLActivos Variables::ArbolAVLAuxiliar = nullptr;
	string Variables::ArrayAux[9];
	bool Variables::Cabecera = false;
	bool Variables::Usuario = false;
	int Variables::NumerosDeNodosArbolAVL = 0;
	int Variables::ContadorActivos = 0;
	int Variables::ContadorAux  = 0;
	string Variables::IdentificadorAC;
	string Variables::NombreAC;
	string Variables::DescripcionAC;
	int Variables::Color = 0;
	ListaDCTrans Variables::ListaDobleCircularTransaccion = nullptr;
	string Variables::TipoOrdenamiento = "";
	string Variables::ReporteArbol = "";
	int Variables::TodosLosActivos = 0;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

