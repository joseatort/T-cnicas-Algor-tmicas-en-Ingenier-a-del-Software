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

	vector<int> coste_minimos;
	int tam;

	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor() + coste_minimos[w]) {
			dist[w] = dist[v] + a.valor() + coste_minimos[w];
			ulti[w] = a;
			pq.update(w, dist[w]);
		}
	}



public:

	Dijkstra(DigrafoValorado<Valor> const& g, vector<int> const &coste) :
		dist(g.V(), INF), ulti(g.V()), pq(g.V()), tam(g.V()), coste_minimos(coste){

		dist[0] = coste_minimos[0];
		pq.push(0, coste_minimos[0]);
		while (!pq.empty()) {
			int v = pq.top().elem;
			pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}

	}

	int tiempo_minimo()
	{
		return dist[tam - 1] != INF ? dist[tam - 1] : -1;
	}

};

#endif // PROBLEMA_H_
