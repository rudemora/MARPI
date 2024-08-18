// juez7.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "PriorityQueue.h"
#include <fstream>

using namespace std;

struct comparator {
    bool operator() (tuple<double, double, double, double> &p1, tuple<double, double, double, double>& p2){//coef, entrada, asginados, votos
        auto [i1, i2, i3, i4] = p1;
        auto [d1, d2, d3, d4] = p2;
        if (i1 > d1 || (i1 == d1 && i4 > d4) || (i1 == d1 && i2 < d2 && i4 == d4)) {
            return true;
        }
        return false;
    }
};

void resolver(PriorityQueue < tuple<double, double, double, double>, comparator >& cola, int num) {
    for (int i = 0; i < num; i++) {
        auto [i1, i2, i3, i4] = cola.top();
        cola.pop();
        i3 += 1;
        i1 = i4 / (1 + i3);
        cola.push({ i1, i2, i3, i4 });
    }
    vector<int> v(cola.size());
    while (!cola.empty()) {
        auto [i1, i2, i3, i4] = cola.top();
        v[i2] = i3;
        cola.pop();
    }
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << (*it) << " ";
    }
    cout << "\n";
}

bool resuelveCaso() {
    int C, N;
    cin >> C >> N;
    if (C == 0 && N == 0) {
        return false;
    }
    else {
        if (C != 0) {
            double votos;
            PriorityQueue < tuple<double, double, double, double>, comparator > cola; //coef, entrada, asginados, votos
            for (int i = 0; i < C; i++) {
                cin >> votos;
                cola.push({ votos, i, 0, votos });
            }
            resolver(cola, N);
            
        }
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
