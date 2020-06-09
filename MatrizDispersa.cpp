//------------------------------------------------------------------------------

	#pragma hdrstop

//-----------------------------Librerias----------------------------------------

	#include "MatrizDispersa.h"
	#include "Variables.h"
	#include <iostream>
	#include <string>
	#include <cstring>

	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------Métodos--------------------------------------

	bool BuscarMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreEmpresa, string NombreDepartamento)
	{
		MatrizDU Auxiliar = Matriz;
		bool Bandera = false;

		while(Auxiliar != nullptr)
		{
			if(Auxiliar -> NombreDepartamento == NombreDepartamento)
			{
				while(Auxiliar != nullptr)
				{
					if(Auxiliar -> NombreEmpresa == NombreEmpresa)
					{
						if(Auxiliar -> Atr != nullptr)
						{
                            while(Auxiliar != nullptr)
							{

								if(Auxiliar -> NombreUsuario == NombreUsuario)
								{
									Variables::IdentificadorUA = Auxiliar -> Identificador;
									Variables::NombreCompletoUA = Auxiliar -> NombreCompleto;
									Variables::UsuarioA = Auxiliar -> NombreUsuario;
									Variables::PasswordUA = Auxiliar -> Password;
									Variables::DepartamentoUA = Auxiliar -> NombreDepartamento;
									Variables::EmpresaUA = Auxiliar -> NombreEmpresa;
									Bandera = true;
									return Bandera;
									break;
								}
								Auxiliar = Auxiliar -> Atr;
							}
						}
						else
						{
							Variables::IdentificadorUA = Auxiliar -> Identificador;
							Variables::NombreCompletoUA = Auxiliar -> NombreCompleto;
							Variables::UsuarioA = Auxiliar -> NombreUsuario;
							Variables::PasswordUA = Auxiliar -> Password;
							Variables::DepartamentoUA = Auxiliar -> NombreDepartamento;
							Variables::EmpresaUA = Auxiliar -> NombreEmpresa;
							Bandera = true;
							return Bandera;
						}
						break;
					}
					Auxiliar = Auxiliar -> Aba;
				}
				break;
			}
			Auxiliar = Auxiliar -> Sgte;
		}
		return Bandera;
	}
