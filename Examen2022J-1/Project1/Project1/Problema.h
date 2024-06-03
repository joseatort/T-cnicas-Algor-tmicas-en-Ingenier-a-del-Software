#ifndef Problema_H
#define Problema_H

#include <iostream>
#include <vector>
using namespace std;

#include "Grafo.h"

class CaminosDFS {
private:

	vector<bool> visit;
	int coste_total;
	vector<int> Sobornos;

	int dfs(Grafo const& G, int v) 
	{
		int coste = Sobornos[v];
		visit[v] = true;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				coste = min(coste, dfs(G, w));
			}
		}

		return coste;
	}

public:
	CaminosDFS(Grafo const& g, vector<int> &sobornos) : visit(g.V(), false), coste_total(0), Sobornos(sobornos)
	{
		for (int i = 0; i < g.V(); i++)
			if(!visit[i])
				coste_total += dfs(g, i);
			
	}

	int get_coste()
	{
		return coste_total;
	}
};

#endif // !Problema_H