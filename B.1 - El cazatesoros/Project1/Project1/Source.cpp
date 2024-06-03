
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

typedef struct
{
    int prof;
    int valor;
}tTesoros;

using matriz = vector<vector<int>>;

int oromaximo(matriz& oro, const vector<tTesoros>& v)
{
    oro[0][0] = 0;

    for (int i = 1; i < oro.size(); i++)
    {
        for (int j = 0; j < oro[0].size(); j++)
        {
            if (3 * v[i - 1].prof > j)
                oro[i][j] = oro[i - 1][j];
            else
                oro[i][j] = max(oro[i - 1][j], oro[i - 1][j - 3 * v[i - 1].prof] + v[i - 1].valor);
        }
    }

    return oro[oro.size() - 1][oro[0].size() - 1];
}


pair<int, vector<int>> reconstruccion(const vector<tTesoros>& v, int Profundidad)
{
    matriz oro(v.size() + 1, vector<int>(Profundidad + 1, 0));
    int max_oro = oromaximo(oro, v);

    //Reconstruccion
    vector<int> sol;

    if (max_oro != 0)
    {
        int i = v.size(), j = Profundidad;
        while (i > 0 && j > 0)
        {
            if (oro[i][j] != oro[i - 1][j])
            {
                sol.push_back(i - 1);
                j -= 3 * v[i - 1].prof;
            }
            i--;
        }
    }

    return { max_oro, sol };
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int P, T;
    cin >> P >> T;
    if (!std::cin)  // fin de la entrada
        return false;

    int prof, valor;
    vector<tTesoros> v(T);
    for (int i = 0; i < T; i++)
    {
        cin >> prof >> valor;
        v[i] = { prof, valor };
    }

    // resolver el caso posiblemente llamando a otras funciones

    pair<int, vector<int>> sol = reconstruccion(v, P);

    cout << sol.first << "\n";
    cout << sol.second.size() << "\n";
    for (int i = sol.second.size() - 1; i >= 0; i--)
        cout << v[sol.second[i]].prof << " " << v[sol.second[i]].valor << "\n";
    cout << "---\n";
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
