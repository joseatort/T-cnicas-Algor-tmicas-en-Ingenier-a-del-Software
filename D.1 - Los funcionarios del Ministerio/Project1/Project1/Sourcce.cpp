
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
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

using matriz = vector<vector<int>>;

typedef struct Nodo
{
    int k;
    int tiempo_actual;
    vector<bool> marcas;
    vector<int> sol;
    int tiempo_estimado;
    bool operator<(Nodo const& otro) const
    {
        return otro.tiempo_estimado < tiempo_estimado;
    }

};

void RamificacioyPoda(const matriz& datos, vector<int> estimacion, int &tiempominimo)
{
    int N = datos.size();

    Nodo raiz;
    raiz.sol = vector<int>(N, 0);
    raiz.k = -1;
    raiz.tiempo_actual = 0;
    raiz.marcas = vector<bool>(N, false);
    raiz.tiempo_estimado = estimacion[0];

    priority_queue<Nodo> cola;
    cola.push(raiz);

    while (!cola.empty() && cola.top().tiempo_estimado < tiempominimo)
    {
        raiz = cola.top();
        cola.pop();

        Nodo x(raiz);
        x.k++;

        for (int i = 0; i < N; i++)
        {
            if (!raiz.marcas[i])
            {
                x.sol[x.k] = i;
                x.tiempo_actual = raiz.tiempo_actual + datos[x.k][i];
                x.marcas[i] = true;
                x.tiempo_estimado = x.tiempo_actual + estimacion[x.k + 1];
                if (x.tiempo_estimado < tiempominimo)
                    if (x.k == N - 1)
                        tiempominimo = x.tiempo_actual;
                    else
                        cola.push(x);


                x.marcas[i] = false;
            }
        }

    }

}


bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;
   if (N == 0)
      return false;

   matriz datos(N, vector<int>(N));
   vector<int> estimacion(N, numeric_limits<int>::max());
   for (int i = 0; i < N; i++)
       for (int j = 0; j < N; j++)
       {
           cin >> datos[i][j];
           estimacion[i] = min(datos[i][j], estimacion[i]);
       }
     

   for (int i = N - 2; i >= 0; i--)
       estimacion[i] += estimacion[i + 1];
   estimacion.push_back(0);
   int coste_minimo = numeric_limits<int>::max();

   vector<int> mejorsol(N);

   RamificacioyPoda(datos, estimacion, coste_minimo);
   cout << coste_minimo << "\n";

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
