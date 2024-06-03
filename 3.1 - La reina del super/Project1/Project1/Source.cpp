
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
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


struct datos
{
    int tiempo_espera;
    int id;
};

bool operator<(const datos& a, const datos& b)
{
    if (b.tiempo_espera < a.tiempo_espera)
        return true;
    else if (b.tiempo_espera == a.tiempo_espera && b.id < a.id)
        return true;
    else
        return false;
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N, C;
    cin >> N;
    cin >> C;

   if (N == 0 && C == 0)
      return false;


   priority_queue<datos> cajas;

   for (int i = 0; i < N; i++)
       cajas.push({0, i});

   int aux;
   while(C--)
   {
       cin >> aux;

       auto primero = cajas.top();
       cajas.pop();

       cajas.push({ primero.tiempo_espera + aux, primero.id});
   }


   cout << cajas.top().id + 1 << "\n";

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
