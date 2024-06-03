/*@ <authors>
 *
 * Alvaro Velasco Garcia TAIS68
 * Jose Antonio Tortosa Aranda TAIS65
 * 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.


    ACLARACION
    ----------
    Usamos i, como inicio de la lista del turno de mañana
    Usamos j, como inicio de la lista del turno de tarde 
    
    Tam_M = numero de canciones en la lista del turno de mañana
    Tam_T = numero de canciones en la lista del turno de tarde
    M = lista de canciones turno de mañana
    T = lista de canciones turno de tarde


    RECURSION
    ---------
    listaComun(i,j) = numero maximo de canciones comunes en ambas listas (mañana y tarde), y 
                      las cuales tienen que estar en el mismo orden que aparacen originalmente en su lista.
    

    Funcion de recurrencia:
    listaComun(i,j) = { listaComun(i + 1, j + 1) + 1, si M[i] == T[j]                    }
                      {                                                                  }
                      { max(listaComun(i + 1, j), listaComun(i, j + 1),  si M[i] != T[j] }

    Caso base:
        listaComun(i,j) = 0, si (i == Tam_M || j == Tam_T)
   
    Llamada inicial: listaComun(0, 0);


    RESOLUCION
    ----------
    Utilizamos programacion dinamica descendente, con el apoyo de una matriz de enteros del tamaño Tam_M * Tam_T, en la que guardamos 
    el numero maximo de canciones comunes en ambas listas (mañana y tarde), las cuales tienen que estar en el mismo orden que aparacen 
    originalmente en su lista, teniendo como indices i, j los inicios a los que nos referimos por cada lista, matriz[i][j].

    Nuestro numero maximo, quedaria en la posicion matriz[0][0], por lo que empezariamos en la posicion matriz[Tam_M - 1][Tam_T - 1] 
    haciendo el recorrido de datos de derecha a izquierda y de abajo a arriba. Inicializamos todos las celdas de la matriz a -1, 
    y vamos buscando el maximo de canciones por celda como hemos dicho anteriormente. 

    En cada llamada [i][j], comprobamos que la posicion i, j, es una posicion valida que se encuentra dentro de la matriz,
    en caso contrario, devolveria 0, a continuacion, comprobamos si la operacion listaComun(i,j) ha sido calculada anteriormente,
    es decir, si matriz[i][j] != -1.

    Finalmente, tenemos dos posibles casos:

    1) En el que ambas canciones son iguales, M[i] == T[j], por lo tanto, añadimos la cancion a la lista comun
    2) En el que las canciones son distintas, M[i] != T[j], nos quedamos con la mejor opcion de no coger la cancion de la lista 
       del turno de mañana o no coger la del turno de tarde, es decir, elegimos el maximo entre una u otra.


    En la reconstruccion, hacemos el mismo recorrido de forma descendente, y vamos acumulando la solucion en un vector de strings, 
    la funcion realiza lo siguiente:

    Si la posicion i, j, es una posicion que se encuentra fuera de la matriz inicializamos el vector vacio.
    A continuacion, realizamos el mismo recorrido que en listaComun pero teniendo en cuenta los valores guardados en la matriz,
    y en caso de que M[i] == T[j] añadimos dicha cancion al vector.

    Para concluir, mostramos los elementos en el orden inverso al que estan en el vector, dado que se han ido añadiendo, de
    derecha a izquierda y de abajo arriba de acuerdo con los datos de la matriz.

    COSTE
    -----
    El coste del algoritmo en el caso peor es de O(Tam_M * Tam_T), ya que rellenamos Tam_M * Tam_T celdas de la tabla, cada una de 
    ellas con coste O(1).
    
    El coste del algoritmo en tiempo de reconstruccion es de O(Tam_M * Tam_T), ya que recorremos de nuevo la matriz completa.

    El coste en espacio adicional esta en O(Tam_M * Tam_T), debido a la matriz creada, usada para guardar las soluciones a los 
    subproblemas.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using tmatriz = vector<vector<int>> ;

void lectura(const string &linea, vector<string>& palabras)
{
    string aux;

    int contador = 0;
    for (int i = 0; i < linea.size(); i++)
    {
        if (linea[i] == ' ')
        {
            palabras.push_back(aux);
            contador = 0;
            aux = "";
        }
        else
        {
            aux.push_back(linea[i]);
            contador++;
        }
    }
}

int listaComun(int ini1, const vector<string>& m, int ini2, const vector<string>& t, tmatriz &matriz)
{
    if (ini1 == m.size() || ini2 == t.size())
        return 0;
    else if (matriz[ini1][ini2] != -1)
        return matriz[ini1][ini2];
    else
    {
        if (m[ini1] == t[ini2])
            matriz[ini1][ini2] = listaComun(ini1 + 1, m, ini2 + 1, t, matriz) + 1;
        else {
            int tam1 = listaComun(ini1 + 1, m, ini2, t, matriz);
            int tam2 = listaComun(ini1, m, ini2 + 1, t, matriz);
            matriz[ini1][ini2] = max(tam1, tam2);
        }

        return matriz[ini1][ini2];
    }

}

vector<string> reconstruccion(int ini1, const vector<string>& m, int ini2, const vector<string>& t, const tmatriz& matriz)
{
    if (ini1 == m.size() || ini2 == t.size() )
        return vector<string>(0);
    else
    {

        if (m[ini1] == t[ini2])
        {
            vector<string> aux = reconstruccion(ini1 + 1, m, ini2 + 1, t, matriz);
            aux.push_back(m[ini1]);
            return aux;
        }
        else {

            if (ini1 + 1 < m.size() && matriz[ini1][ini2] == matriz[ini1 + 1][ini2])
                return reconstruccion(ini1 + 1, m, ini2, t, matriz);
            else if (ini2 + 1 < t.size())
                return reconstruccion(ini1, m, ini2 + 1, t, matriz);
        }

    }


}

bool resuelveCaso() {

   // leer los datos de la entrada
    string linea1, linea2;
    getline(cin, linea1);
    getline(cin, linea2);

    if (!std::cin)  // fin de la entrada
        return false;

    linea1.push_back(' ');
    linea2.push_back(' ');

    vector<string> manana;
    vector<string> tarde;

    lectura(linea1, manana);
    lectura(linea2, tarde);

    tmatriz matriz(manana.size(), vector<int> (tarde.size(), -1));
    listaComun(0, manana, 0, tarde, matriz);

    vector<string> salida = reconstruccion(0, manana, 0, tarde, matriz);

    for (int i = salida.size() - 1; i >= 0; i--)
        cout << salida[i] << " ";

    cout << "\n";

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
