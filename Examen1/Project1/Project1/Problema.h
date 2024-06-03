#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <vector>
#include <iostream>
#include "Grafo.h"
using namespace std;

class ArbolLibre {
private:
	vector<bool> visit;
	bool ab;
	int s;
	void dfs(Grafo const& G, int v) {
		visit[v] = true;
		int cont = 0;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				dfs(G, w);
			}
			else
				cont++;

			if(cont >= 2)
				ab = false;
			
		}
	}
public:
	ArbolLibre(Grafo const& g, int s) : visit(g.V(), false), ab(true)
	{
		dfs(g, s);
	}

	bool getab()
	{
		return ab;
	}
};

#endif // !PROBLEMA_H
