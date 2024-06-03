
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

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


struct comparador
{
    bool operator()(const long long int& a, const long long int& b) const
    {
        return a > b;
    }
};


long long int resolver(priority_queue<long long int, vector<long long int>, comparador> &q)
{
    long long int aux = 0;

    long long int acumulador_esfuerzo = 0;
    while(q.size() > 1)
    {
        aux = q.top();
        q.pop();
        
        aux += q.top();
        acumulador_esfuerzo += aux;
        q.pop();
        q.push(aux);
    }

    return acumulador_esfuerzo;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   
   priority_queue<long long int, vector<long long int>, comparador> q;

   long long int N, aux;

   cin >> N;

   if (N == 0)
      return false;
   
   for (long long int i = 0; i < N; i++)
   {
       cin >> aux;
       q.push(aux);
   }

   // resolver el caso posiblemente llamando a otras funciones
   cout << resolver(q) << endl;
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
