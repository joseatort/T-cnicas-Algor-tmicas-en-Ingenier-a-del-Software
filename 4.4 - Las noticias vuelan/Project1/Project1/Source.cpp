
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
    int N, grupos;
    cin >> N >> grupos;
   if (!std::cin)  // fin de la entrada
      return false;

   Grafo g(N);

   int aux1, aux2, aux3;
   for (int i = 0; i < grupos; i++)
   {
       cin >> aux1;

       if (aux1 != 0)
       {
           cin >> aux2;

           if (aux1 == 1)
               g.ponArista(aux2 - 1, aux2 - 1);
           else
           {
               for (int y = 0; y < aux1 - 1; y++)
               {
                   cin >> aux3;
                   g.ponArista(aux2 - 1, aux3 - 1);
                   aux2 = aux3;
               }
           }
       }
      

   }

   CaminosDFS resultado (g);

   for (int i = 0; i < N; i++)
       cout << resultado.num_amigos(i) << " ";

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
