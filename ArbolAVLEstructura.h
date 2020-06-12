//------------------------------------------------------------------------------

	#ifndef ArbolAVLEstructuraH
	#define ArbolAVLEstructuraH

//-----------------------------Librerias----------------------------------------

	#include <iostream>
	#include <string>
	#include <cstring>

	using namespace std;

//-----------------------------Estructura---------------------------------------

	struct ArbolAVLEstructura
	{
		//Objetos
		int AlturaArbolAVL;
		string ExisteRentaActivo;
		string CodigoANumericoActivo;
		string NombreActivo;
		string DescripcionActivo;
		//Apuntadores
		struct ArbolAVLEstructura *RI;
		struct ArbolAVLEstructura *LE;

		//Constructor

		ArbolAVLEstructura(string CodigoANumericoActivo, string NombreActivo, string DescripcionActivo)
		{
			//Objetos
			this -> ExisteRentaActivo = "No";
			this -> AlturaArbolAVL = 0;
			this -> CodigoANumericoActivo = CodigoANumericoActivo;
			this -> NombreActivo = NombreActivo;
			this -> DescripcionActivo = DescripcionActivo;
			//Apuntadores
			this -> RI = nullptr;
			this -> LE = nullptr;
		}
	};

	typedef struct ArbolAVLEstructura *ArbolAVLActivos;

//--------------------------------M�todos---------------------------------------

	//Rotaciones Arbol AVL

	void PlantillaRotacionDerechaArbolAVLA(ArbolAVLEstructura &Primero, ArbolAVLEstructura &Segundo);

	void PlantillaRotacionIzquierdaArbolAVLA(ArbolAVLEstructura &Primero, ArbolAVLEstructura &Segundo);

	void SubArbolIzquierdoMayor(ArbolAVLActivos &ArbolAuxiliar);

	void SubArbolDerechoMayor(ArbolAVLActivos &ArbolAuxiliar);

	void ComparacionYEleccionRotacionArbolAVLA(ArbolAVLEstructura &ArbolAVLActivosActual);

	int CalcularAlturaArbolAVLA(ArbolAVLEstructura& ActivoParaCalcular);

    void CalcularAlturaVoidArbolAVLA(ArbolAVLEstructura& ActivoParaCalcular);

//---------------------------------------------------------------------------
	#endif