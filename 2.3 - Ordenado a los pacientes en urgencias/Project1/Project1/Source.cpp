
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

struct registro {

    int momento;
    string nombre;
    int dolor;

};


bool operator<(registro const& a, registro const& b)
{
    return b.dolor > a.dolor || (a.dolor == b.dolor && b.momento < a.momento);
}


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;
   if (N == 0)
      return false;

   priority_queue<registro> q;
   
   // resolver el caso posiblemente llamando a otras funciones


   string tipo, nombre; 
   int gravedad;

   for (int i = 0; i < N; i++)
   {
       cin >> tipo;


       if (tipo == "I")
       {
           cin >> nombre;
           cin >> gravedad;
           q.push({ i, nombre, gravedad });
       }
       else
       {
           cout << q.top().nombre << "\n";
           q.pop();
       }
   }
   // escribir la solución

   cout << "---\n";

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
