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

//---------------------------------Métodos--------------------------------------

	//Rotaciones Arbol AVL

		//Rotación Simple Derecha

	void PlantillaRotacionDerechaArbolAVLA(ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo);

		//Rotación Simple Izquierda

	void PlantillaRotacionIzquierdaArbolAVLA(ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo);

		//Verificar Casos Rotacioens Sub Arbol Izquierdo

	void SubArbolIzquierdoMayor(ArbolAVLActivos &ArbolAuxiliar);

		//Verificar Casos Rotaciones Sub Arbol Derecho

	void SubArbolDerechoMayor(ArbolAVLActivos &ArbolAuxiliar);

		//Comparación Y Selección De Rotaciones

	void ComparacionYEleccionRotacionArbolAVLA(ArbolAVLEstructura &ArbolAVLActivosActual);

	//Calculo De Alturas

		//Calcular Y Devolver Altura

	int CalcularAlturaArbolAVLA(ArbolAVLEstructura& ActivoParaCalcular);

    //Generación De Reportes

		//Generar Cadena Reporte Recursivo

	void GenerarReporteRecursivoArbolAVLA(string Padre, ArbolAVLEstructura& ArbolActivosActual);

		//Generar Imagen Reporte

	void ReporteActivosUsuarioArbolAVLA();

//------------------------------------------------------------------------------
	#endif
