#ifndef Problema_H_
#define Problema_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "DiGrafoValorado.h"
#include "IndexPQ.h"
using namespace std;

template <typename Valor>
class Cercanos {

private:

	const Valor INF = numeric_limits<Valor>::max();
	vector<int> origen;
	int distancia_maxima;
	int contador;
	vector<Valor> dist;
	vector<bool> visitado;
	IndexPQ<Valor> pq;

	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();

			if (dist[w] <= distancia_maxima && !visitado[w])
			{
				contador++;
				visitado[w] = true;
				pq.update(w, dist[w]);
			}
		}
	}


public:
	Cercanos(int D, DigrafoValorado<Valor> const& g, vector<int> const& orig) : origen(orig),
		dist(g.V(), INF), pq(g.V()), contador(orig.size()), visitado(g.V(), false),
		distancia_maxima(D){

		for (int i = 0; i < orig.size(); i++)
		{
			dist[origen[i]] = 0;
			pq.push(origen[i], 0);
			visitado[origen[i]] = true;
		}
		
		while (!pq.empty()) {
			int v = pq.top().elem; 
			pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}

	int lugares_cercanos()
	{
		return contador;
	}
		
};

#endif // Problema_H_