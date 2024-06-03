#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <stdexcept>
#include "Grafo.h"

using namespace std;

class CaminoMasCorto {
private:

	Grafo g;

	int bfs(int origen, int ttl) {
		std::queue<int> q;

		vector<bool> visit(g.V(), false);
		vector<int> ant(g.V(), -1);
		vector<int> dist(g.V(), 0);

		dist[origen] = 0;
		visit[origen] = true;

		int contador = 1;

		q.push(origen);

		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int w : g.ady(v)) {
				if (!visit[w]) {

					ant[w] = v; 
					dist[w] = dist[v] + 1; 

					if (dist[w] <= ttl)
						contador++;

					visit[w] = true;
					q.push(w);
				}
			}
		}


		return g.V() - contador;
	}
public:
	CaminoMasCorto(Grafo const& g) : g(g){}

	// número de aristas entre s y v
	int nodos_alcanzables(int origen, int ttl) {
		return bfs(origen, ttl);
	}
	// devuelve el camino más corto desde el origen a v (si existe)

};

#endif /* GRAFO_H_*/