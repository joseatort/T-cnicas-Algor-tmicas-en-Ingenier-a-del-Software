#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <stdexcept>

#include "Grafo.h"

using namespace std;

class Minimo {
private:
	vector<bool> visit;
	vector<int> oro;
	int coste;

	int dfs(Grafo const& G, int v) {
		visit[v] = true;
		int minimo = oro[v];
		for (int w : G.ady(v))
			if (!visit[w])
				minimo = min(dfs(G, w), minimo);

		return minimo;
	}
public:
		
		Minimo(Grafo const& g, vector<int>& oro) : visit(g.V(), false), coste(0), oro(oro)
		{
			for (int i = 0; i < g.V(); i++)
				if (!visit[i])
					coste += dfs(g, i);
			
		}

		int getcoste()
		{
			return coste;
		}
		
};

#endif //!PROBLEMA_H_