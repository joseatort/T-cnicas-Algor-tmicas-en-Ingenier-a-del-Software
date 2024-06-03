
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

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



struct Festivales
{
    int artistas;
    int precio;

};

int ProgramacionDinamica(int N, int P, const vector<Festivales> &festivales)
{
    vector<int> aux (P + 1, 0);

    for(int i = 1; i <= N; i++)
        for (int j = P; j >= festivales[i - 1].precio; j--)
            aux[j] = max(aux[j], aux[j - festivales[i - 1].precio] + festivales[i - 1].artistas);

    return aux[P];
}


bool resuelveCaso() {

   // leer los datos de la entrada
    int P, N;
    cin >> P >> N;
    if (!std::cin)  // fin de la entrada
      return false;

    vector<Festivales> v(N);
   int aux1, aux2;
   for (int i = 0; i < N; i++)
   {
       cin >> aux1 >> aux2;
       v[i] = { aux1, aux2 };
   }
   
   cout << ProgramacionDinamica(N, P, v) << "\n";

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
