
/*@ <authors>
 *
 * Alvaro Velasco Garcia TAIS68
 * Jose Antonio Tortosa Aranda TAIS65
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <exception>
#include <typeinfo>

using namespace std;

#include "TreeSet_AVL.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>


    En el encabezado .h hemos implementado un atributo nuevo el cual calcula a medida que se van insertado los valores dentro
    del arbol AVL o rotando dentro de el, el numero de elementos a la izquierda de este, mas 1.

    La funcion kesimo llama a una funcion auxiliar que de manera recursiva calcula el valor que tiene de forma ordenada la
    k posicion

    El coste de este algoritmo seria O(n), donde n es el numero de elementos del conjunto


 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada

    int N, M;
    cin >> N;

   if (N == 0)
      return false;

   Set<int> arbol;

   int aux;

   for (int i = 0; i < N; i++)
   {
       cin >> aux;
       arbol.insert(aux);
   }

   cin >> M;

   for (int i = 0; i < M; i++)
   {
       cin >> aux;
       try
       {
           cout << arbol.kesimo(aux) << "\n";

       }
       catch(const exception& e)
       {
           cout << e.what() << "\n";
       }

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
