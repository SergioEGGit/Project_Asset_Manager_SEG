//------------------------------------------------------------------------------

	#pragma hdrstop

//-----------------------------Librerias----------------------------------------

	#include "MatrizDispersaEstructura.h"
	#include "ArbolAVLEstructura.h"
	#include "Metodos.h"
	#include "Interfaz.h"
	#include "Variables.h"
	#include <iostream>
	#include <fstream>
	#include <string>
	#include <cstring>

	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos--------------------------------------

	//Mostrar

		//Mostar Todos Los Usuarios

	void MostrarUsuarios(MatrizDU &Matriz, int ContadorAltura)
	{
		//Declaracion

		//Objeto Tipo Matriz Dispersa

		MatrizDU MatrizAuxiliarUsuario = Matriz -> Aba;

		//Variables Tipo String

		int ContadorAuxiliar = 1;

		//Comienza Impresion

		while(MatrizAuxiliarUsuario != nullptr)
		{
			MatrizDU AuxiliarEmpresa = MatrizAuxiliarUsuario;

			while(MatrizAuxiliarUsuario != nullptr)
			{
				MatrizDU AuxiliarDepartamento = MatrizAuxiliarUsuario;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					MatrizDU AuxiliarUsuario = MatrizAuxiliarUsuario;

					if(MatrizAuxiliarUsuario -> NombreUsuario != "")
					{
						Color(0, 15);
						Posicionar(20, ContadorAltura);
						cout<< ContadorAuxiliar << "." << "Nombre: " << MatrizAuxiliarUsuario -> NombreUsuario << "  Empresa: " << MatrizAuxiliarUsuario -> NombreEmpresa << "  Departamento: " << MatrizAuxiliarUsuario -> NombreDepartamento <<endl;
						ContadorAltura = ContadorAltura - 2;
						ContadorAuxiliar++;
					}
					MatrizAuxiliarUsuario = AuxiliarUsuario -> Atr;
				}

				MatrizAuxiliarUsuario = AuxiliarDepartamento -> Sgte;
			}
			MatrizAuxiliarUsuario = AuxiliarEmpresa -> Aba;
		}
	}

		//Mostrar Todos Los Activos

	void MostrarActivosUsuarios(MatrizDU &Matriz, int ContadorAltura)
	{
		//Declaracion

		//Objeto Tipo Matriz Dispersa

		MatrizDU MatrizAuxiliarUsuario = Matriz -> Aba;

		//Variables Tipo String

		int ContadorAuxiliar = 1;

		//Comienza Impresion

		while(MatrizAuxiliarUsuario != nullptr)
		{
			MatrizDU AuxiliarEmpresa = MatrizAuxiliarUsuario;

			while(MatrizAuxiliarUsuario != nullptr)
			{
				MatrizDU AuxiliarDepartamento = MatrizAuxiliarUsuario;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					MatrizDU AuxiliarUsuario = MatrizAuxiliarUsuario;

					if(MatrizAuxiliarUsuario -> NombreUsuario != "")
					{
						if(MatrizAuxiliarUsuario -> NombreUsuario != Variables::UsuarioA)
						{
							Color(0, 11);
							Posicionar(17, 17);
							cout<< "            Todos Los Activos " <<endl;
							Posicionar(20, Variables::TodosLosActivos);
							cout<< ContadorAuxiliar << "." << "Nombre: " << MatrizAuxiliarUsuario -> NombreUsuario << "  Empresa: " << MatrizAuxiliarUsuario -> NombreEmpresa << "  Departamento: " << MatrizAuxiliarUsuario -> NombreDepartamento <<endl;
							Variables::TodosLosActivos = Variables::TodosLosActivos - 2;
							Variables::Color = 11;
							Variables::ContadorAux = 1;
							MostrarTodosLosActivosArbolAVLA(MatrizAuxiliarUsuario -> ArbolAVLActivosUsuario);
							ContadorAuxiliar++;
                        }
					}
					MatrizAuxiliarUsuario = AuxiliarUsuario -> Atr;
				}

				MatrizAuxiliarUsuario = AuxiliarDepartamento -> Sgte;
			}
			MatrizAuxiliarUsuario = AuxiliarEmpresa -> Aba;
		}
    }

	//Reportes

		//Reporte Activos Por Departamento

	void ReporteActivosPorDepartamentoMatrizDispersaU(MatrizDU &Matriz, string NombreDepartamento)
	{
		//Declaraciones
		ofstream SalidaArchivo("C:\\ReportesEDD\\ReporteActivosPorDepartamento.txt");
		MatrizDU MatrizAuxiliarUsuario = Matriz;
		string CadenaArboles = "";
		int Numero = 0;

		//UpperCase
		NombreDepartamento = UpperCase(NombreDepartamento);

		if(SalidaArchivo.is_open())
		{
			if(Matriz != nullptr)
			{
				//Apertura Archivo Y Comienza Escritura

				SalidaArchivo<< "digraph MatrizDispersa " <<endl;
				SalidaArchivo<< "{" <<endl;
				SalidaArchivo<< "graph[charset=latin1]" <<endl;
				SalidaArchivo<< "node[shape = box, style = rounded, color = midnightblue, fontcolor = darkgreen];" <<endl;
				SalidaArchivo<< "Departamento[ label =\"Departamento : " + NombreDepartamento + "\", width = 2];\n" <<endl;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					MatrizDU AuxiliarDepartamento = MatrizAuxiliarUsuario;

					if(NombreDepartamento == MatrizAuxiliarUsuario -> NombreDepartamento)
					{
						while(MatrizAuxiliarUsuario != nullptr)
						{
							MatrizDU AuxiliarEmpresa = MatrizAuxiliarUsuario;

							while(MatrizAuxiliarUsuario != nullptr)
							{
								MatrizDU AuxiliarUsuarios = MatrizAuxiliarUsuario;

								if(MatrizAuxiliarUsuario -> ArbolAVLActivosUsuario != nullptr)
								{
									Variables::ReporteArbol += MatrizAuxiliarUsuario -> NombreUsuario + "[ label =\"Usuario : " + MatrizAuxiliarUsuario -> NombreUsuario + "\", width = 2];\n";
									Variables::ReporteArbol += MatrizAuxiliarUsuario -> NombreUsuario + " -> NodoArbol" + to_string(Numero) + "0" + "\n\n";
									ReporteActivosDepartamentosArbolAVLA(MatrizAuxiliarUsuario -> ArbolAVLActivosUsuario, Numero);
									Numero++;
									Variables::ReporteArbol += "\n\n";
								}

								MatrizAuxiliarUsuario = AuxiliarUsuarios -> Atr;
							}

							MatrizAuxiliarUsuario = AuxiliarEmpresa -> Aba;
                        }
					}

					MatrizAuxiliarUsuario = AuxiliarDepartamento -> Sgte;
				}

				SalidaArchivo<< Variables::ReporteArbol << endl;
				SalidaArchivo<< "}" << endl;
				SalidaArchivo.close();

                //Generar Archivo Dot Para Graficar
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\ReportesEDD\\ReporteActivosPorDepartamento.txt -o C:\\ReportesEDD\\ReporteActivosPorDepartamento.png");
				//Abrir Imagen Con El Vizualizador de Imagenes
				system("C:\\ReportesEDD\\ReporteActivosPorDepartamento.png &" );
			}
		}
	}

		//Reporte Activos Por Empresa

	void ReporteActivosPorEmpresaMatrizDispersaU(MatrizDU &Matriz, string NombreEmpresa)
	{
		//Declaraciones
		ofstream SalidaArchivo("C:\\ReportesEDD\\ReporteActivosPorEmpresa.txt");
		MatrizDU MatrizAuxiliarUsuario = Matriz;
		string CadenaArboles = "";
		int Numero = 0;

        //UpperCase
		NombreEmpresa = UpperCase(NombreEmpresa);


		if(SalidaArchivo.is_open())
		{
			if(Matriz != nullptr)
			{
				//Apertura Archivo Y Comienza Escritura

				SalidaArchivo<< "digraph MatrizDispersa " <<endl;
				SalidaArchivo<< "{" <<endl;
				SalidaArchivo<< "graph[charset=latin1]" <<endl;
				SalidaArchivo<< "node[shape = box, style = rounded, color = midnightblue, fontcolor = darkgreen];" <<endl;
				SalidaArchivo<< "Empresa[ label =\"Empresa: " + NombreEmpresa + "\", width = 2];\n" <<endl;

				while(MatrizAuxiliarUsuario != nullptr)
				{
					MatrizDU AuxiliarDepartamento = MatrizAuxiliarUsuario;

					if(NombreEmpresa == MatrizAuxiliarUsuario -> NombreEmpresa)
					{
						while(MatrizAuxiliarUsuario != nullptr)
						{
							MatrizDU AuxiliarEmpresa = MatrizAuxiliarUsuario;

							while(MatrizAuxiliarUsuario != nullptr)
							{
								MatrizDU AuxiliarUsuarios = MatrizAuxiliarUsuario;

								if(MatrizAuxiliarUsuario -> ArbolAVLActivosUsuario != nullptr)
								{
									Variables::ReporteArbol += MatrizAuxiliarUsuario -> NombreUsuario + "[ label =\"Usuario : " + MatrizAuxiliarUsuario -> NombreUsuario + "\", width = 2];\n";
									Variables::ReporteArbol += MatrizAuxiliarUsuario -> NombreUsuario + " -> NodoArbol" + to_string(Numero) + "0" + "\n\n";
									ReporteActivosDepartamentosArbolAVLA(MatrizAuxiliarUsuario -> ArbolAVLActivosUsuario, Numero);
									Numero++;
									Variables::ReporteArbol += "\n\n";
								}

								MatrizAuxiliarUsuario = AuxiliarUsuarios -> Atr;
							}

							MatrizAuxiliarUsuario = AuxiliarEmpresa -> Sgte;
                        }
					}

					MatrizAuxiliarUsuario = AuxiliarDepartamento -> Aba;
				}

				SalidaArchivo<< Variables::ReporteArbol << endl;
				SalidaArchivo<< "}" << endl;
				SalidaArchivo.close();

				//Generar Archivo Dot Para Graficar
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\ReportesEDD\\ReporteActivosPorEmpresa.txt -o C:\\ReportesEDD\\ReporteActivosPorEmpresa.png");
				//Abrir Imagen Con El Vizualizador de Imagenes
				system("C:\\ReportesEDD\\ReporteActivosPorEmpresa.png &" );
			}
		}
	}

		//Reporte Matriz

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
						if(MatrizAuxiliarUsuario -> Atr != nullptr)
						{
							SalidaArchivo<< "NodoUsuario" << TrimCadena(MatrizAuxiliarUsuario -> NombreDepartamento) << TrimCadena(MatrizAuxiliarUsuario -> NombreEmpresa) << " [label = \" Usuario:" + MatrizAuxiliarUsuario -> NombreUsuario + "\\lNombre: " + MatrizAuxiliarUsuario -> NombreCompleto  + "\\l" + "Hay Mas Usuarios Atras" + "\", width = 2, color = steelblue, fontcolor = firebrick1, group = " + to_string(ContadorGrupos) + "];\n" <<endl;
						}
						else
						{
							SalidaArchivo<< "NodoUsuario" << TrimCadena(MatrizAuxiliarUsuario -> NombreDepartamento) << TrimCadena(MatrizAuxiliarUsuario -> NombreEmpresa) << " [label = \" Usuario:" + MatrizAuxiliarUsuario -> NombreUsuario + "\\lNombre: " + MatrizAuxiliarUsuario -> NombreCompleto + "\", width = 2, color = steelblue, fontcolor = firebrick1, group = " + to_string(ContadorGrupos) + "];\n" <<endl;
                        }

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

	//Inserci�n

		//Enlazar Cabecera Empresa

	void EnalazarEmpresaNueva(MatrizDU &Inicio, MatrizDU &CabEmp)
	{
		//Declaraciones

		//Objeto Tipo Matriz Dispersa

		MatrizDU AuxInicio = Inicio;

		//Variables Tipo String

		string Empresa = CabEmp -> NombreEmpresa;
		string AuxEmpresa = "";
		string AuxEmpresaAba = "";

		//Comienzo Recorrer Matriz

		while(AuxInicio != nullptr)
		{
			//Asignar Nombre Empresa

			AuxEmpresa = AuxInicio -> NombreEmpresa;

			//Inicio A Comparar

			if(Empresa.compare(AuxEmpresa) > 0)
			{
				//Comparaci�n Empresa

				//Es Mayor

				if(AuxInicio -> Aba == nullptr)
				{
					//Enlazar Cabecera Empresa

					AuxInicio -> Aba = CabEmp;
					CabEmp -> Arr = AuxInicio;
					break;
				}
				else
				{
					//Enalazar Cabecera Empresa

					AuxEmpresaAba = AuxInicio -> Aba -> NombreEmpresa;

					if(Empresa.compare(AuxEmpresaAba) < 0)
					{
						//Comparaci�n Empresa

						//Es Menor

						MatrizDU Aba = AuxInicio -> Aba;
						AuxInicio -> Aba = CabEmp;
						CabEmp -> Arr = AuxInicio;
						Aba -> Arr = CabEmp;
						CabEmp -> Aba = Aba;
						break;
					}
				}
			}
			AuxInicio = AuxInicio -> Aba;
		}
	}

		//Enlazar Cabecera Departamento

	void EnalazarDepartamentoNuevo(MatrizDU &Inicio, MatrizDU &CabDep)
	{
		//Declaraciones

		//Obejto Tipo Matriz Dispersa

		MatrizDU AuxInicio = Inicio;

		//Variables Tipo String

		string Departamento = CabDep -> NombreDepartamento;
		string AuxDepartamento = "";
		string AuxDepartamentoSgte = "";

		//Comienzo Recorrer Matriz

		while(AuxInicio != nullptr)
		{
			//Asignacion Nombre Departamento

			AuxDepartamento = AuxInicio -> NombreDepartamento;

			//Comparacion

			if(Departamento.compare(AuxDepartamento) > 0)
			{
				//Comparaci�n Departamento

				//Es Mayor

				if(AuxInicio -> Sgte == nullptr)
				{
					//Enlazar Cabecera Departamento

					AuxInicio -> Sgte = CabDep;
					CabDep -> Ante = AuxInicio;
					break;
				}
				else
				{
					//Enlazar Cabecera Departamento

					AuxDepartamentoSgte = AuxInicio -> Sgte -> NombreDepartamento;

					if(Departamento.compare(AuxDepartamentoSgte) < 0)
					{
						//Comparaci�n Departamento

						//Es Menor

						MatrizDU Sgte = AuxInicio -> Sgte;
						AuxInicio -> Sgte = CabDep;
						CabDep -> Ante = AuxInicio;
						Sgte -> Ante = CabDep;
						CabDep -> Sgte = Sgte;
						break;
					}
				}
			}
			AuxInicio = AuxInicio -> Sgte;
		}
	}

	//Comparaci�n Y Elecci�n Casos De Inserci�n

	void CasosInsercion(MatrizDU &CabDep, MatrizDU &CabEmp, MatrizDU &Usuario, MatrizDU &Inicio)
	{
		//Declaracioens

		bool HacerEmpresa=false;
		bool HacerDepartamento=false;
		MatrizDU Auxiliar=Inicio;

		//El Departamento no existia y la empresa si

		if(CabDep -> Aba == nullptr)
		{
			CabDep -> Aba = Usuario;
			Usuario -> Arr = CabDep;
			HacerEmpresa = true;
			//revisar entre que nodos de empresa hay que insertar el nuevo
		}

		//La Empresa No Existia pero el departamento si

		if(CabEmp -> Sgte == nullptr)
		{
			CabEmp -> Sgte = Usuario;
			Usuario -> Ante = CabEmp;
			HacerDepartamento = true;
		}

		if(HacerEmpresa == true && HacerDepartamento == true)
		{
			//no hace nada
		}
		else if(HacerEmpresa != true && HacerDepartamento == true)
		{
			//Tengo que enlazar con la empresa
			MatrizDU Aux_Dep = CabDep;
			string DepS_User = Usuario -> NombreEmpresa;
			string DepS_Aux = "";
			string DepS_Aux_Aba = "";

			while(Aux_Dep != nullptr)
			{
				DepS_Aux = Aux_Dep -> NombreEmpresa;

				if(DepS_User.compare(DepS_Aux) > 0)
				{
					//Adelante de Aux_Emp hay que insertar pero falta un If

					if(Aux_Dep -> Aba != nullptr)
					{
						DepS_Aux_Aba = Aux_Dep -> Aba -> NombreEmpresa;

						if(DepS_User.compare(DepS_Aux_Aba) < 0)
						{
							MatrizDU Aba=Aux_Dep->Aba;
							Aux_Dep -> Aba = Usuario;
							Usuario -> Arr = Aux_Dep;
							Aba -> Arr = Usuario;
							Usuario -> Aba = Aba;
							break;
						}
					}
					else
					{
						Aux_Dep -> Aba = Usuario;
						Usuario -> Arr = Aux_Dep;
						break;
					}
				}
				Aux_Dep = Aux_Dep -> Aba;
			}

		}
		else if(HacerEmpresa == true && HacerDepartamento != true)
		{
			MatrizDU Aux_Emp = CabEmp;
			string EmpS_User = Usuario -> NombreDepartamento;
			string EmpS_Aux = "";
			string EmpS_Aux_Sgte = "";

			while(Aux_Emp != nullptr)
			{
				EmpS_Aux = Aux_Emp -> NombreDepartamento;

				if(EmpS_User.compare(EmpS_Aux) > 0)
				{
					//Adelante de Aux_Emp hay que insertar pero falta un If

					if(Aux_Emp->Sgte != nullptr)
					{
						EmpS_Aux_Sgte = Aux_Emp -> Sgte -> NombreDepartamento;

						if(EmpS_User.compare(EmpS_Aux_Sgte) < 0)
						{
							MatrizDU SIG=Aux_Emp->Sgte;
							Aux_Emp -> Sgte = Usuario;
							Usuario -> Ante = Aux_Emp;
							SIG -> Ante = Usuario;
							Usuario -> Sgte = SIG;
							break;
						}
					}
					else
					{
						Aux_Emp -> Sgte = Usuario;
						Usuario -> Ante = Aux_Emp;
						break;
					}
				}
				Aux_Emp = Aux_Emp -> Sgte;
			}
		}
		else if(HacerEmpresa != true && HacerDepartamento != true)
		{
			//Aqui Tengo que insertar
			MatrizDU AuxDep = CabDep;
			MatrizDU AuxEmp = CabEmp;
			bool SeHizo = false;

			while(AuxDep != nullptr)
			{
				if(AuxEmp -> NombreEmpresa.compare(AuxDep -> NombreEmpresa) == 0)
				{
					MatrizDU Aux2 = AuxDep;

					while(Aux2 != nullptr)
					{
						if(Aux2 -> Atr == nullptr)
						{
							Aux2 -> Atr = Usuario;
							Usuario -> Adte = Aux2;
							SeHizo = true;
							break;
						}
						Aux2 = Aux2 -> Atr;
					}
				}
				AuxDep = AuxDep -> Aba;
			}
			if(SeHizo==false)
			{
				//Voy a Mover la cebecera en lugar de hacer una variable
				string AuxS_Dep=Usuario->NombreEmpresa;
				string AuxS_Dep_Evaluar="",AuxS_Dep_Sig="";
				while(CabDep!=nullptr){
					AuxS_Dep_Evaluar= CabDep->NombreEmpresa;
					if(AuxS_Dep.compare(AuxS_Dep_Evaluar)>0){
						if(CabDep->Aba==nullptr){
							CabDep->Aba=Usuario;
							Usuario->Arr=CabDep;
							break;
						}
						else{
							AuxS_Dep_Sig=CabDep->Aba->NombreEmpresa;
							if(AuxS_Dep.compare(AuxS_Dep_Sig)<0){
								MatrizDU ABA=CabDep->Aba;
								CabDep->Aba=Usuario;
								Usuario->Arr=CabDep;
								ABA->Arr=Usuario;
								Usuario->Aba=ABA;
								break;
							}
						}
					}
					CabDep=CabDep->Aba;
				}

				//Empresa
				string AuxS_Emp=Usuario->NombreDepartamento;
				string AuxS_Emp_Evaluar="",AuxS_Emp_Sig="";
				while(CabEmp!=nullptr){
					AuxS_Emp_Evaluar= CabEmp->NombreDepartamento;
					if(AuxS_Emp.compare(AuxS_Emp_Evaluar)>0){
						if(CabEmp->Sgte==nullptr){
							CabEmp->Sgte=Usuario;
							Usuario->Ante=CabEmp;
							break;
						}
						else{
							AuxS_Emp_Sig=CabEmp->Sgte->NombreDepartamento;
							if(AuxS_Emp.compare(AuxS_Emp_Sig)<0){
								MatrizDU SGTE=CabEmp->Sgte;
								CabEmp->Sgte=Usuario;
								Usuario->Ante=CabEmp;
								SGTE->Ante=Usuario;
								Usuario->Sgte=SGTE;
								break;
							}
						}
					}
					CabEmp=CabEmp->Sgte;
				}

			}
		}
	}

		//Insertar Nuevo Usuario

	void AgregarUsuario(string NombreCompleto_Usuario, string Nombre_Usuario, string Contrasena_Usuario, string Departamento_Usuario, string Empresa_Usuario, MatrizDU &Matriz)
	{
		//Declaraciones

		//Objeto Tipo Matriz Dispersa

		MatrizDU Inicio = Matriz;
		MatrizDU CabDep = Inicio;
		MatrizDU CabEmp = Inicio;

		//Variables Tipo String

		string Aux = "";

        //UpperCase
		Departamento_Usuario = UpperCase(Departamento_Usuario);
		Empresa_Usuario = UpperCase(Empresa_Usuario);

		//Buscar Cabecera Departamento

		while(CabDep!=nullptr)
		{
			Aux = CabDep -> NombreDepartamento;

			if(Aux.compare(Departamento_Usuario) == 0)
			{
				break;
			}

			CabDep = CabDep -> Sgte;
		}

		//Buscar Cabecera Empresa

		while(CabEmp != nullptr)
		{
			Aux = CabEmp -> NombreEmpresa;

			if(Aux.compare(Empresa_Usuario) == 0)
			{
				break;
			}

			CabEmp = CabEmp -> Aba;
		}

		//Crear Cabecera Departamento

		if(CabDep == nullptr)
		{
			CabDep = new MatrizDispersaEstructura("Dep", Departamento_Usuario);
			EnalazarDepartamentoNuevo(Inicio,CabDep);
		}

		//Crear Cabecera Empresa

		if(CabEmp == nullptr)
		{
			CabEmp = new MatrizDispersaEstructura("Emp", Empresa_Usuario);
			EnalazarEmpresaNueva(Inicio,CabEmp);
		}

		//Crear Usuario

		MatrizDU Usuario = new MatrizDispersaEstructura(NombreCompleto_Usuario, Nombre_Usuario, Contrasena_Usuario, Empresa_Usuario, Departamento_Usuario);

		//Verificar Casos Inserci�n

		CasosInsercion(CabDep, CabEmp, Usuario, Inicio);
	}

	//B�squeda

		//Buscar Una Usuario

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

		//Buscar Arbol Usuario

	void BuscarArbolUsuarioMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreEmpresa, string NombreDepartamento)
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
									Variables::AuxiliarArbol = Auxiliar;
									break;
								}
								Auxiliar = Auxiliar -> Atr;
							}
						}
						else
						{
							Variables::AuxiliarArbol = Auxiliar;
						}
						break;
					}
					Auxiliar = Auxiliar -> Aba;
				}
				break;
			}
			Auxiliar = Auxiliar -> Sgte;
		}
	}

