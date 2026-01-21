#include <iostream>

/*

	   | co                n = 1
T(N) = |
	   | 2T(N - 1) + c1    n > 1

	n es la profundidad del movil


	O(2^n)
*/

bool moviles(int &peso) {
	int distanciaIz, distanciaD, pesoIz, pesoDcha;
	bool eqIz = true, eqDcha = true;

	std::cin >> pesoIz >> distanciaIz >> pesoDcha >> distanciaD;


	if (pesoIz == 0) eqIz = moviles(pesoIz);
	if (pesoDcha == 0) eqDcha = moviles(pesoDcha);

	peso = pesoIz + pesoDcha;

	return eqIz && eqDcha && (pesoIz * distanciaIz == pesoDcha * distanciaD);
}

void resuelveCaso() {
	int peso = 0;
	bool equilibrado;

	equilibrado = moviles(peso);

	if (equilibrado) std::cout << "SI\n";
	else std::cout << "NO\n";

}


int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i){
		resuelveCaso();
	}
}