#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <vector>
#include <stdexcept>
#include <queue>
#include "Grafo.h"

using namespace std;

class Distancias {
private:

	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto

	int s;
	void bfs(Grafo const& g) {
		std::queue<int> q;

		dist[s] = 0; 
		visit[s] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int w : g.ady(v)) {
				if (!visit[w]) {
					dist[w] = dist[v] + 1;
					visit[w] = true;
					q.push(w);
				}
			}
		}
	}


public:
	Distancias( Grafo const &g, int o) : visit(g.V(), false) , dist(g.V(), -1), s(o)
	{
		bfs(g);
	}


	vector<int> distancias()
	{
		return dist;
	}

};






#endif // PROBLEMA_H_
