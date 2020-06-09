//------------------------------------------------------------------------------

	#ifndef MatrizDispersaH
	#define MatrizDispersaH

//-----------------------------Librerias----------------------------------------

	#include <iostream>
	#include <string>
	#include <cstring>

	using namespace std;

//-----------------------------Estructura---------------------------------------

	struct MatrizDispersa
	{
		int Identificador;
		string NombreCompleto;
		string NombreUsuario;
		string Password;
		string NombreDepartamento;
		string NombreEmpresa;
		bool TipoCabecera;
		//Arbol AVL
		struct MatrizDispersa *Sgte;
		struct MatrizDispersa *Ante;
		struct MatrizDispersa *Arr;
		struct MatrizDispersa *Aba;
		struct MatrizDispersa *Adte;
		struct MatrizDispersa *Atr;

		MatrizDispersa(int Identificador, string NombreCompleto, string NombreUsuario, string Password, string NombreEmpresa, string NombreDepartamento)
		{
			this -> Identificador = Identificador;
			this -> NombreCompleto = NombreCompleto;
			this -> NombreUsuario = NombreUsuario;
			this -> Password = Password;
			this -> NombreEmpresa = NombreEmpresa;
			this -> NombreDepartamento = NombreDepartamento;
			this -> TipoCabecera = false;
			this -> Sgte = nullptr;
			this -> Ante = nullptr;
			this -> Arr = nullptr;
			this -> Aba = nullptr;
			this -> Adte = nullptr;
			this -> Atr = nullptr;
        }

		MatrizDispersa(bool TipoCabecera, string NombreCabecera)
		{
			this -> Sgte = nullptr;
			this -> Ante = nullptr;
			this -> Arr = nullptr;
			this -> Aba = nullptr;
			this -> Adte = nullptr;
			this -> Atr = nullptr;
			this -> TipoCabecera = false;

			if(TipoCabecera)
			{
				//Soy Un Departamento
				this -> NombreDepartamento = NombreCabecera;
				this -> NombreEmpresa = "";
			}
			else
			{
				//Soy Una Empresa
				this -> NombreEmpresa = NombreCabecera;
				this -> NombreDepartamento = "";
            }
		}
	};

	typedef struct MatrizDispersa *MatrizDU;

//--------------------------------M�todos---------------------------------------

	bool BuscarMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreEmpresa, string NombreDepartamento);

//---------------------------------------------------------------------------
	#endif
