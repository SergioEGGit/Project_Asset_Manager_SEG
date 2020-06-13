//------------------------------------------------------------------------------

	#pragma hdrstop

//-----------------------------Librerias----------------------------------------

	#include "MatrizDispersaEstructura.h"
	#include "Metodos.h"
	#include "Variables.h"
	#include <iostream>
	#include <fstream>
	#include <string>
	#include <cstring>

	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------Métodos--------------------------------------

	bool InsertarCabeceraEmpresaMatrizDispersaU(MatrizDU &Matriz, string NombreEmpresa, MatrizDispersaEstructura& UsuarioAux, MatrizDispersaEstructura& EmpresaAux)
	{
		//Declaraciones
		MatrizDU UsuarioNuevoAux = &UsuarioAux;
		MatrizDU EmpresaNuevaAux = &EmpresaAux;
		MatrizDU NuevaEmpresa = Matriz;

		//Insertar Cabecera De Tipo Empresa

		//UpperCase
		NombreEmpresa = UpperCase(NombreEmpresa);

		while(NuevaEmpresa != nullptr)
		{
			if(NuevaEmpresa -> Aba != nullptr)
			{
				MatrizDU AuxiliarNuevaEmpresa = NuevaEmpresa -> Aba;
				NuevaEmpresa -> Aba = EmpresaNuevaAux;
				AuxiliarNuevaEmpresa -> Arr = EmpresaNuevaAux;
				EmpresaNuevaAux -> Arr = NuevaEmpresa;
				EmpresaNuevaAux -> Aba = AuxiliarNuevaEmpresa;
				EmpresaNuevaAux -> Sgte = UsuarioNuevoAux;
				UsuarioNuevoAux -> Ante = EmpresaNuevaAux;
				return true;
			}
			else
			{
				NuevaEmpresa -> Aba = EmpresaNuevaAux;
				EmpresaNuevaAux -> Arr = NuevaEmpresa;
				EmpresaNuevaAux -> Sgte = UsuarioNuevoAux;
				UsuarioNuevoAux -> Ante = EmpresaNuevaAux;
				return true;
			}
			NuevaEmpresa = NuevaEmpresa -> Aba;
		}
		return false;
	}

	bool InsertarCabeceraDepartamentoMatrizDispersaU(MatrizDU &Matriz, string NombreDepartamento, MatrizDispersaEstructura& UsuarioAux, MatrizDispersaEstructura& DepartamentoAux)
	{
		//Declaraciones
		MatrizDU UsuarioNuevoAux = &UsuarioAux;
		MatrizDU DepartamentoNuevoAux = &DepartamentoAux;
		MatrizDU NuevoDepartamento = Matriz;

		//Insertar Cabecera De Tipo Departamento

		//UpperCase
		NombreDepartamento = UpperCase(NombreDepartamento);

		while(NuevoDepartamento != nullptr)
		{
			if(NuevoDepartamento -> Sgte != nullptr)
			{
				MatrizDU AuxiliarNuevoDepartamento = NuevoDepartamento -> Sgte;
				NuevoDepartamento -> Sgte = DepartamentoNuevoAux;
				AuxiliarNuevoDepartamento -> Ante = DepartamentoNuevoAux;
				DepartamentoNuevoAux -> Ante = NuevoDepartamento;
				DepartamentoNuevoAux -> Sgte = AuxiliarNuevoDepartamento;
				DepartamentoNuevoAux -> Aba = UsuarioNuevoAux;
				UsuarioNuevoAux -> Arr = DepartamentoNuevoAux;
				return true;
			}
			else
			{
				NuevoDepartamento -> Sgte = DepartamentoNuevoAux;
				DepartamentoNuevoAux -> Ante = NuevoDepartamento;
				DepartamentoNuevoAux -> Aba = UsuarioNuevoAux;
				UsuarioNuevoAux -> Arr = DepartamentoNuevoAux;
				return true;
			}
			NuevoDepartamento = NuevoDepartamento -> Sgte;
		}
		return false;
	}

	bool InsertarUsuarioMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreCompleto, string Password, string NombreDepartamento, string NombreEmpresa)
	{
		//Declaraciones
		MatrizDU AuxDepartamento = Matriz;
		MatrizDU AuxEmpresa = Matriz;

        //UpperCase
		NombreEmpresa = UpperCase(NombreEmpresa);
		NombreDepartamento = UpperCase(NombreDepartamento);

		//Recorrer Cabeceras Departamento

		while(AuxDepartamento != NULL)
		{
			if(AuxDepartamento -> NombreDepartamento == NombreDepartamento)
			{
				break;
			}
			AuxDepartamento = AuxDepartamento -> Sgte;
		}

		//Recorrer Cabeceras  Empresa

		while(AuxEmpresa != NULL)
		{
			if(AuxEmpresa -> NombreEmpresa == NombreEmpresa)
			{
				break;
			}
			AuxEmpresa = AuxEmpresa -> Aba;
		}


		//Casos Insercion

		if(AuxDepartamento != NULL && AuxEmpresa != NULL)
		{
			//Caso 1: Ya Existen Ambas Cabeceras

			//Declaraciones
			while(AuxDepartamento != NULL)
			{
				if(AuxDepartamento -> NombreDepartamento == NombreDepartamento && AuxDepartamento -> NombreEmpresa == NombreEmpresa)
				{
					while(AuxDepartamento != NULL)
					{
						if(AuxDepartamento -> NombreUsuario == NombreUsuario)
						{
							return false;
						}
						else if(AuxDepartamento -> Atr == NULL)
						{
							MatrizDU UsuarioNuevo = new MatrizDispersaEstructura(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);
							AuxDepartamento -> Atr = UsuarioNuevo;
							UsuarioNuevo -> Adte = AuxDepartamento;
							return true;
						}
						AuxDepartamento = AuxDepartamento -> Atr;
					}
				}
				AuxDepartamento = AuxDepartamento -> Aba;
			}
		}
		else if(AuxDepartamento == NULL && AuxEmpresa == NULL)
		{
			//Caso 2: No Existe Ninguna Cabecera

			//Declaraciones
			MatrizDU DepartamentoNuevo = new MatrizDispersaEstructura("Dep", NombreDepartamento);
			MatrizDU EmpresaNueva = new MatrizDispersaEstructura("Emp", NombreEmpresa);
			MatrizDU UsuarioNuevo = new MatrizDispersaEstructura(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);

			if(InsertarCabeceraDepartamentoMatrizDispersaU(Matriz, NombreDepartamento, *UsuarioNuevo, *DepartamentoNuevo) == true)
			{
				if(InsertarCabeceraEmpresaMatrizDispersaU(Matriz, NombreEmpresa, *UsuarioNuevo, *EmpresaNueva) == true)
				{
					return true;
				}
			}
		}
		else if(AuxDepartamento != NULL && AuxEmpresa == NULL)
		{
			//Caso 3: No Existe Empresa

			//Declaraciones
			MatrizDU EmpresaNueva = new MatrizDispersaEstructura("Emp", NombreEmpresa);
			MatrizDU UsuarioNuevo = new MatrizDispersaEstructura(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);
			InsertarCabeceraEmpresaMatrizDispersaU(Matriz, NombreEmpresa, *UsuarioNuevo, *EmpresaNueva);
			MatrizDU AuxiliarEmpresa = EmpresaNueva -> Arr;
			string AuxEmpresaAnte = AuxiliarEmpresa -> NombreEmpresa;

			while(AuxDepartamento != NULL)
			{
				if(AuxDepartamento -> NombreEmpresa == AuxEmpresaAnte)
				{
					if(AuxDepartamento -> Aba != NULL)
					{
						MatrizDU AuxiliarDepartamento = AuxDepartamento -> Aba;
						AuxDepartamento -> Aba = UsuarioNuevo;
						AuxiliarDepartamento -> Arr = UsuarioNuevo;
						UsuarioNuevo -> Arr = AuxDepartamento;
						UsuarioNuevo -> Aba = AuxiliarDepartamento;
						return true;
					}
					else
					{
						AuxDepartamento -> Aba = UsuarioNuevo;
						UsuarioNuevo -> Arr = AuxDepartamento;
						return true;
					}
				}
				AuxDepartamento = AuxDepartamento -> Aba;
			}
		}
		else if(AuxDepartamento == NULL && AuxEmpresa != NULL)
		{
			//Caso 4: No Existe Departamento

			//Declaraciones
			MatrizDU DepartamentoNuevo = new MatrizDispersaEstructura("Dep", NombreDepartamento);
			MatrizDU UsuarioNuevo = new MatrizDispersaEstructura(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);
			InsertarCabeceraDepartamentoMatrizDispersaU(Matriz, NombreDepartamento, *UsuarioNuevo, *DepartamentoNuevo);
			MatrizDU AuxiliarDepartamento = DepartamentoNuevo -> Ante;
			string AuxEmpresaAnte = AuxiliarDepartamento -> NombreDepartamento;

			while(AuxEmpresa != NULL)
			{
				if(AuxEmpresa -> NombreDepartamento == AuxEmpresaAnte)
				{
					if(AuxEmpresa -> Sgte != NULL)
					{
						MatrizDU AuxiliarEmpresa = AuxEmpresa -> Sgte;
						AuxEmpresa -> Sgte = UsuarioNuevo;
						AuxiliarEmpresa -> Ante = UsuarioNuevo;
						UsuarioNuevo -> Sgte = AuxiliarEmpresa;
						UsuarioNuevo -> Ante = AuxEmpresa;
						return true;
					}
					else
					{
						AuxEmpresa -> Sgte = UsuarioNuevo;
						UsuarioNuevo -> Ante = AuxEmpresa;
						return true;
					}
				}
				AuxEmpresa = AuxEmpresa -> Sgte;
			}
		}
		return false;
	}

	bool BuscarUsuarioMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreEmpresa, string NombreDepartamento)
	{
		//Declaraciones
		MatrizDU Auxiliar = Matriz;
		bool Bandera = false;

        //UpperCase
		NombreEmpresa = UpperCase(NombreEmpresa);
		NombreDepartamento = UpperCase(NombreDepartamento);

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

	void ReporteUsuariosMatrizDispersaU(MatrizDU &Matriz)
	{
		//Declaraciones
		ofstream SalidaArchivo("C:\\ReportesEDD\\ReporteMatrizDispersaUsuarios.txt");
		int ContadorGrupo = 2;
		int ContadorArray = 0;
		string ContadorArrayS = "";
		string ArrayGrupos[50][2];
		string AuxCabeceras = "";
		string AuxCabecerasAba = "";

		if(SalidaArchivo.is_open())
		{
			if(Matriz != nullptr)
			{
				//Declaraciones
				MatrizDispersaEstructura*EmpresasCabeceras = Matriz -> Aba;
				MatrizDispersaEstructura *DepartamentosCabeceras = Matriz -> Sgte;
				MatrizDispersaEstructura *AuxiliarEmpresaFila = Matriz -> Aba;
				MatrizDispersaEstructura *AuxiliarDepartamentoColumna = Matriz -> Sgte;
				MatrizDispersaEstructura *Auxiliar;


				//Comienza Generar Reporte
				SalidaArchivo<< "digraph G {" << endl;
				SalidaArchivo<< "graph [ charset=latin1 ]" <<endl;
				SalidaArchivo<< "node [shape = box]" << endl;
				SalidaArchivo<< "MatrizEstructura[ label = \"Matriz Dispersa: \\l Usuarios\", width = 2, font = \"Times New Roman\", fontcolor = indigo, style = filled, fillcolor = cadetblue1, group = 1 ];" << endl;

				//Recorrer Empresas

				while(EmpresasCabeceras != nullptr)
				{
					AuxCabeceras = TrimCadena(EmpresasCabeceras -> NombreEmpresa);
					SalidaArchivo<< "Emp" << AuxCabeceras;
					SalidaArchivo<< "[label = \"" << EmpresasCabeceras -> NombreEmpresa << "\"";
					SalidaArchivo<< "width = 2, style = filled, fillcolor = darkseagreen1, fontcolor = darkslategray, group = 1 ];" << endl;
					EmpresasCabeceras = EmpresasCabeceras -> Aba;
				}

				EmpresasCabeceras = Matriz -> Aba;

				//Crear Enlaces Entre Empresas

				while(EmpresasCabeceras -> Aba != nullptr)
				{
					AuxCabeceras = TrimCadena(EmpresasCabeceras -> NombreEmpresa);
					AuxCabecerasAba = TrimCadena(EmpresasCabeceras -> Aba -> NombreEmpresa);
					SalidaArchivo<< "Emp" << AuxCabeceras << "-> Emp" << AuxCabecerasAba << ";" << endl;
					EmpresasCabeceras = EmpresasCabeceras -> Aba;
				}

				//Recorrer Departamentos

				while(DepartamentosCabeceras != nullptr)
				{
					AuxCabeceras = TrimCadena(DepartamentosCabeceras -> NombreDepartamento);
					SalidaArchivo<< "Dep" << AuxCabeceras;
					SalidaArchivo<< "[label = \"" << DepartamentosCabeceras -> NombreDepartamento << "\"";
					SalidaArchivo<< "width = 2, style = filled, fillcolor = lightblue3, fontcolor = maroon, group =" << ContadorGrupo << "];" << endl;
					ArrayGrupos[ContadorArray][0] = DepartamentosCabeceras -> NombreDepartamento;
					ArrayGrupos[ContadorArray][1] = to_string(ContadorGrupo);
					DepartamentosCabeceras = DepartamentosCabeceras -> Sgte;
					ContadorGrupo++;
					ContadorArray++;
				}

				DepartamentosCabeceras = Matriz -> Sgte;

				//Crear Enlaces Entre Departamentos

				while(DepartamentosCabeceras -> Sgte != nullptr)
				{
					AuxCabeceras = TrimCadena(DepartamentosCabeceras -> NombreDepartamento);
					AuxCabecerasAba = TrimCadena(DepartamentosCabeceras -> Sgte -> NombreDepartamento);
					SalidaArchivo<< "Dep" << AuxCabeceras  << "-> Dep" << AuxCabecerasAba << ";" << endl;
					DepartamentosCabeceras = DepartamentosCabeceras -> Sgte;
				}

				//Rank Same
				AuxCabeceras = TrimCadena(Matriz -> Aba -> NombreEmpresa);
				AuxCabecerasAba = TrimCadena(Matriz -> Sgte -> NombreDepartamento);

				SalidaArchivo<< "MatrizEstructura -> Emp" << AuxCabeceras << ";" << endl;
				SalidaArchivo<< "MatrizEstructura -> Dep" << AuxCabecerasAba << ";" << endl;

				SalidaArchivo << "{ rank = same; MatrizEstructura;";
				DepartamentosCabeceras = Matriz -> Sgte;

				while(DepartamentosCabeceras != nullptr)
				{
					AuxCabeceras = TrimCadena(DepartamentosCabeceras -> NombreDepartamento);
					SalidaArchivo<< "Dep" << AuxCabeceras << ";";
					DepartamentosCabeceras = DepartamentosCabeceras -> Sgte;
				}

				SalidaArchivo<< "}" << endl;

				//Recorrer Usuarios

				while(AuxiliarEmpresaFila != nullptr)
				{
					Auxiliar = AuxiliarEmpresaFila -> Sgte;

					while(Auxiliar != nullptr)
					{
						AuxCabeceras = TrimCadena(Auxiliar -> NombreDepartamento);
						AuxCabecerasAba = TrimCadena(Auxiliar -> NombreEmpresa);
						SalidaArchivo<< "Dep" << AuxCabeceras ;
						SalidaArchivo<< "Emp" << AuxCabecerasAba;
						SalidaArchivo<< " [label = \"Usuario: " << Auxiliar -> NombreUsuario << "\\lNombre: "  << Auxiliar -> NombreCompleto << "\" width = 2, color = salmon, fontcolor = midnightblue,";

						for(int i = 0; i < 50; i++)
						{
							if(Auxiliar -> NombreDepartamento == ArrayGrupos[i][0])
							{
								ContadorArrayS = ArrayGrupos[i][1];
                            }
						}

						SalidaArchivo<< " group = " << atoi(ContadorArrayS.c_str()) << "];" << endl;
						Auxiliar = Auxiliar -> Sgte;
					}
					AuxiliarEmpresaFila = AuxiliarEmpresaFila -> Aba;
				}

				AuxiliarEmpresaFila = Matriz -> Aba;

				//Generar Enlaces Fila Empresas

				while(AuxiliarEmpresaFila != nullptr)
				{
					Auxiliar = AuxiliarEmpresaFila;

					while(Auxiliar -> Sgte != nullptr)
					{
						AuxCabeceras = TrimCadena(Auxiliar -> NombreDepartamento);
						AuxCabecerasAba = TrimCadena(Auxiliar -> NombreEmpresa);

						if(Auxiliar -> NombreDepartamento == "")
						{
							SalidaArchivo<< "Emp" << AuxCabecerasAba;
						}
						else
						{
							SalidaArchivo<< "Dep" << AuxCabeceras;
							SalidaArchivo<< "Emp" << AuxCabecerasAba;
						}

						AuxCabeceras = TrimCadena(Auxiliar -> Sgte -> NombreDepartamento);
						AuxCabecerasAba = TrimCadena(Auxiliar -> Sgte -> NombreEmpresa);

						SalidaArchivo<< " -> Dep" << AuxCabeceras;
						SalidaArchivo<< "Emp" << AuxCabecerasAba << " [dir = \"both\"];" << endl;
						Auxiliar = Auxiliar -> Sgte;
					}

					SalidaArchivo<< "{ rank = same; ";
					Auxiliar = AuxiliarEmpresaFila;

					while(Auxiliar != nullptr)
					{
						AuxCabeceras = TrimCadena(Auxiliar -> NombreDepartamento);
						AuxCabecerasAba = TrimCadena(Auxiliar -> NombreEmpresa);

						if(Auxiliar -> NombreDepartamento == "")
						{
							SalidaArchivo<< " Emp" << AuxCabecerasAba << ";";
						}
						else
						{
							SalidaArchivo<< " Dep" << AuxCabeceras;
							SalidaArchivo<< "Emp" << AuxCabecerasAba << ";";
						}
						Auxiliar = Auxiliar -> Sgte;
					}
					SalidaArchivo<< "}" << endl;
					AuxiliarEmpresaFila = AuxiliarEmpresaFila -> Aba;
				}

				//Generar Enlaces Columna Departamentos

				while(AuxiliarDepartamentoColumna != nullptr)
				{
					Auxiliar = AuxiliarDepartamentoColumna;

					while(Auxiliar -> Aba != nullptr)
					{
						AuxCabeceras = TrimCadena(Auxiliar -> NombreDepartamento);
						AuxCabecerasAba = TrimCadena(Auxiliar -> NombreEmpresa);

						if(Auxiliar -> NombreEmpresa == "")
						{
							SalidaArchivo<< "Dep" << AuxCabeceras;
						}
						else
						{
							SalidaArchivo<< "Dep" << AuxCabeceras;
							SalidaArchivo<< "Emp" << AuxCabecerasAba;
						}

						AuxCabeceras = TrimCadena(Auxiliar -> Aba -> NombreDepartamento);
						AuxCabecerasAba = TrimCadena(Auxiliar -> Aba -> NombreEmpresa);

						SalidaArchivo<< " -> Dep" << AuxCabeceras;
						SalidaArchivo<< "Emp" << AuxCabecerasAba << " [dir = \"both\"];" << endl;
						Auxiliar = Auxiliar -> Aba;
					}
					AuxiliarDepartamentoColumna = AuxiliarDepartamentoColumna -> Sgte;
				}

				SalidaArchivo<< "}" << endl;
				SalidaArchivo.close();

				//Generar Archivo Dot Para Graficar
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\ReportesEDD\\ReporteMatrizDispersaUsuarios.txt -o C:\\ReportesEDD\\ReporteMatrizDispersaUsuarios.png");
				//Abrir Imagen Con El Vizualizador de Imagenes
				system("C:\\ReportesEDD\\ReporteMatrizDispersaUsuarios.png &" );
			}
		}
	}

