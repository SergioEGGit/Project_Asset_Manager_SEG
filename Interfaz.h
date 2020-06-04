//------------------------------------------------------------------------------

	#ifndef InterfazH
	#define InterfazH

//------------------------------Variables---------------------------------------

	namespace VariablesInterfaz
	{
		extern int AnchoPantalla;
		extern int AltoPantalla;
	}

//-------------------------------Métodos----------------------------------------

	void Color(int Fondo, int Color);

	void Fullscreen();

	void Resolucion();

	void Posicionar(int x, int y);

	void MenuLogin();

	void Marco(int Col1, int Col2, int Fil1, int Fil2);

//------------------------------------------------------------------------------

	#endif
