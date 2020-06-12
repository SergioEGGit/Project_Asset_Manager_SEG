//------------------------------------------------------------------------------

	#pragma hdrstop

//-----------------------------Librerias----------------------------------------

	#include "ArbolAVLEstructura.h"
	#include "Metodos.h"
	#include "Variables.h"
	#include <iostream>
	#include <fstream>
	#include <string>
	#include <cstring>

	using namespace std;

//---------------------------------Variables------------------------------------

	bool TengoQueAumentar = false;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------Métodos--------------------------------------

	//Rotaciones Arbol AVL

	void PlantillaRotacionDerechaArbolAVLA(ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo)
	{
		//Declaraciones
		ArbolAVLActivos AuxiliarPrimero = &Primero;
		ArbolAVLActivos AuxiliarUltimo = &Ultimo;
		string NombreActivoAuxiliar = AuxiliarPrimero -> NombreActivo;
		string NombreActivoAuxiliarUltimo = AuxiliarUltimo -> NombreActivo;
		string DescripcionActivoAuxiliar = AuxiliarPrimero -> DescripcionActivo;
		string DescripcionActivoAuxiliarUltimo = AuxiliarUltimo -> DescripcionActivo;

		//Inicio Plantilla Rotacion Derecha

		AuxiliarPrimero -> NombreActivo = NombreActivoAuxiliarUltimo;
		AuxiliarPrimero -> DescripcionActivo = DescripcionActivoAuxiliarUltimo;

		AuxiliarUltimo -> NombreActivo = NombreActivoAuxiliar;
		AuxiliarUltimo -> DescripcionActivo = DescripcionActivoAuxiliarUltimo;

		AuxiliarPrimero -> LE = AuxiliarUltimo -> LE;

		AuxiliarUltimo -> LE = AuxiliarUltimo -> RI;
		AuxiliarUltimo -> RI = AuxiliarPrimero -> RI;

		AuxiliarPrimero -> RI = AuxiliarUltimo;

		TengoQueAumentar = false;
    }

	void PlantillaRotacionIzquierdaArbolAVLA(ArbolAVLEstructura &Primero, ArbolAVLEstructura &Ultimo)
	{
		//Declaraciones
		ArbolAVLActivos AuxiliarPrimero = &Primero;
		ArbolAVLActivos AuxiliarUltimo = &Ultimo;
		string NombreActivoAuxiliar = AuxiliarPrimero -> NombreActivo;
		string NombreActivoAuxiliarUltimo = AuxiliarUltimo -> NombreActivo;
		string DescripcionActivoAuxiliar = AuxiliarPrimero -> DescripcionActivo;
		string DescripcionActivoAuxiliarUltimo = AuxiliarUltimo -> DescripcionActivo;

		//Inicio Plantilla Rotacion Izquierda

		AuxiliarPrimero -> NombreActivo = NombreActivoAuxiliarUltimo;
		AuxiliarPrimero -> DescripcionActivo = DescripcionActivoAuxiliarUltimo;
		AuxiliarPrimero -> RI = AuxiliarUltimo -> RI;

		AuxiliarUltimo -> NombreActivo = NombreActivoAuxiliar;
		AuxiliarUltimo -> DescripcionActivo = DescripcionActivoAuxiliar;
		AuxiliarUltimo -> RI = AuxiliarUltimo -> LE;
		AuxiliarUltimo -> LE = AuxiliarPrimero -> LE;

		AuxiliarPrimero -> LE = NULL;
		AuxiliarPrimero -> LE = AuxiliarUltimo;

		TengoQueAumentar = false;
    }

	void SubArbolIzquierdoMayor(ArbolAVLActivos &ArbolAuxiliar)
	{
		//Inicio Comparacion Y Elección

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

	void SubArbolDerechoMayor(ArbolAVLActivos &ArbolAuxiliar)
	{
		//Inicio Comparacion Y Elección

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

	void ComparacionYEleccionRotacionArbolAVLA(ArbolAVLEstructura &ArbolAVLActivosActual)
	{
		ArbolAVLActivos ArbolAuxiliar = &ArbolAVLActivosActual;

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

	int CalcularAlturaArbolAVLA(ArbolAVLEstructura& ActivoParaCalcular)
	{
		//Declaraciones
		ArbolAVLActivos Auxiliar = &ActivoParaCalcular;


		if(Auxiliar -> RI == NULL && Auxiliar -> LE == NULL)
		{
			return 0;
		}
		else
		{
			if(Auxiliar -> RI != NULL)
			{
				Auxiliar -> RI -> AlturaArbolAVL = 0;
				int AlturaParcial = CalcularAlturaArbolAVLA(*Auxiliar -> RI) + 1;
				Auxiliar -> AlturaArbolAVL += AlturaParcial;

				if(Auxiliar -> LE != NULL)
				{
					Auxiliar -> LE -> AlturaArbolAVL = 0;
					int AlturaParcial2 = CalcularAlturaArbolAVLA(*Auxiliar -> LE) + 1;
					Auxiliar -> AlturaArbolAVL -= AlturaParcial2;
				}
				return AlturaParcial;
			}
			if(Auxiliar -> LE != NULL)
			{
				Auxiliar -> LE -> AlturaArbolAVL = 0;
				int AlturaParcial = CalcularAlturaArbolAVLA(*Auxiliar -> LE) + 1;
				Auxiliar -> AlturaArbolAVL -= AlturaParcial;

				if(Auxiliar -> RI != NULL)
				{
					Auxiliar -> RI -> AlturaArbolAVL = 0;
					int AlturaParcial2 = CalcularAlturaArbolAVLA(*Auxiliar -> RI) + 1;
					Auxiliar -> AlturaArbolAVL += AlturaParcial2;
				}
				return AlturaParcial;
			}
		}
	}

	void CalcularAlturaVoidArbolAVLA(ArbolAVLEstructura& ActivoParaCalcular)
	{
		//Declaracion
		ArbolAVLActivos AuxiliarAltura = &ActivoParaCalcular;


		AuxiliarAltura -> AlturaArbolAVL = 0;

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
				int AlturaParcial = CalcularAlturaArbolAVLA(*AuxiliarAltura -> RI) + 1;
				AuxiliarAltura -> AlturaArbolAVL += AlturaParcial;
			}
		}
	}