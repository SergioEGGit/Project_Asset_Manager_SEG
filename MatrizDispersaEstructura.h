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
		//Variables
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

	//Mostrar

		//Mostrar Todos Los Usuarios

	void MostrarUsuarios(MatrizDU &Matriz, int ContadorAltura);

		//Mostrar Todos Los Activos

	void MostrarActivosUsuarios(MatrizDU &Matriz, int ContadorAltura);

	//Reportes

		//Reporte Activos Por Departamento

	void ReporteActivosPorDepartamentoMatrizDispersaU(MatrizDU &Matriz, string NombreDepartamento);

		//Reporte Activos Por Empresa

	void ReporteActivosPorEmpresaMatrizDispersaU(MatrizDU &Matriz, string NombreEmpresa);

		//Reporte Matriz

	void ReporteUsuariosMatrizDispersaU(MatrizDU &Matriz);

	//Inserci�n

		//Enlazar Cabecera Empresa

	void EnalazarEmpresaNueva(MatrizDU &Inicio, MatrizDU &CabEmp);

		//Enlazar Cabecera Departamento

	void EnalazarDepartamentoNuevo(MatrizDU &Inicio, MatrizDU &CabDep);

	//Comparaci�n Y Elecci�n Casos De Inserci�n

	void CasosInsercion(MatrizDU &CabDep, MatrizDU &CabEmp, MatrizDU &Usuario, MatrizDU &Inicio);

		//Insertar Nuevo Usuario

	void AgregarUsuario(string NombreCompleto_Usuario, string Nombre_Usuario, string Contrasena_Usuario, string Departamento_Usuario, string Empresa_Usuario, MatrizDU &Matriz);

	//B�squeda

		//Buscar Una Usuario

	bool BuscarUsuarioMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreEmpresa, string NombreDepartamento);

		//Buscar Arbol Usuario

	void BuscarArbolUsuarioMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreEmpresa, string NombreDepartamento);





//---------------------------------------------------------------------------
	#endif
