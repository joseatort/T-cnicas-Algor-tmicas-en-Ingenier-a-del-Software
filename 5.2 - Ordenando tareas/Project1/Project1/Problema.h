#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>
#include <stdexcept>
#include "Digrafo.h"

using namespace std;

class OrdenarTareas {
private:
	vector <bool> visit;
	vector <bool> apilado;
	bool hayCiclos;
	deque<int> postordenInv;

	bool dfs(Digrafo const& d, int v)
	{
		visit[v] = true;
		apilado[v] = true;
		bool ciclo = false;
		int cont = 0; 

		while (!ciclo && cont < d.ady(v).size())
		{
			if (apilado[d.ady(v)[cont]])
				ciclo = true;
			else if (!visit[d.ady(v)[cont]])
				ciclo = dfs(d, d.ady(v)[cont]);
			++cont;
		}

		postordenInv.push_front(v);
		apilado[v] = false;
		
		return ciclo;
	}


	
public:

	OrdenarTareas(Digrafo const& d) : visit(vector<bool>(d.V(), false)), apilado(vector<bool>(d.V(), false)),
		hayCiclos(false), postordenInv(deque<int>())
	{
		int cont = 0;
		while (!hayCiclos && cont < d.V())
		{
			if (!visit[cont])
				hayCiclos = dfs(d, cont);
			++cont;
		}

	}

	bool const aciclico() const
	{
		return hayCiclos;
	}

	deque<int> const& tareasOrdenadas() const	
	{
		return postordenInv;
	}

};

#endif /* GRAFO_H_*/