
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

#include "EntInf.h"


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

using posicion = pair<int, int>;
using matriz = vector<vector<EntInf>>;
using matriz_n = vector<vector<int>>;
using matriz_posiciones = vector<vector<bool>>;

struct Camara
{
    int x;
    int y;
    int valor;
};

void transformar(vector<string>& laberinto, queue<Camara> &camaras)
{
    posicion norte(-1, 0), sur(1, 0), este(0, 1), oeste(0, -1);

    bool mn, ms, me, mo;

    while (!camaras.empty())
    {
        Camara actual = camaras.front();
        camaras.pop();

        //Si encontramos un muro no seguimos
        mn = false, ms = false, me = false, mo = false;

        laberinto[actual.x][actual.y] = 'V';

        for (int i = 1; i <= actual.valor; i++)
        {
            //Norte
            if (actual.x + i * norte.first >= 0 && !mn)
            {
                if (laberinto[actual.x + i * norte.first][actual.y] == '#')
                    mn = true;
                else
                    laberinto[actual.x + i * norte.first][actual.y] = 'V';

            }
                
            //Sur
            if (actual.x + i * sur.first < laberinto.size() && !ms)
            {
                if (laberinto[actual.x + i * sur.first][actual.y] == '#')
                    ms = true;
                else
                    laberinto[actual.x + i * sur.first][actual.y] = 'V';
            }
                
            //Este
            if (actual.y + i * este.second < laberinto[0].size() && !me)
            {
                if (laberinto[actual.x][actual.y + i * este.second] == '#')
                    me = true;
                else
                    laberinto[actual.x][actual.y + i * este.second] = 'V';
            }
                
            //Oeste
            if (actual.y + i * oeste.second >= 0 && !mo)
            {
                if (laberinto[actual.x][actual.y + i * oeste.second] == '#')
                    mo = true;
                else
                    laberinto[actual.x][actual.y + i * oeste.second] = 'V';
            }
                
        }

    }
}

//Forma Descendente (No es muy rentable por el coste en el vector de booleanos)
EntInf ProgramacionDinamica2(int i, int j, pair<int, int> Salida, const vector<string>& laberinto, matriz & aux, matriz_posiciones mposiciones)
{
    if (i == Salida.first && j == Salida.second)
    {
        aux[i][j] = 0;
        return aux[i][j];
    }
    else if (laberinto[i][j] == 'V')
        return Infinito;
    else if (aux[i][j] != -1)
        return aux[i][j];
    else
    {
        EntInf auxiliar = Infinito;
        //Norte
        if (i - 1 >= 0 && !mposiciones[i - 1][j] && laberinto[i - 1][j] != 'V' && laberinto[i - 1][j] != '#')
        {
            mposiciones[i][j] = true;
            auxiliar = min(auxiliar, ProgramacionDinamica2(i - 1, j, Salida, laberinto, aux, mposiciones) + 1);
        }

        //Sur
        if (i + 1 < laberinto.size() && !mposiciones[i + 1][j] && laberinto[i + 1][j] != 'V' && laberinto[i + 1][j] != '#')
        {
            mposiciones[i][j] = true;
            auxiliar = min(auxiliar, ProgramacionDinamica2(i + 1, j, Salida, laberinto, aux, mposiciones) + 1);
        }

        //Este
        if (j + 1 < laberinto[0].size() && !mposiciones[i][j + 1] && laberinto[i][j + 1] != 'V' && laberinto[i][j + 1] != '#')
        {
            mposiciones[i][j] = true;
            auxiliar = min(auxiliar, ProgramacionDinamica2(i, j + 1, Salida, laberinto, aux, mposiciones) + 1);
        }

        //Oeste
        if (j - 1 >= 0 && !mposiciones[i][j - 1] && laberinto[i][j - 1] != 'V' && laberinto[i][j - 1] != '#')
        {
            mposiciones[i][j] = true;
            auxiliar = min(auxiliar, ProgramacionDinamica2(i, j - 1, Salida, laberinto, aux, mposiciones) + 1);
        }

        aux[i][j] = auxiliar;
        return aux[i][j];
    }

}

