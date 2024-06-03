
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

int superiores(const vector<int> &v, int y)
{
    if (v.size() == 1)
        return v[y];
    else if (y == 0)
        return max(v[y], v[y + 1]);
    else if (y == v.size() - 1)
        return max(v[y], v[y - 1]);
    else
        return max({ v[y], v[y - 1], v[y + 1] });
    
}


pair<int, int> progDinamica(const vector<vector<int>> &v)
{
    vector<int> sol = v[0];
    vector<int> aux = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        for (int y = 0; y < v.size(); y++)
            sol[y] = superiores(aux, y) + v[i][y];

        aux = sol;
    }



    int maximo = 0;
    for (int i = 1; i < sol.size(); i++)
        if (sol[maximo] < sol[i])
            maximo = i;
        
    return { sol[maximo], maximo };
}


bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;
   vector<vector<int>> v(N, vector<int>(N));
   for (int i = 0; i < N; i++)
       for (int y = 0; y < N; y++)
           cin >> v[i][y];
   // resolver el caso posiblemente llamando a otras funciones

   pair<int, int> sol = progDinamica(v);
   // escribir la solución

   cout << sol.first << " " << sol.second + 1<< "\n";

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
