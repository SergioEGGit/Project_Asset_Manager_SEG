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

		bool InsertarActivoArbolAVLA(string CodigoANumerico, string NombreActivo, string DescripcionActivo, ArbolAVLEstructura& ActivoInsertar);

		bool InsertarActvioArbolAVLANuevoActivo(string CodigoANumerico, string NombreActivo, string DescripcionActivo);

		void CalcularAlturaVoidArbolAVLA(ArbolAVLEstructura& ActivoParaCalcular);
	};

	typedef struct ArbolAVLEstructura *ArbolAVLActivos;

//---------------------------------M�todos--------------------------------------

	//Rotaciones Arbol AVL

		//Rotaci�n Simple Derecha

	void PlantillaRotacionDerechaArbolAVLA(ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo);

		//Rotaci�n Simple Izquierda

	void PlantillaRotacionIzquierdaArbolAVLA(ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo);

		//Verificar Casos Rotacioens Sub Arbol Izquierdo

	void SubArbolIzquierdoMayor(ArbolAVLActivos &ArbolAuxiliar);

		//Verificar Casos Rotaciones Sub Arbol Derecho

	void SubArbolDerechoMayor(ArbolAVLActivos &ArbolAuxiliar);

		//Comparaci�n Y Selecci�n De Rotaciones

	void ComparacionYEleccionRotacionArbolAVLA(ArbolAVLEstructura &ArbolAVLActivosActual);

	//Calculo De Alturas

		//Calcular Y Devolver Altura

	int CalcularAlturaArbolAVLA(ArbolAVLEstructura& ActivoParaCalcular);

    //Generaci�n De Reportes

		//Generar Cadena Reporte Recursivo

	void GenerarReporteRecursivoArbolAVLA(string Padre, ArbolAVLEstructura& ArbolActivosActual);

		//Generar Imagen Reporte

	void ReporteActivosUsuarioArbolAVLA();

//------------------------------------------------------------------------------
	#endif
