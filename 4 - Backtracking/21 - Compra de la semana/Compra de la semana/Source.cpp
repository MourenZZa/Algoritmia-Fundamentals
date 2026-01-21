//Santiago Mourenza Rivero
//FAL : DG

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>


void minimoPrecio(std::vector<std::vector<int>> const& m, std::vector<int>& comprados, std::vector<int> const & sumasParciales, std::vector<bool>& productos, int precio, int& minPrecio, bool& sol, size_t k) {
	for (size_t i = 0; i < comprados.size(); ++i){
		if (productos[k] && comprados[i] < 3) {
			precio += m[i][k];
			productos[k] = false;
			comprados[i]++;

			if (k == productos.size() - 1) {
				sol = true;
				minPrecio = std::min(precio, minPrecio);
			}
			else if (precio + sumasParciales[k + 1] < minPrecio)
				minimoPrecio(m, comprados, sumasParciales, productos, precio, minPrecio, sol, k + 1);

			precio -= m[i][k];
			productos[k] = true;
			comprados[i]--;
		}
	}
}

void resuelveCaso() {
	int s, p, aux;
	bool sol = false;
	int minPrecio = 0;

	std::cin >> s >> p;

	std::vector<std::vector<int>> m(s, std::vector<int>(p));
	std::vector<int> comprados(s, 0);
	std::vector<bool> productos(p, true);
	std::vector<int> sumasParciales(p, INT_MAX);

	for (int i = 0; i < s; ++i){
		for (int j = 0; j < p; j++){
			std::cin >> aux;
			m[i][j] = aux;
			minPrecio += aux;
			sumasParciales[j] = std::min(sumasParciales[j], aux);
		}
	}

	for (int i = sumasParciales.size() - 1; i > 0 ; i--){
		sumasParciales[i - 1] += sumasParciales[i];
	}

	if (p > 0)
		minimoPrecio(m, comprados, sumasParciales, productos, 0, minPrecio, sol, 0);

	if (sol) std::cout << minPrecio << '\n';
	else std::cout << "Sin solucion factible\n";
		
}


int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i){
		resuelveCaso();
	}
}