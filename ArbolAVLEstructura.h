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
		//Declaraciones
			//Declaracion Variables Tipo Int
		int AlturaArbolAVL;
			//Declaracion Variables Tipo String
		string ExisteRentaActivo;
		string CodigoANumericoActivo;
		string NombreActivo;
		string DescripcionActivo;
			//Declaracion Apuntadores Tipo Struct
		struct ArbolAVLEstructura *RI;
		struct ArbolAVLEstructura *LE;

		//Constructor

		ArbolAVLEstructura(string CodigoANumericoActivo, string NombreActivo, string DescripcionActivo)
		{
			//Asignaicones
				//Asignaciones Variables Tipo Int
			this -> AlturaArbolAVL = 0;
				//Asignaciones Variables Tipo String
			this -> CodigoANumericoActivo = CodigoANumericoActivo;
			this -> NombreActivo = NombreActivo;
			this -> DescripcionActivo = DescripcionActivo;
			this -> ExisteRentaActivo = "No";
				//Asignaciones Apuntadores Tipo Struct
			this -> RI = nullptr;
			this -> LE = nullptr;
		}

		typedef struct ArbolAVLEstructura *ArbolAVLActivos2;

		//M�todos

			//Insertar Arbol AVL

		static string InsertarActivoArbolAVLA(ArbolAVLActivos2 &Arbol, string CodigoANumerico, string NombreActivo, string DescripcionActivo, ArbolAVLEstructura& ActivoInsertar);

			//Insertar Nuevo Nodo Arbol AVL

		static string InsertarActvioArbolAVLANuevoActivo(ArbolAVLActivos2 &Arbol, string CodigoANumerico, string NombreActivo, string DescripcionActivo);

			//Calcular Altura Arbol AVL

		static void CalcularAlturaVoidArbolAVLA(ArbolAVLActivos2 &Arbol, ArbolAVLEstructura& ActivoParaCalcular);

		static string EliminarActivoArbolAVLA(ArbolAVLEstructura &ActivoActualArbol, string CodigoANumericoActivo);
	};

	//Definicion Struct Arbol AVL Activos

	typedef struct ArbolAVLEstructura *ArbolAVLActivos;

//---------------------------------M�todos--------------------------------------

    //Generaci�n De Reportes

		//Generar Cadena Reporte Recursivo

	void GenerarReporteRecursivoArbolAVLA(ArbolAVLActivos &Arbol, string Padre, ArbolAVLEstructura& ArbolActivosActual);

		//Generar Imagen Reporte

	void ReporteActivosUsuarioArbolAVLA(ArbolAVLActivos &Arbol);

	//Mostrar Activos

		//Recorrido Pre Orden Arbol AVL

	void MostrarActivosArbolAVLA(ArbolAVLActivos &Arbol);

	//Rotaciones Arbol AVL

		//Rotaci�n Simple Derecha

	void PlantillaRotacionDerechaArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo);

		//Rotaci�n Simple Izquierda

	void PlantillaRotacionIzquierdaArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo);

		//Verificar Casos Rotacioens Sub Arbol Izquierdo

	void SubArbolIzquierdoMayor(ArbolAVLActivos &Arbol, ArbolAVLActivos &ArbolAuxiliar);

		//Verificar Casos Rotaciones Sub Arbol Derecho

	void SubArbolDerechoMayor(ArbolAVLActivos &Arbol, ArbolAVLActivos &ArbolAuxiliar);

		//Comparaci�n Y Selecci�n De Rotaciones

	void ComparacionYEleccionRotacionArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura &ArbolAVLActivosActual);

	//Calculo De Alturas

		//Calcular Y Devolver Altura

	int CalcularAlturaArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura& ActivoParaCalcular);

	//B�squeda

		//Buscar Activo

	ArbolAVLActivos BuscarActivoArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura &ActivoActualAuxiliar, string CodigoANumericoActivo);

	//Eliminaci�n

		//Quien Es El Mayor

	ArbolAVLActivos SoyElMayor(ArbolAVLActivos &Arbol, ArbolAVLEstructura &ActivoActualAuxiliar);

		//Eliminar Nodo Auxiliar

	void EliminarNodoAuxilair(ArbolAVLActivos &Arbol, ArbolAVLEstructura &ActivoActualAuxiliar);

		//Comparaci�n Y Elecci�n Casos De Eliminaci�n

	string ComparacionYEleccionArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura &ActivoActualArbol);


//------------------------------------------------------------------------------
	#endif
