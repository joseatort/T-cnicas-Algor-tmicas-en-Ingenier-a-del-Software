/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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


typedef struct
{
    int inicio;
    int final;
}Tareas;

bool operator<(Tareas& a, Tareas& b)
{
    return a.inicio < b.inicio;
}

pair<bool, int> voraz(int C, int F, vector<Tareas>& tareas)
{
    sort(tareas.begin(), tareas.end());

    int ultTrabajo = C, cont = 0, nTrabajos = 0;
    bool haySol = true;

    while (haySol && ultTrabajo < F)
    {
        int mejorFin = -1;
        if (cont >= tareas.size() || tareas[cont].inicio > ultTrabajo)
            haySol = false;
        else
        {
            while (haySol && cont < tareas.size() && tareas[cont].inicio <= ultTrabajo)
            {
                if (tareas[cont].final > ultTrabajo && tareas[cont].final > mejorFin)
                    mejorFin = tareas[cont].final;
                cont++;
            }

            ultTrabajo = mejorFin;
            nTrabajos++;
        }


    }

    return { haySol , nTrabajos };
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int C, F, N;
    cin >> C >> F >> N;
   if (C == 0 && F == 0 && N == 0)
      return false;

   vector<Tareas> Tareas(N);
   int ini, fin;
   for (int i = 0; i < N; i++)
   {
       cin >> ini >> fin;
       Tareas[i] = { ini, fin };
   }

   pair <bool, int> sol = voraz(C, F, Tareas);

   if (sol.first)
       cout << sol.second;
   else
       cout << "Imposible";
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
