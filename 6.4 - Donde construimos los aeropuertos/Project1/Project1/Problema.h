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

struct ReverseComparator {
	bool operator()(const Arista<Valor>& a, const Arista<Valor>& b) {
		return a.valor() > b.valor();
	}
};

template <typename Valor>
class Aeropuertos
{
private:
	int vertices_visitados;
	Valor coste;
	int num_aeropuertos;
	int tam;



public:

	Aeropuertos(GrafoValorado<Valor> const& g, int coste_aeropuerto) : coste(0), tam(g.V()), vertices_visitados(0), num_aeropuertos(0){
		PriorityQueue<Arista<Valor>, ReverseComparator<Valor>> pq(g.aristas());
		ConjuntosDisjuntos cjtos(g.V());

		while (!pq.empty()) {
			auto a = pq.top(); 
			pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (a.valor() < coste_aeropuerto && !cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				vertices_visitados++;
				coste += a.valor();
				if (vertices_visitados == g.V() - 1)
					break;
			}
		}

		num_aeropuertos = cjtos.num_cjtos();
		coste += num_aeropuertos * coste_aeropuerto;
	}

	pair<int, int> CosteAeropuertos() const 
	{
		return { coste, num_aeropuertos};
	}

};

#endif // PROBLEMA_H_
