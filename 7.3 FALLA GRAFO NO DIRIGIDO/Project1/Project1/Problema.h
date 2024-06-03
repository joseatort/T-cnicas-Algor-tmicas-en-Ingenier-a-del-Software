#ifndef PROBLEMA_H_
#define PROBLEMA_H_


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>

#include "GrafoValorado.h"

using namespace std;

template <typename Valor>
class MinimoCamino
{
private:

	Valor minimo_def;

	vector<bool> visit;

	GrafoValorado<Valor> G;

	void dfs(int v, int fin, int valor)
	{
		for (auto a : G.ady(v)) {

			visit[v] = true;

			if (valor + a.valor() < minimo_def) {
				int w = a.otro(v);
				if (w == fin)
					minimo_def = min(valor + a.valor(), minimo_def);
				else if (!visit[w])
					dfs(w, fin, valor + a.valor());
			}
		}
		visit[v] = false;
	}

public:

	MinimoCamino(GrafoValorado<Valor> const& g) : G(g), visit(g.V(), false) {}

	int getdistancia(int v, int w)
	{
		minimo_def = INT_MAX;
		fill(visit.begin(), visit.end(), false);
		dfs(v, w, 0);
		return minimo_def;
	}

};

#endif // PROBLEMA_H_
