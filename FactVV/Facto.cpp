#include "Facto.h"

int Facto::FactI(int val)
{
	int resultado = 1; // esto esta mal

	for (int i = val; i > 1; i--)
	{
		resultado *= i;
	}

	return resultado;

}

int Facto::FactR(int val)
{
	//la recursion por definicion debe tener un caso base, o donde debe terminar

	if (val == 1)
		return 1;

	// y si no, entonces se debe llamar a si mismo
	else
		return val * Facto::FactR(val - 1);
	
	


}
