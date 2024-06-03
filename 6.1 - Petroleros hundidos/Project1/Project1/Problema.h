#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "ConjuntosDisjuntos.h"

using namespace std;

using elem = pair<int, int>;
const vector<pair<int, int>> dirs = { {1,0}, {0,1}, {-1,0}, {0,-1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

class Petroleros
{
private:

	ConjuntosDisjuntos mar;
	int tamMax;

	vector<string> Buques;
	int F;
	int C;

	int numElem(int i, int y) const
	{
		return i * C + y;
	}

	bool valida(const elem e) const
	{
		return((e.first >= 0 && e.first < F) && (e.second >= 0 && e.second < C));
	}

	void comprobarUniones(int i, int y)
	{
		elem sig;

		for (auto d : dirs)
		{
			sig.first = i + d.first;
			sig.second = y + d.second;

			if (valida(sig) && Buques[sig.first][sig.second] == '#' && !mar.unidos(numElem(sig.first, sig.second), numElem(i, y)))
				mar.unir(numElem(sig.first, sig.second), numElem(i, y));
		}
		tamMax = max(tamMax, mar.cardinal(numElem(i, y)));
	}

public:

	Petroleros(vector<string> const & buques, int f, int c) : mar(f*c) , tamMax(0), Buques(buques), F(f), C(c)
	{
		for (int i = 0; i < f; ++i)
			for (int y = 0; y < c; ++y)
				if (buques[i][y] == '#')
					comprobarUniones(i, y);
	}

	int tamayomaximo()
	{
		return tamMax;
	}

	void anadirbuque(int x, int y)
	{
		Buques[x][y] = '#';
		comprobarUniones(x, y);
	}

};


#endif // !PROBLEMA_H_

