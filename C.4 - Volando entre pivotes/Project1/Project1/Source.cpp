
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
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

/*
int f(int i, int N, int M, vector<int>& v)
{
    if (i == N - 1)
    {
        v[i] = 1;
        return 1;
    }
    else if (v[i] != -1)
        return v[i];
    else
    {
        int aux = 0;
        for (int k = 0; k <= min(M, N - 2 - i); k++)
            aux = (aux + f(i + k + 1, N, M, v)) % 1000000007;

        v[i] = aux;
        return v[i];
    }
}*/

int f(int i, int N, int M)
{
    vector<int> v(N, 0);
    v[N - 1] = 1;

    for (int i = N - 2; i >= 0; i--)
        for (int k = 0; k <= min(M, N - 2 - i); k++)
            v[i] = (v[i] + v[i + k + 1]) % 1000000007;

    return v[0];
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N, M;
    cin >> N >> M;
   if (N == 0 && M == 0)
      return false;

   vector<int> v(N, -1);
   cout << f(0, N, M) << "\n";

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
