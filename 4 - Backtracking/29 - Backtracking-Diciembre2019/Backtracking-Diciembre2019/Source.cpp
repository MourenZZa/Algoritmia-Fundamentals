#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>

void calculaMaximaDonacion(std::vector<std::vector<int>> &donaciones, std::vector<std::vector<int>> &vetos, size_t k, std::vector<bool>& artistas, std::vector<int> &sumasParciales, int donacion, int& donacionMaxima, bool& sol, size_t &seguidos, size_t &ant, size_t N) {
	for (size_t i = 0; i < N; ++i){
		if (i != ant && artistas[i]) {

			if (k == 0 || vetos[i][ant] == 1) {
				donacion += donaciones[i][k];
				artistas[i] = false;
				seguidos++;

				if (k == N - 1) {
					if (seguidos == N) {
						donacionMaxima = std::max(donacion, donacionMaxima);
						sol = true;
					}
				}
				else if (donacion + sumasParciales[k + 1] > donacionMaxima)
					calculaMaximaDonacion(donaciones, vetos, k + 1, artistas, sumasParciales, donacion, donacionMaxima, sol, seguidos, i, N);

				donacion -= donaciones[i][k];
				artistas[i] = true;
				seguidos = std::max((int)seguidos - 1, 0);

			}	
		}
	}
}

void resuelveCaso() {
	//unsigned t0, t1;

	//t0 = clock();

	size_t n, seguidos = 0, ant = 0;
	std::cin >> n;

	int aux, donacionMaxima = 0;
	bool sol = false;
	std::vector<std::vector<int>> donaciones(n, std::vector<int>(n)), vetos(n, std::vector<int>(n));
	std::vector<bool> artistas(n, true);
	std::vector<int> sumasParciales(n, 0);

	for (size_t i = 0; i < n; ++i){
		for (size_t j = 0; j < n; ++j){
			std::cin >> aux;
			donaciones[i][j] = aux;
			sumasParciales[j] = std::max(sumasParciales[j], aux);
		}
	}

	for (size_t i = 0; i < n; ++i){
		for (size_t j = 0; j < n; ++j){
			std::cin >> vetos[i][j];
		}
	}

	for (size_t i = sumasParciales.size() - 1; i > 0; --i){
		sumasParciales[i - 1] += sumasParciales[i];
	}

	calculaMaximaDonacion(donaciones, vetos, 0, artistas, sumasParciales, 0, donacionMaxima, sol, seguidos, ant, n);

	if (sol) std::cout << donacionMaxima << '\n';
	else std::cout << "NEGOCIA CON LOS ARTISTAS\n";

	//t1 = clock();

	//double secs = (double)(t1 - t0) / CLOCKS_PER_SEC;
	//printf("%.16g milisegundos\n", secs * 1000.0);
}


int main() {
	
		// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		resuelveCaso();
	}
	
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	// system("PAUSE");
#endif

	return 0;
}