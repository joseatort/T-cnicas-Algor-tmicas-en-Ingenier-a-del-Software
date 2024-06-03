/*@ <authors>
 *
 * Alvaro Velasco Garcia TAIS68
 * Jose Antonio Tortosa Aranda TAIS65
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "DiGrafoValorado.h"
#include "Problema.h"
using namespace std;

/*@ <answer>

    EXPLICACION
    ----------- 
    Interpretamos los datos como un DigrafoValorado, y guardamos las carreteras como aristas que pueden
    leerse en ambos sentidos, las aristas recogen el inicio, fin y coste.

    A continuacion, hacemos dos Dijkstra (uno para cada planta) para calcular el coste de recorrer la distancia de cada 
    planta a cada pueblo, y recogemos los dos vectores de costes, uno de la planta norte y otro de la planta sur.

    Creamos un vector de pair<int,int> llamado diferencias con una posicion para cada pueblo (N - 2), 
    en el que guardamos:

        En el primer valor (.first): La diferencia de coste en alcanzar dicho pueblo desde las dos plantas en valor 
                            absoluto. Es decir, la resta del coste de alcanzar dicho pueblo desde la planta norte
                            y el coste desde la planta sur.

        En el segundo valor (.second): El indice de dicho pueblo, que nos servira mas adelante como un identificador.

    Finalmente, el vector de diferencias lo ordenamos de mayor a menor en funcion del primer valor, iteramos el vector,
    comparamos el coste de la planta Norte (Planta_Norte[diferencias[y].second]), con el de la planta Sur(Planta_Sur[diferencias[y].second]) 
    y seleccionamos el menor siempre que desde la planta a la que le corresponde no hayan salido ya (N - 2) /2 camiones, ya que en ese
    caso el camion seria asignado a la planta contraria, para que finalmente el numero de camiones en ambas sea el mismo.

    
    DEMOSTRACION
    ------------
    V y O (Voraz y Optima) == vectores de string que indican si para cada pueblo añade el camino que lo une con la 
                              planta Norte ("N") o si se añade el camino que lo une con la planta Sur ("S")

    Planta_Norte == vector de int, que representa los costes de los caminos de cada pueblo a la planta Norte.  
    Planta_Sur == vector de int, que representa los costes de los caminos de cada pueblo a la planta Sur.  

    Nuestra estrategia voraz, es similar a la resolucion de forma voraz del Problema de la Mochila fraccionaria, solo que 
    nosotros en lugar tomar una densidad, tomamos el valor absoluto de la diferencia de coste descrita anteriormente, siendo
    el valor, el coste que nos ahorrariamos al coger el camino menor. De este modo estamos seleccionando de forma creciente 
    las opciones que nos ahorran un mayor coste con el fin de reducir lo maximo posible el coste total.
                              
    V[0] V[1] ... | V[k] ...
     =    =          !=   
    O[0] O[1] ... | O[k] ...

    Vemos que la solucion voraz es optima usando el metodo de reduccion de diferencias, sea V una solucion voraz
    y O una solucion optima, que coinciden hasta la posicion k.
    Consideramos los siguientes casos:
        
        Caso 1: Si V[k] == "N" y O[k] == "S", esto implica que la solucion voraz selecciona el camino desde la planta Norte
                y la solucion Optima añade el camino desde la planta Sur, distinguiriamos los siguientes subcasos:

                Caso 1.1: Si Planta_Norte[k] < Planta_Sur[k], esto implica que nuestra solucion voraz añade
                          al ser posible por el numero de camiones, el camino desde la planta Norte, de esta
                          forma seria absurdo por parte de la solucion optima seleccionar un coste mayor. Por lo tanto,
                          esto no podria suceder.

                Caso 1.2: Si Planta_Norte[k] == Planta_Sur[k], si el coste de ambos caminos es igual y la solucion
                          voraz añade la planta Norte, significa que aun quedan camiones que puedan salir desde la planta 
                          Norte, por lo tanto, se podria susituir la solucion O[k] a "N", sin afectar al coste, 
                          pareciendose esta mas a nuetra solucion voraz.

        Caso 2: Si V[k] == "S" y O[k] == "N", esto implica que la solucion voraz selecciona el camino desde la planta Sur
                y la solucion Optima añade el camino desde la planta Norte, distinguiriamos los siguientes subcasos:

                Caso 2.1: Si Planta_Sur[k] < Planta_Norte[k], esto implica que nuestra solucion voraz añade
                          al ser posible por el numero de camiones, el camino desde la planta Sur, de esta
                          forma seria absurdo por parte de la solucion optima seleccionar un coste mayor. Por lo tanto,
                          esto no podria suceder.

                Caso 2.2: Si Planta_Sur[k] == Planta_Norte[k], si el coste de ambos caminos es igual y la solucion
                          voraz añade la planta Sur, significa que aun quedan camiones que puedan salir desde la planta 
                          Sur, por lo tanto, se podria susituir la solucion O[k] a "S", sin afectar al coste, 
                          pareciendose esta mas a nuetra solucion voraz.

    COSTE
    -----
    El coste del algoritmo implementado es O(A log N) siendo A el numero de carreteras y N el numero de puntos 
    importantes (Pueblos y plantas), debido al uso del Algoritmo Dijkstra. En espacio adicional, tenemos un coste de O(N),
    debido al espacio adicional que necesita Dijkstra y que ademas se tambien se encuentre en los vectores Planta_Norte y Planta_Sur
    que usamos para recoger los valores dados por el.

    Tambien usamos operaciones con coste O(N log N), como viene siendo en el caso del sort, donde ordenamos de mayor 
    a menor el vector de diferencias, y otros en funcion de O(A) para guardar las carreteras en el grafo dirigido.

    En conclusion, el coste del algoritmo implementado es O(A log N), y en espacio adicional O(N), siendo este 
    mayor a los anteriores.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool compare(pair<long int, int>& a, pair<long int, int>& b)
{
    return a.first > b.first;
}


long int coste_minimo(vector <long int> &Planta_Norte, vector <long int>& Planta_Sur, int N)
{
    vector<pair<long int,int>> diferencias(N - 2);
    long int coste = 0;
    int contadorPlanta_Norte = 0, contadorPlanta_Sur = 0;
    for (int i = 1; i < N - 1; i++)
    {
        diferencias[i - 1].first = abs(Planta_Norte[i] - Planta_Sur[i]);
        diferencias[i - 1].second = i;
    }

    sort(diferencias.begin(), diferencias.end(),compare);

    for (int y = 0; y < N - 2; y++)
    {
        int indice = diferencias[y].second;
        if ((Planta_Norte[indice] < Planta_Sur[indice] || contadorPlanta_Sur == (N - 2) / 2) && contadorPlanta_Norte < (N - 2) / 2)
        {
            coste += Planta_Norte[indice] * 2;
            contadorPlanta_Norte++;
        }
        else
        {
            coste += Planta_Sur[indice] * 2;
            contadorPlanta_Sur++;
        }
            
    }

    return coste;
}

bool resuelveCaso() {

   // leer los datos de la entrada

    int N, A;
    cin >> N >> A;
   if (!std::cin)  // fin de la entrada
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   DigrafoValorado<long int> carreteras(N);

   int v, w, coste;
   for (int i = 0; i < A; i++)
   {
       cin >> v >> w >> coste;
       carreteras.ponArista({ v - 1, w - 1, coste });
       carreteras.ponArista({ w - 1, v - 1, coste });
   }
       
   // escribir la solución
   Dijkstra<long int> sol(carreteras, 0);
   vector<long int> Planta_Norte = sol.distancia();

   Dijkstra<long int> sol2(carreteras, N - 1);
   vector<long int> Planta_Sur = sol2.distancia();

   cout << coste_minimo(Planta_Norte, Planta_Sur, N) << "\n";

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
