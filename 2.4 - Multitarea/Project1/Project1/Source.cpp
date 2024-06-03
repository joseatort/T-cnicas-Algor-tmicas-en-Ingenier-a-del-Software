
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


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


struct calendario {

    int inicio;
    int fin;
    int periodo;

};


bool operator<(calendario const& a, calendario const& b)
{
    return b.inicio < a.inicio;
}


bool resuelveCaso() {

   // leer los datos de la entrada
    
    int num_unicas, num_periodicas, mins;

    cin >> num_unicas;
    cin >> num_periodicas;
    cin >> mins;

   if (!std::cin)  // fin de la entrada
      return false;

   priority_queue<calendario> q;

   int min, max;
   for (int i = 0; i < num_unicas; i++)
   {
       cin >> min;
       cin >> max;  
       q.push({ min, max, -1});

   }

   int periodo;

   for (int i = 0; i < num_periodicas; i++)
   {
       cin >> min;
       cin >> max;
       cin >> periodo;
       q.push({ min, max, periodo });
   }

   bool conflicto = false;

   while (q.size() > 1 && !conflicto && q.top().inicio < mins)
   {

       auto aux = q.top();
       q.pop();

       if (aux.fin > q.top().inicio && q.top().inicio < mins)
           conflicto = true;
       else
       {
           if(aux.periodo != -1)
               q.push({ aux.inicio + aux.periodo, aux.fin + aux.periodo, aux.periodo });
       }
   }


   if (conflicto)
       cout << "SI\n";
   else
       cout << "NO\n";

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
