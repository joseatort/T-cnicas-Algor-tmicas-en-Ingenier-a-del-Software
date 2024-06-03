
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
typedef struct
{
    int comienzo;
    int duracion;
}TPelicula;

using matriz = vector<vector<int>>;

bool operator<(const TPelicula& a, const TPelicula& b)
{
    return a.comienzo < b.comienzo;
}


int maximo_peliculas(int N, const vector<TPelicula> &peliculas)
{
    int min_max = 1500;

    vector<int> aux (min_max + 1, 0);

    for (int i = N - 1; i >= 0; i--)
        for (int j = 0; j <= min_max; j++)
            if (peliculas[i].comienzo >= j)
                aux[j] = max(aux[j], aux[peliculas[i].comienzo + peliculas[i].duracion + 10] + peliculas[i].duracion);

    return aux[0];
}

/*
int maximo_peliculas(int i, int j, const vector<TPelicula>& peliculas, matriz & aux)
{
    if (i == 0 || j == 0)
    {
        aux[i][j] = 0;
        return 0;
    }
    else if (aux[i][j] != -1)
        return aux[i][j];
    else
    {
        int duracion = peliculas[i - 1].final - peliculas[i - 1].inicio;

        aux[i][j] = max(aux[i][j], duracion + maximo_peliculas(i - 1, peliculas[i - 1].inicio, peliculas, aux));
        return aux[i][j];
    }

}
*/
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;

    // resolver el caso posiblemente llamando a otras funciones

    int hora, minutos, duracion;
    vector<TPelicula> peliculas;
    for (int i = 0; i < N; i++)
    {
        cin >> hora;
        cin.ignore();
        cin >> minutos;
        cin >> duracion;

        peliculas.push_back({ hora * 60 + minutos, duracion});
    }

    sort(peliculas.begin(), peliculas.end());
    //int Minutos_Dia = 1440;
    //matriz aux(N + 1, vector<int>(Minutos_Dia + 1, -1));
    // escribir la solución
    //cout << maximo_peliculas(N, Minutos_Dia, peliculas, aux) << "\n";
    cout << maximo_peliculas(N, peliculas) << "\n";
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
