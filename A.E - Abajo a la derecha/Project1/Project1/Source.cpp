
/*@ <authors>
 *
 * Alvaro Velasco Garcia TAIS68
 * Jose Antionio Tortosa Aranda TAIS65
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*@ <answer>
    
     ACLARACION
     ----------
     F = numero de filas de la matriz
     C = numero de columnas de la matriz
     dato = valor correspondiente en posicion [i][j] de la matriz de entrada
     dato_2 = valor correspondiente en posicion [x][y] de la matriz de entrada
 
     RECURSION
     ---------
     maneras(i,j) = es el numero de maneras en las que se puede alcanzar la posicion [i][j] de la matriz
                    desde la posicion [0][0].


     maneras(i,j) = { sumatorio ( matriz(x,y) | ( (i,j) = (x + dato_2, y) || (i,j) = (x, y + dato_2) ) ) }


     CASOS BASE
     maneras(0,0) = 1

     La llamada inicial es maneras(F, C)

     RESOLUCION
     ----------
     Resolvemos el ejercicio mediante programacion dinamica ascendente, a parte de la matriz de entrada, 
     creamos una nueva matriz auxiliar del mismo tamaño (F * C), en la que guardamos el numero de maneras 
     en las que esta posicion puede ser alcanzada desde la posicion [0][0], por lo que nuestra solucion final,
     se encontraría en la posicion [F - 1][C - 1] de la matriz auxiliar. Hacemos el recorrido de datos de 
     izquierda a derecha y de arriba a abajo. 
     
     Inicializamos todas las posiciones de la matriz auxiliar a 0, a excepcion de la posicion [0][0]
     que inicializamos en 1. En la llamada a cada posicion [i][j], comprobamos si dicha posicion es alcanzable,
     es decir, si el valor en dicha matriz auxiliar es distinto de 0. En ese caso, se comprueban si las posiciones
     [i + dato][j] y [i][j + dato], estan dentro de los marcos de la matriz. En caso afirmativo, se suman al valor 
     en dichas posiciones de la matriz auxiliar las formas de alcanzar la posicion [i][j].


     COSTE
     -----
     El coste algoritmico es O(F * C), ya que realizanos un total de F*C operaciones, 
     cada una de ellas con coste O(1)

     El coste en espacio adicional es O(F*C), ya que usamos una matriz de ese tamaño para
     almacenar los datos

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using matriz = vector<vector<int>>;

int maneras(const matriz& datos, int F, int C)
{
    matriz aux (F, vector<int>(C, 0));
    aux[0][0] = 1;
    for(int i = 0; i < F; i++)
        for (int j = 0; j < C; j++)
        {

            if (aux[i][j] != 0)
            {
                int dato = datos[i][j];

                if(i + dato < F)
                    aux[i + dato][j] += aux[i][j];
                
                if (j + dato < C)
                    aux[i][j + dato] += aux[i][j];
            }
               
        }

    return aux[F - 1][C - 1];
}

bool resuelveCaso() {

   // leer los datos de la entrada
    int F, C;
    cin >> F >> C;
   if (!std::cin)  // fin de la entrada
      return false;

   matriz m(F, vector<int>(C));

   for (int i = 0; i < F; i++)
       for (int y = 0; y < C; y++)
           cin >> m[i][y];
   // resolver el caso posiblemente llamando a otras funciones
   cout << maneras(m, F, C) << "\n";
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
