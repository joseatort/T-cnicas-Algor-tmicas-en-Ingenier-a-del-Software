
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

// propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>



struct registro {

    int momento;
    long long int id;
    int periodo;

};


bool operator<(registro const& a, registro const& b) 
{
    return b.momento < a.momento || (a.momento == b.momento && b.id < a.id);
}

//El operator en este caso, busca el elemento que va a ir primero en la cola, el que entra nuevo es el b
//y solamente ira delante del a, si su momento es menor y en caso de ser igual su id es menor que el de a


//En colas de prioridad unicamente hemos visto dos tipo de operadores, (), que se añade en la declaracion del priority queue
//o tambien el operator <, que se debe tener como parametros de entrada los mismos del struct de su declaracion

bool resuelveCaso() {
   
   // leer los datos de la entrada
    
    int N;
    cin >> N;
   if (N == 0) return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   
   priority_queue<registro> q;

   // escribir la solución

   long long int id_usu;
   int periodo;
   for (int i = 0; i < N; ++i)
   {
       cin >> id_usu >> periodo;
       q.push({ periodo, id_usu, periodo });
   }

   int envios;
   cin >> envios;
    
   while (envios--)
   {
       auto e = q.top();
       q.pop();
       cout << e.id << "\n";
       e.momento += e.periodo;
       q.push(e); 
   }

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
