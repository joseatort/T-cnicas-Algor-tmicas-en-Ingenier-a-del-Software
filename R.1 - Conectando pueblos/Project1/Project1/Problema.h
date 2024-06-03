#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"

using namespace std;

template <typename Valor>
class ARM_Kruskal {
private:
	vector<Arista<Valor>> _ARM;
	Valor coste;
	bool posible;
public:

	ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), posible(false)
	{
		PriorityQueue<Arista<Valor>> pq(g.aristas());
		ConjuntosDisjuntos cjtos(g.V());
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				_ARM.push_back(a); 
				coste = max(coste, a.valor());
				if (_ARM.size() == g.V() - 1)
				{
					posible = true;
					break;
				}
					
			}
		}
	}

	Valor ultimaArista() const {
		return coste;
	}

	bool es_posible() const
	{
		return posible;
	}
};

#endif // !PROBLEMA_H_	