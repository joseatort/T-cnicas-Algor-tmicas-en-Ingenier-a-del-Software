
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


bool compare(int &a, int &b)
{
    return a > b;
}


int maximo_coches(vector<int>& v, int Voltaje)
{
    sort(v.begin(), v.end(), compare);

    int contizq = 0;
    int contdrc = v.size() - 1;

    int resultado = 0;
    while (contizq < contdrc)
    {
        if (v[contizq] + v[contdrc] >= Voltaje)
        {
            resultado++;
            contizq++;
            contdrc--;
        }
        else
            contdrc--;
    }
    
    return resultado;
}


void resuelveCaso() {

   // leer los datos de la entrada
    int N, Volt;
    cin >> N >> Volt;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];
   // resolver el caso posiblemente llamando a otras funciones
    cout << maximo_coches(v, Volt) << "\n";
   // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("1.in");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
