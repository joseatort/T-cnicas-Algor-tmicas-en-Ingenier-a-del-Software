
/*@ <authors>
 *
 * Jose Antonio Tortosa Aranda TAIS65
 * Alvaro Velasco Garcia TAIS68
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

#include "IndexPQ.h"

/*@ <answer>

    ACLARACION
    ----------
    Primeramente, separamos las posibles instrucciones, y modificamos en "IndexPQ.h" las funciones push y update, 
    ya que nuetro vector de posiciones ha sido sustituido por un unordered_map, con el fin guardar la posicion en
    la que se encuentra los diferentes elementos, finalmente utilizamos la funcion mostrar, la cual de manera 
    recursiva, en orden de mayor a menor, y en caso de empate, en orden contrario al que han sido añadidos,
    muestra los 3 primeros eventos, y los que haya, si estos son menores a 3.

    COSTE
    -----
    El coste del algoritmo sería de O(N log N), siendo N el numero de instruciones que se van a ejectuar,
    deducimos este coste debido a las operaciones que utilizamos en la priority queue, como viene siendo 
    el pop() y el front().

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


struct datos
{
    int citas;
    int i;
};

bool operator <(const datos& a, const datos& b)
{
    if (b.citas < a.citas)
        return true;
    else if (b.citas == a.citas && b.i < a.i)
        return true;
    else
        return false;
}


void mostrar(IndexPQ<datos> &q, int contador, int tamano)
{
    if (contador == 3 || contador >= tamano)
        return;
    else if (contador == 2)
        cout << contador + 1 << " " << q.top().elem <<"\n";
    else
    {
        auto aux = q.top();
        q.pop();
        cout << contador + 1 << " " << aux.elem << "\n";

        mostrar(q, contador + 1, tamano);
        q.push(aux.elem, aux.prioridad);
    }

}


bool resuelveCaso() {

   // leer los datos de la entrada

    int N, N_citas;
    string tipo, tema;
    cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;

   IndexPQ<datos> q;

   unordered_map<string, int> contador;


   for (int i = 0; i < N; i++)
   {
       cin >> tipo;
       if(tipo == "TC")
       {    
           mostrar(q, 0, q.size());           
       }
       else
       {
           cin >> tema;
           cin >> N_citas;

           datos aux;
           aux.citas = N_citas;
           aux.i = i;

           if (tipo == "C")
           {
               if (contador.count(tema) == 0)
               {
                   q.push(tema, aux);
                   contador[tema] += N_citas;
               }
               else
               {

                   contador[tema] += N_citas;
                   aux.citas = contador[tema];
                   q.update(tema, aux);
               }
     

           }
           else
           {

               if (contador.count(tema) != 0)
               {
                   contador[tema] -= N_citas;
                   aux.citas = contador[tema];
                   q.update(tema, aux);
               }
               
              
           }

       }
   }

   cout << "---\n";
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
