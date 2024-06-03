
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>

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

using matriz = vector<vector<int>>;
//filas corresponden a letra que empieza
//columnas corresponden a letra que acaba

int pal(matriz& m, string palabra)
{
    int N = m.size();
    for (int i = N - 2; i >= 0; --i)
    {
        for (int j = i + 1; j < N; j++)
        {
            //Intercala entre la ultima y su anterior
            if (palabra[i] == palabra[j])
                m[i][j] = m[i + 1][j - 1];
            //Añade al final de la ultima
            else
                m[i][j] = min(m[i + 1][j], m[i][j - 1]) + 1;
        }   
    }

    return m[0][N - 1];
}

string reconstruccion(int i, int j, matriz M, string &palabra)
{

    if (i == j)
        return string(1, palabra[i]);
    else if (i > j)
        return "";
    else
        //Intercala entre la ultima y su anterior
        if (palabra[i] == palabra[j])
            return palabra[i] + reconstruccion(i + 1, j - 1, M, palabra) + palabra[j];
        //Entra en la posicion i y pega la posicion j
        else if(M[i][j] - 1 == M[i][j - 1])
            return palabra[j] + reconstruccion(i, j - 1 , M, palabra) + palabra[j];
        //Entra en la posicion j y pega la posicion i
        else
            return palabra[i] + reconstruccion(i + 1, j, M, palabra) + palabra[i];

}


pair<int, string> progDinamica(string palabra)
{
    int N = palabra.size();
    matriz m(N, vector<int>(N, 0));
    int minLetras = pal(m, palabra);

    string nuevapalabra = palabra;
    if (minLetras != 0)
    {
        nuevapalabra = reconstruccion(0, N - 1, m, palabra);
    }

    return { minLetras, nuevapalabra };
}


bool resuelveCaso() {

   // leer los datos de la entrada
    string palabra;
    cin >> palabra;
   if (!std::cin)  // fin de la entrada
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   pair<int, string> sol = progDinamica(palabra);
   
   cout << sol.first << " " << sol.second << "\n";
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
