#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <stdexcept>
#include "Digrafo.h"

using namespace std;

class SerpientesyEscaleras
{
private:

	int minimo = 0;
	int Caras;

	int bfs(Digrafo const& dg, int v)
	{
		queue<int> q;

		vector<bool> visit(dg.V(), false);
		vector<int> dist(dg.V(), 0);

		minimo = 0;
		bool encontrado = false;
		dist[v] = 0;
		visit[v] = true;

		q.push(v);

		while (!q.empty() && minimo == 0) {

			int v = q.front();
			q.pop();

			int actual;
			for (int i = 1; i <= Caras && !encontrado; i++) {

				actual = v + i;

				if (!dg.ady(actual).empty())
					actual = dg.ady(actual)[0];

				if (actual == dg.V() - 1)
				{
					minimo = dist[v] + 1;
					encontrado = true;
				}
				else if (!visit[actual]) {
					visit[actual] = true;
					dist[actual] = dist[v] + 1;

					q.push({actual});
				}
			}
		}
		return minimo;
	}


public:
	SerpientesyEscaleras(Digrafo const & dg, int K) : Caras(K)
	{
		minimo = bfs(dg, 0);
	}

	int minimo_lanzamientos()
	{
		return minimo;
	}

};


#endif PROBLEMA_H_