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
class Dijkstra
{
private:

	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	int destino;
	
	std::vector<Valor> dist;
	vector<int> ult;
	IndexPQ<Valor> pq;

	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			ult[w] = v;
			pq.update(w, dist[w]);
		}
	}
	

public:

	Dijkstra(DigrafoValorado<Valor> const& g, int orig, int dest) : origen(orig), destino(dest),
		dist(g.V(), INF), pq(g.V()), ult(g.V(), -1) {

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

	void camino(int origen, int destino)
	{
		if (origen == destino)
		{
			cout << origen + 1;
			return;
		}
		else
		{

			
			camino(origen, ult[destino]);
			cout << " -> " << destino + 1;
		}
		
	}

};

#endif // PROBLEMA_H_
