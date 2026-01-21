#include <iostream>
#include <vector>

/*

	 | co           si n = 1
T  = |
	 | T(N/2) + c1  si n > 1

	 O(log N)
*/

int numeroTachar(const std::vector<int> V, const int& ini, const int& fin, const int num) {
	if (ini + 1 == fin) {
		if (ini + num == V[ini]) return V[ini];
		else return -1;
	}

	int m = (ini + fin - 1) / 2;
	
	if (m + num == V[m]) return V[m];
	if (m + num > V[m]) return numeroTachar(V, m + 1, fin, num);
	else return numeroTachar(V, ini, m + 1, num);
}

void resuelveCaso() {
	int N, num, aux, sol;
	std::vector<int> V;

	std::cin >> N >> num;

	for (int i = 0; i < N; ++i){
		std::cin >> aux;
		V.push_back(aux);
	}

	sol = numeroTachar(V, 0, N, num);

	if (sol == -1) std::cout << "NO\n";
	else std::cout << sol << '\n';
}


int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i){
		resuelveCaso();
	}
}