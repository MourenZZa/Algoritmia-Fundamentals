#include <iostream>
#include <vector>

bool esValida(const std::vector<int> &X, const int pos, const int r, const int a, const int v) {
	if (a < v) return false;
	else if (pos > 0 && X[pos - 1] == 2 && X[pos] == 2)return false;
	else return true;
}

void escribirSol(const std::vector<int> V, int pos) {
	for (int i = 0; i <= pos; ++i){
		if (V[i] == 0) std::cout << "azul ";
		else if (V[i] == 1) std::cout << "rojo ";
		else std::cout << "verde ";
	}
	std::cout << '\n';
}

void construyeTorre(std::vector<int>& X, const int& pos, int r, int a, int v, int R, int A, int V, bool& sol) {
	for (int i = 0; i < 3; ++i){
		if ((i == 0 && a < A) || (i == 1 && r < R) || (i == 2 && v < V)) {
			X[pos] = i;

			if (i == 0) a++;
			else if (i == 1) r++;
			else v++;

			if (esValida(X, pos, r, a, v)) {
				if (pos == X.size() - 1) {
					if (r > a + v) {
						escribirSol(X, pos);
						sol = true;
					}
				}
				else construyeTorre(X, pos + 1, r, a, v, R, A, V, sol);
			}
			if (i == 0) a--;
			else if (i == 1) r--;
			else v--;
		}

	}
}

bool resuelveCaso() {
	int N, A, R, V;
	bool sol = false;

	std::cin >> N >> A >> R >> V;

	if (N == 0 && A == 0 && R == 0 && V == 0)
		return false;

	std::vector<int> X(N);

	X[0] = 1;

	construyeTorre(X, 1, 1, 0, 0, R, A, V, sol);
	
	if (!sol) std::cout << "SIN SOLUCION\n";
	std::cout << '\n';

	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}