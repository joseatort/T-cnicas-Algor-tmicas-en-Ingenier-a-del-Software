
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

typedef struct Baterias
{
    int id;
    int capacidad;
    int Tcarga;

    bool operator<(const Baterias& otro) const
    {
        return (otro.Tcarga > Tcarga || (otro.Tcarga == Tcarga && otro.id > id));
    }
};


bool resuelveCaso() {

   // leer los datos de la entrada
    int B;
    cin >> B;
    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<Baterias> baterias_actuales;
    int aux;

    for (int i = 0; i < B; i++)
    {
        cin >> aux;
        baterias_actuales.push({ i + 1, aux });
    }

    int R;
    cin >> R;

    queue<pair<int,int>> respuestos;
    for (int i = 0; i < R; i++)
    {
        cin >> aux;
        respuestos.push({ i + 1, aux });
    }

    int desgaste, T;
    cin >> desgaste >> T;

    while (!baterias_actuales.empty() && baterias_actuales.top().Tcarga <= T)
    {
        Baterias aux = baterias_actuales.top();
        baterias_actuales.pop();

        aux.Tcarga += aux.capacidad;
        aux.capacidad -= desgaste;

        if (aux.capacidad > 0)
            baterias_actuales.push(aux);
        else if (!respuestos.empty() && aux.Tcarga <= T)
        {
            baterias_actuales.push({B + respuestos.front().first, respuestos.front().second, aux.Tcarga });
            respuestos.pop();
        }
        else if(aux.Tcarga >= T)
            baterias_actuales.push(aux);
        
    }

    if (respuestos.size() == R && baterias_actuales.size() == B)
        cout << "CORRECTO";
    else if (baterias_actuales.size() > 0)
        cout << "FALLO EN EL SISTEMA";
    else
        cout << "ABANDONEN INMEDIATAMENTE LA BASE";
    cout << "\n";

    while (!baterias_actuales.empty())
    {
        Baterias aux = baterias_actuales.top();
        baterias_actuales.pop();

        cout << aux.id << " " << aux.Tcarga << "\n";
    }

    cout << "---\n";

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
