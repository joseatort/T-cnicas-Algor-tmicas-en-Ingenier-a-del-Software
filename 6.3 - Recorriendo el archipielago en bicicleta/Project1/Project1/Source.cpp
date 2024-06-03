
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
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
    int N, P;
    cin >> N >> P;
   if (!std::cin)  // fin de la entrada
      return false;

   GrafoValorado<int> gv(N);

   int aux1, aux2, valor;
   for (int i = 0; i < P; i++)
   {
       cin >> aux1 >> aux2 >> valor;
       gv.ponArista({ aux1 - 1, aux2 - 1, valor });
   }
   // resolver el caso posiblemente llamando a otras funciones

   ARM_Kruskal<int> sol(gv);

   if (sol.costeARM() == -1)
       cout << "No hay puentes suficientes\n";
   else
       cout << sol.costeARM() << "\n";

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
