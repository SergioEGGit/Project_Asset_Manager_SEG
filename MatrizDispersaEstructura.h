//------------------------------------------------------------------------------

	#ifndef MatrizDispersaEstructuraH
	#define MatrizDispersaEstructuraH

//-----------------------------Librerias----------------------------------------

	#include <iostream>
	#include <string>
	#include <cstring>
	#include "ArbolAVLEstructura.h"

	using namespace std;

//-----------------------------Estructura---------------------------------------

	struct MatrizDispersaEstructura
	{
		//Objetos
		string NombreCompleto;
		string NombreUsuario;
		string Password;
		string NombreDepartamento;
		string NombreEmpresa;
		string TipoCabecera;
		//Arbol AVL De Activos
		ArbolAVLEstructura* ArbolAVLActivosUsuario;
		//Apuntadores
		struct MatrizDispersaEstructura *Sgte;
		struct MatrizDispersaEstructura *Ante;
		struct MatrizDispersaEstructura *Arr;
		struct MatrizDispersaEstructura *Aba;
		struct MatrizDispersaEstructura *Adte;
		struct MatrizDispersaEstructura *Atr;

		//Constructores

		//Nuevo Usuario
		MatrizDispersaEstructura(string NombreCompleto, string NombreUsuario, string Password, string NombreEmpresa, string NombreDepartamento)
		{
			//Objetos
			this -> NombreCompleto = NombreCompleto;
			this -> NombreUsuario = NombreUsuario;
			this -> Password = Password;
			this -> NombreEmpresa = NombreEmpresa;
			this -> NombreDepartamento = NombreDepartamento;
			this -> TipoCabecera = "";
			//Arbol AVL Activos
			this -> ArbolAVLActivosUsuario = nullptr;
			//Apuntadores
			this -> Sgte = nullptr;
			this -> Ante = nullptr;
			this -> Arr = nullptr;
			this -> Aba = nullptr;
			this -> Adte = nullptr;
			this -> Atr = nullptr;
		}

		//Nueva Cabecera
		MatrizDispersaEstructura(string TipoCabecera, string NombreCabecera)
		{
			//Apuntadores
			this -> Sgte = nullptr;
			this -> Ante = nullptr;
			this -> Arr = nullptr;
			this -> Aba = nullptr;
			this -> Adte = nullptr;
			this -> Atr = nullptr;

			//Arbola AVL Activos
			this -> ArbolAVLActivosUsuario = nullptr;

			//Tipo De Cabecera
			//Dep = Departamento
			//Emp = Empresa

			this -> TipoCabecera = "";

			if(TipoCabecera == "Dep")
			{
				//Soy Un Departamento
				this -> NombreDepartamento = NombreCabecera;
				this -> NombreEmpresa = "";
			}
			else if(TipoCabecera == "Emp")
			{
				//Soy Una Empresa
				this -> NombreEmpresa = NombreCabecera;
				this -> NombreDepartamento = "";
			}
		}
	};

	typedef struct MatrizDispersaEstructura *MatrizDU;

//--------------------------------M�todos---------------------------------------

	bool InsertarCabeceraEmpresaMatrizDispersaU(string NombreEmpresa, MatrizDispersaEstructura& UsuarioAux, MatrizDispersaEstructura& EmpresaAux);

	bool InsertarCabeceraDepartamentoMatrizDispersaU(MatrizDU &Matriz, string NombreDepartamento, MatrizDispersaEstructura& UsuarioAux, MatrizDispersaEstructura& DepartamentoAux);

	bool InsertarUsuarioMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreCompleto, string Password, string NombreDepartamento, string NombreEmpresa);

	bool BuscarUsuarioMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreEmpresa, string NombreDepartamento);

	void ReporteUsuariosMatrizDispersaU(MatrizDU &Matriz);

//---------------------------------------------------------------------------
	#endif
