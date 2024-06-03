
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>    
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

typedef struct
{
    int inicio;
    int final;
}TLinea;

bool operator<(TLinea& a, TLinea& b)
{
    return a.final < b.final;
}

int minimo_puentes(vector <TLinea> &v)
{
    int puentes = 0, contador = 0;
    int ultimo_final = -1;

    sort(v.begin(), v.end());
    while (contador < v.size())
    {
        if (v[contador].inicio >= ultimo_final)
        {
            puentes++;
            ultimo_final = v[contador].final;
        }

        contador++;
    }

    return puentes;
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;
   if (N == 0)
      return false;

   vector <TLinea> v(N);
   int ini, fin;
   for (int i = 0; i < N; i++)
   {
       cin >> ini >> fin;
       v[i] = { ini, fin };
   }

   // resolver el caso posiblemente llamando a otras funciones
   cout << minimo_puentes(v) << "\n";
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
