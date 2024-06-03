
/*@ <authors>
 *
 * Alvaro Velasco Garcia TAIS68
 * Jose Antonio Tortosa Aranda TAIS65
 * 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EntInf.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

    ACLARACION
    ----------
    C = es la cantidad a alcanzar
    N = es el numero de monedas del sistema
    
    monedas = vector en el que almacenamos las monedas minimas necesarias para alcanzar C
    maneras = vector en el que almacenamos las maneras que existen para alcanzar C, con el minimo 
              numero de monedas

    v = vector del tamaño N que contiene los tipos de monedas dados

    RECURSION
    ---------
    maneras(i, j) = maneras que existen para alcazar j, con el minimo numero de monedas de tipo v[0] a v[i - 1]
    monedas(i, j) = numero minimo de monedas necesarias para alcanzar j, usando monedas de tipo v[0] a v[i - 1]
    
    Casos Base:
    monedas(0, j) = Infinito
    monedas(i, 0) = 0

    maneras(0, j) = 0
    maneras(i, 0) = 1

    Casos Recursivos:
    monedas(i, j) = min( monedas(i, j - v[i - 1]) + 1)        si v[i - 1] < j

    maneras(i, j) = maneras(i, j - v[i - 1])                  si v[i - 1] < j && (monedas(i, j) > monedas(i, j - v[i - 1]) + 1)
    maneras(i, j) = maneras(i, j) + maneras(i, j - v[i - 1])  si v[i - 1] < j && (monedas(i, j) == monedas(i, j - v[i - 1]) + 1)

    EXPLICACION
    -----------
    Realizamos el problema de forma ascendente, recorriendo la matriz de izquierda a derecha y de arriba
    a abajo, por lo que nuestra solucion final se encontraria en la posicion [N][C] de nuestra matriz.
    Usamos un total de 2 matrices, las cuales se pueden llegar a reducir a dos vectores monedas y maneras,
    de tamaño C, el ultimo almacenara nuestra solucion

    Para cada moneda recorremos cada uno de los vectores simultaneamente para poder ir deduciendo los 
    resultados, con respecto al numero de monedas recurrimos al minimo entre añadirla o no añadirla, 
    es decir, min(monedas[j], monedas[j - v[i - 1]] + 1), y con respecto a las maneras, comprobamos si la solucion
    que tenemos actualmente reduce el numero de monedas que ya teniamos, en dicho caso recurrimos a
    maneras[j - v[i - 1]], en caso de ser iguales, recurrimos a añadir a las maneras que teniamos para esa 
    j, las maneras que habia en maneras[j - v[i - 1]]

    Inicialmente el vector maneras inicializa todas las posiciones a 0, a excepcion de maneras[0] que empieza en 1,
    el vector monedas inicializa todas las posiciones a Infinito, a excepcion de monedas[0] que empieza en 0

    Finalmente, la solucion se encontraria en maneras[C]

    COSTE
    -----
    El coste en tiempo de algoritmo es O(N * C), ya que realizamos N * C operaciones, cada una de ellas
    con coste O(1)

    El coste en espacio adicional es de O(2C), es decir, O(C) dado que usamos dos vectores auxiliares, 
    monedas y maneras


 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int ProgDinamica(int C, const vector<int>& v)
{
    int N = v.size();

    vector<EntInf> monedas (C + 1, Infinito);

    vector<int> maneras (C + 1, 0);

    EntInf minimo = Infinito;

    monedas[0] = 0;
    maneras[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = v[i - 1]; j <= C; j++)
        {
            if (monedas[j] > monedas[j - v[i - 1]] + 1)
                maneras[j] = maneras[j - v[i - 1]];
            else if(monedas[j] == monedas[j - v[i - 1]] + 1)
                maneras[j] += maneras[j - v[i - 1]];

            monedas[j] = min(monedas[j], monedas[j - v[i - 1]] + 1);

        }

    }

    return maneras[C];
}


bool resuelveCaso() {

   // leer los datos de la entrada
    int C, N;
    cin >> C >> N;
   if (!std::cin)  // fin de la entrada
      return false;

   vector<int> v(N);
   for (int i = 0; i < N; i++)
       cin >> v[i];

   cout << ProgDinamica(C, v) << "\n";
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
