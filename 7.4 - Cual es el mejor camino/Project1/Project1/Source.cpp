
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Problema.h"  // propios o los de las estructuras de datos de clase
#include "DiGrafoValorado.h"

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

   DigrafoValorado <int> g(N);

   int v, w, valor;

   for(int i = 0; i < A; i++)
   {
       cin >> v >> w >> valor;
       g.ponArista({ v - 1, w - 1, valor });
       g.ponArista({ w - 1, v - 1, valor });
   }

   int consultas;
   cin >> consultas;

   int v2, w2;
   for (int i = 0; i < consultas; i++)
   {
       cin >> v2 >> w2;
       MejorCamino<int> sol(g, v2 - 1, w2 - 1);

       pair<int, string> resultado = sol.camino();

       if (resultado.first != -1)
           cout << resultado.first << " " << resultado.second;
       else
           cout << "SIN CAMINO";
       cout << "\n";
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
