#ifndef PROBLEMA_H_
#define PROBLEMA_H_


#include <iostream>
#include <fstream>
#include <vector>

#include "GrafoValorado.h"

using namespace std;

class Camiones
{
private:

	GrafoValorado<int> G;
	vector<bool> visit;

	bool encontrado;

	void dfs(int v, int destino, int anchura) {

		visit[v] = true;
		for (auto a : G.ady(v)) {
			if (a.valor() >= anchura && !encontrado) {
				int w = a.otro(v);

				if (w == destino)
					encontrado = true;
				else if (!visit[w])
					dfs(w, destino, anchura);
			}
		}
	}



public:

	Camiones(GrafoValorado<int> const & gv) : G(gv), visit(G.V(), false), encontrado(false) {}

	bool consulta(int inicio, int fin, int tam_camion)
	{
		fill(visit.begin(), visit.end(), false);
		encontrado = false;
		dfs(inicio, fin, tam_camion);

		return encontrado;
	}


};





#endif // PROBLEMA_H_
