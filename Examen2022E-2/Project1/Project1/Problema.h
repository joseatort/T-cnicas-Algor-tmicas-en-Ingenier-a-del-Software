#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <iostream>
#include <vector>

#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"

using namespace std;

template <typename Valor>
class ARM_Kruskal {
private:
	int vertices_visitados;
	int ultima_arista;
public:
	
	ARM_Kruskal(GrafoValorado<Valor> const& g) : vertices_visitados(0), ultima_arista(-1){
		PriorityQueue<Arista<Valor>> pq(g.aristas());
		ConjuntosDisjuntos cjtos(g.V());
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				vertices_visitados++;
				if (vertices_visitados == g.V() - 1)
				{
					ultima_arista = a.valor();
					break;
				}
			}
		}
	}

	int getmaxima_arista()
	{
		return ultima_arista;
	}
};

#endif // !PROBLEMA_H