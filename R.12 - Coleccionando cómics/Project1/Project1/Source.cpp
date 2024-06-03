
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
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


struct Comics
{
    int id;
    int pila;

    bool operator<(const Comics& otro) const
    {
        return otro.id < id;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<deque<int>> pilas(N);

    int m, aux;

    int indice_menor = numeric_limits<int>::max();

    for (int i = 0; i < N; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> aux;
            indice_menor = min(aux, indice_menor);
            pilas[i].push_front(aux);
        }
    }

    priority_queue<Comics> cimas;

    //Rellenamos filas
    for (int i = 0; i < N; i++)
    {
        cimas.push({ pilas[i].front(), i });
        pilas[i].pop_front();
    }

    int posicion = 0;
    bool encontrado = false;
    while (!encontrado)
    {
        Comics comic = cimas.top();
        cimas.pop();

        if (comic.id == indice_menor)
            encontrado = true;
        else if (!pilas[comic.pila].empty())
        {
            cimas.push({ pilas[comic.pila].front(), comic.pila });
            pilas[comic.pila].pop_front();
        }

        posicion++;
    }

    cout << posicion << "\n";

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
