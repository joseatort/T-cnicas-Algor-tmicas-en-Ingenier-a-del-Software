#ifndef PROBLEMA_H_
#define PROBLEMA_H_


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>

#include "DiGrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

template <typename Valor>
class MejorCamino
{
private:

	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	int destino;
	
	bool alcanzable;
	std::vector<Valor> dist;

	vector<int> ult;
	IndexPQ<Valor> pq;
	vector<int> aristas;

	int minaristas;

	int bfs(DigrafoValorado<int> const& gv, int origen, int destino)
	{
		vector<bool> visit(gv.V(), false);
		queue<int> q;
		vector<int> d(gv.V());
		visit[origen] = true;
		d[origen] = 0;

		q.push(origen);
		while (!alcanzable && !q.empty())
		{
			int v = q.front();
			q.pop();

			int cont = 0;
			while (!alcanzable && cont < gv.ady(v).size())
			{
				int sig = gv.ady(v)[cont].hasta();

				if (sig == destino)
				{
					alcanzable = true;
					d[sig] = d[v] + 1;
				}
				else if (!visit[sig])
				{
					visit[sig] = true;
					d[sig] = d[v] + 1;
					q.push(sig);
				}

				++cont;	
			}
		}

		return d[destino];
	}



	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			aristas[w] = aristas[v] + 1;
			ult[w] = v;
			pq.update(w, dist[w]);
		}
		else if (dist[w] == dist[v] + a.valor() && aristas[v] + 1 < aristas[w])
			aristas[w] = aristas[v] + 1;
		
	}

	void dijkstra(DigrafoValorado<int> const& gv, int origen)
	{
		dist[origen] = 0;
		pq.push(origen, 0);

		while (!pq.empty()) {
			int v = pq.top().elem;
			pq.pop();

			for (auto a : gv.ady(v))
				relajar(a);
		}
	}

	

public:

	MejorCamino(DigrafoValorado<Valor> const& g, int orig, int dest) : alcanzable(false), origen(orig), destino(dest),
		dist(g.V(), INF), pq(g.V()), ult(g.V(), -1), aristas(vector<int>(g.V(), 0)), minaristas(0){

		minaristas = bfs(g, orig, dest);
		dijkstra(g, origen);
		
	}

	pair<int, string> camino()
	{
		if (dist[destino] != INF)
		{
			if (minaristas == aristas[destino])
				return { dist[destino], "SI" };
			else
				return { dist[destino], "NO" };
			
		}
		else
			return { -1 , ""};
		
	}

};

#endif // PROBLEMA_H_
