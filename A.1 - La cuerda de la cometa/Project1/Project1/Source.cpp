/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EntInf.h"  // propios o los de las estructuras de datos de clase

typedef struct
{
    int longitud;
    int coste;
}Cordeles;

long long int nmaneras(const vector<Cordeles>& v, int L)
{
    int N = v.size();
    vector<long long int> maneras(L + 1, 0);
    maneras[0] = 1;
    for (int i = 1; i <= N; i++)
        for (int y = L; y >= v[i - 1].longitud; y--)
            maneras[y] = maneras[y] + maneras[y - v[i - 1].longitud];

    return maneras[L];
}

EntInf mincordel(const vector<Cordeles>& v, int L)
{
    int N = v.size();
    vector<EntInf> mincordel(L + 1, Infinito);
    mincordel[0] = 0;
    for (int i = 1; i <= N; i++)
        for (int y = L; y >= v[i - 1].longitud; y--)
            mincordel[y] = min(mincordel[y], mincordel[y - v[i - 1].longitud] + 1);

    return mincordel[L];
}

EntInf mincoste(const vector<Cordeles>& v, int L)
{
    int N = v.size();
    vector<EntInf> mincoste(L + 1, Infinito);
    mincoste[0] = 0;
    for (int i = 1; i <= N; i++)
        for (int y = L; y >= v[i - 1].longitud; y--)
            mincoste[y] = min(mincoste[y], mincoste[y - v[i - 1].longitud] + v[i - 1].coste);

    return mincoste[L];
}

void soluciones(const vector<Cordeles> &v, int L)
{
    long long int maneras = nmaneras(v, L);

    if (maneras > 0)
    {
        cout << "SI ";
        cout << maneras << " ";
        cout << mincordel(v, L) << " ";
        cout << mincoste(v, L);
    }
    else
        cout << "NO";
    cout << "\n";

}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N, L;
    cin >> N >> L;
   if (!std::cin)  // fin de la entrada
      return false;

   vector<Cordeles> v(N);

   int l, c;
   for (int i = 0; i < N; i++)
   {
       cin >> l >> c;
       v[i] = { l, c };
   }

   soluciones(v, L);

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
