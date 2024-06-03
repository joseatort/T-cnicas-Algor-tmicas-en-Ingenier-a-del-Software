
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EntInf.h"
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

EntInf progDinamica(const vector<int> &v)
{
    matriz m(v.size(), vector<EntInf> (v.size(), 0));
    for (int d = 2; d < v.size(); d++)
        for (int i = 0; i < v.size() - d; i++)
        {
            int j = i + d;
            m[i][j] = Infinito;

            for (int k = i + 1; k < j; k++)
            {
                EntInf temp = m[i][k] + m[k][j] + 2 * (v[j] - v[i]);
                m[i][j] = min(m[i][j], temp);
            }
        }

    return m[0][v.size() - 1];   
}   

bool resuelveCaso() {

   // leer los datos de la entrada
    int L, T;
    cin >> L >> T;
    if (L == 0 && T == 0)
        return false;

    vector<int> v(T + 2);
    v[0] = 0;
    v[T + 1] = L;
    for (int i = 1; i <= T; i++)
        cin >> v[i];
    // resolver el caso posiblemente llamando a otras funciones

    cout << progDinamica(v) << "\n";

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
