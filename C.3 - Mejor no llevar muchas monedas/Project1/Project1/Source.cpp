
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
/*
EntInf progDinamica(int i, int j, const vector<int> &c, const vector<int>& v, matriz& aux)
{
    if (j == 0)
    {
        aux[i][j] = 0;
        return 0;
    }
    else if (i == 0 && j > 0)
    {
        aux[i][j] = Infinito;
        return Infinito;
    }
    else if (aux[i][j] != -1)
        return aux[i][j];
    else
    {
        aux[i][j] = Infinito;
        for (int k = 0; k <= min(c[i - 1], j / v[i - 1]); k++)
        {
            aux[i][j] = min(aux[i][j], progDinamica(i - 1, j - k * v[i - 1], c, v, aux) + k);
        }

        return aux[i][j];
    }
    

}*/

EntInf progDinamica(int N, int P, const vector<int>& c, const vector<int>& v)
{
    matriz aux (N + 1, vector<EntInf>(P + 1, Infinito));

    for (int i = 0; i <= N; i++)
        aux[i][0] = 0;

    for(int i = 1; i <= N; i++)
        for (int j = 1; j <= P; j++)
            for (int k = 0; k <= min(c[i - 1], j / v[i - 1]); k++)
                aux[i][j] = min(aux[i][j], aux[i - 1][j - k * v[i - 1]] + k);

    return aux[N][P];
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<int> c(N);

    for (int j = 0; j < N; j++)
        cin >> c[j];

    int P;
    cin >> P;

    //matriz aux(N + 1, vector <EntInf> (P + 1, -1));

    EntInf sol = progDinamica(N, P, c, v);
    sol == Infinito ? cout << "NO" : cout << "SI " << sol;
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
