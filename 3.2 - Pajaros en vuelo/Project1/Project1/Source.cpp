
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


struct maximos
{
    int edad;
};

bool operator<(const maximos& a, const maximos& b)
{
    return a.edad < b.edad;
}

struct minimos
{
    int edad;
};

bool operator<(const minimos& a, const minimos& b)
{
    return a.edad > b.edad;
}

bool resuelveCaso() {

   // leer los datos de la entrada

    int primero, N;

    cin >> primero;
    cin >> N;
   if (primero == 0 && N == 0)
      return false;

   priority_queue<maximos> q_max;
   priority_queue<minimos> q_min;
   q_max.push({primero});
   q_min.push({primero});


   int aux;
   for(int i = 0; i < N * 2; i++)
   {
       cin >> aux;

       if (aux < q_max.top().edad)
       {
           q_max.push({ aux });
       }
       else
       {
           q_min.push({ aux });
       }

       if (i % 2 == 1)
       {
           if (q_max.size() > q_min.size())
           {
               q_max.pop();
               q_min.push({ q_max.top().edad });
           }
           else if (q_max.size() < q_min.size())
           {
               q_min.pop();
               q_max.push({ q_min.top().edad });
           }

           cout << q_max.top().edad << " ";

       }
           

   }
   
   cout << "\n";
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
