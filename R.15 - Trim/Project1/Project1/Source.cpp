
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

int ProgramacionDinamica(int i, int j, string &palabra, matriz &aux)
{
    if (i == j)
    {
        aux[i][j] = 1;
        return aux[i][j];
    }
    else if (i > j)
    {
        aux[i][j] = 0;
        return aux[i][j];
    }
    else if (aux[i][j] != -1)
        return aux[i][j];
    else
    {
        char letra_inicial = palabra[i], letra_final = palabra[j];
        int contador1 = 0;
        int contador2 = 0;

        while (palabra[i + contador1] == letra_inicial && i + contador1 < j)
            contador1++;

        while (palabra[j - contador2] == letra_final && j - contador2 > i)
            contador2++;

        if (palabra[i] != palabra[j])
        {
            aux[i][j] = min(ProgramacionDinamica(i + contador1, j, palabra, aux), ProgramacionDinamica(i, j - contador2, palabra, aux)) + 1;
        }
        else
        {
            aux[i][j] = ProgramacionDinamica(i + contador1, j - contador2, palabra, aux) + 1;
        }
            
        return aux[i][j];
    }



}

bool resuelveCaso() {

   // leer los datos de la entrada
    string palabra;
    cin >> palabra;
   if (!std::cin)  // fin de la entrada
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   matriz aux(palabra.size() + 1, vector<int>(palabra.size() + 1, -1));
   
   cout << ProgramacionDinamica(0, palabra.size() - 1, palabra, aux) << "\n";
   

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
