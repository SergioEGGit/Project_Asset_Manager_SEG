//------------------------------------------------------------------------------

	#ifndef ArbolAVLH
	#define ArbolAVLH

//-----------------------------Librerias----------------------------------------

	#include <iostream>
	#include <string>
	#include <cstring>

	using namespace std;

//-----------------------------Estructura---------------------------------------

	struct ArbolAVLEstructura
	{
		bool ExisteRenta;
		int Identificador;
		int AlturaNodo;
		string CodigoAlfaNumerico;
		string NombreActivo;
		string DescripcionActivo;
		ArbolAVLEstructura *RI;
		ArbolAVLEstructura *LE;
	};

	typedef struct ArbolAVLEstructura *ArbolAVLActivos;

//--------------------------------M�todos---------------------------------------



//---------------------------------------------------------------------------
	#endif