#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <stdexcept>
#include "Digrafo.h"

using namespace std;

class Sumidero
{
private:

	vector <bool> visit;
	vector<pair<int, int>> EntradasySalidas;  //First = Entradas y Second = Salidas

	void dfs(Digrafo const& d, int v)
	{
		visit[v] = true;

		for (int w : d.ady(v))
		{
			EntradasySalidas[w].first++;
			EntradasySalidas[v].second++;

			if (!visit[w])
				dfs(d, w);
		}

	}


public:
	Sumidero(Digrafo const& d) : visit(d.V(), false), EntradasySalidas(d.V(), { 0, 0 })
	{
		for(int i = 0; i < d.V(); i++)
		{
			if (!visit[i])
				dfs(d, i);
		}
		
	}

	pair<bool, int> hayS()
	{
		for (int i = 0; i < EntradasySalidas.size(); i++)
		{
			if (EntradasySalidas[i].first == EntradasySalidas.size() - 1 && EntradasySalidas[i].second == 0)
				return { true, i };
		}

		return { false, -1 };
	}

};


#endif //PROBLEMA_H_