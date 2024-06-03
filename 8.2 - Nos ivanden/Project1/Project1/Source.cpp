
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
int max_ganados(const vector<int> &v, const vector<int>& w)
{
    int maximo = 0;
    int contador = v.size() - 1;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] <= w[contador])
        {
            maximo++;
            contador--;
        }
    }

    return maximo;
}


bool resuelveCaso() {

   // leer los datos de la entrada

    int N;
    cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;

   vector<int> v(N);
   vector<int> w(N);

   for (int i = 0; i < N; i++)
       cin >> v[i];

   for (int i = 0; i < N; i++)
       cin >> w[i];

   // resolver el caso posiblemente llamando a otras funciones

   sort(v.begin(), v.end());
   sort(w.begin(), w.end());


   cout << max_ganados(v, w) << "\n";

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
