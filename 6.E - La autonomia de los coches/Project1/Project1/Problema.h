#ifndef	PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <fstream> 
#include <vector>


#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"

using namespace std;
template <typename Valor>
class Autonomia
{
private:

	Valor autonomia_necesaria;
	int tam;
	int num_visitados;

public:

	//Implementamos Kruskal
	Autonomia(GrafoValorado<Valor> const& g) : autonomia_necesaria(0), num_visitados(0), tam(g.V())
	{
		PriorityQueue<Arista<Valor>> pq(g.aristas());//O(A)
		ConjuntosDisjuntos cjtos(g.V());//O(V)

		while (!pq.empty())//O(A)
		{
			auto a = pq.top();//O(1)
			pq.pop();//O(log A)

			int v = a.uno();//O(1)
			int w = a.otro(v);//O(1)
			if (!cjtos.unidos(v, w))
			{
				cjtos.unir(v, w);
				num_visitados++;
				
				if (num_visitados == g.V() - 1)//O(1)
				{
					autonomia_necesaria = a.valor();//O(1)
					break;
				}
					
			}
		}
	}

	int autonomia_minima()
	{
		if (num_visitados == tam - 1)
			return autonomia_necesaria;
		else
			return -1;
	}
};


#endif // PROBLEMA_H_
