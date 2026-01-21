#include <iostream>
#include <vector>

bool resolver(std::vector<int> v1, std::vector<int> v2, int& pos1, int& pos2, int ini, int fin) {
	int mitad = (ini + fin) / 2;
	if (v1[mitad] == v2[mitad]) {
		pos1 = mitad;
		pos2 = mitad;
		return true;
	}
	else if (fin - ini == 0) {
		if (v1[mitad] == v2[mitad]) {
			pos1 = mitad;
			pos2 = mitad;
			return true;
		}
		else {
			if (v1[mitad] > v2[mitad]) {
				pos1 = mitad - 1;
				pos2 = mitad;
			}
			else {
				pos1 = mitad;
				pos2 = mitad + 1;
			}
			return false;
		}
	}
	else if (v1[mitad] > v2[mitad]) {
		return resolver(v1, v2, pos1, pos2, ini, mitad);
	}
	else {
		return resolver(v1, v2, pos1, pos2, mitad + 1, fin);
	}
}

bool resuelveCaso() {
	int N, aux;
	std::vector<int> V, X;

	std::cin >> N;

	if (N == 0) return false;

	for (int i = 0; i < N; ++i){
		std::cin >> aux;
		V.push_back(aux);
	}

	for (int i = 0; i < N; ++i)	{
		std::cin >> aux;
		X.push_back(aux);
	}

	int pos1 = 0;
	int pos2 = 0;
	if (resolver(V, X, pos1, pos2, 0, V.size() - 1)) {
		std::cout << "SI" << " " << pos1 << '\n';
	}
	else {
		std::cout << "NO" << " " << pos1 << " " << pos2 << '\n';
	}


	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}