#include <iostream>
#include <vector>

/*
	 | co           si n = 1
T =  |
     | c1           si n = 2
	 |
     | T(N/2) + c2  si n >= 2

	 O(log N)
*/

int libroPerdido(const std::vector<int> V, int ini, int fin, int num) {
	if (ini + 1 == fin) return ini;
	if (ini + 1 >= fin - 1) {
		if (ini != num) return ini;
		else return fin - 1;
	}
	
	int m = (ini + fin - 1) / 2;

	if (V[m] == V[m - 1] && (m - 1) % 2 != 0) return libroPerdido(V, ini, m + 1, m);
	else if (V[m] == V[m - 1] && (m - 1) % 2 == 0) return libroPerdido(V, m + 1, fin, m);
	else if (V[m] == V[m + 1] && m % 2 == 0) return libroPerdido(V, m + 1, fin, m + 1);
	else if (V[m] == V[m + 1] && m % 2 != 0) return libroPerdido(V, ini, m + 1, m);
	else return m;
}


void resuelveCaso() {
	int N, aux, sol;
	std::vector<int> V;

	std::cin >> N;

	for (int i = 0; i < N; ++i){
		std::cin >> aux;
		V.push_back(aux);
	}

	sol = libroPerdido(V, 0, N, 0);
	
	std::cout << sol << '\n';
}


int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i){
		resuelveCaso();
	}
}