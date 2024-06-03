
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
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

using matriz = vector<vector<int>>;

struct Nodo
{
    int k;
    vector<int> sol;
    vector<int> marcaje;
    
    int valor_actual;
    int valor_estimacion;
     
    bool operator<(const Nodo& otro) const
    {
        return valor_estimacion > otro.valor_estimacion;
    }
};

void RamificacionyPoda(const matriz &datos, const vector<int> &estimaciones, int &coste_min,
                        int N, int M)
{
    Nodo raiz;

    raiz.k = -1;

    raiz.marcaje = vector<int>(N, 0);
    raiz.sol = vector<int>(M, -1);
    raiz.valor_actual = 0;
    raiz.valor_estimacion = estimaciones[0];

    priority_queue<Nodo> cola;
    cola.push(raiz);

    while (!cola.empty() && cola.top().valor_estimacion < coste_min)
    {
        raiz = cola.top();
        cola.pop();

        for (int i = 0; i < N; i++)
        {
            Nodo x(raiz);
            x.k++;
            if (raiz.marcaje[i] < 3)
            {
                //Marcamos
                x.sol[x.k] = i;
                x.valor_actual = x.valor_actual + datos[i][x.k];
                x.marcaje[i]++;
                x.valor_estimacion = x.valor_actual + estimaciones[x.k + 1];

                if (x.valor_estimacion < coste_min)
                {
                    if (x.k == M - 1)
                        coste_min = x.valor_actual;
                    else
                        cola.push(x);
                }

            }
            

        }

    }

}

void resuelveCaso() {

   // leer los datos de la entrada
    int N, M;
    cin >> N >> M;

    matriz datos(N, vector<int>(M));
    vector<int> estimaciones(M + 1, numeric_limits<int>::max());

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> datos[i][j];
            estimaciones[j] = min(estimaciones[j], datos[i][j]);
        }
            

    for (int i = M - 1; i > 0; i--)
        estimaciones[i - 1] += estimaciones[i];
    estimaciones[M] = 0;


   // resolver el caso posiblemente llamando a otras funciones
    int coste_min = numeric_limits<int>::max();
    RamificacionyPoda(datos, estimaciones, coste_min, N, M);
    cout << coste_min << "\n";

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
