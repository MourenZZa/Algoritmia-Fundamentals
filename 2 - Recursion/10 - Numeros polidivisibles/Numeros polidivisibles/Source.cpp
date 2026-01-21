////Santiago Mourenza Rivero
//FAL DG::Numeros polidivisibles

#include <iostream>
#include <string>

/*
		   | co             si n = 10
	T(n) = |
		   | T(n + 1) + c1  si n = 0
	0 <= n <= 10
	O(n)
*/

void escribePolidivisibles(long long int N, int maxDigitos);

//Comprueba si es polidivisble el numero n * 10 + i
void polidivisible(long long int n, int i, int longitud, int maxDigitos) {
	if (i < 10) {
		if ((n + i) % longitud == 0) { //Si lo es lo escribe y comprueba los polidivisibles de (n * 10 + i) + j
			escribePolidivisibles(n + i, maxDigitos);
		}
		polidivisible(n, i + 1, longitud, maxDigitos);//Comprueba si es polidivisible con el siguiente digito
	}
	else if (i == 11) {
		std::cout << n << '\n';
	}
}

void escribePolidivisibles(long long int N, int maxDigitos) {
	std::string raiz; long long int n, l;

	raiz = std::to_string(N);
	l = raiz.size();

	polidivisible(N, 11, l, maxDigitos);
	l++;
	if (l <= maxDigitos) {
		n = N * 10;
		polidivisible(n, 0, l, maxDigitos);
		l++;
	}
}

bool resuelveCaso() {
	long long int N;
	int D;
	std::cin >> N;
	std::cin >> D;
	if (!std::cin) // fin de la entrada
		return false;

	escribePolidivisibles(N, D);

	std::cout << "---" << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}