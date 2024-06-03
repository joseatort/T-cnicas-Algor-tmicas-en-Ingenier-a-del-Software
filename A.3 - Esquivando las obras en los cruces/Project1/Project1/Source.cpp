
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


int minmaneras(const vector<string> &intersecciones, int C)
{
    vector<int> v(C, 0);
    v[0] = 1;
    for (int i = 0; i < intersecciones.size(); i++)
        for (int y = 0; y < C; y++)
        {
            if (intersecciones[i][y] == 'X')
                v[y] = 0;
            else if (y != 0)
                v[y] = v[y] + v[y - 1];
                
        }
    
    return v[C - 1];
            
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int F, C;
    cin >> F >> C;
   if (!std::cin)  // fin de la entrada
      return false;
   

   vector<string> intersecciones(F);
   for (int i = 0; i < F; i++)
       cin >> intersecciones[i];    
   // resolver el caso posiblemente llamando a otras funciones

   cout << minmaneras(intersecciones, C) << "\n";
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
