
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

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

typedef struct
{
    int inicio;
    int final;
}TPelicula;

bool operator<(const TPelicula& a, const TPelicula& b)
{
    return b.final > a.final;
}

int maximo_peliculas(vector<TPelicula>& peliculas)
{
    int maximo_peliculas = 0;
    int ultpelicula = -1;

    sort(peliculas.begin(), peliculas.end());
    for (int i = 0; i < peliculas.size(); i++)
    {
        if (peliculas[i].inicio >= ultpelicula)
        {
            maximo_peliculas++;
            ultpelicula = peliculas[i].final;
        }

    }
    return maximo_peliculas;
}


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

       peliculas.push_back({ hora * 60 + minutos, hora * 60 + minutos + duracion + 10});
   }

   // escribir la solución
   cout << maximo_peliculas(peliculas) << "\n";
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
