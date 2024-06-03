
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
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
    int N, D, T, P;
    cin >> N >> D >> T >> P;
   if (!std::cin)  // fin de la entrada
      return false;

   DigrafoValorado<int> gv(N);

   int v, w, k;
   for (int i = 0; i < P; i++)
   {
       cin >> v >> w >> k;
       gv.ponArista({ v - 1, w - 1, k });
   }
   
   //Invierto el grafo, para ver distancias desde la salida
   gv = gv.inverso();

   Dijkstra<int> sol(gv, D - 1, T);

   cout << sol.numratones() << "\n";

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
