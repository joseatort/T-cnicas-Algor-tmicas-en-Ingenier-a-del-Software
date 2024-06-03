
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

using matriz = vector<vector<int>>;

int progDinamica(const vector<int> &cubos)
{

    matriz m (cubos.size(), vector<int>(cubos.size(), 0));

    for (int i = 0; i < cubos.size(); i++)
        m[i][i] = cubos[i];

    int sol_i, sol_j;
    for(int i = cubos.size() - 2; i >= 0; i--)
        for (int j = i + 1; j < cubos.size(); j++)
        {
            if (cubos[i + 1] > cubos[j])
                sol_i = m[i + 2][j];
            else
                sol_i = m[i + 1][j - 1];

            if (cubos[i] < cubos[j - 1])
                sol_j = m[i][j - 2];
            else
                sol_j = m[i + 1][j - 1];

            m[i][j] = max(cubos[i] + sol_i, cubos[j] + sol_j);
        }
    return m[0][cubos.size() - 1];
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
      return false;

    vector<int> cubos(N);
   // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < N; i++)
        cin >> cubos[i];
    
    cout << progDinamica(cubos) << "\n";
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
