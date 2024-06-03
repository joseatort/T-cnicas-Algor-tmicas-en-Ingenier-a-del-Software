
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
    int N;
    cin >> N;
   if (N == 0)
      return false;

   vector<int> coste_individual(N);

   for (int i = 0; i < N; i++)
       cin >> coste_individual[i];

   DigrafoValorado<int> digrafo(N);

   int A, v, w, valor;
   cin >> A;

   for (int i = 0; i < A; i++)
   {
       cin >> v >> w >> valor;
       digrafo.ponArista({ v - 1, w - 1, valor });
   }

   Dijkstra<int> sol(digrafo, coste_individual);

   if (sol.tiempo_minimo() == -1)
       cout << "IMPOSIBLE";
   else
       cout << sol.tiempo_minimo();
   cout << "\n";

   // resolver el caso posiblemente llamando a otras funciones

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
