#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <stdexcept>
#include "Digrafo.h"

using namespace std;

class BFSDirigido {


private:
	vector<vector<bool>> visit; // visit[v] = ¿hay camino de s a v?
	vector<vector<int>> aux;
	int formas; 

	int dfs(int N, int k, int w) {
		int origen = w;
		
		for (int i = 1; (i <= k && w + 1 <= N); i++)
		{
			if (aux[i][w] != -1)
				return aux[i][w];


			w += 1;
			if (w == N)
				return 1;
			else if (!visit[origen][w])
			{
				visit[origen][i] = true;
				aux[i][w] = dfs(N, k, w);
			}
				
		}

		return aux[k][N];
	}

public:
	BFSDirigido(int N, int k) : visit(N, vector<bool> (N, false)), formas(0), aux (N, vector<int>(N, -1))
	{
		dfs(N, k, 0);
	}

	int numformas() {
		return formas;
	}

};

#endif  /* PROBLEMA_H_*/