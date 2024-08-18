// juez8.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "PriorityQueue.h"
#include <fstream>

using namespace std;

bool resuelveCaso() {
	int a, b;
	cin >> a >> b;
	if (a == 0 && b == 0) {
		return false;
	}
	else {
		int p1, p2;
		PriorityQueue<int, less<int>> mayores; //mayores ordenados de menor a mayor
		PriorityQueue<int, greater<int>> menores; //menores ordenados de mayor a menor
		for (int i = 0; i < b; i = i + 1) {
			cin >> p1 >> p2;
			if (p1 < a) {
				menores.push(p1);
			}
			else {
				mayores.push(p1);
			}
			if (p2 < a) {
				menores.push(p2);
			}
			else {
				mayores.push(p2);
			}
			if (menores.size() < mayores.size()) {
				menores.push(a);
				mayores.pop(a); 
			}
			else if (menores.size() > mayores.size()) {
				mayores.push(a);
				menores.pop(a);
			}
			cout << a << " ";
		}
		cout << "\n";
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
