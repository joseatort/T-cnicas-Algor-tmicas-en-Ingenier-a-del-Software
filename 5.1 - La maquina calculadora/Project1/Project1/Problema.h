#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <stdexcept>
#include "Digrafo.h"

using namespace std;

class Calculadora {
private:

	const int MAX = 10000;
	const int INF = 1000000000; 

	int resultado;

	int adyacente(int v, int i) {
		switch (i) {
		case 0: return (v + 1) % MAX; // + 1
		case 1: return (v * 2) % MAX; // * 2
		case 2: return v / 3; // / 3
		}
	}

	int bfs(int origen, int destino) {
		if (origen == destino) 
			return 0;

		vector<int> distancia(MAX, INF);
		distancia[origen] = 0;
		queue<int> cola; 
		cola.push(origen);

		while (!cola.empty()) {
			int v = cola.front(); 
			cola.pop();

			for (int i = 0; i < 3; ++i) {
				int w = adyacente(v, i);

				if (distancia[w] == INF) {
					distancia[w] = distancia[v] + 1;

					if (w == destino) 
						return distancia[w];
					else 
						cola.push(w);
				}
			}
		}
	}
public:
	Calculadora(int destino, int origen)
	{
		resultado = bfs(destino, origen);
	}

	int solucion()
	{
		return resultado;
	}
};

#endif /* GRAFO_H_*/