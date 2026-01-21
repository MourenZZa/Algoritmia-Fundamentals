#include <iostream>
#include <vector>
#include <algorithm>

/*
	  | co         si n = 1 
 T =  |
      | 2T(N/2)    si n > 1

	  O(logN)

*/

int calculaPerfil(std::vector<int> V, int N, int ini, int fin) {
	
	if (N == 1) return V[0];
	else if (N == 2) return std::min(V[0], V[1]);

	if (ini + 1 >= fin - 1) return std::min(V[ini], V[fin - 1]);

	int m = (ini + fin - 1) / 2;

	if (V[m - 1] > V[m] && V[m] < V[m + 1]) return V[m];
	else if (V[m] < V[m + 1]) return calculaPerfil(V, N, ini, m + 1);
	else return calculaPerfil(V, N, m + 1, fin);
}

bool resuelveCaso() {
	std::vector<int> V;
	int N, aux, sol;

	std::cin >> N;

	if (!std::cin) return false;

	for (int i = 0; i < N; ++i)	{
		std::cin >> aux;
		V.push_back(aux);
	}

	sol = calculaPerfil(V, N, 0, N);

	std::cout << sol << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}