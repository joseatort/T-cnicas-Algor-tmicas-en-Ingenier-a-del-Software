
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

#include "DiGrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "Problema.h"
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
   if (!std::cin)  // fin de la entrada
      return false;

   DigrafoValorado<int> gf(V);

   int v, w, valor;
   for (int i = 0; i < A; i++)
   {
       cin >> v >> w >> valor;
       gf.ponArista({ v - 1, w - 1, valor });
       gf.ponArista({ w - 1, v - 1, valor });
   }

   // resolver el caso posiblemente llamando a otras funciones

  

   int C;
   cin >> C;

   int v1, w2, aux;
   for (int i = 0; i < C; i++)
   {
       cin >> v1 >> w2;
       Dijkstra<int> sol(gf, v1 - 1, w2 - 1);
       aux = sol.getdistancia();

       if (aux != std::numeric_limits<int>::max())
       {
           cout << aux << ": ";
           sol.camino(v1 - 1, w2 - 1);
       }
           
       else
           cout << "NO LLEGA";
       cout << "\n";
   }

   cout << "---\n";

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
