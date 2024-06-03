
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Equipos
{
    long long int jugadores;

    bool operator<(const Equipos& otro) const
    {
        return otro.jugadores < jugadores;
    }
};



bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;
   if (N == 0)
      return false;

   priority_queue<Equipos> equipos;

   long long int aux;
   for (int i = 0; i < N; i++)
   {
       cin >> aux;
       equipos.push({ aux });
   }
    
   long long int acumulador = 0;

   while (equipos.size() >= 2)
   {
       Equipos equipo1 = equipos.top();
       equipos.pop();
       Equipos equipo2 = equipos.top();
       equipos.pop();

       acumulador += equipo1.jugadores + equipo2.jugadores;

       equipos.push({ equipo1.jugadores + equipo2.jugadores });
   }

   cout << acumulador << "\n";
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
