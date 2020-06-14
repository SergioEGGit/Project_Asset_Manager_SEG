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

//---------------------------------M�todos--------------------------------------

	//Generaci�n De Reportes

	void ReporteUsuariosMatrizDispersaU(MatrizDU &Matriz)
	{
		//Declaraciones
		ofstream SalidaArchivo("C:\\ReportesEDD\\ReporteMatrizDispersaUsuarios.txt");
		MatrizDU MatrizAuxiliarUsuario = Matriz;
		int ContadorGrupos = 0;
		string RankSameCadena = "";

		if(SalidaArchivo.is_open())
		{
			if(Matriz != nullptr)
			{
				//Apertura Archivo Y Comienza Escritura

				SalidaArchivo<< "digraph MatrizDispersa " <<endl;
				SalidaArchivo<< "{" <<endl;
				SalidaArchivo<< "node[shape = box, style = rounded, color = midnightblue, fontcolor = darkgreen];" <<endl;
				SalidaArchivo<< "MatrizEstructura[ label =\"Matriz Dispersa: Usuarios\", width = 2, group = 1];\n" <<endl;

				//Recorrer Empresas

				MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Aba;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					SalidaArchivo<< "Emp" << TrimCadena(MatrizAuxiliarUsuario -> NombreEmpresa) << " [label = \""<< MatrizAuxiliarUsuario -> NombreEmpresa << "\", width = 2, color = orange, fontcolor = 	midnightblue, group=1];\n" <<endl;
					MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Aba;
				}

				ContadorGrupos = 2;

				//Recorrer Departamentos

				MatrizAuxiliarUsuario = Matriz -> Sgte;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					SalidaArchivo<< "Dep" << TrimCadena(MatrizAuxiliarUsuario -> NombreDepartamento) << " [label = \"" << MatrizAuxiliarUsuario -> NombreDepartamento << "\", width = 2, color = mediumspringgreen, fontcolor = palevioletred1, group = "<< to_string(ContadorGrupos) <<"];\n" <<endl;
					ContadorGrupos++;
					MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Sgte;
				}

				//Generar Enlaces Empresas

				MatrizAuxiliarUsuario = Matriz -> Aba;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					if(MatrizAuxiliarUsuario -> Aba != nullptr)
					{
						SalidaArchivo<< "Emp" << TrimCadena(MatrizAuxiliarUsuario -> NombreEmpresa) << " -> " << "Emp" << TrimCadena(MatrizAuxiliarUsuario -> Aba -> NombreEmpresa) <<" [dir=\"both\"];\n" <<endl;
					}
					MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Aba;
				}

				//Generar Enlaces Departamentos

				MatrizAuxiliarUsuario = Matriz -> Sgte;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					if(MatrizAuxiliarUsuario -> Sgte != nullptr)
					{
						SalidaArchivo<< "Dep" << TrimCadena(MatrizAuxiliarUsuario -> NombreDepartamento) << " -> " << "Dep" << TrimCadena(MatrizAuxiliarUsuario -> Sgte -> NombreDepartamento) << " [dir=\"both\"];\n" <<endl;
					}
					MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Sgte;
				}

				//Comienza Rank Same

				if(Matriz -> Aba != nullptr)
				{
					SalidaArchivo<< "MatrizEstructura -> Emp" << TrimCadena(Matriz -> Aba -> NombreEmpresa) <<" [dir=\"both\"];\n" <<endl;
				}

				if(Matriz -> Sgte != nullptr)
				{
					SalidaArchivo<< "MatrizEstructura -> Dep" << TrimCadena(Matriz -> Sgte -> NombreDepartamento) << " [dir=\"both\"];\n" <<endl;
				}

				SalidaArchivo<< "{ rank=same;MatrizEstructura;";

				MatrizAuxiliarUsuario = Matriz -> Sgte;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					SalidaArchivo<< "Dep" << TrimCadena(MatrizAuxiliarUsuario -> NombreDepartamento) <<";";
					MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Sgte;
				}

				SalidaArchivo<< "}\n";

				//Recoorrer Usuarios

				MatrizAuxiliarUsuario = Matriz -> Sgte;
				ContadorGrupos = 2;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					MatrizDU AuxiliarCabecera = MatrizAuxiliarUsuario;

					MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Aba;

					while(MatrizAuxiliarUsuario != nullptr)
					{
                        cout<< "usuario";
						SalidaArchivo<< "NodoUsuario" << TrimCadena(MatrizAuxiliarUsuario -> NombreDepartamento) << TrimCadena(MatrizAuxiliarUsuario -> NombreEmpresa) << " [label = \" Usuario:" + MatrizAuxiliarUsuario -> NombreUsuario + "\\lNombre: " + MatrizAuxiliarUsuario -> NombreCompleto + "\", width = 2, color = steelblue, fontcolor = firebrick1, group = " + to_string(ContadorGrupos) + "];\n" <<endl;
						//Nodo Xd
						MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Aba;
					}
					MatrizAuxiliarUsuario = AuxiliarCabecera -> Sgte;
					ContadorGrupos++;
				}

				MatrizAuxiliarUsuario = Matriz -> Aba;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					MatrizDU AuxiliarCabecera = MatrizAuxiliarUsuario;

					RankSameCadena = "";

					SalidaArchivo<< "Emp" << TrimCadena(MatrizAuxiliarUsuario -> NombreEmpresa) <<" -> NodoUsuario" << TrimCadena(MatrizAuxiliarUsuario -> Sgte -> NombreDepartamento) << TrimCadena(MatrizAuxiliarUsuario -> Sgte -> NombreEmpresa) <<" [dir=\"both\"];\n" <<endl;
					MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Sgte;

					while(MatrizAuxiliarUsuario != nullptr)
					{
						RankSameCadena += "NodoUsuario" + TrimCadena(MatrizAuxiliarUsuario -> NombreDepartamento) + TrimCadena(MatrizAuxiliarUsuario -> NombreEmpresa) + ";";
						if(MatrizAuxiliarUsuario -> Sgte != nullptr)
						{
							SalidaArchivo<< "NodoUsuario" << TrimCadena(MatrizAuxiliarUsuario -> NombreDepartamento) << TrimCadena(MatrizAuxiliarUsuario -> NombreEmpresa) << " -> NodoUsuario" << TrimCadena(MatrizAuxiliarUsuario -> Sgte -> NombreDepartamento) << TrimCadena(MatrizAuxiliarUsuario -> Sgte -> NombreEmpresa) << " [dir=\"both\"];\n" <<endl;
						}
						MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Sgte;
					}
					SalidaArchivo<< "{ rank = same ; Emp" << TrimCadena(AuxiliarCabecera -> NombreEmpresa) << ";" << RankSameCadena;
					SalidaArchivo<< "}\n" <<endl;
					MatrizAuxiliarUsuario = AuxiliarCabecera -> Aba;
				}

				MatrizAuxiliarUsuario = Matriz -> Sgte;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					MatrizDU AuxiliarCabecera = MatrizAuxiliarUsuario;

					SalidaArchivo<< "Dep" << TrimCadena(MatrizAuxiliarUsuario -> NombreDepartamento) <<" -> NodoUsuario" << TrimCadena(MatrizAuxiliarUsuario -> Aba -> NombreDepartamento) << TrimCadena(MatrizAuxiliarUsuario -> Aba -> NombreEmpresa) <<" [dir=\"both\"];\n" <<endl;
					MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Aba;

					while(MatrizAuxiliarUsuario != nullptr)
					{
						if(MatrizAuxiliarUsuario -> Aba != nullptr)
						{
							SalidaArchivo<< "NodoUsuario" << TrimCadena(MatrizAuxiliarUsuario -> NombreDepartamento) << TrimCadena(MatrizAuxiliarUsuario -> NombreEmpresa) << " -> NodoUsuario" << TrimCadena(MatrizAuxiliarUsuario -> Aba -> NombreDepartamento) << TrimCadena(MatrizAuxiliarUsuario -> Aba -> NombreEmpresa) << " [dir=\"both\"];\n" <<endl;
						}
						MatrizAuxiliarUsuario = MatrizAuxiliarUsuario -> Aba;
					}
					MatrizAuxiliarUsuario = AuxiliarCabecera -> Sgte;
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

	//B�squeda De Usuarios

	   //B�squeda Usuario Retorna True = Existe False = No Existe

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
									Variables::ArbolAVLActivosUsuarioActual = Auxiliar;
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
							Variables::ArbolAVLActivosUsuarioActual = Auxiliar;
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

		//B�squeda Usuario Retorna AuxiliarMatriz

	MatrizDU BuscarUsuarioAuxMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreEmpresa, string NombreDepartamento)
	{
		//Declraciones
		MatrizDU UsuarioAuxiliar = Matriz;

		if(UsuarioAuxiliar -> NombreUsuario == NombreUsuario && UsuarioAuxiliar -> NombreDepartamento == NombreDepartamento && UsuarioAuxiliar -> NombreEmpresa == NombreEmpresa)
		{
			return UsuarioAuxiliar;
		}
		else
		{
			while(UsuarioAuxiliar != nullptr)
			{
				if(UsuarioAuxiliar -> NombreDepartamento == NombreDepartamento)
				{
					while(UsuarioAuxiliar != nullptr)
					{
						if(UsuarioAuxiliar -> NombreEmpresa == NombreEmpresa)
						{
							while(UsuarioAuxiliar != nullptr)
							{
								if(UsuarioAuxiliar -> NombreUsuario == NombreUsuario)
								{
									return UsuarioAuxiliar;
								}

								UsuarioAuxiliar = UsuarioAuxiliar -> Atr;

								if(UsuarioAuxiliar == nullptr)
								{
									return nullptr;
								}
							}
						}
						UsuarioAuxiliar = UsuarioAuxiliar -> Aba;

						if(UsuarioAuxiliar == nullptr)
						{
							return nullptr;
						}
					}
				}
				UsuarioAuxiliar = UsuarioAuxiliar -> Sgte;
			}
		}
		return nullptr;
	}

	//Insercion

		//Crear Cabecera Empresa

	bool InsertarCabeceraEmpresaMatrizDispersaU(MatrizDU &Matriz, string NombreEmpresa, MatrizDispersaEstructura& UsuarioAux, MatrizDispersaEstructura& EmpresaAux)
	{
		//Declaraciones
		MatrizDU UsuarioNuevoAuxiliar = &UsuarioAux;
		MatrizDU EmpresaNuevaAuxiliar = &EmpresaAux;
		MatrizDU AuxiliarEmpresa = Matriz;
		string Comparacion = "";

        //Insertar Cabecera De Tipo Empresa

		//UpperCase
		NombreEmpresa = UpperCase(NombreEmpresa);

		while(AuxiliarEmpresa != nullptr)
		{
			Comparacion = AuxiliarEmpresa -> NombreEmpresa;

			if(NombreEmpresa.compare(Comparacion) == 1)
			{
				if(AuxiliarEmpresa -> Aba != nullptr)
				{
					Comparacion = AuxiliarEmpresa -> Aba -> NombreEmpresa;

					if(NombreEmpresa.compare(Comparacion) == -1)
					{
						MatrizDU AuxiliarAbajo = AuxiliarEmpresa -> Aba;
						AuxiliarEmpresa -> Aba = EmpresaNuevaAuxiliar;
						AuxiliarAbajo -> Arr = EmpresaNuevaAuxiliar;
						EmpresaNuevaAuxiliar -> Arr = AuxiliarEmpresa;
						EmpresaNuevaAuxiliar -> Aba = AuxiliarAbajo;
						EmpresaNuevaAuxiliar -> Sgte = UsuarioNuevoAuxiliar;
						UsuarioNuevoAuxiliar -> Ante = EmpresaNuevaAuxiliar;
						return true;
					}
				}
				else
				{
					AuxiliarEmpresa -> Aba = EmpresaNuevaAuxiliar;
					EmpresaNuevaAuxiliar -> Arr = AuxiliarEmpresa;
					EmpresaNuevaAuxiliar -> Sgte = UsuarioNuevoAuxiliar;
					UsuarioNuevoAuxiliar -> Ante = EmpresaNuevaAuxiliar;
					return true;
				}
			}
			AuxiliarEmpresa = AuxiliarEmpresa -> Aba;
		}
		return false;
	}

		//Crear Cabecera Departamento

	bool InsertarCabeceraDepartamentoMatrizDispersaU(MatrizDU &Matriz, string NombreDepartamento, MatrizDispersaEstructura& UsuarioAux, MatrizDispersaEstructura& DepartamentoAux)
	{
		//Declaraciones
		MatrizDU UsuarioNuevoAuxiliar = &UsuarioAux;
		MatrizDU DepartamentoNuevoAuxiliar = &DepartamentoAux;
		MatrizDU AuxiliarDepartamento = Matriz;
		string Comparacion = "";

        //Insertar Cabecera De Tipo Departamento

		//UpperCase
		NombreDepartamento = UpperCase(NombreDepartamento);

		while(AuxiliarDepartamento != nullptr)
		{
			Comparacion = AuxiliarDepartamento -> NombreDepartamento;

			if(NombreDepartamento.compare(Comparacion) == 1)
			{
				if(AuxiliarDepartamento -> Sgte != nullptr)
				{
                    Comparacion = AuxiliarDepartamento -> Sgte -> NombreDepartamento;

					if(NombreDepartamento.compare(Comparacion) == -1)
					{
						MatrizDU AuxiliarSiguiente = AuxiliarDepartamento -> Sgte;
						AuxiliarDepartamento -> Sgte = DepartamentoNuevoAuxiliar;
						AuxiliarSiguiente -> Ante = DepartamentoNuevoAuxiliar;
						DepartamentoNuevoAuxiliar -> Ante = AuxiliarDepartamento;
						DepartamentoNuevoAuxiliar -> Sgte = AuxiliarSiguiente;
						DepartamentoNuevoAuxiliar -> Aba = UsuarioNuevoAuxiliar;
						UsuarioNuevoAuxiliar -> Arr = DepartamentoNuevoAuxiliar;
						return true;
					}
				}
				else
				{
					AuxiliarDepartamento -> Sgte = DepartamentoNuevoAuxiliar;
					DepartamentoNuevoAuxiliar -> Ante = AuxiliarDepartamento;
					DepartamentoNuevoAuxiliar -> Aba = UsuarioNuevoAuxiliar;
					UsuarioNuevoAuxiliar -> Arr = DepartamentoNuevoAuxiliar;
					return true;
				}
			}
			AuxiliarDepartamento = AuxiliarDepartamento -> Sgte;
		}
		return false;
	}

		//Comparar Y Elegir Caso De Inserci�n

	void ComparacionYEleccionCasosInsercionMatrizDispersaU(MatrizDispersaEstructura& UsuarioNuevo, MatrizDispersaEstructura& EmpresaNueva, MatrizDispersaEstructura& DepartamentoNuevo)
	{
		//Declaraciones
		MatrizDU DepartamentoAuxiliar = &DepartamentoNuevo;
		MatrizDU EmpresaAuxiliar = &EmpresaNueva;
		MatrizDU UsuarioAuxiliar = &UsuarioNuevo;
		string ComparacionE = "";
		string ComparacionE2 = "";
		string ComparacionD = "";
		string ComparacionD2 = "";


        //Comienza Comparaci�n Y Elecci�n

		//Comienzo En Empresa

		while(EmpresaAuxiliar != nullptr)
		{
			ComparacionE = UsuarioAuxiliar -> NombreDepartamento;
			ComparacionE2 = EmpresaAuxiliar -> NombreDepartamento;

			if(ComparacionE.compare(ComparacionE2) == 1)
			{
				if(EmpresaAuxiliar -> Sgte != nullptr)
				{
					ComparacionE = UsuarioAuxiliar -> NombreDepartamento;
					ComparacionE2 = EmpresaAuxiliar -> Sgte -> NombreDepartamento;

					if(ComparacionE.compare(ComparacionE2) == -1)
					{
						cout<< "Agregue Empresa ";
						MatrizDU AuxSiguiente = EmpresaAuxiliar -> Sgte;
						EmpresaAuxiliar -> Sgte = UsuarioAuxiliar;
						UsuarioAuxiliar -> Ante = EmpresaAuxiliar;
						AuxSiguiente -> Ante = UsuarioAuxiliar;
						UsuarioAuxiliar -> Sgte = AuxSiguiente;
						break;
					}
				}
				else
				{
                    cout<< "Agregue Empresa else ";
					EmpresaAuxiliar -> Sgte = UsuarioAuxiliar;
					UsuarioAuxiliar -> Ante = EmpresaAuxiliar;
					break;
				}
			}
			EmpresaAuxiliar = EmpresaAuxiliar -> Sgte;
		}

		//Comienzo En Departamento

		while(DepartamentoAuxiliar != nullptr)
		{
			ComparacionD = UsuarioAuxiliar -> NombreEmpresa;
			ComparacionD2 = DepartamentoAuxiliar -> NombreEmpresa;

			if(ComparacionD.compare(ComparacionD2) == 1)
			{
				if(DepartamentoAuxiliar -> Aba != nullptr)
				{
					ComparacionD = UsuarioAuxiliar -> NombreEmpresa;
					ComparacionD2 = DepartamentoAuxiliar -> Aba -> NombreEmpresa;

					if(ComparacionD.compare(ComparacionD2) == -1)
					{
						cout<< "Agregue Departamento ";
						MatrizDU AuxiliarAbajo = DepartamentoAuxiliar -> Aba;
						DepartamentoAuxiliar -> Aba = UsuarioAuxiliar;
						UsuarioAuxiliar -> Arr = DepartamentoAuxiliar;
						AuxiliarAbajo -> Arr = UsuarioAuxiliar;
						UsuarioAuxiliar -> Aba = AuxiliarAbajo;
						break;
					}
				}
				else
				{
                    cout<< "Agregue Departamento else ";
					DepartamentoAuxiliar -> Aba = UsuarioAuxiliar;
					UsuarioAuxiliar -> Arr = DepartamentoAuxiliar;
					break;
				}
			}
			DepartamentoAuxiliar = DepartamentoAuxiliar -> Aba;
		}
	}

		//Insertar Usuario

	bool InsertarUsuarioMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreCompleto, string Password, string NombreDepartamento, string NombreEmpresa)
	{
		//Declaraciones

		MatrizDU DepartamentoAuxiliar = Matriz;
		MatrizDU EmpresaAuxiliar = Matriz;
		MatrizDU UsuarioAuxiliarBusqueda;

		//UpperCase
		NombreEmpresa = UpperCase(NombreEmpresa);
		NombreDepartamento = UpperCase(NombreDepartamento);

        //Asignaciones

		UsuarioAuxiliarBusqueda = BuscarUsuarioAuxMatrizDispersaU(Matriz, NombreUsuario, NombreEmpresa, NombreDepartamento);

		//Comenzar Recorrer Matriz Dispersa

		if(UsuarioAuxiliarBusqueda == nullptr)
		{
			//Recorrer Departamentos

			while(DepartamentoAuxiliar != nullptr)
			{
				if(NombreDepartamento == DepartamentoAuxiliar -> NombreDepartamento)
				{
					break;
				}

				DepartamentoAuxiliar = DepartamentoAuxiliar -> Sgte;
			}

			//Recorrer Empresas

			while(EmpresaAuxiliar != nullptr)
			{
				if(NombreEmpresa == EmpresaAuxiliar -> NombreEmpresa)
				{
					break;
				}

				EmpresaAuxiliar = EmpresaAuxiliar -> Aba;
			}

			if(DepartamentoAuxiliar != nullptr && EmpresaAuxiliar != nullptr)
			{
				//Caso 1: Existen Ambas Cabecera

				cout<< "Caso 1";

				MatrizDU CabeceraDepartamento = DepartamentoAuxiliar;
				MatrizDU CabeceraEmpresa = EmpresaAuxiliar;

				while(DepartamentoAuxiliar != nullptr)
				{
					if(DepartamentoAuxiliar -> NombreDepartamento == NombreDepartamento && DepartamentoAuxiliar -> NombreEmpresa == NombreEmpresa)
					{
						while(DepartamentoAuxiliar != nullptr)
						{
							if(DepartamentoAuxiliar -> Atr == nullptr)
							{
								MatrizDU Auxiliar = new MatrizDispersaEstructura(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);
								DepartamentoAuxiliar -> Atr = Auxiliar;
								Auxiliar -> Adte = DepartamentoAuxiliar;
								return true;
							}

							DepartamentoAuxiliar = DepartamentoAuxiliar -> Atr;
						}
					}
					DepartamentoAuxiliar = DepartamentoAuxiliar -> Aba;
				}

				MatrizDU Auxiliar2 = new MatrizDispersaEstructura(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);
				ComparacionYEleccionCasosInsercionMatrizDispersaU(*Auxiliar2, *CabeceraEmpresa, *CabeceraDepartamento);
				return true;
			}
			else if(DepartamentoAuxiliar == nullptr && EmpresaAuxiliar == nullptr)
			{
				//Caso 2: No Existe Ninguna Cabecera

				cout<< "Caso 2";

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
			else if(DepartamentoAuxiliar != nullptr && EmpresaAuxiliar == nullptr)
			{
				//Caso 3: No Existe Empresa

				cout<< "Caso 3";

				MatrizDU EmpresaNueva = new MatrizDispersaEstructura("Emp", NombreEmpresa);
				MatrizDU UsuarioNuevo = new MatrizDispersaEstructura(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);
				InsertarCabeceraEmpresaMatrizDispersaU(Matriz, NombreEmpresa, *UsuarioNuevo, *EmpresaNueva);
				ComparacionYEleccionCasosInsercionMatrizDispersaU(*DepartamentoAuxiliar, *EmpresaNueva, *UsuarioNuevo);
				return true;
			}
			else if(DepartamentoAuxiliar == nullptr && EmpresaAuxiliar != nullptr)
			{
				//Caso 4: No Existe Departamento

				cout<< "Caso 4";

				MatrizDU DepartamentoNuevo = new MatrizDispersaEstructura("Dep", NombreDepartamento);
				MatrizDU UsuarioNuevo = new MatrizDispersaEstructura(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);
				InsertarCabeceraDepartamentoMatrizDispersaU(Matriz, NombreDepartamento, *UsuarioNuevo, *DepartamentoNuevo);
				ComparacionYEleccionCasosInsercionMatrizDispersaU(*DepartamentoNuevo, *EmpresaAuxiliar, *UsuarioNuevo);
				return true;
			}
		}
		else
		{
			return false;
		}
		return false;
	}


