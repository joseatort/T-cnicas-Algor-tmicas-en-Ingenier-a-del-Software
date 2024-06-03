#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include <vector>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"

template <typename Valor>
class ARM_Kruskal 
{
	private:
		int aristas_vistas;
		int ultima_arista;
	public:

		ARM_Kruskal(GrafoValorado<Valor> const& g) :ultima_arista(-1), aristas_vistas(0){
			PriorityQueue<Arista<Valor>> pq(g.aristas());
			ConjuntosDisjuntos cjtos(g.V());
			while (!pq.empty()) {
				auto a = pq.top(); 
				pq.pop();
				int v = a.uno(), w = a.otro(v);
				if (!cjtos.unidos(v, w)) {
					cjtos.unir(v, w);
					aristas_vistas++;
					if (aristas_vistas == g.V() - 1)
					{
						ultima_arista = a.valor();
						break;
					}
						
				}
			}
		}

		int getultima_artista()
		{
			return ultima_arista;
		}
};

#endif // KRUSKAL_H