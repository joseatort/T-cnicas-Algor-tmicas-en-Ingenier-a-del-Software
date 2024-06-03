
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EntInf.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using matriz = vector<vector<EntInf>>;

vector<int> resolver(int T, const vector<int> &v)
{   
    vector<EntInf> minimo (T + 1, Infinito);
    minimo[0] = 0;
    for(int i = 1; i <= v.size(); i++)
        for(int y = v[i-1]; y <= T; y++)
            minimo[y] = min(minimo[y], minimo[y - v[i - 1]] + 1);


    vector<int> sol;
    if (minimo[T] != Infinito)
    {
        int i = v.size(), j = T;
        while (j > 0)
        {
            if (v[i - 1] <= j && minimo[j] == minimo[j - v[i - 1]] + 1)
            {
                sol.push_back(v[i - 1]);
                j = j - v[i - 1];
            }
            else
                i--;   
        }
    }


    return sol;
}


bool resuelveCaso() {

   // leer los datos de la entrada
    int T, N;
    cin >> T >> N;
   if (!std::cin)  // fin de la entrada
      return false;
   vector <int> v(N);

   for (int i = 0; i < N; i++)
       cin >> v[i];
   // resolver el caso posiblemente llamando a otras funciones

   vector<int> sol = resolver(T, v);

   if (sol.size() > 0)
       cout << sol.size() << ": ";
   else
       cout << "Imposible";


   for (int i = 0; i < sol.size(); i++)
   {
       cout << sol[i] << " ";
   }
   cout << "\n";
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
