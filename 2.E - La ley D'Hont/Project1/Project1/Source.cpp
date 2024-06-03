
/*@ <authors>
 *
 * Alvaro Garcia Velasco TAIS68
 * Jose Antonio Tortosa Aranda TAIS65
 * 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

/*@ <answer>

    EXPLICACION
    -----------
    
    Creamos un struct de los datos de un partido con sus votos, sus escanos, su coeficiente y su id (posición en la que se introdujo).
    Creamos una priority queue que ordena los partidos comparando primero sus coeficientes, si son iguales, sus votos, y si también son iguales, sus ids.
    Creamos también un vector en el que guardamos en orden de entrada los escanos de los partidos, inicializados a 0.
    Tras introducir los datos a la queue realizamos un bucle que se repetirá hasta que no queden escanos que repartir. En él, sacamos de la queue
    el partido con mayor coeficiente, le sumamos un escano, actualizamos su coeficiente y lo volvemos a introducir en la queue para que vuelva a ordenarse.
    Tambien actualizamos el vector en dicha posicion con su nuevo número de escanos y restamos 1 a los escanos pendientes de repartir.
    Por ultimo, tras finalizar el bucle, escribimos los valores del vector, que son los escanos de los partidos en el orden de entrada, es decir, la solucion.

    COSTE
    -----

    El coste empleado en este algoritmo sería O(N log N), debido a que el coste de las operaciones push y pop en monticulos binarios son de O(log N), como 
    en este caso lo aplicamos a N numero de partidos, entonces el coste asciende a O(N log N).


 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


struct datos
{
    int votos;
    int e;
    double coeficiente;
    int id;
};


bool operator<(const datos& a, const datos& b)
{    
    if (b.coeficiente > a.coeficiente)
        return true;
    else if (b.coeficiente == a.coeficiente && b.votos > a.votos)
        return true;
    else if (b.coeficiente == a.coeficiente && b.votos == a.votos && b.id < a.id)
        return true;
    else
        return false;
}


bool resuelveCaso() {

   // leer los datos de la entrada


    int N, escanos;

    cin >> N;
    cin >> escanos;
   if (N == 0 && escanos == 0)
      return false;

   priority_queue<datos> q;
   vector<int> v(N, 0);


   int aux;
   double aux2;
   for (int i = 0; i < N; ++i)
   {
       cin >> aux;
       aux2 = aux;

       //El coeficiente se inicializa en el numero de votos, ya que sus escanos inicialmente son 0 y la operacion para calcular el coeficiente equivale al numero de votos
       //aux2 = aux / (1 + 0)
       //Usamos un double para que en los siguientes repartos de escanos tengamos en cuenta los decimales a la hora de operar 
       q.push({aux, 0, aux2, i});
   }
       
   
   while (escanos > 0)
   {
       auto aux = q.top();
       q.pop();
       
       aux.e++;
       aux.coeficiente = aux.votos / double(aux.e + 1);
       
       v[aux.id]++;
        
       q.push({ aux.votos, aux.e, aux.coeficiente , aux.id});

       escanos--;
   }
   

   for (int i = 0; i < N; i++)
       cout << v[i] << " ";

   cout << "\n";

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
