
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

using matriz = vector<vector<int>>;

typedef struct Nodo
{
    int k;
    vector<bool> marcas;
    int calidad_actual;
    int calidad_estimacion;
    bool operator<(Nodo const& otro) const
    {
        return otro.calidad_estimacion > calidad_estimacion;
    }

};

void RamificacionyPoda(const vector<int> & carros, const vector<int>& calles, const matriz& calidades, 
                       int &maximo_calidades, const vector<int>& estimacion)
{
    int N = carros.size();
    int M = calles.size();

    Nodo raiz;

    raiz.k = -1;
    raiz.calidad_actual = 0;
    raiz.marcas = vector<bool>(M, false);
    raiz.calidad_estimacion = estimacion[0];

    priority_queue<Nodo> cola;
    cola.push(raiz);

    while (!cola.empty() && cola.top().calidad_estimacion > maximo_calidades)
    {
        raiz = cola.top();
        cola.pop();
        
        Nodo x(raiz);
        x.k++;

        for (int i = 0; i < M; i++)
        {
            //Si el carro cabe por la calle probamos a asignarlo
            if (!raiz.marcas[i] && carros[x.k] <= calles[i])
            {
                x.calidad_actual = raiz.calidad_actual + calidades[x.k][i];
                x.marcas[i] = true;
                x.calidad_estimacion = x.calidad_actual + estimacion[x.k + 1];

                if (x.calidad_estimacion > maximo_calidades)
                {
                    if (x.k == N - 1)
                        maximo_calidades = max(maximo_calidades, x.calidad_actual);
                    else
                        cola.push(x);
                }

                x.marcas[i] = false;
            }


        }

        //Probamos a no asignarle ningun camino
        x.calidad_actual = raiz.calidad_actual;     //Continua el arbol hacia abajo sin asignar este ultimo
        x.calidad_estimacion = x.calidad_actual + estimacion[x.k + 1];
        if (x.calidad_estimacion > maximo_calidades)
        {
            if (x.k == N - 1)
                maximo_calidades = max(maximo_calidades, x.calidad_actual);
            else
                cola.push(x);
        }

    }

}

void resuelveCaso() {

    int N, M;
    cin >> N >> M;

    vector<int> carros(N);
    for (int i = 0; i < N; i++)
        cin >> carros[i];

    vector<int> calles(M);
    for (int i = 0; i < M; i++)
        cin >> calles[i];

    matriz calidades(N, vector<int> (M, 0));
    vector<int> estimacion(M, 0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> calidades[i][j];
            estimacion[j] = max(estimacion[j], calidades[i][j]);
        }
            
    for (int i = estimacion.size() - 2; i >= 0; i--)
        estimacion[i] += estimacion[i + 1];
    estimacion.push_back(0);


    int maximo_calidades = 0;
    RamificacionyPoda(carros, calles, calidades, maximo_calidades, estimacion);
    cout << maximo_calidades << "\n";
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
