// juez5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "PriorityQueue.h"
#include <fstream>

using namespace std;

struct comparator {
	bool operator() (tuple<string, int, int>& p1, tuple<string, int, int>& p2) {
		auto [i1, i2, i3] = p1;
		auto [d1, d2, d3] = p2;
		if (i2 > d2 || (i2 == d2 && i3 < d3)) {
			return true;
		}
		else {
			return false;
		}
	}
};

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		char tipo;
		string nombre;
		int num;
		PriorityQueue<tuple<string, int, int>, comparator> cola;
		
		for (int i = 0; i < n; i++) {
			cin >> tipo;
			if (tipo == 'A') {
				auto [i1, i2, i3] = cola.top();
				cola.pop();
				cout << i1 << "\n";
			}
			else {
				cin >> nombre;
				cin >> num;
				cola.push({ nombre, num, i });
			}
		}
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
