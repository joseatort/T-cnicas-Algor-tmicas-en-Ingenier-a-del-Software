
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
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


typedef struct
{
    float duracion;
    float puntuacion;
}Canciones;

bool compare(const Canciones & a, const Canciones& b)
{
    return (a.duracion / a.puntuacion) < (b.duracion / b.puntuacion);
}

typedef struct Nodo
{
    int k;
    vector<int> sol;
    float puntuacion_actual;
    float puntuacion_estimada;
    float duracion1;
    float duracion2;
    bool operator<(Nodo const& otro) const
    {
        return otro.puntuacion_estimada > puntuacion_estimada;
    }

};

float calcular_estimacion(const vector<Canciones>& canciones, float D, Nodo const x)
{
    float espacio_disponible = (D - x.duracion1) + (D - x.duracion2);
    float estimacion = x.puntuacion_actual;

    int i = x.k + 1;
    while (i < canciones.size() && canciones[i].duracion <= espacio_disponible)
    {
        espacio_disponible -= canciones[i].duracion;
        estimacion += canciones[i].puntuacion;
        i++;
    }

    if (i < canciones.size())
        estimacion += (canciones[i].puntuacion * espacio_disponible) / canciones[i].duracion;

    return estimacion;
}


void RamificacionyPoda(const vector<Canciones> &canciones, float D,
                        float& maximo_puntuacion)
{
    int N = canciones.size();

    Nodo raiz;

    raiz.k = -1;
    raiz.puntuacion_actual = 0;
    raiz.duracion1 = 0;
    raiz.duracion2 = 0;
    //Llamamos a una operacion voraz que calcure la operacion
    raiz.puntuacion_estimada = calcular_estimacion(canciones, D, raiz);

    raiz.sol = vector<int>(N, -1);
    priority_queue<Nodo> cola;
    cola.push(raiz);

    while (!cola.empty() && cola.top().puntuacion_estimada > maximo_puntuacion)
    {
        raiz = cola.top();
        cola.pop();
        raiz.k++;

        Nodo x(raiz);

        //Probamos a añadirlo a la primera lista
        if (raiz.duracion1 + canciones[x.k].duracion <= D)
        {
            x.sol[x.k] = 1;
            x.puntuacion_actual = raiz.puntuacion_actual + canciones[x.k].puntuacion;
            x.duracion1 = raiz.duracion1 + canciones[x.k].duracion;
            x.puntuacion_estimada = raiz.puntuacion_estimada;
            if (x.k == N - 1)
                maximo_puntuacion = x.puntuacion_actual;
            else
                cola.push(x);
            
            x.duracion1 = raiz.duracion1;
        }

        //Probamos a añadirlo a la segunda lista
        if (raiz.duracion2 + canciones[x.k].duracion <= D)
        {
            x.sol[x.k] = 2;
            x.puntuacion_actual = raiz.puntuacion_actual + canciones[x.k].puntuacion;     
            x.duracion2 = raiz.duracion2 + canciones[x.k].duracion;
            x.puntuacion_estimada = raiz.puntuacion_estimada;
            if (x.k == N - 1)
                maximo_puntuacion = x.puntuacion_actual;
            else
                cola.push(x);

            x.duracion2 = raiz.duracion2;
        }


        //Probamos a no añadirlo a ninguna lista
        x.sol[x.k] = 0;
        x.duracion1 = raiz.duracion1;
        x.duracion2 = raiz.duracion2;
        x.puntuacion_actual = raiz.puntuacion_actual;

        x.puntuacion_estimada = calcular_estimacion(canciones, D, x);
        
        if (x.puntuacion_estimada > maximo_puntuacion)
        {
            if (x.k == N - 1)
                maximo_puntuacion = x.puntuacion_actual;
            else
                cola.push(x);
        }

        
    }

}

bool resuelveCaso() {

   // leer los datos de la entrada
    int N;
    float D;
    cin >> N >> D;
    if (N == 0)
      return false;

    vector<Canciones> canciones(N);
    for (int i = 0; i < N; i++)
    {
        cin >> canciones[i].duracion;
        cin >> canciones[i].puntuacion;
    }
   // resolver el caso posiblemente llamando a otras funciones

    sort(canciones.begin(), canciones.end(), compare);

    float maximo_puntuacion = 0;
    RamificacionyPoda(canciones, D, maximo_puntuacion);
    cout << maximo_puntuacion << "\n";
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
