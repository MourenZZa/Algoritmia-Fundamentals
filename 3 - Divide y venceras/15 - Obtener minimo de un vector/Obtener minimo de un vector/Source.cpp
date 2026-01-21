#include <iostream>
#include <vector>

//		| c0 si n == 1
// T(n) |
//		| T(n/2) + c0 si n > 1
//
//	Despliegue:
//	T(n) = T(n/2) + c0 = T(n/(2^2)) + c0 + c0 = T(n/(2^3)) + c0 + c0 + c0 =...
//	= T(n/(2^k)) + k*c0
//	Por tanto, log(n) + n*c0
//
//Coste O(logn)

int buscarMinimo(const std::vector<int>& V, const int& ini, const int& fin) {
	int m = (ini + fin - 1) / 2;

	if (ini + 1 == fin) return V[ini];

	if (V[ini] < V[m]) return buscarMinimo(V, ini, m + 1);
	else if (V[m] > V[m + 1]) return buscarMinimo(V, m + 1, fin);
	else return V[m];
}



bool resuelveCaso() {
	int n;
	std::cin >> n;

	if (!std::cin) return false;

	std::vector<int> v;

	for (int i = 0; i < n; ++i) {
		int aux;
		std::cin >> aux;
		v.push_back(aux);
	}

	std::cout << buscarMinimo(v, 0, n) << '\n';

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}