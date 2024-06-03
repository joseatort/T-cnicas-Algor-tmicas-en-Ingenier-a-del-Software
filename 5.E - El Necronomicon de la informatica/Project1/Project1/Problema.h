#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <iostream>
#include <stdexcept>
#include <vector>

#include "DiGrafo.h"
using namespace std;

class Operaciones
{
private:

	vector<bool> visit;
	vector<bool> apilado;
	bool llega_fin;
	int ciclos;


	void dfs(Digrafo const& g, int v) {
		visit[v] = true;
		apilado[v] = true;
		/*
		* 
		* 		Hemos cambiado el for each predeterminado, a este for con el fin de que sea mas optimo
		*		y que cuando llega al final y ya existe un ciclo, no siga porque aunque haya mas ciclos 
		*		el resultado seguira siendo el mismo
		* 
		*/


		for (int i = 0; i < g.ady(v).size() && (ciclos < 1 || !llega_fin); i++)
		{
			int w = g.ady(v)[i];

			if (apilado[w])
				ciclos++;

			if (!visit[w])
			{
				if (w == g.V() - 1)
					llega_fin = true;

				dfs(g, w);
			}
		}

		apilado[v] = false;
	}

public:

	Operaciones(Digrafo const& dg) : visit(dg.V(), false), apilado(dg.V(), false), llega_fin(false), ciclos(0)
	{
		dfs(dg, 0);
	}

	string solucion()
	{

		if (!llega_fin)
			return "NUNCA";
		else if (llega_fin && ciclos == 0)
			return "SIEMPRE";
		else
			return "A VECES";
	}

};


#endif // PROBLEMA_H
