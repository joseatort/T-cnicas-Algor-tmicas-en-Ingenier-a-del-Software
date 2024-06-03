#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>

#include "ConjuntosDisjuntos.h"
#include "Grafo.h"

using namespace std;

struct supermercado
{
	int numero;
	int precio;

	bool operator<(const supermercado& otro) const
	{
		return otro.numero < numero;
	}
};

class Mercados
{

private:

	ConjuntosDisjuntos puntos;
	vector<int> supers_cercanos;
	Grafo g;
	unordered_map<int, int> precio_minimo;

public:
	Mercados(const Grafo& ciudad, priority_queue<supermercado> supermercados) : puntos(ciudad.V()), supers_cercanos(ciudad.V(), numeric_limits<int>::max()), g(ciudad)
	{
		//Creamos el conjunto disjunto
		for (int i = 0; i < ciudad.V(); i++)
			for (int a : ciudad.ady(i))
				if (!puntos.unidos(i, a))
					puntos.unir(i, a);

		
		for(int i = 0; i < ciudad.V(); i++)
		{
			if (precio_minimo.find(puntos.buscar(i)) == precio_minimo.end())
				precio_minimo[puntos.buscar(i)] = numeric_limits<int>::max();


			if (!supermercados.empty() && i == supermercados.top().numero)
			{
				precio_minimo[puntos.buscar(i)] = min(precio_minimo[puntos.buscar(i)], supermercados.top().precio);
				supermercados.pop();
			}


		}

	}

	int lugar(int indice)
	{
		return precio_minimo[puntos.buscar(indice)];
	}




};
#endif //|PROBLEMA_H_