
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Problema.h"  // propios o los de las estructuras de datos de clase
#include "Grafo.h"

bool resuelveCaso() {

   // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
   if (!std::cin)  // fin de la entrada
      return false;

   vector<int> sobornos(V);
   for (int i = 0; i < V; i++)
       cin >> sobornos[i];

   Grafo g(V);
   int v, w;
   for (int i = 0; i < A; i++)
   {
       cin >> v >> w;
       g.ponArista(v - 1, w - 1);
   }

   CaminosDFS sol(g, sobornos);

   cout << sol.get_coste() << "\n";

   return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("1.in");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
