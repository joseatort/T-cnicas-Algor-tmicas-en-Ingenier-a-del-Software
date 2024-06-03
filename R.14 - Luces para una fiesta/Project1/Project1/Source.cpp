
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


pair<EntInf, int> ProgramacionDinamica(int N, int Pmax, int Pmin, vector<int> &potencias, vector<int> &precio)
{
    vector<EntInf> aux (Pmax + 1, Infinito);
    aux[0] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = potencias[i - 1]; j <= Pmax; j++)
            aux[j] = min(aux[j], aux[j - potencias[i - 1]] + precio[i - 1]);

    EntInf coste = Infinito;
    int potencia = -1;
    for (int i = Pmin; i <= Pmax; i++)
    {
        if (coste > aux[i])
        {
            coste = aux[i];
            potencia = i;
        }
    }
        

    return { coste, potencia };
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N, Pmax, Pmin;
    cin >> N >> Pmax >> Pmin;
    if (!std::cin)  // fin de la entrada
      return false;

    vector<int> potencias(N);
    for (int i = 0; i < N; i++)
        cin >> potencias[i];

    vector<int> precio(N);
    for (int i = 0; i < N; i++)
        cin >> precio[i];

   // resolver el caso posiblemente llamando a otras funciones

    pair<EntInf, int> sol = ProgramacionDinamica(N, Pmax, Pmin, potencias, precio);
    
    if (sol.first != Infinito)
        cout << sol.first << " " << sol.second;
    else
        cout << "IMPOSIBLE";
    cout << "\n";
    

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
