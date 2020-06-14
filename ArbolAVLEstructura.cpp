//------------------------------------------------------------------------------

	#pragma hdrstop

//-----------------------------Librerias----------------------------------------

	#include "ArbolAVLEstructura.h"
	#include "Metodos.h"
	#include "Variables.h"
	#include "Interfaz.h"
	#include <iostream>
	#include <fstream>
	#include <string>
	#include <cstring>

	using namespace std;

//---------------------------------Variables------------------------------------

	//Bandera Necesito Aumentar?
	bool TengoQueAumentar = false;

	//Bandera Esta Equilibrado?
	bool EstaEquilibrado = false;

	//Cadena Generar Reporte
	string Cadena = "";

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos--------------------------------------

	//Rotaciones Arbol AVL

		//Rotaci�n Simple Derecha

	void PlantillaRotacionDerechaArbolAVLA(ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo)
	{
		//Declaraciones
		ArbolAVLActivos AuxiliarPrimero = &Primero;
		ArbolAVLActivos AuxiliarUltimo = &Ultimo;
		string CodigoANumericoActivoPrimero = AuxiliarPrimero -> CodigoANumericoActivo;
		string CodigoANumericoActivoUltimo = AuxiliarUltimo -> CodigoANumericoActivo;
		string NombreActivoPrimero = AuxiliarPrimero -> NombreActivo;
		string NombreActivoUltimo = AuxiliarUltimo -> NombreActivo;
		string DescripcionActivoPrimero = AuxiliarPrimero -> DescripcionActivo;
		string DescripcionActivoUltimo = AuxiliarUltimo -> DescripcionActivo;
		string ExisteRentaActivoPrimero = AuxiliarPrimero -> ExisteRentaActivo;
		string ExisteRentaActivoUltimo = AuxiliarUltimo -> ExisteRentaActivo;

		//Comienza Rotacion Derecha

		AuxiliarPrimero -> CodigoANumericoActivo = CodigoANumericoActivoUltimo;
		AuxiliarPrimero -> NombreActivo = NombreActivoUltimo;
		AuxiliarPrimero -> DescripcionActivo = DescripcionActivoUltimo;
		AuxiliarPrimero -> ExisteRentaActivo = ExisteRentaActivoUltimo;

		AuxiliarUltimo -> CodigoANumericoActivo = CodigoANumericoActivoPrimero;
		AuxiliarUltimo -> NombreActivo = NombreActivoPrimero;
		AuxiliarUltimo -> DescripcionActivo = DescripcionActivoUltimo;
		AuxiliarUltimo -> ExisteRentaActivo = ExisteRentaActivoPrimero;

		AuxiliarPrimero -> LE = AuxiliarUltimo -> LE;
		AuxiliarUltimo -> LE = AuxiliarUltimo -> RI;
		AuxiliarUltimo -> RI = AuxiliarPrimero -> RI;
		AuxiliarPrimero -> RI = AuxiliarUltimo;

		TengoQueAumentar = false;
	}

		//Rotaci�n Simple Izquierda

	void PlantillaRotacionIzquierdaArbolAVLA(ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo)
	{
		//Declaraciones
		ArbolAVLActivos AuxiliarPrimero = &Primero;
		ArbolAVLActivos AuxiliarUltimo = &Ultimo;
		string CodigoANumericoActivoPrimero = AuxiliarPrimero -> CodigoANumericoActivo;
		string CodigoANumericoActivoUltimo = AuxiliarUltimo -> CodigoANumericoActivo;
		string NombreActivoPrimero = AuxiliarPrimero -> NombreActivo;
		string NombreActivoUltimo = AuxiliarUltimo -> NombreActivo;
		string DescripcionActivoPrimero = AuxiliarPrimero -> DescripcionActivo;
		string DescripcionActivoUltimo = AuxiliarUltimo -> DescripcionActivo;
		string ExisteRentaActivoPrimero = AuxiliarPrimero -> ExisteRentaActivo;
		string ExisteRentaActivoUltimo = AuxiliarUltimo -> ExisteRentaActivo;

		//Comienza Rotacion Izquierda

		AuxiliarPrimero -> CodigoANumericoActivo = CodigoANumericoActivoUltimo;
		AuxiliarPrimero -> NombreActivo = NombreActivoUltimo;
		AuxiliarPrimero -> DescripcionActivo = DescripcionActivoUltimo;
		AuxiliarPrimero -> ExisteRentaActivo = ExisteRentaActivoUltimo;
		AuxiliarPrimero -> RI = AuxiliarUltimo -> RI;

		AuxiliarUltimo -> CodigoANumericoActivo = CodigoANumericoActivoPrimero;
		AuxiliarUltimo -> NombreActivo = NombreActivoPrimero;
		AuxiliarUltimo -> DescripcionActivo = DescripcionActivoPrimero;
		AuxiliarUltimo -> ExisteRentaActivo = ExisteRentaActivoPrimero;
		AuxiliarUltimo -> RI = AuxiliarUltimo -> LE;
		AuxiliarUltimo -> LE = AuxiliarPrimero -> LE;

		AuxiliarPrimero -> LE = NULL;
		AuxiliarPrimero -> LE = AuxiliarUltimo;

		TengoQueAumentar = false;
	}

		//Verificar Casos Rotacioens Sub Arbol Izquierdo

	void SubArbolIzquierdoMayor(ArbolAVLActivos &ArbolAuxiliar)
	{
		//Inicio Comparacion Y Elecci�n

		if(ArbolAuxiliar -> RI != NULL && ArbolAuxiliar -> LE != NULL)
		{
			if(abs(ArbolAuxiliar -> RI -> AlturaArbolAVL) > abs(ArbolAuxiliar -> LE -> AlturaArbolAVL))
			{
				//Primer Caso: If -> Rotacion Simple Derecha else -> Rotacion Doble Izquierda

				if(ArbolAuxiliar -> RI -> AlturaArbolAVL == -1)
				{
					PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> RI);
				}
				else if (ArbolAuxiliar -> RI -> AlturaArbolAVL == 1)
				{
					PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar -> RI, *ArbolAuxiliar -> RI -> RI);
					PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> RI);
				}
			}
			else
			{
				//Segundo Caso: If -> Rotacion Simple Derecha else -> Rotacion Doble Izquierda

				if(ArbolAuxiliar -> LE -> AlturaArbolAVL == -1)
				{
					PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> LE);
				}
				else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 1)
				{
					PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar -> LE, *ArbolAuxiliar -> LE -> RI);
					PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> LE);
				}
			}
		}
		else if(ArbolAuxiliar -> RI != NULL && ArbolAuxiliar -> LE == NULL)
		{
			//Tercer Caso: If -> Rotacion Simple Derecha else if -> Rotacion Doble Izquierda else if -> Rotacion Simple Derecha

			if(ArbolAuxiliar -> RI -> AlturaArbolAVL == -1)
			{
				PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
			else if(ArbolAuxiliar -> RI -> AlturaArbolAVL == 1)
			{
				PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar -> RI, *ArbolAuxiliar -> RI -> RI);
				PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
			else if(ArbolAuxiliar -> RI -> AlturaArbolAVL == 0)
			{
				PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
		}
		else if(ArbolAuxiliar -> RI == NULL && ArbolAuxiliar -> LE != NULL)
		{
			//Cuarto Caso: if Rotacion Simple Derecha else if Rotacion Doble Izquierda else if Rotacion Simple Derecha
			if(ArbolAuxiliar -> LE -> AlturaArbolAVL == -1)
			{
				PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
			else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 1)
			{
				PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar -> LE, *ArbolAuxiliar -> LE -> RI);
				PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
			else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 0)
			{
				PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
		}
	}

		//Verificar Casos Rotaciones Sub Arbol Derecho

	void SubArbolDerechoMayor(ArbolAVLActivos &ArbolAuxiliar)
	{
		//Inicio Comparacion Y Elecci�n

		if(ArbolAuxiliar -> RI != NULL && ArbolAuxiliar -> LE != NULL)
		{
			if(abs(ArbolAuxiliar -> RI -> AlturaArbolAVL) > abs(ArbolAuxiliar -> LE -> AlturaArbolAVL))
			{
				//Primer Caso: if -> Rotacion Doble Derecha else if -> Rotacion Simple Izquierda

				if(ArbolAuxiliar -> RI -> AlturaArbolAVL == -1)
				{
					PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar -> RI, *ArbolAuxiliar -> RI -> LE);
					PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> RI);
				}
				else if(ArbolAuxiliar -> RI -> AlturaArbolAVL == 1)
				{
					PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar,*ArbolAuxiliar -> RI);
				}
			}
			else
			{
				if(ArbolAuxiliar -> LE -> AlturaArbolAVL == -1)
				{
					PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar -> LE, *ArbolAuxiliar -> LE -> LE);
					PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> LE);
				}
				else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 1)
				{
					PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> LE);
				}
				else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 0)
				{
					PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> LE);
				}
			}
		}
		else if(ArbolAuxiliar -> RI != NULL && ArbolAuxiliar -> LE == NULL)
		{
			//Segundo Caso: if -> Rotacion Doble Derecha else if -> Rotacion Simple Izquirda else if -> Rotacion Simple Izquierda

			if(ArbolAuxiliar -> RI -> AlturaArbolAVL == -1)
			{
				PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar -> RI, *ArbolAuxiliar -> RI -> LE);
				PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
			else if(ArbolAuxiliar -> RI -> AlturaArbolAVL == 1)
			{
				PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
			else if(ArbolAuxiliar -> RI -> AlturaArbolAVL == 0)
			{
				PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
		}
		else if(ArbolAuxiliar -> RI == NULL && ArbolAuxiliar -> LE != NULL)
		{
			//Tercer Caso: if -> Rotacion Doble Derecha else if -> Rotacion Simple Izquierda else if -> Rotacion Simple Izquierda

			if(ArbolAuxiliar -> LE -> AlturaArbolAVL == -1)
			{
				PlantillaRotacionDerechaArbolAVLA(*ArbolAuxiliar -> LE, *ArbolAuxiliar -> LE -> LE);
				PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
			else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 1)
			{
				PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
			else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 0)
			{
				PlantillaRotacionIzquierdaArbolAVLA(*ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
		}
	}

		//Comparaci�n Y Selecci�n De Rotaciones

	void ComparacionYEleccionRotacionArbolAVLA(ArbolAVLEstructura &ArbolAVLActivosActual)
	{
		//Declaraciones
		ArbolAVLActivos ArbolAuxiliar = &ArbolAVLActivosActual;

		//Empieza Comaparaci�n Y Elecci�n

		if(ArbolAuxiliar -> AlturaArbolAVL == -2)
		{
			SubArbolIzquierdoMayor(ArbolAuxiliar);
		}
		else if(ArbolAuxiliar -> AlturaArbolAVL == 2)
		{
			SubArbolDerechoMayor(ArbolAuxiliar);
		}
    }

	//Calculo De Alturas

		//Calcular Y Devolver Altura

	int CalcularAlturaArbolAVLA(ArbolAVLEstructura& ActivoParaCalcular)
	{
		//Declaraciones
		ArbolAVLActivos AuxiliarArbol = &ActivoParaCalcular;

		//Calculo De Alturas

		if(AuxiliarArbol -> RI == NULL && AuxiliarArbol -> LE == NULL)
		{
			return 0;
		}
		else
		{
			if(AuxiliarArbol -> RI != NULL)
			{
				AuxiliarArbol -> RI -> AlturaArbolAVL = 0;
				int AlturaParcial = CalcularAlturaArbolAVLA(*AuxiliarArbol -> RI) + 1;
				AuxiliarArbol -> AlturaArbolAVL += AlturaParcial;

				if(AuxiliarArbol -> LE != NULL)
				{
					AuxiliarArbol -> LE -> AlturaArbolAVL = 0;
					int AlturaParcial2 = CalcularAlturaArbolAVLA(*AuxiliarArbol -> LE) + 1;
					AuxiliarArbol -> AlturaArbolAVL -= AlturaParcial2;
				}

				if((AuxiliarArbol -> AlturaArbolAVL == -2 || AuxiliarArbol -> AlturaArbolAVL == 2)&& EstaEquilibrado == true)
				{
					ComparacionYEleccionRotacionArbolAVLA(*AuxiliarArbol);
					EstaEquilibrado = false;
				}
				return AlturaParcial;
			}
			if(AuxiliarArbol -> LE != NULL)
			{
				AuxiliarArbol -> LE -> AlturaArbolAVL = 0;
				int AlturaParcial3 = CalcularAlturaArbolAVLA(*AuxiliarArbol -> LE) + 1;
				AuxiliarArbol -> AlturaArbolAVL -= AlturaParcial3;

				if(AuxiliarArbol -> RI != NULL)
				{
					AuxiliarArbol -> RI -> AlturaArbolAVL = 0;
					int AlturaParcial4 = CalcularAlturaArbolAVLA(*AuxiliarArbol -> RI) + 1;
					AuxiliarArbol -> AlturaArbolAVL += AlturaParcial4;
				}
				if((AuxiliarArbol -> AlturaArbolAVL == -2 || AuxiliarArbol -> AlturaArbolAVL == 2) && EstaEquilibrado == true)
				{
					ComparacionYEleccionRotacionArbolAVLA(*AuxiliarArbol);
					EstaEquilibrado = false;
				}
				return AlturaParcial3;
			}
		}
	}

		//Verificar Y Devolver Casos Altura

	void ArbolAVLEstructura::CalcularAlturaVoidArbolAVLA(ArbolAVLEstructura& ActivoParaCalcular)
	{
		//Declaracion
		ArbolAVLActivos AuxiliarAltura = &ActivoParaCalcular;
		AuxiliarAltura -> AlturaArbolAVL = 0;

		//Calculo De Alturas

		if(AuxiliarAltura -> LE == NULL && AuxiliarAltura -> RI == NULL)
		{
			AuxiliarAltura -> AlturaArbolAVL = 0;
		}
		else
		{
			if(AuxiliarAltura -> LE != NULL)
			{
				AuxiliarAltura -> LE -> AlturaArbolAVL = 0;
				int AlturaParcial = CalcularAlturaArbolAVLA(*AuxiliarAltura -> LE) + 1;
				AuxiliarAltura -> AlturaArbolAVL -= AlturaParcial;
			}

			if(AuxiliarAltura -> RI != NULL)
			{
				AuxiliarAltura -> RI -> AlturaArbolAVL = 0;
				int AlturaParcial2 = CalcularAlturaArbolAVLA(*AuxiliarAltura -> RI) + 1;
				AuxiliarAltura -> AlturaArbolAVL += AlturaParcial2;
			}

			if((AuxiliarAltura -> AlturaArbolAVL == -2 || AuxiliarAltura -> AlturaArbolAVL == 2) && EstaEquilibrado == true)
			{
				ComparacionYEleccionRotacionArbolAVLA(*AuxiliarAltura);
				EstaEquilibrado = false;
			}
		}
	}

	//Inserci�n

		//M�todo Insertar

	bool ArbolAVLEstructura::InsertarActivoArbolAVLA(string CodigoANumerico, string NombreActivo, string DescripcionActivo, ArbolAVLEstructura& ActivoInsertar)
	{
		//Declaraciones
		ArbolAVLActivos ArbolAuxiliar = &ActivoInsertar;
		ArbolAVLActivos ActivoNuevo = nullptr;
		bool Bandera = false;

		//Comienzo Inserci�n

		if(NombreActivo.compare(ArbolAuxiliar -> NombreActivo) > 0)
		{
			if(ArbolAuxiliar -> RI != NULL)
			{
				Bandera = InsertarActivoArbolAVLA(CodigoANumerico, NombreActivo, DescripcionActivo, *ArbolAuxiliar -> RI);

				if(TengoQueAumentar)
				{
					ArbolAuxiliar -> AlturaArbolAVL++;
				}

				ComparacionYEleccionRotacionArbolAVLA(*ArbolAuxiliar);
				return Bandera;
			}
			else
			{
				ActivoNuevo = new ArbolAVLEstructura(CodigoANumerico, NombreActivo, DescripcionActivo);
				ArbolAuxiliar -> RI = ActivoNuevo;
				ArbolAuxiliar -> AlturaArbolAVL++;

				if(ArbolAuxiliar -> LE == NULL)
				{
					TengoQueAumentar = true;
				}
				return true;
			}
		}
		else if(NombreActivo.compare(ArbolAuxiliar -> NombreActivo) < 0)
		{
			if(ArbolAuxiliar -> LE != NULL)
			{
				Bandera = InsertarActivoArbolAVLA(CodigoANumerico, NombreActivo, DescripcionActivo, *ArbolAuxiliar -> LE);

				if(TengoQueAumentar == true)
				{
					ArbolAuxiliar -> AlturaArbolAVL--;
				}

				ComparacionYEleccionRotacionArbolAVLA(*ArbolAuxiliar);
				return Bandera;
			}
			else
			{
				ActivoNuevo = new ArbolAVLEstructura(CodigoANumerico, NombreActivo, DescripcionActivo);
				ArbolAuxiliar -> LE = ActivoNuevo;
				ArbolAuxiliar -> AlturaArbolAVL--;

				if(ArbolAuxiliar -> RI == NULL)
				{
					TengoQueAumentar = true;
				}
				return true;
			}
		}
		else
		{
			return false;
		}
	}

		//Generar Nodo Y Llamar A Insertar

	bool ArbolAVLEstructura::InsertarActvioArbolAVLANuevoActivo(string CodigoANumerico, string NombreActivo, string DescripcionActivo)
	{
		TengoQueAumentar = false;

		if(Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario == NULL)
		{
			Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario = new ArbolAVLEstructura(CodigoANumerico, NombreActivo, DescripcionActivo);
			return true;
		}
		else
		{
			return InsertarActivoArbolAVLA(CodigoANumerico, NombreActivo, DescripcionActivo, *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario);
		}


	}

	//Eliminaci�n





	//Generaci�n De Reportes

		//Generar Cadena Reporte Recursivo

	void GenerarReporteRecursivoArbolAVLA(string Padre, ArbolAVLEstructura& ArbolActivosActual)
	{
		//Declaraciones
		ArbolAVLActivos ArbolAuxiliar = &ArbolActivosActual;
		string PadreAuxiliar;

		//Comienzo A Generar Reporte

		//SubArbol Izquierdo

		if(ArbolAuxiliar -> LE != NULL)
		{
			Cadena += "NodoArbol" + to_string(Variables::NumerosDeNodosArbolAVL);

			Cadena += "[label = \" C�digo: " + ArbolAuxiliar -> LE -> CodigoANumericoActivo +
							 + "\\lNombre: " + ArbolAuxiliar -> LE -> NombreActivo +
							 + "\\lRentado: " + ArbolAuxiliar -> LE -> ExisteRentaActivo +
					   + "\\lDescripci�n: " + Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario -> DescripcionActivo +
					   + "\\l_" + + "\"]; \n";


			Cadena += Padre + "->" + "NodoArbol" + to_string(Variables::NumerosDeNodosArbolAVL) + ";\n";
			PadreAuxiliar  = "NodoArbol" + to_string(Variables::NumerosDeNodosArbolAVL);
			Variables::NumerosDeNodosArbolAVL++;
			GenerarReporteRecursivoArbolAVLA(PadreAuxiliar, *ArbolAuxiliar -> LE);
		}

		//SubArbol Derecho

		if(ArbolAuxiliar -> RI != NULL)
		{
			Cadena += "NodoArbol" + to_string(Variables::NumerosDeNodosArbolAVL);

			Cadena += "[label = \" C�digo: " + ArbolAuxiliar -> RI -> CodigoANumericoActivo +
							 + "\\lNombre: " + ArbolAuxiliar -> RI -> NombreActivo +
							 + "\\lRentado: " + ArbolAuxiliar -> RI -> ExisteRentaActivo +
					   + "\\lDescripci�n: " + Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario -> DescripcionActivo +
					   + "\\l_" + + "\"]; \n";

			Cadena += Padre + "->" + "NodoArbol" + to_string(Variables::NumerosDeNodosArbolAVL) + ";\n";
			PadreAuxiliar = "NodoArbol" + to_string(Variables::NumerosDeNodosArbolAVL);
			Variables::NumerosDeNodosArbolAVL++;
			GenerarReporteRecursivoArbolAVLA(PadreAuxiliar, *ArbolAuxiliar -> RI);
		}
	}

		//Generar Imagen Reporte

	void ReporteActivosUsuarioArbolAVLA()
	{
		//Declaraciones
		ofstream SalidaArchivo("C:\\ReportesEDD\\ReporteArbolAVLActivosUsuarios.txt");
		int ContadorNodosArbol = 0;

		Variables::NumerosDeNodosArbolAVL = 0;
		Cadena = "";
		string CadenaAux = "";

		//Comienzo Generar Reporte

		if(SalidaArchivo.is_open())
		{
			if(Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario != nullptr)
			{
				SalidaArchivo<< "digraph ArbolAVLActivosUsuarios" <<endl;
				SalidaArchivo<< "{" <<endl;
				SalidaArchivo<< "graph [ charset=latin1 ]" <<endl;
				SalidaArchivo<< "node [shape = record, style = rounded, color = springgreen1, fontcolor = indigo];" <<endl;

				Cadena += "NodoArbol" + to_string(ContadorNodosArbol);
				CadenaAux = "NodoArbol" + to_string(ContadorNodosArbol);

				Cadena += "[label = \"C�digo: " + Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario -> CodigoANumericoActivo +
								+ "\\lNombre: " + Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario -> NombreActivo +
								+ "\\lRentado: " + Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario -> ExisteRentaActivo +
							   + "\\lDescripci�n: " + Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario -> DescripcionActivo +
							   + "\\l_" + "\"]; \n";

				Variables::NumerosDeNodosArbolAVL++;

				GenerarReporteRecursivoArbolAVLA(CadenaAux , *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario);

				SalidaArchivo<< Cadena <<endl;
				SalidaArchivo<< "}" <<endl;
				SalidaArchivo.close();

                //Generar Archivo Dot Para Graficar
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\ReportesEDD\\ReporteArbolAVLActivosUsuarios.txt -o C:\\ReportesEDD\\ReporteArbolAVLActivosUsuarios.png");
				//Abrir Imagen Con El Vizualizador de Imagenes
				system("C:\\ReportesEDD\\ReporteArbolAVLActivosUsuarios.png &" );
			}
			else
			{
				Color(0, 4);
				Posicionar(17, 9);
				cout<< "  El Arbol AVL Se Encuentra Vacio" <<endl;
				system("pause > 0");
            }
		}
	}
