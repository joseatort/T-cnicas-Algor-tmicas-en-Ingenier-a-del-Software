
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <unordered_map>
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

void floid(matriz &M)
{
    for (int k = 0; k < M.size(); k++)
        for (int i = 0; i < M.size(); i++)
            for (int j = 0; j < M.size(); j++)
                M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
}

EntInf buscarmaximo(const matriz& M)
{
    EntInf maximo = -1;
    for (int i = 0; i < M.size(); i++)
        for (int j = 0; j < M.size(); j++)
        {
            if (M[i][j] == Infinito)
                return Infinito;
            else
                maximo = max(maximo, M[i][j]);
        }

    return maximo;
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
    if (!std::cin)  // fin de la entrada
        return false;

    matriz M (V, vector<EntInf>(V, Infinito));
   // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < V; i++)
        M[i][i] = 0;
   // escribir la solución

    unordered_map<string, int> nombres;

    string n1, n2;
    for (int i = 0; i < A; i++)
    {
        cin >> n1 >> n2;
        if (nombres.find(n1) == nombres.end())
            nombres[n1] = nombres.size();

        if (nombres.find(n2) == nombres.end())
            nombres[n2] = nombres.size();

        M[nombres[n1]][nombres[n2]] = 1;
        M[nombres[n2]][nombres[n1]] = 1;
    }

    floid(M);

    EntInf sol = buscarmaximo(M);

    if (sol == Infinito)
        cout << "DESCONECTADA";
    else
        cout << sol;
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
