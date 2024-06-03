#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>

#include "DiGrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int orig, int T) : origen(orig),
		dist(g.V(), INF), pq(g.V()), Tiempo(T), ratones(0)
	{
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; 
			pq.pop();
			for (auto a : g.ady(v))
			{
				relajar(a);
			}
				
		}
	}

	Valor distancia(int v) const { return dist[v]; }
	int numratones() const { return ratones; }

private:
	const Valor INF = numeric_limits<Valor>::max();
	int origen;
	int Tiempo;
	int ratones;
	vector<Valor> dist;
	IndexPQ<Valor> pq;
	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();

		//Si se puede sumo raton
		if (dist[w] > Tiempo && dist[v] + a.valor() <= Tiempo)
			ratones++;


		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			pq.update(w, dist[w]);
		}
	}
};

#endif // !PROBLEMA_H_