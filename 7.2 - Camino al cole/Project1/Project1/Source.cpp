
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "DiGrafoValorado.h"
#include "Problema.h"  // propios o los de las estructuras de datos de clase

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
    int N, A;
    cin >> N >> A;
   if (!std::cin)  // fin de la entrada
      return false;
   DigrafoValorado<int> digrafo(N);

   int v, w, valor;
   for (int i = 0; i < A; i++)
   {
       cin >> v >> w >> valor;
       digrafo.ponArista({v - 1, w - 1, valor});
       digrafo.ponArista({ w - 1, v - 1, valor });
   }
   // resolver el caso posiblemente llamando a otras funciones

   Dijkstra<int> sol (digrafo);

   cout << sol.getcaminos() << "\n";
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
