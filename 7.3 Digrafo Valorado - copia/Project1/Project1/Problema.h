#ifndef PROBLEMA_H_
#define PROBLEMA_H_


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>

#include "GrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

template <typename Valor>
class Dijkstra
{
private:

	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	int destino;
	std::vector<Valor> dist;
	IndexPQ<Valor> pq;

	void relajar(Arista<Valor> a) {
		int v = a.uno(), w = a.otro(v);
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor(); 
			pq.update(w, dist[w]);
		}
	}
	

public:

	Dijkstra(GrafoValorado<Valor> const& g, int orig, int dest) : origen(orig), destino(dest),
		dist(g.V(), INF), pq(g.V()) {

		dist[origen] = 0;
		pq.push(origen, 0);

		while (!pq.empty()) {
			int v = pq.top().elem; 
			pq.pop();

			for (auto a : g.ady(v))
				relajar(a);
		}

	}

	int getdistancia()
	{
		return dist[destino];
	}

};

#endif // PROBLEMA_H_
