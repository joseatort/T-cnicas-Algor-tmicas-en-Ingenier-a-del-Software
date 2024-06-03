
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
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

struct baterias_usadas
{
    int horas_disponibles;
    int tipo; //0 pequeñas, 1 grandes
};

struct baterias
{
    int horas_disponibles;
};

bool operator<(const baterias& a, const baterias& b)
{
    return b.horas_disponibles > a.horas_disponibles;
}


bool resuelveCaso() {

   // leer los datos de la entrada

    int N_drones, N_9, N_1;

    cin >> N_drones;
    cin >> N_9;
    cin >> N_1;
   if (!std::cin)  // fin de la entrada
      return false;

   priority_queue<baterias> q_grandes;
   priority_queue<baterias> q_pequenas;
   int aux;
   for (int i = 0; i < N_9; i++)
   {
       cin >> aux;
       q_grandes.push({ aux });
   }

   for (int i = 0; i < N_1; i++)
   {
       cin >> aux;
       q_pequenas.push({ aux });
   }


   int horas_vuelo;

   vector<baterias_usadas> baterias_usadas;

   while (q_grandes.size() > 0 && q_pequenas.size() > 0)
   {
       horas_vuelo = 0;
       for (int i = 0; i < N_drones && (q_grandes.size() > 0 && q_pequenas.size() > 0); i++)
       {
           if (q_grandes.top().horas_disponibles >= q_pequenas.top().horas_disponibles)
           {
               auto aux = q_grandes.top();
               q_grandes.pop();

               aux.horas_disponibles -= q_pequenas.top().horas_disponibles;

               horas_vuelo += q_pequenas.top().horas_disponibles;
               q_pequenas.pop();

               if (aux.horas_disponibles != 0)
               {
                   baterias_usadas.push_back({ aux.horas_disponibles, 1 });
               }

           }
           else
           {
               auto aux2 = q_pequenas.top();
               q_pequenas.pop();

               aux2.horas_disponibles -= q_grandes.top().horas_disponibles;

               horas_vuelo += q_grandes.top().horas_disponibles;
               q_grandes.pop();


               baterias_usadas.push_back({ aux2.horas_disponibles, 0 });
           }



       }

       int contador = 0;
       while (contador < baterias_usadas.size())
       {
           if (baterias_usadas[contador].tipo == 0)
           {
               q_pequenas.push({ baterias_usadas[contador].horas_disponibles });
           }
           else
           {
               q_grandes.push({ baterias_usadas[contador].horas_disponibles });
           }

           contador++;
       }

       baterias_usadas.clear();

       cout << horas_vuelo << " ";

   }
   
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
