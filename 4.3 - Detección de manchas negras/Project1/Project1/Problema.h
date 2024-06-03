#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Grafo.h"

using namespace std;

class CaminosDFS {
private:
	int F, C;
	std::vector<vector<bool>> visit; // visit[v] = ¿hay camino de s a v?
	int num;
	int maxim;

	int vertices_vistados = 0;

	int max_amigos = 0;

	const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };

	bool correcta(int i, int j) const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}

	int dfs(vector<string> const& M, int i, int j) {
		visit[i][j] = true;
		int tam = 1;
		for (auto d : dirs) {
			int ni = i + d.first, nj = j + d.second;
			if (correcta(ni, nj) && M[ni][nj] == '#' && !visit[ni][nj]) {
				tam += dfs(M, ni, nj);
			}
		}
		return tam;
	}


public:
	CaminosDFS(vector<string> const& M) : F(M.size()), C(M[0].size()),
		visit(F, vector<bool>(C, false)), num(0), maxim(0) {

		for (int i = 0; i < F; ++i) {
			for (int j = 0; j < C; ++j) {
				if (!visit[i][j] && M[i][j] == '#') { // se recorre una nueva mancha
					++num;
					int nuevotam = dfs(M, i, j);
					maxim = max(maxim, nuevotam);
				}
			}
		}
	}

	int numero() const { return num; }
	int maximo() const { return maxim; }

};

#endif /* PROBLEMA_H_*/