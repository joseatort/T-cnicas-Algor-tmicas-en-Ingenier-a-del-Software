
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include "bintree.h"
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

template <typename T>
struct TResultado
{
    bool AVL;
    int altura;
    T min;
    T max;

    
    
};

template <typename T>
TResultado<T> resolver(const BinTree<T>& arbol, const string &tipo )
{
    T limite;
    if (tipo == "N")
        limite = -1;
    else
        limite = T{};


    if (arbol.empty())
    {
        return { true, 0, limite, limite};
    }
    else
    {
        TResultado<T> iz = resolver(arbol.left(), tipo);
        TResultado<T> dr = resolver(arbol.right(), tipo);

        if (iz.AVL && dr.AVL)
        {
            if (abs(iz.altura - dr.altura) > 1 || (arbol.root() <= iz.max && iz.max != limite) || (arbol.root() >= dr.min && dr.max != limite))
                return { false, 0, limite, limite };
            else
                return{ true, max(iz.altura, dr.altura) + 1, arbol.left().empty() ? arbol.root() : min(arbol.root(), iz.min), arbol.right().empty() ? arbol.root() : max(arbol.root() ,dr.max) };
        }
        else
        {
            return { false, 0, limite, limite };

        }

    }
}

bool resuelveCaso() {

   // leer los datos de la entrada
   
    string tipo;

   cin >> tipo;
   if (!std::cin)  // fin de la entrada
      return false;

   
   if (tipo == "N")
   {
       BinTree<int> arbol;
       arbol = read_tree<int>(cin);
       if (resolver(arbol, tipo).AVL)
           cout << "SI\n";
       else
           cout << "NO\n";
   }
   else
   {
       BinTree<string> arbol;
       arbol = read_tree<string>(cin);
       if (resolver(arbol, tipo).AVL)
           cout << "SI\n";
       else
           cout << "NO\n";
   }


   // resolver el caso posiblemente llamando a otras funciones

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
