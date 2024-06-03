
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

using matriz = vector<vector<int>>;

int ProgramacionDinamica(int i, int j, const vector<int>& v, matriz& aux)
{

    if (i == j - 1)
    {
        if (v[i] == v[j] && (v[i] == 1 || v[i] == 2))
            aux[i][j] = 1;
        else
            aux[i][j] = 0;

        return aux[i][j];
    }
    else if (aux[i][j] != -1)
        return aux[i][j];
    else
    {
        //Comprobamos laterales actuales
        if (v[i] == v[j] && (v[i] == 1 || v[i] == 2))
        {
            aux[i][j] = 0;
            aux[i][j] = max(aux[i][j], ProgramacionDinamica(i + 1, j - 1, v, aux)) + 1;

        }   
        else
        {
            //Comprobamos que tipo de particion nos viene mejor
            int auxiliar = -1;
            auxiliar = max(auxiliar, ProgramacionDinamica(i + 2, j, v, aux));
            auxiliar = max(auxiliar, ProgramacionDinamica(i, j - 2, v, aux));
            auxiliar = max(auxiliar, ProgramacionDinamica(i + 1, j - 1, v, aux));

            aux[i][j] = auxiliar;
        }

        return aux[i][j];
    }
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

   matriz aux(N + 1, vector<int>(N + 1, -1));
   cout << ProgramacionDinamica(0, N - 1, v, aux) << "\n";

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
