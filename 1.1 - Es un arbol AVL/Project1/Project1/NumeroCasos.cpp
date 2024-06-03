
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;
#include <climits>
#include "bintree.h"

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
    bool AVL;
    int altura;
    int min;
    int max;


}TResultado;

TResultado resolver(const BinTree<int> & arbol)
{

    if (arbol.empty())
    {
        return { true, 0, -1, -1};
    }
    else
    {
        TResultado iz = resolver(arbol.left());
        TResultado dr = resolver(arbol.right());

        if (iz.AVL && dr.AVL)
        {
            if (abs(iz.altura - dr.altura) > 1 || (arbol.root() <= iz.max && iz.max != -1) || (arbol.root() >=  dr.min && dr.max != -1))
                return { false, 0, 0, 0 };
            else
                return{ true, max(iz.altura, dr.altura) + 1, arbol.left().empty() ? arbol.root() : min(arbol.root(), iz.min), arbol.right().empty() ? arbol.root() : max(arbol.root() ,dr.max)};
        }
        else
        {
            return { false, 0, 0 };

        }

    }



}


void resuelveCaso() {
   
   // leer los datos de la entrada
    BinTree<int> arbol;

    arbol = read_tree<int>(cin);
   // resolver el caso posiblemente llamando a otras funciones
   
    if (resolver(arbol).AVL)
        cout << "SI\n";
    else
        cout << "NO\n";


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
