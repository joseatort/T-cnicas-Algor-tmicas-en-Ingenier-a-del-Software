
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

struct Actividad
{
    int inicio;
    int fin;

    bool operator<(const Actividad& otro) const
    {
        return  otro.inicio < inicio;
    }
};

struct Persona
{
    int inicio;
    int fin;

    bool operator<(const Persona& otro) const
    {
        return  otro.fin < fin;
    }
};



bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;
   if (N == 0)
      return false;

   int aux1, aux2;
   priority_queue<Actividad> pq;
   for (int i = 0; i < N; i++)
   {
       cin >> aux1 >> aux2;
       pq.push({ aux1, aux2 });
   }

   priority_queue<Persona> personas;

   while (!pq.empty())
   {
       Actividad aux = pq.top();
       pq.pop();

       if (personas.empty() || personas.top().fin > aux.inicio)
           personas.push({aux.inicio, aux.fin});
   }

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
