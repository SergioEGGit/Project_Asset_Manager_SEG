//------------------------------------------------------------------------------

	#ifndef InterfazH
	#define InterfazH

//------------------------------Variables---------------------------------------

	namespace VariablesInterfaz
	{
		extern int AnchoPantalla;
		extern int AltoPantalla;
	}

//-------------------------------M�todos----------------------------------------

	void Color(int Fondo, int Color);

	void Fullscreen();

	void Resolucion();

	void Posicionar(int x, int y);

	void MenuLogin();

	void MenuAdministrador();

    void MenuUsuario();

	void MenuRegistrarUsuario();

	void MenuCrearActivo();

	void MenuEliminarActivo();

	void MenuEliminado();

    void MenuReporteActivoPorUsuario();

	void Marco(int Col1, int Col2, int Fil1, int Fil2);

//------------------------------------------------------------------------------

	#endif
