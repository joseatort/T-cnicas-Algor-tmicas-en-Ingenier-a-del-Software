
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
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

typedef struct Baterias
{
    int id;
    int capacidad;
    int carga;

    bool operator<(const Baterias& otro) const
    {
        return (otro.carga < carga || (otro.carga == carga && otro.id < id));
    }
};

bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;

   priority_queue<Baterias> baterias;
   int aux;
   for (int i = 0; i < N; i++)
   {
       cin >> aux;
       baterias.push({ i + 1, aux, aux });
   };
   
       

   int R;
   cin >> R;

   queue<Baterias> repuestos;
   for (int i = 0; i < R; i++)
   {
       cin >> aux;
       repuestos.push({N + i + 1, aux, aux});
   };

   int gasto_recarga, T;
   cin >> gasto_recarga >> T;

   int tiempo = 0;
   while (!baterias.empty() && baterias.top().carga <= T)
   {
       
       Baterias actual = baterias.top();
       baterias.pop();
       tiempo = actual.carga;
       actual.capacidad -= gasto_recarga;
       actual.carga = actual.carga + actual.capacidad;

       if (actual.capacidad > 0)
           baterias.push(actual);
       else if (!repuestos.empty())
       {
           repuestos.front().carga = tiempo + repuestos.front().capacidad;
           baterias.push(repuestos.front());
           repuestos.pop();
       }
        
   }

   if (baterias.size() == N)
       cout << "CORRECTO";
   else if (baterias.size() == 0)
       cout << "ABANDONEN INMEDIATAMENTE LA BASE";
   else
       cout << "FALLO EN EL SISTEMA";
   cout << "\n";

   while (!baterias.empty())
   {
       cout << baterias.top().id << ' ' << baterias.top().carga << "\n";
       baterias.pop();
   }

   cout << "---" << "\n";

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
