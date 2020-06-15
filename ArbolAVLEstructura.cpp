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
	string TengoQueAumentar = "No";

	//Bandera Esta Equilibrado?
	string EstaEquilibrado = "No";

	//Cadena Generar Reporte
	string Cadena = "";

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos--------------------------------------

    //Generaci�n De Reportes

		//Generar Cadena Reporte Recursivo

	void GenerarReporteRecursivoArbolAVLA(ArbolAVLActivos &Arbol, string Padre, ArbolAVLEstructura& ArbolActivosActual)
	{
		//Declaraciones

		//Objetos Tipo Arbol AVL

		ArbolAVLActivos ArbolAuxiliar = &ArbolActivosActual;

		//Variables Tipo String

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
			GenerarReporteRecursivoArbolAVLA(Variables::ArbolAVLAuxiliar, PadreAuxiliar, *ArbolAuxiliar -> LE);
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
			GenerarReporteRecursivoArbolAVLA(Variables::ArbolAVLAuxiliar, PadreAuxiliar, *ArbolAuxiliar -> RI);
		}
	}

		//Generar Imagen Reporte

	void ReporteActivosUsuarioArbolAVLA(ArbolAVLActivos &Arbol)
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

				GenerarReporteRecursivoArbolAVLA(Arbol, CadenaAux , *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario);

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

	//Mostrar Activos

		//Recorrido Pre Orden Arbol AVL

	void MostrarActivosArbolAVLA(ArbolAVLActivos &Arbol)
	{
		if(Arbol == nullptr)
		{
			return;
		}
		else
		{
			if(Arbol -> RI == nullptr && Arbol -> LE == nullptr)
			{
				Color(0, 9);
				Posicionar(17, Variables::ContadorActivos);
				cout<< "            " << Variables::ContadorAux << "." << Arbol -> CodigoANumericoActivo << ", " << Arbol -> NombreActivo <<endl;
				Variables::ContadorActivos = Variables::ContadorActivos - 2;
				Variables::ContadorAux++;
			}
			else
			{
				Color(0, 9);
				Posicionar(17, Variables::ContadorActivos);
				cout<< "            " << Variables::ContadorAux << "." << Arbol -> CodigoANumericoActivo << ", " << Arbol -> NombreActivo <<endl;
				Variables::ContadorActivos = Variables::ContadorActivos - 2;
				Variables::ContadorAux++;
				MostrarActivosArbolAVLA(Arbol -> LE);
				MostrarActivosArbolAVLA(Arbol -> RI);
			}
		}
	}

	//Rotaciones Arbol AVL

		//Rotaci�n Simple Derecha

	void PlantillaRotacionDerechaArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo)
	{
		//Declaraciones

		//Variables Tipo Arbol AVL
		ArbolAVLActivos AuxiliarPrimero = &Primero;
		ArbolAVLActivos AuxiliarUltimo = &Ultimo;

		//Variables Tipo String

			//Codigo Alfa N�merico Activo

		string CodigoANumericoActivoPrimero = AuxiliarPrimero -> CodigoANumericoActivo;
		string CodigoANumericoActivoUltimo = AuxiliarUltimo -> CodigoANumericoActivo;

			//Nombre Activo

		string NombreActivoPrimero = AuxiliarPrimero -> NombreActivo;
		string NombreActivoUltimo = AuxiliarUltimo -> NombreActivo;

			//Descripci�n Activo

		string DescripcionActivoPrimero = AuxiliarPrimero -> DescripcionActivo;
		string DescripcionActivoUltimo = AuxiliarUltimo -> DescripcionActivo;

			//Existe Renta Activo

		string ExisteRentaActivoPrimero = AuxiliarPrimero -> ExisteRentaActivo;
		string ExisteRentaActivoUltimo = AuxiliarUltimo -> ExisteRentaActivo;

			//Tengo Que Aumentar

		TengoQueAumentar = "No";

		//Comienza Rotacion Derecha

			//Asignaci�n De Ultimo A Primero

		AuxiliarPrimero -> CodigoANumericoActivo = CodigoANumericoActivoUltimo;
		AuxiliarPrimero -> NombreActivo = NombreActivoUltimo;
		AuxiliarPrimero -> DescripcionActivo = DescripcionActivoUltimo;
		AuxiliarPrimero -> ExisteRentaActivo = ExisteRentaActivoUltimo;

			//Asignaci�n De Primero A Ultimo

		AuxiliarUltimo -> CodigoANumericoActivo = CodigoANumericoActivoPrimero;
		AuxiliarUltimo -> NombreActivo = NombreActivoPrimero;
		AuxiliarUltimo -> DescripcionActivo = DescripcionActivoPrimero;
		AuxiliarUltimo -> ExisteRentaActivo = ExisteRentaActivoPrimero;

			//Comienza Rotaci�n

		AuxiliarPrimero -> LE = AuxiliarUltimo -> LE;
		AuxiliarUltimo -> LE = AuxiliarUltimo -> RI;
		AuxiliarUltimo -> RI = AuxiliarPrimero -> RI;
		AuxiliarPrimero -> RI = AuxiliarUltimo;
	}

		//Rotaci�n Simple Izquierda

	void PlantillaRotacionIzquierdaArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo)
	{
		//Declaraciones

		//Variables Tipo Arbol AVL

		ArbolAVLActivos AuxiliarPrimero = &Primero;
		ArbolAVLActivos AuxiliarUltimo = &Ultimo;

		//Variables Tipo String

			//Codigo Alfa N�merico Activo

		string CodigoANumericoActivoPrimero = AuxiliarPrimero -> CodigoANumericoActivo;
		string CodigoANumericoActivoUltimo = AuxiliarUltimo -> CodigoANumericoActivo;

			//Nombre Activo

		string NombreActivoPrimero = AuxiliarPrimero -> NombreActivo;
		string NombreActivoUltimo = AuxiliarUltimo -> NombreActivo;

			//Descripci�n Activo

		string DescripcionActivoPrimero = AuxiliarPrimero -> DescripcionActivo;
		string DescripcionActivoUltimo = AuxiliarUltimo -> DescripcionActivo;

			//Existe Renta Activo

		string ExisteRentaActivoPrimero = AuxiliarPrimero -> ExisteRentaActivo;
		string ExisteRentaActivoUltimo = AuxiliarUltimo -> ExisteRentaActivo;

			//Tengo Que Aumentar

		TengoQueAumentar = "No";

		//Comienza Rotacion Izquierda

			//Asignaci�n De Ultimo A Primero

		AuxiliarPrimero -> CodigoANumericoActivo = CodigoANumericoActivoUltimo;
		AuxiliarPrimero -> NombreActivo = NombreActivoUltimo;
		AuxiliarPrimero -> DescripcionActivo = DescripcionActivoUltimo;
		AuxiliarPrimero -> ExisteRentaActivo = ExisteRentaActivoUltimo;
		AuxiliarPrimero -> RI = AuxiliarUltimo -> RI;

			//Asignaci�n De Primero A Ultimo

		AuxiliarUltimo -> CodigoANumericoActivo = CodigoANumericoActivoPrimero;
		AuxiliarUltimo -> NombreActivo = NombreActivoPrimero;
		AuxiliarUltimo -> DescripcionActivo = DescripcionActivoPrimero;
		AuxiliarUltimo -> ExisteRentaActivo = ExisteRentaActivoPrimero;
		AuxiliarUltimo -> RI = AuxiliarUltimo -> LE;
		AuxiliarUltimo -> LE = AuxiliarPrimero -> LE;

			//ComienzaRotaci�n

		AuxiliarPrimero -> LE = NULL;
		AuxiliarPrimero -> LE = AuxiliarUltimo;
	}

		//Verificar Casos Rotacioens Sub Arbol Izquierdo

	void SubArbolIzquierdoMayor(ArbolAVLActivos &Arbol, ArbolAVLActivos &ArbolAuxiliar)
	{
		//Inicio Comparacion Y Elecci�n

		if(ArbolAuxiliar -> RI != NULL && ArbolAuxiliar -> LE == NULL)
		{
			//Tercer Caso

			if(ArbolAuxiliar -> RI -> AlturaArbolAVL == 1)
			{
				//Rotaci�n Doble Izquirda

				PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar -> RI, *ArbolAuxiliar -> RI -> RI);
				PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
			else if(ArbolAuxiliar -> RI -> AlturaArbolAVL == 0)
			{
				//Rotaci�n Simple Derecha

				PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
			else if(ArbolAuxiliar -> RI -> AlturaArbolAVL == -1)
			{
				//Rotaci�n Simple Derecha

				PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
		}
		else if(ArbolAuxiliar -> RI != NULL && ArbolAuxiliar -> LE != NULL)
		{
			if(abs(ArbolAuxiliar -> RI -> AlturaArbolAVL) > abs(ArbolAuxiliar -> LE -> AlturaArbolAVL))
			{
				//Comparaci�n Es Mayor

				//Primer Caso

				if (ArbolAuxiliar -> RI -> AlturaArbolAVL == 1)
				{
					//Rotaci�n Doble Izquierda

					PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar -> RI, *ArbolAuxiliar -> RI -> RI);
					PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> RI);
				}
				else if(ArbolAuxiliar -> RI -> AlturaArbolAVL == -1)
				{
					//Rotaci�n Simple Derecha

					PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> RI);
				}
			}
			else
			{
				//Comparaci�n Es Menor

				//Segundo Caso

				if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 1)
				{
					//Rotaci�n Doble Izquirda

					PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar -> LE, *ArbolAuxiliar -> LE -> RI);
					PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> LE);
				}
				else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == -1)
				{
					//Rotaci�n Simple Derecha

					PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> LE);
				}
			}
		}
        else if(ArbolAuxiliar -> RI == NULL && ArbolAuxiliar -> LE != NULL)
		{
			//Cuarto Caso

			if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 1)
			{
				//Rotaci�n Doble Izquierda

				PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar -> LE, *ArbolAuxiliar -> LE -> RI);
				PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
			else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 0)
			{
				//Rotaci�n Simple Derecha

				PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
			else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == -1)
			{
				//Rotaci�n Simple Derecha

				PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
		}
	}

		//Verificar Casos Rotaciones Sub Arbol Derecho

	void SubArbolDerechoMayor(ArbolAVLActivos &Arbol, ArbolAVLActivos &ArbolAuxiliar)
	{
        //Inicio Comparacion Y Elecci�n

		if(ArbolAuxiliar -> RI != NULL && ArbolAuxiliar -> LE == NULL)
		{
			if(ArbolAuxiliar -> RI -> AlturaArbolAVL == 1)
			{
				//Rotaci�n Simple Izquierda

				PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
			else if(ArbolAuxiliar -> RI -> AlturaArbolAVL == 0)
			{
				//Rotaci�n Simple Izquierda

				PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
			else if(ArbolAuxiliar -> RI -> AlturaArbolAVL == -1)
			{
				//Rotaci�n Doble Derecha

				PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar -> RI, *ArbolAuxiliar -> RI -> LE);
				PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> RI);
			}
		}
		else if(ArbolAuxiliar -> RI != NULL && ArbolAuxiliar -> LE != NULL)
		{
			if(abs(ArbolAuxiliar -> RI -> AlturaArbolAVL) > abs(ArbolAuxiliar -> LE -> AlturaArbolAVL))
			{
				//Comparaci�n Es Mayor

				//Primer Caso

				if(ArbolAuxiliar -> RI -> AlturaArbolAVL == 1)
				{
					//Rotaci�n Simple Izquirda

					PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar,*ArbolAuxiliar -> RI);
				}
				else if(ArbolAuxiliar -> RI -> AlturaArbolAVL == -1)
				{
					//Rotaci�n Doble Derecha

					PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar -> RI, *ArbolAuxiliar -> RI -> LE);
					PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> RI);
				}
			}
			else
			{
				//Comparaci�n Es Menor

				if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 1)
				{
					//Rotaci�n Simple Izquierda

					PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> LE);
				}
				else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 0)
				{
					//Rotaci�n Simple Izquierda

					PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> LE);
				}
				else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == -1)
				{
					//Rotaci�n Dolbe Derecha

					PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar -> LE, *ArbolAuxiliar -> LE -> LE);
					PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> LE);
				}
			}
		}
        else if(ArbolAuxiliar -> RI == NULL && ArbolAuxiliar -> LE != NULL)
		{
			//Tercer Caso: if -> Rotacion Doble Derecha else if -> Rotacion Simple Izquierda else if -> Rotacion Simple Izquierda

			if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 1)
			{
				//Rotaci�n Simple Izquierda

				PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
			else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == 0)
			{
				//Rotaci�n Simple Izquierda

				PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
			else if(ArbolAuxiliar -> LE -> AlturaArbolAVL == -1)
			{
				//Rotaci�n Doble Derecha

				PlantillaRotacionDerechaArbolAVLA(Arbol, *ArbolAuxiliar -> LE, *ArbolAuxiliar -> LE -> LE);
				PlantillaRotacionIzquierdaArbolAVLA(Arbol, *ArbolAuxiliar, *ArbolAuxiliar -> LE);
			}
		}
	}

		//Comparaci�n Y Selecci�n De Rotaciones

	void ComparacionYEleccionRotacionArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura &ArbolAVLActivosActual)
	{
		//Declaraciones

		//Objetos Tipo Arbol AVL

		ArbolAVLActivos ArbolAuxiliar = &ArbolAVLActivosActual;

		//Empieza Comaparaci�n Y Elecci�n

		if(ArbolAuxiliar -> AlturaArbolAVL == 2)
		{
			SubArbolDerechoMayor(Arbol, ArbolAuxiliar);
		}
		else if(ArbolAuxiliar -> AlturaArbolAVL == -2)
		{
			SubArbolIzquierdoMayor(Arbol, ArbolAuxiliar);
		}
	}

	//Calculo De Alturas

		//Calcular Y Devolver Altura

	int CalcularAlturaArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura& ActivoParaCalcular)
	{
		//Declaraciones

		//Objetos Tipo Arbol AVL

		ArbolAVLActivos AuxiliarArbol = &ActivoParaCalcular;

		//Calculo De Alturas

		if(AuxiliarArbol -> RI == NULL && AuxiliarArbol -> LE == NULL)
		{
			//Ambas Lados Estan Vacios

			return 0;
		}
		else
		{
			//Si Existe Izquierda

            if(AuxiliarArbol -> LE != NULL)
			{
				//Asigno Variables

				AuxiliarArbol -> LE -> AlturaArbolAVL = 0;
				int AlturaParcial3 = CalcularAlturaArbolAVLA(Arbol, *AuxiliarArbol -> LE) + 1;
				AuxiliarArbol -> AlturaArbolAVL -= AlturaParcial3;

				//Revisar Derecha Arbol

				if(AuxiliarArbol -> RI != NULL)
				{
					AuxiliarArbol -> RI -> AlturaArbolAVL = 0;
					int AlturaParcial4 = CalcularAlturaArbolAVLA(Arbol, *AuxiliarArbol -> RI) + 1;
					AuxiliarArbol -> AlturaArbolAVL += AlturaParcial4;
				}


                //Comparo Alturas Y Si Esta Equilibrado

				if((AuxiliarArbol -> AlturaArbolAVL == 2 || AuxiliarArbol -> AlturaArbolAVL == -2))
				{
					if(EstaEquilibrado == "Si")
					{
                        ComparacionYEleccionRotacionArbolAVLA(Arbol, *AuxiliarArbol);
						EstaEquilibrado = "No";
					}
				}

				return AlturaParcial3;
			}

			//Si Existe Derecha

			if(AuxiliarArbol -> RI != NULL)
			{
				//Asigno Variables

				AuxiliarArbol -> RI -> AlturaArbolAVL = 0;
				int AlturaParcial = CalcularAlturaArbolAVLA(Arbol, *AuxiliarArbol -> RI) + 1;
				AuxiliarArbol -> AlturaArbolAVL += AlturaParcial;

				if(AuxiliarArbol -> LE != NULL)
				{
					AuxiliarArbol -> LE -> AlturaArbolAVL = 0;
					int AlturaParcial2 = CalcularAlturaArbolAVLA(Arbol, *AuxiliarArbol -> LE) + 1;
					AuxiliarArbol -> AlturaArbolAVL -= AlturaParcial2;
				}

                //Comparo Alturas Y Esta Equilibrado

				if((AuxiliarArbol -> AlturaArbolAVL == -2 || AuxiliarArbol -> AlturaArbolAVL == 2))
				{
					if(EstaEquilibrado == "Si")
					{
                        ComparacionYEleccionRotacionArbolAVLA(Arbol, *AuxiliarArbol);
						EstaEquilibrado = "No";
					}
				}

				return AlturaParcial;
			}
		}
		return 0;
	}

		//Verificar Y Devolver Casos Altura

	void ArbolAVLEstructura::CalcularAlturaVoidArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura& ActivoParaCalcular)
	{
		//Declaracion

		//Objetos Tipo Arbol AVL
		ArbolAVLActivos AuxiliarAltura = &ActivoParaCalcular;

		//Asignaci�n Altura

		AuxiliarAltura -> AlturaArbolAVL = 0;

		//Calculo De Alturas

		if(AuxiliarAltura -> LE == NULL && AuxiliarAltura -> RI == NULL)
		{
			//Ambos Lados Estan Vacios

			AuxiliarAltura -> AlturaArbolAVL = 0;
		}
		else
		{
			//Si Existe Izquierda

			if(AuxiliarAltura -> LE != NULL)
			{
				AuxiliarAltura -> LE -> AlturaArbolAVL = 0;
				int AlturaParcial = CalcularAlturaArbolAVLA(Arbol, *AuxiliarAltura -> LE) + 1;
				AuxiliarAltura -> AlturaArbolAVL -= AlturaParcial;
			}

			//Si Existe Derecha

			if(AuxiliarAltura -> RI != NULL)
			{
				AuxiliarAltura -> RI -> AlturaArbolAVL = 0;
				int AlturaParcial2 = CalcularAlturaArbolAVLA(Arbol, *AuxiliarAltura -> RI) + 1;
				AuxiliarAltura -> AlturaArbolAVL += AlturaParcial2;
			}

			//Compar Alturas

			if((AuxiliarAltura -> AlturaArbolAVL == -2 || AuxiliarAltura -> AlturaArbolAVL == 2))
			{
				if(EstaEquilibrado == "Si")
				{
                    ComparacionYEleccionRotacionArbolAVLA(Arbol, *AuxiliarAltura);
					EstaEquilibrado = "No";
				}
			}
		}
	}

	//Inserci�n

		//M�todo Insertar

	string ArbolAVLEstructura::InsertarActivoArbolAVLA(ArbolAVLActivos &Arbol, string CodigoANumerico, string NombreActivo, string DescripcionActivo, ArbolAVLEstructura& ActivoInsertar)
	{
		//Declaraciones

		//Objetos Tipo Arbol AVL
		ArbolAVLActivos ArbolAuxiliar = &ActivoInsertar;
		ArbolAVLActivos ActivoNuevo = nullptr;

		//Variable Tipo Bool

		string Bandera = "No";

		//Comienzo Inserci�n


		if(CodigoANumerico.compare(ArbolAuxiliar -> CodigoANumericoActivo) > 0)
		{
			//Es Mayor

			if(ArbolAuxiliar -> RI != NULL)
			{
				//Derecha No Esta Vacio

				Bandera = InsertarActivoArbolAVLA(Arbol, CodigoANumerico, NombreActivo, DescripcionActivo, *ArbolAuxiliar -> RI);

				if(TengoQueAumentar == "Si")
				{
					ArbolAuxiliar -> AlturaArbolAVL++;
				}

				ComparacionYEleccionRotacionArbolAVLA(Arbol, *ArbolAuxiliar);
				return Bandera;
			}
			else
			{
				//Derecha Esta Vacia

				ActivoNuevo = new ArbolAVLEstructura(CodigoANumerico, NombreActivo, DescripcionActivo);
				ArbolAuxiliar -> RI = ActivoNuevo;
				ArbolAuxiliar -> AlturaArbolAVL++;

				if(ArbolAuxiliar -> LE == NULL)
				{
					TengoQueAumentar = "Si";
				}
				return "Si";
			}
		}
		else if(CodigoANumerico.compare(ArbolAuxiliar -> CodigoANumericoActivo) < 0)
		{
			//Es Menor

			if(ArbolAuxiliar -> LE != NULL)
			{
				//Izquierda No Esta Vacia

				Bandera = InsertarActivoArbolAVLA(Arbol, CodigoANumerico, NombreActivo, DescripcionActivo, *ArbolAuxiliar -> LE);

				if(TengoQueAumentar == "Si")
				{
					ArbolAuxiliar -> AlturaArbolAVL--;
				}

				ComparacionYEleccionRotacionArbolAVLA(Arbol, *ArbolAuxiliar);
				return Bandera;
			}
			else
			{
				//Izquierda Esta Vacia

				ActivoNuevo = new ArbolAVLEstructura(CodigoANumerico, NombreActivo, DescripcionActivo);
				ArbolAuxiliar -> LE = ActivoNuevo;
				ArbolAuxiliar -> AlturaArbolAVL--;

				if(ArbolAuxiliar -> RI == NULL)
				{
					TengoQueAumentar = "Si";
				}
				return "Si";
			}
		}
		else
		{
			return "No";
		}
	}

		//Generar Nodo Y Llamar A Insertar

	string ArbolAVLEstructura::InsertarActvioArbolAVLANuevoActivo(ArbolAVLActivos &Arbol, string CodigoANumerico, string NombreActivo, string DescripcionActivo)
	{
		TengoQueAumentar = "No";

		if(Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario == NULL)
		{
			Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario = new ArbolAVLEstructura(CodigoANumerico, NombreActivo, DescripcionActivo);
			return "Si";
		}
		else
		{
			return InsertarActivoArbolAVLA(Arbol, CodigoANumerico, NombreActivo, DescripcionActivo, *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario);
		}

	}

	//B�squeda

		//Buscar Activo

	ArbolAVLActivos BuscarActivoArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura &ActivoActualAuxiliar, string CodigoANumericoActivo)
	{
		//Declaraciones

		//Objeto Tipo Arbol AVL

		ArbolAVLActivos RecorridoAuxiliar = &ActivoActualAuxiliar;

		//UpperCase
		CodigoANumericoActivo = TrimCadena(CodigoANumericoActivo);
		CodigoANumericoActivo = UpperCase(CodigoANumericoActivo);

		if(RecorridoAuxiliar != nullptr)
		{
			//Comienza Comparaciones

			if(CodigoANumericoActivo.compare(RecorridoAuxiliar -> CodigoANumericoActivo) == 0)
			{
				cout<< RecorridoAuxiliar -> CodigoANumericoActivo;
				return RecorridoAuxiliar;
			}
			else if(CodigoANumericoActivo.compare(RecorridoAuxiliar -> CodigoANumericoActivo) > 0)
			{
				BuscarActivoArbolAVLA(Arbol, *RecorridoAuxiliar -> RI, CodigoANumericoActivo);
			}
			else if(CodigoANumericoActivo.compare(RecorridoAuxiliar -> CodigoANumericoActivo) < 0)
			{
				BuscarActivoArbolAVLA(Arbol, *RecorridoAuxiliar -> LE, CodigoANumericoActivo);
            }
		}

		return nullptr;
	}



	//Actualizaci�n

		//Actualizar Descripci�n

   /*	string ModificarDescripcionActivoArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura &ActivoActualAuxiliar)
	{
		//Declaraciones

		//Objetos Tipo Arbol AVL

		ArbolAVLActivos RecorridoAuxiliar = &Nodo;

		if (Aux!=NULL) {
		if (strcmp(Nombre.c_str(), Aux->Nombre.c_str()) == 0) {
			Aux->Descripcion = Descripcion;
			return true;
		}
		else if (strcmp(Nombre.c_str(), Aux->Nombre.c_str()) == 1) {
			if (Aux->Derecha != NULL) {
				bool Editado = NodoAVL::EditarActivo(*Aux->Derecha, Descripcion, Nombre);
				return Editado;
			}
			else {
				return false;
			}
		}
		else if (strcmp(Nombre.c_str(), Aux->Nombre.c_str()) == -1) {
			if (Aux->Izquierda != NULL) {
				bool Editado = NodoAVL::EditarActivo(*Aux->Izquierda, Descripcion, Nombre);
				return Editado;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
    }

		*/

	//Eliminaci�n

		//Quien Es El Mayor

	ArbolAVLActivos SoyElMayor(ArbolAVLActivos &Arbol, ArbolAVLEstructura &ActivoActualAuxiliar)
	{
		//Declaraciones

		//Objeto Tipo Arbol AVL

		ArbolAVLActivos RecorridoAuxiliar = &ActivoActualAuxiliar;

		//Comienza Recorrer

		if(RecorridoAuxiliar != nullptr)
		{
			if(RecorridoAuxiliar -> RI == nullptr)
			{
				return RecorridoAuxiliar;
			}
			else
			{
				return SoyElMayor(Arbol, *RecorridoAuxiliar -> RI);
			}
		}

		return nullptr;
	}

		//Eliminar Nodo Auxiliar

	void EliminarNodoAuxilair(ArbolAVLActivos &Arbol, ArbolAVLEstructura &ActivoActualAuxiliar)
	{
		//Declaraciones

		//Objeto Tipo Arbol AVL

		ArbolAVLActivos RecorridoAuxiliar = &ActivoActualAuxiliar;

		//Arbol No Vacio

		if(RecorridoAuxiliar != nullptr)
		{
			//Recorrido En Derecha

			if(RecorridoAuxiliar -> RI != nullptr)
			{
				//Se Encuentra Vacio

				if(RecorridoAuxiliar -> RI -> CodigoANumericoActivo == "")
				{
					//Elimino El Nodo

					delete RecorridoAuxiliar -> RI;
					RecorridoAuxiliar -> RI = nullptr;
				}
				else
				{
					//Sigo Recorriendo

					EliminarNodoAuxilair(RecorridoAuxiliar -> RI, *RecorridoAuxiliar -> RI);
				}
			}

			//Recorrido En Izquierda

			if(RecorridoAuxiliar -> LE != nullptr)
			{
				//Se Encuentra Vacio

				if(RecorridoAuxiliar -> LE -> CodigoANumericoActivo == "")
				{
					//Elimino El Nodo

					delete RecorridoAuxiliar -> LE;
					RecorridoAuxiliar -> LE = nullptr;
				}
				else
				{
					//Sigo Recorriendo

					EliminarNodoAuxilair(RecorridoAuxiliar -> LE, *RecorridoAuxiliar -> LE);
				}
			}
		}
	}

		//Comparaci�n Y Elecci�n Casos De Eliminaci�n

	string ComparacionYEleccionArbolAVLA(ArbolAVLActivos &Arbol, ArbolAVLEstructura &ActivoActualArbol)
	{
		//Declaraciones

		//Objetos Tipo Arbol AVL

		ArbolAVLActivos RecorridosAuxiliar = &ActivoActualArbol;
		ArbolAVLActivos OtroAuxiliarRecorridos = nullptr;

		//Comienzo Reocrrer Arbol

		if(RecorridosAuxiliar != nullptr)
		{

			if(RecorridosAuxiliar -> LE == nullptr)
			{
				if(RecorridosAuxiliar -> RI != nullptr)
				{
					OtroAuxiliarRecorridos = RecorridosAuxiliar -> RI;

					RecorridosAuxiliar -> LE = RecorridosAuxiliar -> RI -> LE;
					RecorridosAuxiliar -> RI = RecorridosAuxiliar -> RI -> RI;

					RecorridosAuxiliar -> CodigoANumericoActivo = OtroAuxiliarRecorridos -> CodigoANumericoActivo;
					RecorridosAuxiliar -> NombreActivo = OtroAuxiliarRecorridos -> NombreActivo;
					RecorridosAuxiliar -> DescripcionActivo = OtroAuxiliarRecorridos -> DescripcionActivo;
					RecorridosAuxiliar -> ExisteRentaActivo = OtroAuxiliarRecorridos -> ExisteRentaActivo;

					OtroAuxiliarRecorridos -> CodigoANumericoActivo = "";

					return "Si";
				}
			}
			else if(RecorridosAuxiliar -> LE != nullptr)
			{
				if(RecorridosAuxiliar -> RI != nullptr)
				{
					OtroAuxiliarRecorridos = SoyElMayor(Arbol, *RecorridosAuxiliar -> LE);

					if(OtroAuxiliarRecorridos -> LE == nullptr)
					{
						if(OtroAuxiliarRecorridos -> RI == nullptr)
						{
							RecorridosAuxiliar -> CodigoANumericoActivo = OtroAuxiliarRecorridos -> CodigoANumericoActivo;
							RecorridosAuxiliar -> NombreActivo = OtroAuxiliarRecorridos -> NombreActivo;
							RecorridosAuxiliar -> DescripcionActivo = OtroAuxiliarRecorridos -> DescripcionActivo;
							RecorridosAuxiliar -> ExisteRentaActivo = OtroAuxiliarRecorridos -> ExisteRentaActivo;

							OtroAuxiliarRecorridos -> CodigoANumericoActivo = "";

							return "Si";
						}
					}
					else
					{
						RecorridosAuxiliar -> LE = OtroAuxiliarRecorridos -> LE;

						RecorridosAuxiliar -> CodigoANumericoActivo = OtroAuxiliarRecorridos -> CodigoANumericoActivo;
						RecorridosAuxiliar -> NombreActivo = OtroAuxiliarRecorridos -> NombreActivo;
						RecorridosAuxiliar -> DescripcionActivo = OtroAuxiliarRecorridos -> DescripcionActivo;
						RecorridosAuxiliar -> ExisteRentaActivo = OtroAuxiliarRecorridos -> ExisteRentaActivo;

						OtroAuxiliarRecorridos -> CodigoANumericoActivo = "";

						return "Si";
					}
				}
			}
			else if(RecorridosAuxiliar -> LE != nullptr)
			{
				if(RecorridosAuxiliar -> RI == nullptr)
				{
					OtroAuxiliarRecorridos = RecorridosAuxiliar -> LE;

					RecorridosAuxiliar -> RI = RecorridosAuxiliar -> LE -> RI;
					RecorridosAuxiliar -> LE = RecorridosAuxiliar -> LE -> LE;

					RecorridosAuxiliar -> CodigoANumericoActivo = OtroAuxiliarRecorridos -> CodigoANumericoActivo;
					RecorridosAuxiliar -> NombreActivo = OtroAuxiliarRecorridos -> NombreActivo;
					RecorridosAuxiliar -> DescripcionActivo = OtroAuxiliarRecorridos -> DescripcionActivo;
					RecorridosAuxiliar -> ExisteRentaActivo = OtroAuxiliarRecorridos -> ExisteRentaActivo;

					OtroAuxiliarRecorridos -> CodigoANumericoActivo = "";

					return "Si";
				}
			}
			else if(RecorridosAuxiliar -> LE == nullptr)
			{
				if(RecorridosAuxiliar -> RI == nullptr)
				{
					RecorridosAuxiliar -> CodigoANumericoActivo = "";
					RecorridosAuxiliar = nullptr;
					return "Si";
				}
			}
		}
		return "No";
	}

		//Eliminar Activo

	string ArbolAVLEstructura::EliminarActivoArbolAVLA(ArbolAVLEstructura &ActivoActualArbol, string CodigoANumericoActivo)
	{
		//Declaraciones

		//Objeto Tipo Arbol AVL

		ArbolAVLActivos AuxiliarRecorrido = &ActivoActualArbol;

		//Variables Tipo String

		string ActivoFueEliminado = "";

		//Recorrer Arbol AVL

		if(AuxiliarRecorrido != nullptr)
		{
			if(CodigoANumericoActivo.compare(AuxiliarRecorrido -> CodigoANumericoActivo) > 0)
			{
				if(AuxiliarRecorrido  -> RI != nullptr)
				{
					EliminarActivoArbolAVLA(*Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario -> RI, CodigoANumericoActivo);
				}
				else
				{
					return "No";
				}
			}
			else if(CodigoANumericoActivo.compare(AuxiliarRecorrido -> CodigoANumericoActivo) < 0)
			{
				if(AuxiliarRecorrido -> LE != nullptr)
				{
					EliminarActivoArbolAVLA(*Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario -> LE, CodigoANumericoActivo);
				}
				else
				{
					return "No";
				}
			}
			else if(CodigoANumericoActivo.compare(AuxiliarRecorrido -> CodigoANumericoActivo) == 0)
			{
				//Asignaciones

				Variables::IdentificadorAC = AuxiliarRecorrido -> CodigoANumericoActivo;
				Variables::NombreAC = AuxiliarRecorrido -> NombreActivo;
				Variables::DescripcionAC = AuxiliarRecorrido -> DescripcionActivo;
				ActivoFueEliminado = "No";

				MenuEliminado();

				//Recorrer Arbol Activos Usuarios

				if(AuxiliarRecorrido == Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario)
				{
					if(Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario -> RI == nullptr)
					{
						if(Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario -> LE == nullptr)
						{
							Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario = nullptr;
							ActivoFueEliminado = "Si";
                        }
					}
				}
				else
				{
					if(AuxiliarRecorrido -> ExisteRentaActivo == "No")
					{
						//Verificar Casos Eliminaci�n

						ActivoFueEliminado = ComparacionYEleccionArbolAVLA(AuxiliarRecorrido, *AuxiliarRecorrido);

						//Eliminar Nodo

						EliminarNodoAuxilair(AuxiliarRecorrido, *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario);

						//Calculo Altura Y Equilibrio

						EstaEquilibrado = "Si";

						ArbolAVLEstructura::CalcularAlturaVoidArbolAVLA(AuxiliarRecorrido, *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario);

						if(EstaEquilibrado == "No")
						{
							EstaEquilibrado = "Si";

							ArbolAVLEstructura::CalcularAlturaVoidArbolAVLA(AuxiliarRecorrido, *Variables::ArbolAVLActivosUsuarioActual -> ArbolAVLActivosUsuario);
						}
					}
				}
				return ActivoFueEliminado;
			}
			else
			{
				return "No";
			}
		}
		else
		{
			return "No";
		}
		return "No";
	}




