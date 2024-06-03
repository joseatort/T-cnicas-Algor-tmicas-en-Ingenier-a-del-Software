#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Grafo.h"

using namespace std;

class CaminosDFS {
private:
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?

	Grafo const G;

	vector<int> tam_componente;
	vector<int> identificador_componente;

	int vertices_vistados;

	int dfs(Grafo const& G, int v, int componente) {
		visit[v] = true;
		vertices_vistados++;

		identificador_componente[v] = componente;
		for (int w : G.ady(v))
		{
			if (!visit[w])
				vertices_vistados = dfs(G, w, componente);
		}

		return vertices_vistados;
	}

public:
	CaminosDFS(Grafo const& g) : G(g), visit(g.V(), false) , identificador_componente(g.V(), -1)
	{
		int componente = 0;
		for (int i = 0; i < g.V(); i++)
		{
			vertices_vistados = 0;

			if (!visit[i])
			{
				tam_componente.push_back(dfs(G, i, componente));
				componente++;
			}			
		}

	}

	int num_amigos(int o) 
	{
		return tam_componente[identificador_componente[o]];
	}
};

#endif /* PROBLEMA_H_*/