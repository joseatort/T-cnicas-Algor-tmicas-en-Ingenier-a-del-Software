#ifndef PROBLEMA_H_
#define PROBLEMA_H_


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#include "DiGrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

template <typename Valor>
class Dijkstra
{
private:

	const Valor INF = numeric_limits<Valor>::max();

	vector<Valor> dist;
	vector<AristaDirigida<Valor>> ulti;
	IndexPQ<Valor> pq;

	vector<int> caminos;

	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();

		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			ulti[w] = a;

			caminos[w] = caminos[v];

			pq.update(w, dist[w]);
		}
		else if (dist[v] + a.valor() == dist[w])
			caminos[w] += caminos[v];
	}

public:

	Dijkstra(DigrafoValorado<Valor> const& g) : dist(g.V(), INF), ulti(g.V()), pq(g.V()),
		caminos(g.V(), 0){

		dist[0] = 0;
		caminos[0] = 1;
		pq.push(0, 0);

		while (!pq.empty()) {
			int v = pq.top().elem;
			pq.pop();

			for (auto a : g.ady(v))
				relajar(a);
		}

	}

	int getcaminos()
	{
		return caminos[caminos.size() - 1];
	}

};

#endif // PROBLEMA_H_
