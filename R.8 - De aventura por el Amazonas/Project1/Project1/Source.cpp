
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

using matriz = vector<vector<EntInf>>;

matriz ProgramacionDinamica(const matriz& datos,int N)
{
    matriz sol(N, vector<EntInf>(N, Infinito));
    
    for (int i = 0; i < N; i++)
        sol[i][i] = 0;

    for(int d = 1; d < N; d++)
        for (int i = 0; i < N - d; i++)
        {
            int col = d + i;
            for(int k = i + 1; k <= col; k++)
                sol[i][col] = min(sol[i][col], datos[i][k] + sol[k][col]);

        }


    
    return sol;
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;

   matriz datos(N, vector<EntInf>(N, Infinito));

   int fila = 0;
   while (fila <= N)
   {
       int aux;
       for (int j = fila + 1; j < N; j++)
       {
           cin >> aux;
           datos[fila][j] = aux;
       }
       fila++;
   }
   matriz sol = ProgramacionDinamica(datos, N);

   for (int i = 0; i < N; i++)
   {
       for (int j = 1 + i; j < N; j++)
           cout << sol[i][j] << " ";
       cout << "\n";
   }


           


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
