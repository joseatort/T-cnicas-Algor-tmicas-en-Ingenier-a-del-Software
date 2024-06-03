
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

int minparches(const vector<int> &v, int L)
{
    int contador = 0; 
    int posicion_parche = -1;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > posicion_parche)
        {
            contador++;
            posicion_parche = v[i] + L;
        }
    }

    return contador;
}


bool resuelveCaso() {

   // leer los datos de la entrada
    int N, L;
    cin >> N >> L;
   if (!std::cin)  // fin de la entrada
      return false;

   vector<int> v(N);

   for (int i = 0; i < N; i++)
       cin >> v[i];

   // resolver el caso posiblemente llamando a otras funciones
   cout << minparches(v, L) << "\n";
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
