
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase
#include "Problema.h" 

bool resuelveCaso() {

   // leer los datos de la entrada
    int N, A;
    cin >> N >> A;
   if (!std::cin)  // fin de la entrada
      return false;
   Grafo gv(N);

   vector<int> oro(N);
   for (int i = 0; i < N; i++)
       cin >> oro[i];


   for (int i = 0; i < A; i++)
   {
       int aux1, aux2;
       cin >> aux1 >> aux2;
       gv.ponArista(aux1 - 1, aux2 - 1);
   }
   // resolver el caso posiblemente llamando a otras funciones

   Minimo sol(gv, oro);
   cout << sol.getcoste() << "\n";
   // escribir la solución

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