//Forma Ascendente - No eficiente
EntInf ProgramacionDinamica(pair<int, int> Entrada, pair<int, int> Salida, const vector<string>& laberinto)
{
    int F = laberinto.size();
    int C = laberinto[0].size();

    matriz aux(F, vector<EntInf>(C, Infinito));

    //Hacemos el recorrido desde la salida hacia la entrada
    aux[Salida.first][Salida.second] = 0;

    //El primer for sirve para ver el numero de casillas adyacentes, es un estilo a Floid, a medida que se 
    //va repitiendo el bucle se van generando nuevos resultado, por lo tanto tenemos que probralos tantas
    //veces como maximo se posible, por ejemplo como si la Entrada estuviese en una esquina y la salida 
    //en la opuesta, el maximo sería F * C
    for (int d = 1; d < F * C; ++d) {
        for (int i = 0; i < F; ++i) {
            for (int j = 0; j < C; ++j) {
                if (laberinto[i][j] != 'V' && laberinto[i][j] != '#') {

                    //Norte
                    if (i - 1 >= 0) {
                        aux[i][j] = min(aux[i][j], aux[i - 1][j] + 1);
                    }
                    //Sur
                    if (i + 1 < F) {
                        aux[i][j] = min(aux[i][j], aux[i + 1][j] + 1);
                    }
                    //Este
                    if (j - 1 >= 0) {
                        aux[i][j] = min(aux[i][j], aux[i][j - 1] + 1);
                    }
                    //Oeste
                    if (j + 1 < C) {
                        aux[i][j] = min(aux[i][j], aux[i][j + 1] + 1);
                    }
                }
            }
        }
    }

    // Devolvemos el resultado para la casilla de entrada
    return aux[Entrada.first][Entrada.second];
}


EntInf bfs(const vector<string>& laberinto, pair<int,int> Entrada, pair<int, int> Salida)
{
    posicion posiciones[] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

    int F = laberinto.size();
    int C = laberinto[0].size();

    matriz dist (F, vector<EntInf> (C, Infinito));
    queue<posicion> q;

    //Comprobamos si la entrada esta vigilada
    if (laberinto[Entrada.first][Entrada.second] == 'V')
        return Infinito;

    dist[Entrada.first][Entrada.second] = 0;
    q.push(Entrada);
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();

        for (posicion w : posiciones)
        {

            int x_siguiente = v.first + w.first;
            int y_siguiente = v.second + w.second;

            //comprobamos margenes
            if (x_siguiente >= 0 && x_siguiente < F && y_siguiente >= 0 && y_siguiente < C)
            {

                //Comprobamos si esa casilla se puede visitar o no
                if (laberinto[x_siguiente][y_siguiente] != '#' && laberinto[x_siguiente][y_siguiente] != 'V')
                {

                    //Aplicamos el metodo relajar de dijsktra
                    if (dist[x_siguiente][y_siguiente] > dist[v.first][v.second] + 1) {
                        dist[x_siguiente][y_siguiente] = dist[v.first][v.second] + 1;
                        q.push({ x_siguiente , y_siguiente });
                    }

                }


            }



        }
    }

    return dist[Salida.first][Salida.second];
}




void resuelveCaso() {

    int C, F;
    cin >> C >> F;


    pair<int,int> Entrada, Salida;
    vector<string> laberinto(F, "");
    queue<Camara> camaras;
    char aux;
    for (int i = 0; i < F; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> aux;
            if (aux >= 48 && aux <= 57)
                camaras.push({ i, j, aux - 48 });
            else if (aux == 'E')
                Entrada = { i, j };
            else if (aux == 'P')
                Salida = { i, j };

            laberinto[i].push_back(aux);
        }
        
    //Marcamos zonas vigiladas
    transformar(laberinto, camaras);
    //matriz_posiciones mposiciones(F, vector<bool>(C, false));
    EntInf sol = bfs(laberinto, Entrada, Salida);
    if (sol == Infinito)
        cout << "NO";
    else
        cout << sol;
    cout << "\n";
   

}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("1.in");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
