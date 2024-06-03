
/*@ <authors>
 *
 * Alvaro Velasco Garcia TAIS68
 * Jose Antonio Tortosa Aranda TAIS65
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

/*@ <answer>

    EXPLICACION
    -----------
    Dado que nuestro objetivo es minimizar la suma de precios de las pilas, proponemos recorrer las pilas de forma creciente
    de tal modo que solo añadimos a la caja las pilas que cumplan con la restriccion siguiente, no existe un precio que sumado
    con el precio de otro elemento de la caja este sea igual a S


    DEMOSTRACION
    ------------
    P == vector de valores en Ohmios de las pilas (Ohmios = precio)
    V y O (Voraz y Optima) == vectores de booleanos que indican si dicha solucion añade o no la pila a la suma

    Nota: Sobreentendemos que con el fin de minimizar la suma de los costes recorremos las pilas en orden creciente,
          de modo que tanto V y O estan ordenados de forma creciente en valores de P.


    V[0] V[1] ...| V[k] ...
      =   =         !=
    O[0] O[1] ...| O[k] ...

    Vemos que la solucion voraz es optima usando el metodo de reduccion de diferencias, sea V una solucion voraz
    y O una solucion optima, que coinciden hasta la posicion k
    Consideramos los siguientes casos:

    Caso 1: Si V[k] == 1 && O[k] == 0, esto implica que la solucion voraz añade un elemento que la solucion optima no añade, 
            es decir, añade un P[k + j] siendo j > 0, por lo tanto, como ambos vectores estarían teniendo en cuenta los valores
            de P en orden creciente, la solucion optima seria absurda, ya que si hacemos el cambio para que O[k] sea igual a 1 
            reduciriamos el coste y al comprobar su complementario y hacer el cambio para que siga siendo valida tambien reducimos
            el coste, por lo que la solucion optima no es optima, lo cual es contradictorio e indica que ese caso no puede
            suceder.

    Caso 2: Si V[k] == 0 && O[k] == 1, esto implica que en la solucion voraz no añade un elemento que la solucion optima si
            añade, de forma que esto seria absurdo, ya que si nuestra solucion voraz no añade P[k] significa que 
            P[k] + P[k - j] == S, siendo 0 < j <= k, por lo que si la optima si añade P[k] lo convertiría en una solucion no valida
            lo cual es contradictorio e implica que este caso no puede suceder.


    COSTE
    -----
    El coste del algoritmo implementado es O(N) siendo N el numero de pilas que tenemos que recorrer en orden creciente, 
    hasta rellenar la caja, el coste adicional en memoria es O(1), ya que no usamos ninguna herramienta para guardar valores,
    unicamente operaciones constantes.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

long long int coste_minimo(int N, int S)
{
    int contador = 1;
    long long int coste_acumulado = 0;
    int num_pilas = 0;

    while(num_pilas < N)
    {
        if (contador + contador - 1 < S || contador >= S)
        {
            coste_acumulado += contador;
            num_pilas++;
        }
        contador++;
    }

    return coste_acumulado;
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N, S;
    cin >> N >> S;
   if (!std::cin)  // fin de la entrada
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   cout << coste_minimo(N, S) << "\n";
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
