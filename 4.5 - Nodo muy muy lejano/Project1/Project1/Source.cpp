
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Problema.h"  // propios o los de las estructuras de datos de clase
#include "Grafo.h"

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
    int N, C;
    cin >> N >> C;
   if (!std::cin)  // fin de la entrada
      return false;


   Grafo g(N);
   
   int aux1, aux2;
   for (int i = 0; i < C; i++)
   {
       cin >> aux1;
       cin >> aux2;
       g.ponArista(aux1 - 1, aux2 - 1);
   }

   int K;
   cin >> K;

   CaminoMasCorto resultado (g);

    int o, tls;
  

   for (int y = 0; y < K; y++)
   {
       cin >> o >> tls;
       cout << resultado.nodos_alcanzables(o - 1, tls) << "\n";
   }

   cout << "---\n";

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
