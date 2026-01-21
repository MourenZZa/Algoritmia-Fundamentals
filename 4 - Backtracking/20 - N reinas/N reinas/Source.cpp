
////Santiago Mourenza Rivero
//FAL DG::Las N reinas

#include <iostream>
#include <vector>

using namespace std;


void nReinas(vector<int>& sol, const int& k, vector<bool>& C, vector<bool>& D, int& cuenta) {
	int n = sol.size() - 1;
	for (int i = 0; i < n; i++) {
		sol[k] = i + 1;

		if ((!C[sol[k]] && !D[sol[k] - k + n]) && (!D[k + sol[k] + 2 * n - 2])) {
			C[sol[k]] = true;
			D[sol[k] - k + n] = true;
			D[k + sol[k] + 2 * n - 2] = true;

			if (k == n) {
				cuenta++;
			}
			else nReinas(sol, k + 1, C, D, cuenta);

			C[sol[k]] = false;
			D[sol[k] - k + n] = false;
			D[k + sol[k] + 2 * n - 2] = false;
		}
	}
}

void resuelveCaso() {
	int n, cuenta = 0;
	cin >> n;

	vector<bool> C(n + 1, false), D(4 * n - 1, false);
	vector<int> sol(n + 1);

	nReinas(sol, 1, C, D, cuenta);

	cout << cuenta << endl;
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}