
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
* 
*   El algoritmo voraz escoge para cada jugador una camiseta aun no asignada que sea de la menor
*   talla posible siempre y cuando esta se ajuste a la talla del jugador en su misma medida o 
*   uno mas
* 
*   S = {V,O} (Siendo V nuestra solucion voraz y O una solucion optima}
* 
*   V[0]   V[1] ... | V[k] ...
*    =      =          !=
*   O[0]   O[1] ... | O[k] ...
*   
*   Vemos que la solucion voraz es optima aplicando el metodo de reduccion por diferencias. La solucion
* Voraz y la solucion optima coincida hasta la posicion k, donde a partir de esta con esta incluida
* pueden suceder los diferentes tipos casos:
* 
*   Caso 1: V[k] == O[k] - 1, como V[k] es la menor talla no asignada anteriormente se cumple de que esta es una
*   solucion optima, por lo tanto, en la solucion optima en una posicion k + j, siendo j > 0, debe existir una 
*   solucion que sea igual V[k] y puede ser susituitda por O[k] de forma que la solucion optima se parezca mas a 
*   la voraz
*        
* 
*
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
int jugadores_sincamiseta(const vector<int> &j, const vector<int>& e)
{
    int sincamiseta = j.size();
    int contador1 = 0, contador2 = 0;

    while (contador1 < j.size() && contador2 < e.size())
    {
        if (j[contador1] == e[contador2] || j[contador1] == e[contador2] - 1)
        {
            sincamiseta--;
            contador1++;
            contador2++;
        }
        else if (j[contador1] > e[contador2])
            contador2++;
        else
            contador1++;
    }
    return sincamiseta;
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N, M;
    cin >> N >> M;
   if (!std::cin)  // fin de la entrada
      return false;

   vector<int> j(N), e(M);

   for (int i = 0; i < N; i++)
       cin >> j[i];

   for (int y = 0; y < M; y++)
       cin >> e[y];

   // resolver el caso posiblemente llamando a otras funciones
   sort(j.begin(), j.end());
   sort(e.begin(), e.end());

   // escribir la solución
   cout << jugadores_sincamiseta(j, e) << "\n";

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
