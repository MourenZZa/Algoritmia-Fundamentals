#include <iostream>
#include <vector>
#include <algorithm>

/*
{N > 1}
fun tamSegmentoMaximo(V[0,..N): ent, n: ent) dev r: ent
{ r =  max a, b : 0 <= a <= b < N && iguales(V, a, b) : b - a }

iguales(V, a, b) = ∀p :  a <= p <= b : V[a] = V[p] 

I = n < N && r =  max a, b : 0 <= a <= b < n && iguales(V, a, b) : b - a
C = N - n


*/


int tamSegmentoMaximo(const std::vector<int> V, const int N) {
	int r = 0, s = 0, n = 0;

	while (n != N - 1) {
		if (V[n] != V[n + 1]) s = n + 1;

		r = std::max(r, n + 1 - s);
		n++;
	}
	return r;
}


bool resuelveCaso() {
	int aux, sol;
	std::vector<int> V;

	std::cin >> aux;
	if (aux == -1) return false;


	while (aux != -1){
		V.push_back(aux);
		std::cin >> aux;
	}

	sol = tamSegmentoMaximo(V, V.size());

	if (sol == 0) std::cout << "HOY NO COMEN\n";
	else std::cout << sol << '\n';


	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}
