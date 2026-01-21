//Santiago Mourenza Rivero
//FAL DG::Vector Parcialemente Ordenaado

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/*        | c0 si n == 1
   T(n)   |
		  | 2T(n/2) + c0 si n > 1

   Donde n es la longitud del vector ya que en el enunciado se garantiza que el tama�o del vector es una potencia de 2
	Coste O(n log n)
*/

struct sol{
	int min;
	int max;
	bool ord;
};

sol semiordenado(const std::vector<int>& V, const int& p, const int& q) {
	int r = (p + q - 1) / 2;
	sol sol, iz, dcha;

	if (p + 1 >= q - 1) {
		if (V[p] <= V[q - 1]) return { V[p], V[q - 1], true };
		else return { V[q - 1], V[p], false };
	}

	iz = semiordenado(V, p, r + 1);

	if (!iz.ord) {
		sol.ord = false;
		return sol;
	}

	dcha = semiordenado(V, r + 1, q);

	if (!dcha.ord) {
		sol.ord = false;
		return sol;
	}

	sol.ord = (iz.min <= dcha.min) && (dcha.max >= iz.max);

	sol.min = std::min(iz.min, dcha.min);
	sol.max = std::max(iz.max, dcha.max);

	return sol;
}

bool resuelveCaso() {
	std::vector<int> V;
	int aux;

	std::cin >> aux;

	if (aux == 0) return false;

	while (aux != 0) {
		V.push_back(aux);
		std::cin >> aux;
	}

	if (V.size() == 1) {
		std::cout << "SI\n";
		return true;
	}

	sol iz, dcha;

	iz = semiordenado(V, 0, V.size() / 2);
	dcha = semiordenado(V, V.size() / 2, V.size());

	if (iz.ord && dcha.ord && dcha.max >= iz.max && iz.min <= dcha.min) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;

}

int main() {
	while (resuelveCaso());
	return 0;
}