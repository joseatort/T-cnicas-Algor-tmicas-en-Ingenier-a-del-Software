#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "Grafo.h"

class CaminosDFS {
private:
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	int s; // vértice origen

	bool libre = false;
	int vertices_vistados = 0;

	bool dfs(Grafo const& G, int v) {
		visit[v] = true;
		vertices_vistados++;

		bool l = true;
		int cont = 0;

		while (l && cont < G.ady(v).size())
		{
			if (visit[G.ady(v)[cont]] && ant[v] != G.ady(v)[cont])
				l = false;
			else if (!visit[G.ady(v)[cont]])
			{
				ant[G.ady(v)[cont]] = v;
				l = dfs(G, G.ady(v)[cont]);
			}
			cont++;
		}
		return l;
	}
	
public:
	CaminosDFS(Grafo const& g, int s) : visit(g.V(), false),
		ant(g.V()), s(s) {
		libre = dfs(g, s) && vertices_vistados == g.V();
	}
	
	bool es_libre() const {
		return libre;
	}
};

#endif /* GRAFO_H_*/