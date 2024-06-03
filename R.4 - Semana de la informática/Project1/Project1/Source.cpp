
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
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

struct Eventos
{
    int comienzo;
    int fin;

};

struct duracion
{
    int duracion;
};

bool operator<(Eventos const& a, Eventos const& b)
{
    return  a.comienzo > b.comienzo;
}

bool operator<(duracion const& a, duracion const& b)
{
    return  a.duracion > b.duracion;
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;

   if (N == 0)
      return false;

   priority_queue<Eventos> eventos;
   int aux1, aux2;
   for (int i = 0; i < N; i++)
   {
       cin >> aux1 >> aux2;
       eventos.push({ aux1, aux2 });
   }
   
   priority_queue<duracion> personas;

   int inicio_anterior = 0;
   while (!eventos.empty())
   {
       Eventos actual = eventos.top();
       eventos.pop();

       if (!personas.empty() && personas.top().duracion <= actual.comienzo)
           personas.pop();

       //Necesitamos personal -> asignamos
       personas.push({ actual.fin });


   }
   // escribir la solución

   cout << personas.size() - 1 << "\n";

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
