#include <iostream>
#include <vector>

/*
{0 < N < 10000, ∀i: 0 <= i < N : -274 < V[i] < 1000}
proc picos_y_valles(V[0,..N): ent, E/S p: ent, E/S v: ent)
{p = # q : 1 <= q < N - 1 : V[q - 1] < V[q] > V[q + 1], v = # r : 1 <= r < N - 1 : V[r - 1] > V[r] < V[r + 1]}

I = n < N && p = # q : 1 <= q < n - 1 : V[q - 1] < V[q] > V[q + 1], v = # r : 1 <= r < n - 1 : V[r - 1] > V[r] < V[r + 1]
C = N - n 


*/

void picos_y_valles(const std::vector<int> V, int& p, int& v) {  //O(n)

	if (V.size() > 1) {
		for (size_t i = 1; i < V.size() - 1; ++i) {
			if (V[i - 1] > V[i] && V[i] < V[i + 1])  v++;
			if (V[i - 1] < V[i] && V[i] > V[i + 1])  p++;
		}
	}
}

void resuelveCaso() { //O(n)
	int N, aux;
	std::vector<int> V;

	std::cin >> N;

	for (size_t i = 0; i < N; ++i){
		std::cin >> aux;
		V.push_back(aux);
	}

	int picos = 0, valles = 0;

	picos_y_valles(V, picos, valles);

	std::cout << picos << " " << valles << '\n';
}

int main() {
	int n;
	std::cin >> n;

	for (size_t i = 0; i < n; ++i){
		resuelveCaso();
	}
}