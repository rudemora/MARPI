// juez6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "PriorityQueue.h"
#include <fstream>

using namespace std;

struct comparator {
    bool operator() (const tuple<int, int, bool, int>& left, const tuple<int, int, bool, int>& right) {
        auto [i1, i2, i3, i4] = left;
        auto [d1, d2, d3, d4] = right;
        if (i1 < d1 || (i1 == d1 && i2 < d2)) {
            return true;
        }
        else {
            return false;
        }
    }
};

bool resolver(PriorityQueue<tuple<int, int, bool, int>, comparator >& cola, int tiempo) {
    int tiempoActual = 0;
    while (tiempoActual < tiempo && !cola.empty()) {
        auto [i1, i2, i3, i4] = cola.top();
        cola.pop();
        if (i1 < tiempoActual ) {
            return true;
        }

        tiempoActual = i2;

        if (i3) {
            cola.push({ i1 + i4, i2 + i4, i3, i4 });
        }
    }
    if (!cola.empty()) {
        auto [i1, i2, i3, i4] = cola.top();
        cola.pop();

        if (tiempo > i1) {
            return true;
        }
    }
    return false;
}

bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin) {
        return false;
    }
    else {
        int M;
        int T;
        int inicio;
        int final;
        int periodicidad;
        cin >> M >> T;
        PriorityQueue<tuple<int, int, bool, int>, comparator > cola;
        for (int i = 0; i < N; i = i + 1) {
            cin >> inicio;
            cin >> final;
            cola.push({ inicio, final, false, 0 });
        }

        for (int i = 0; i < M; i = i + 1) {
            cin >> inicio >> final >> periodicidad;
            cola.push({ inicio, final, true, periodicidad });
        }

        if (resolver(cola, T)) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }


        return true;
    }
}

int main()
{
/*#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif
 */   while (resuelveCaso());

/*#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
  */  return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
