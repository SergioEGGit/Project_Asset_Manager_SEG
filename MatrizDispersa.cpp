//------------------------------------------------------------------------------

	#pragma hdrstop

//-----------------------------Librerias----------------------------------------

	#include "MatrizDispersa.h"
	#include "Variables.h"
	#include <iostream>
	#include <fstream>
	#include <string>
	#include <cstring>

	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos--------------------------------------

	bool InsertarCabeceraEmpresaMatrizDispersaU(MatrizDU &Matriz, string NombreEmpresa, MatrizDispersa& UsuarioAux, MatrizDispersa& EmpresaAux)
	{
		MatrizDU UsuarioNuevoAux = &UsuarioAux;
		MatrizDU EmpresaNuevaAux = &EmpresaAux;
		MatrizDU NuevaEmpresa = Variables::MatrizDispersaUsuarios;

		while(NuevaEmpresa != NULL)
		{
			if(NuevaEmpresa -> Aba != NULL)
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

	bool InsertarCabeceraDepartamentoMatrizDispersaU(MatrizDU &Matriz, string NombreDepartamento, MatrizDispersa& UsuarioAux, MatrizDispersa& DepartamentoAux)
	{
		MatrizDU UsuarioNuevoAux = &UsuarioAux;
		MatrizDU DepartamentoNuevoAux = &DepartamentoAux;
		MatrizDU NuevoDepartamento = Matriz;

		while(NuevoDepartamento != nullptr)
		{
			if(NuevoDepartamento -> Sgte != NULL)
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
		MatrizDU AuxDepartamento = Matriz;
		MatrizDU AuxEmpresa = Matriz;

		//Recorrer Cabeceras

		while(AuxDepartamento != NULL)
		{
			if(AuxDepartamento -> NombreDepartamento == NombreDepartamento)
			{
				break;
			}
			AuxDepartamento = AuxDepartamento -> Sgte;
		}

		while(AuxEmpresa != NULL)
		{
			if(AuxEmpresa -> NombreEmpresa == NombreEmpresa)
			{
				break;
			}
			AuxEmpresa = AuxEmpresa -> Aba;
		}

		if(AuxDepartamento != NULL && AuxEmpresa != NULL)
		{
			//Ya Existen Cabeceras
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
							MatrizDU UsuarioNuevo = new MatrizDispersa(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);
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
			//No Existen Cabeceras
			MatrizDU DepartamentoNuevo = new MatrizDispersa("Dep", NombreDepartamento);
			MatrizDU EmpresaNueva = new MatrizDispersa("Emp", NombreEmpresa);
			MatrizDU UsuarioNuevo = new MatrizDispersa(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);

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
			//No Existe Empresa
			MatrizDU EmpresaNueva = new MatrizDispersa("Emp", NombreEmpresa);
			MatrizDU UsuarioNuevo = new MatrizDispersa(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);
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
			//No Existe Departamento
			MatrizDU DepartamentoNuevo = new MatrizDispersa("Dep", NombreDepartamento);
			MatrizDU UsuarioNuevo = new MatrizDispersa(NombreCompleto, NombreUsuario, Password, NombreEmpresa, NombreDepartamento);
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

	bool BuscarMatrizDispersaU(MatrizDU &Matriz, string NombreUsuario, string NombreEmpresa, string NombreDepartamento)
	{
		MatrizDU Auxiliar = Matriz;
		bool Bandera = false;

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

	void ReporteMatrizDispersaU(MatrizDU &Matriz)
	{
		ofstream SalidaArchivo("C:\\ReportesEDD\\ReporteMatrizDispersaUsuarios.txt");

		int ContadorGrupo = 2;

		if(SalidaArchivo.is_open())
		{
			if(Matriz != nullptr)
			{
				MatrizDispersa *EmpresasCabeceras = Matriz -> Aba;
				MatrizDispersa *DepartamentosCabeceras = Matriz -> Sgte;
				MatrizDispersa *AuxFila = Matriz -> Aba;
				MatrizDispersa *AuxColumna = Matriz -> Sgte;
				MatrizDispersa *Aux;
				string ArrayGrupos[50][2];

				SalidaArchivo<< "digraph G {" << endl;
				SalidaArchivo<< "graph [charset=latin1]" <<endl;
				SalidaArchivo<< "node [shape = box]" << endl;
				SalidaArchivo<< "MatrizEstructura[ label = \"Matriz Dispersa: \\l Usuarios\", width = 1.5, font = \"Times New Roman\", fontcolor = darkslategray, style = filled, fillcolor = cadetblue1, group = 1 ];" << endl;

				while(EmpresasCabeceras != nullptr)
				{
					SalidaArchivo<< "Emp" << EmpresasCabeceras -> NombreEmpresa;
					SalidaArchivo<< "[label = \"" << EmpresasCabeceras -> NombreEmpresa << "\"";
					SalidaArchivo<< "width = 1.5, style = filled, fillcolor = darkslategray1, fontcolor = firebrick1, group = 1 ];" << endl;
					EmpresasCabeceras = EmpresasCabeceras -> Aba;
				}

				EmpresasCabeceras = Matriz -> Aba;

				while(EmpresasCabeceras -> Aba != nullptr)
				{
					SalidaArchivo<< "Emp" << EmpresasCabeceras -> NombreEmpresa << "-> Emp" << EmpresasCabeceras -> Aba -> NombreEmpresa << ";" << endl;
					EmpresasCabeceras = EmpresasCabeceras -> Aba;
				}

				int ContadorArray = 0;

				while(DepartamentosCabeceras != nullptr)
				{
					SalidaArchivo<< "Dep" << DepartamentosCabeceras -> NombreDepartamento;
					SalidaArchivo<< "[label = \"" << DepartamentosCabeceras -> NombreDepartamento << "\"";
					SalidaArchivo<< "width = 1.5, style = filled, fillcolor = \"#9DFF20\", fontcolor = \"#0131D3\", group =" << ContadorGrupo << "];" << endl;
					ArrayGrupos[ContadorArray][0] = DepartamentosCabeceras -> NombreDepartamento;
					ArrayGrupos[ContadorArray][1] = to_string(ContadorGrupo);
					DepartamentosCabeceras = DepartamentosCabeceras -> Sgte;
					ContadorGrupo++;
					ContadorArray++;
				}

				DepartamentosCabeceras = Matriz -> Sgte;

				while(DepartamentosCabeceras -> Sgte != nullptr)
				{
					SalidaArchivo<< "Dep" << DepartamentosCabeceras -> NombreDepartamento << "-> Dep" << DepartamentosCabeceras -> Sgte -> NombreDepartamento << ";" << endl;
					DepartamentosCabeceras = DepartamentosCabeceras -> Sgte;
				}

				SalidaArchivo<< "MatrizEstructura -> Emp" << Matriz -> Aba -> NombreEmpresa << ";" << endl;
				SalidaArchivo<< "MatrizEstructura -> Dep" << Matriz -> Sgte -> NombreDepartamento << ";" << endl;

				SalidaArchivo << "{ rank = same; MatrizEstructura;";
				DepartamentosCabeceras = Matriz -> Sgte;

				while(DepartamentosCabeceras != nullptr)
				{
					SalidaArchivo<< "Dep" << DepartamentosCabeceras -> NombreDepartamento << ";";
					DepartamentosCabeceras = DepartamentosCabeceras -> Sgte;
				}

				SalidaArchivo<< "}" << endl;

				string ContadorArrayS = "";

				while(AuxFila != nullptr)
				{
					Aux = AuxFila -> Sgte;

					while(Aux != nullptr)
					{
						SalidaArchivo<< "Dep" << Aux -> NombreDepartamento;
						SalidaArchivo<< "Emp" << Aux -> NombreEmpresa;
						SalidaArchivo<< " [label = \"" << Aux -> NombreUsuario << "\" width = 1.5,";

						for(int i = 0; i < 50; i++)
						{
							if(Aux -> NombreDepartamento == ArrayGrupos[i][0])
							{
								ContadorArrayS = ArrayGrupos[i][1];
                            }
						}

						SalidaArchivo<< " group = " << atoi(ContadorArrayS.c_str()) << "];" << endl;
						Aux = Aux -> Sgte;
					}
					AuxFila = AuxFila  -> Aba;
				}

				AuxFila = Matriz -> Aba;

				while(AuxFila != nullptr)
				{
					Aux = AuxFila;

					while(Aux -> Sgte != nullptr)
					{
						if(Aux -> NombreDepartamento == "")
						{
							SalidaArchivo<< "Emp" << Aux -> NombreEmpresa;
						}
						else
						{
							SalidaArchivo<< "Dep" << Aux -> NombreDepartamento;
							SalidaArchivo<< "Emp" << Aux -> NombreEmpresa;
						}
						SalidaArchivo<< " -> Dep" << Aux -> Sgte -> NombreDepartamento;
						SalidaArchivo<< "Emp" << Aux -> Sgte -> NombreEmpresa << " [dir=\"both\"];" << endl;
						Aux = Aux -> Sgte;
					}

					SalidaArchivo<< "{ rank = same; ";
					Aux = AuxFila;

					while(Aux != nullptr)
					{
						if(Aux -> NombreDepartamento == "")
						{
							SalidaArchivo<< " Emp" << Aux -> NombreEmpresa << ";";
						}
						else
						{
							SalidaArchivo<< " Dep" << Aux -> NombreDepartamento;
							SalidaArchivo<< "Emp" << Aux -> NombreEmpresa << ";";
						}
						Aux = Aux -> Sgte;
					}
					SalidaArchivo<< "}" << endl;
					AuxFila = AuxFila -> Aba;
				}

                while(AuxColumna != nullptr)
				{
					Aux = AuxColumna;

					while(Aux -> Aba != nullptr)
					{
						if(Aux -> NombreEmpresa == "")
						{
							SalidaArchivo<< "Dep" << Aux -> NombreDepartamento;
						}
						else
						{
							SalidaArchivo<< "Dep" << Aux -> NombreDepartamento;
							SalidaArchivo<< "Emp" << Aux -> NombreEmpresa;
						}
						SalidaArchivo<< " -> Dep" << Aux -> Aba -> NombreDepartamento;
						SalidaArchivo<< "Emp" << Aux -> Aba -> NombreEmpresa << " [dir=\"both\"];" << endl;
						Aux = Aux -> Aba;
					}
					AuxColumna = AuxColumna -> Sgte;
				}


				SalidaArchivo<< "}" << endl;
				SalidaArchivo.close();

                //Generar Imagen
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\ReportesEDD\\ReporteMatrizDispersaUsuarios.txt -o C:\\ReportesEDD\\ReporteMatrizDispersaUsuarios.png");
				//Abrir Imagen
				system("C:\\ReportesEDD\\ReporteMatrizDispersaUsuarios.png &" );
			}
			else
			{
				cout << "No Se Puede Abrir El Archivo";
			}
		}
	}

