//Santiago Mourenza Rivero
//FAL : DG

#include<iostream>
#include <limits.h>
#include <vector>
#include <algorithm>


void mejorTiempo(std::vector<std::vector<int>> const& funcionarios, std::vector<bool>& trabajos, std::vector<int> const& sumasParciales, int tiempo, int& sol, size_t k) {
	for (int i = 0; i < trabajos.size(); ++i){
		if (trabajos[i]) {
			tiempo += funcionarios[k][i];
			trabajos[i] = false;

			if (k == trabajos.size() - 1) {
				sol = std::min(tiempo, sol);
			}
			else if (tiempo + sumasParciales[k + 1] < sol)
				mejorTiempo(funcionarios, trabajos, sumasParciales, tiempo, sol, k + 1);

			tiempo -= funcionarios[k][i];
			trabajos[i] = true;
		}
	}
}


bool resuelveCaso() {
	int n;
	std::cin >> n;

	if (n == 0) return false;

	int aux, sol = 0;
	std::vector<std::vector<int>> funcionarios(n, std::vector<int>(n));
	std::vector<bool> trabajos(n, true);
	std::vector<int> sumasParciales(n, INT_MAX);

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			std::cin >> aux;
			funcionarios[i][j] = aux;
			sol += aux;
			sumasParciales[i] = std::min(aux, sumasParciales[i]);
		}
	}

	for (int i = sumasParciales.size() - 1; i > 0 ; --i){
		sumasParciales[i - 1] += sumasParciales[i];
	}

	mejorTiempo(funcionarios, trabajos, sumasParciales, 0, sol, 0);

	std::cout << sol << '\n';

	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}