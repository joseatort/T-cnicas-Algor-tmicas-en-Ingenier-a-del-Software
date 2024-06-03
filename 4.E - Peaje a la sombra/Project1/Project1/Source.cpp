
/*@ <authors>
 *
 * Alvaro Velasco Garcia TAIS68
 * Jose Antonio Tortosa Aranda TAIS65
 * 
 *@ </authors> */

#include <iostream>
#include <fstream>

using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase
#include "Problema.h" 

/*@ <answer>

    EXPLICACION
    ----------
    Leemos los datos, y a la entrada dada se le resta 1 a cada vertice, con el fin de que cuadre en nuestro grafo que 
    empieza en 0. 

    Hemos creado la clase Distancias, que se encuentra en Problema.h, en cuyo constructor recibe el grafo y el vertice origen
    y a partir de la funcion distancias() obtenemos la distancia que existe entre ese vertice de origen y el resto de elementos
    del grafo, mediante un bfs aplicado al constructor de la instacia Distancias.

    Creamos 3 instancias de dicha clase, para cada dato recibido, casa1, casa2, trabajo.

    Llamamos a la funcion distancias() desde cada una de las instancias y recibimos los vectores nombrados anteriormente.

    Reccoremos todos los vertices del grafo, buscando el minimo de la suma de las distancias a cada uno de ellos. Ese minimo
    seria nuestra solucion.
    
    COSTE
    -----
    El coste del algoritmo empleado para resolver el problema, seria O(V + A), siendo V el numero de vertices de nuestro grafo
    y A el numero de aristas de este. Dado que en nuestra funcion bfs, situada dentro de la clase Distancias, en Problema.h, 
    calcula la distancia recorriendo todos los vertices del grafo desde un origen, a partir de aristas adyacentes a este.

    Para obtener las distancias empleamos un coste O(1), dado que ya se encuentran calculadas en las instancias Distancias,
    y finalmente para calcular la distancia minima usamos un algoritmo de coste O(V), siendo V el numero de vertices del grafo.

    Por lo que el coste general del algoritmo seria O(V + A) ya que este sería mayor a todos los demas costes empleados.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada

    int V, A, c1, c2, trab;
    cin >> V >> A >> c1 >> c2 >> trab;
   if (!std::cin)  // fin de la entrada
      return false;
   
   Grafo g(V);

   int aux1, aux2;
   for (int i = 0; i < A; i++)
   {
       cin >> aux1 >> aux2;

       g.ponArista(aux1 - 1, aux2 - 1);

   }

   // resolver el caso posiblemente llamando a otras funciones

   Distancias dist1 (g, c1 - 1);
   Distancias dist2 (g, c2 - 1);
   Distancias dist3 (g, trab - 1);


   vector<int> d1 = dist1.distancias();
   vector<int> d2 = dist2.distancias();
   vector<int> d3 = dist3.distancias();

   int dist_min = (V * (V - 1) / 2) + 1; 

   for (int i = 0; i < V; i++)
       dist_min = min(d1[i] + d2[i] + d3[i], dist_min);

   // escribir la solución

   cout << dist_min << "\n";

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
