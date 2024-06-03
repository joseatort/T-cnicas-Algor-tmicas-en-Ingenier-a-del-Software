
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

using matriz = vector<vector<int>>;

int ProgramacionDinamica(int i, int j, int F, int C, matriz& datos, matriz& aux)
{
    if (i == F && j == C)
        return 1;
    else if (aux[i][j] != -1)
        return aux[i][j];
    else
    {
        int auxiliar = 0;

        //Abajo
        if(i + datos[i][j] <= F)
            auxiliar += ProgramacionDinamica(i + datos[i][j], j, F, C, datos, aux);
        
        //Derecha
        if (j + datos[i][j] <= C)
            auxiliar += ProgramacionDinamica(i, j + datos[i][j], F, C, datos, aux);


        aux[i][j] = auxiliar;
        return aux[i][j];
    }
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int F, C;
    cin >> F >> C;
   if (!std::cin)  // fin de la entrada
      return false;

   matriz datos(F, vector<int> (C));

   for (int i = 0; i < F; i++)
       for (int j = 0; j < C; j++)
           cin >> datos[i][j];

   matriz aux(F + 1, vector<int>(C + 1, -1));
   cout << ProgramacionDinamica(0, 0, F - 1, C - 1, datos, aux) << "\n";

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
