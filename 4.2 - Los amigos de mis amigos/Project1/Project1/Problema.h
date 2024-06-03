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
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	int s; // vértice origen

	int vertices_vistados = 0;

	int max_amigos = 0;



	int dfs(Grafo const& G, int v) {
		visit[v] = true;
		vertices_vistados++;

		for (int w : G.ady(v))
		{
			if (!visit[w])
			{
				ant[w] = v;
				vertices_vistados = dfs(G, w);
			}
		}

		return vertices_vistados;
	}
	
	int amigos(Grafo const& G)
	{
		int maximo = 0; 
		for (int i = 0; i < G.V(); i++)
		{
			if (!visit[i])
			{
				maximo = max(dfs(G, i), maximo);
				vertices_vistados = 0;
			}
		}

		return maximo;
	}


public:
	CaminosDFS(Grafo const& g, int s) : visit(g.V(), false),
		ant(g.V()), s(s) {
		max_amigos = amigos(g);
	}
	
	int num_amigos() const {
		return max_amigos;
	}
};

#endif /* PROBLEMA_H_*/