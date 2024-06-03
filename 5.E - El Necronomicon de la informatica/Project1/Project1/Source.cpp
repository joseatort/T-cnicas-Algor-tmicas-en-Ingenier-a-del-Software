
/*@ <authors>
 *
 * Alvaro Velasco Garcia TAIS68 
 * Jose Antonio Tortosa Aranda TAIS65
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "DiGrafo.h"  // propios o los de las estructuras de datos de clase
#include "Problema.h"

/*@ <answer>

    ACLARACION
    ----------
    Hemos creado un Grafo Direccionado con una posicion mas de las instrucciones dadas, a continuacion,
    leemos los datos y rellenamos el grafo, para posteriormente llamar a una instancia 
    de la clase operacion. Que tiene la siguiente funcion:

        Hacemos un recorrido en profundidad en el que desde el vertice origen, en este corresponde
        a la primera instruccion, hasta el ultimo mas 1, comprobamos si existe un camino.
        En caso negativo, la variable llega_fin sera false, y por lo tanto el programa no acabará nunca,
        el resultado dado sera "NUNCA".

        En caso afirmativo, la variable llega_fin sera true, y comprobaremos si existen ciclos en el
        grafo dirigido, esta comprobacion tambien se hace a medida que se recorre el grafo, debido al
        uso del vector "apilado". Si existen ciclos devolvemos "A VECES", y si no existen,
        devolvemos "SIEMPRE"


    COSTE
    -----
    El coste del algoritmo en el peor de los casos seria O(V + A), siendo V el numero de vertices
    del grafo y A el numero de aristas, ya que en el peor de los casos, en el recorrido en profundidad
    dfs recorremos todos los vertices y todas las aristas.

    Otras operaciones que usamos quitando la lectura, que sería lineal, tienen coste constante, 
    como por ejemplo la funcion ponArista del grafo, por lo tanto no cambia el coste del algoritmo.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;
   
   Digrafo dg(N + 1);
   string aux1;
   int aux2;
   for(int i = 0 ; i < N; i++)
   {
       cin >> aux1;

       if (aux1 == "A")
       {
            dg.ponArista(i, i + 1);
       }
       else if (aux1 == "J")
       {
           cin >> aux2;
           dg.ponArista(i, aux2 - 1);
       }
       else
       {
           cin >> aux2;

           dg.ponArista(i, i + 1);
           dg.ponArista(i, aux2 - 1);
       }
 
   }

   // resolver el caso posiblemente llamando a otras funciones
   Operaciones sol(dg);

   // escribir la solución
   cout << sol.solucion() << "\n";

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
