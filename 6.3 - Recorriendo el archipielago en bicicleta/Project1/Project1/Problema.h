#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>

#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

template <typename Valor>
class ARM_Kruskal
{
private:
	int vertices_visitados;
	Valor coste;
	int tam;

public:

	ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), tam(g.V()), vertices_visitados(0) {
		PriorityQueue<Arista<Valor>> pq(g.aristas());
		ConjuntosDisjuntos cjtos(g.V());

		while (!pq.empty()) {
			auto a = pq.top(); 
			pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				vertices_visitados++;
				coste += a.valor();
				if (vertices_visitados == g.V() - 1)
					break;
			}
		}
	}

	Valor costeARM() const {

		if (vertices_visitados == tam - 1)
			return coste;
		else
			return -1;
		
	}

};

#endif // PROBLEMA_H_
