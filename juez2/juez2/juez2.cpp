// juez2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "TreeSet_AVL.h"
#include <vector>
#include <fstream>

using namespace std;

bool resuelveCaso() {
    size_t N;
    std::cin >> N;
    if (N == 0)
        return false;

    std::vector<size_t> cosa(N);

    for (size_t i = 0; i < N; ++i)
        std::cin >> cosa[i];

    std::sort(cosa.begin(), cosa.end());
    cosa.erase(unique(cosa.begin(), cosa.end()), cosa.end());

    size_t M, el;
    std::cin >> M;

    for (size_t i = 0; i < M; ++i) {
        std::cin >> el; --el;
        if (el > cosa.size() - 1)
            std::cout << "??\n";
        else
            std::cout << cosa[el] << '\n';
    }

    std::cout << "---\n";

    return true;
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
