
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

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
    int F, C;
    cin >> F >> C;
   if (!std::cin)  // fin de la entrada
      return false;

   
   vector<string> v;


   string aux;

   for (int i = 0; i < F; i++)
   {
       cin >> aux;
       v.push_back(aux);
   }

   // resolver el caso posiblemente llamando a otras funciones

   // escribir la solución

   CaminosDFS manchas(v);
   cout << manchas.numero() << ' ' << manchas.maximo() << '\n';


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
