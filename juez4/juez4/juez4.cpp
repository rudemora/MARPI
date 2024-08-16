// juez4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "PriorityQueue.h"
#include <tuple>
#include <fstream>

using namespace std;


struct comparator {
    bool operator () (tuple<int, int, int>& p1, tuple<int, int, int>& p2) {
        auto [i1, i2, i3] = p1;
        auto [d1, d2, d3] = p2;
        if (i3 < d3 || (i3 == d3 && i1 < d1)) {
            return true;
        }
        return false;
    }
};

void resolver(PriorityQueue<tuple<int, int, int>, comparator>& cola, int num) {
    for (int i = 0; i < num; i++) {
        auto [i1, i2, i3] = cola.top();
        cola.pop();
        cout << i1 << "\n";
        i3 += i2;
        cola.push({ i1,i2,i3 });
    }


}

bool resuelveCaso() {
    int num;
    cin >> num;
    if (num == 0) {
        return false;
    }
    else {
        PriorityQueue<tuple<int, int, int>,comparator> cola; //id, coste,acumulado
        int id;
        int coste;
        for (int i = 0; i < num; i++) {
            cin >> id >> coste;
            cola.push({ id, coste, coste });
        }
        int k;
        cin >> k;
        resolver(cola, k);
        cout << "---\n";
        return true;
    }
}

int main()
{
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif
    while (resuelveCaso());
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
