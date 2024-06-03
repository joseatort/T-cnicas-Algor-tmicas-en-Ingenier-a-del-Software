/*@ <authors>
 *
 * Alvaro Velasco Garcia TAIS68
 * Jose Antonio Tortosa Aranda TAIS65
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Problema.h"  // propios o los de las estructuras de datos de clase
#include "GrafoValorado.h"

/*@ <answer>
*
*   Explicacion
*   -----------
*   Guardamos los datos en un grafo valorado no direccional, a continuacion, llamamos a una instancia
*   de la clase Autonomia, que se encuentra en Problema.h
* 
*   Dentro de esta instancia, mediante Kruskal, buscamos el Arbol de Recubrimiento de coste Minimo (ARM), 
*   y guardamos el valor de la ultima arista que pertence a este, que sería la de mayor autonomia necesaria.
*   
*   Hemos empleado un ARM, ya que nos permite recorrer todos los vertices (ciudades), con el menor coste 
*   posible, ademas comprueba si el grafo es conexo, si no lo es devolvemos "Imposible", en caso de que lo
*   sea devolvemos la autonomia necesaria para recorrer la arista con mayor valor del ARM.
* 
*   Coste
*   -----
*   El coste del algoritmo implementado sería O(A log A), siendo A el numero de aristas de nuestro 
*   grafo valorado, en este caso A corresponde al numero de carreteras.
* 
*   Deducimos este coste, por el algoritmo Kruskal implementado, donde hacemos un bucle por A aristas,
*   y por cada iteracion del bucle realizamos un pop() sobre la PriorityQueue de aristas, el cual, tiene
*   un coste de O(log A).
* 
*   El resto de operaciones que usamos tienen un coste menor a O(A log A) y estas estan explicadas
*   dentro de Problema.h
* 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada
    int N, M;
    cin >> N >> M;
   if (!std::cin)  // fin de la entrada
      return false;
   
   GrafoValorado<int> g(N);
    
   int v, w, valor;
   for (int i = 0; i < M; i++)
   {
       cin >> v >> w >> valor;
       g.ponArista({ v - 1, w - 1, valor });
   }

   // resolver el caso posiblemente llamando a otras funciones
   Autonomia<int> sol(g);

   // escribir la solución
   if (sol.autonomia_minima() == -1)
       cout << "Imposible";
   else
       cout << sol.autonomia_minima();
   cout << "\n";

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
