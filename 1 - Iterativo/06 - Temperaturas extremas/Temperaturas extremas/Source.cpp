#include <iostream>
#include <limits.h>

/*
{N > 0}
proc temperaturasExtremas(X[0,..N), E/S min: ent, E/S numMin: ent, E/S max: ent, E/S numMax: ent)
{min = min p : 0 <= p < N : X[p] && max = max q : 0 <= q < N : X[q] && numMin = # w : 0 <= w < N : X[w] = min && numMax = # y : 0 <= y < N : X[y] = max}


I = n < N && min = min p : 0 <= p <= n : X[p] && max = max q : 0 <= q <= n : X[q] && numMin = # w : 0 <= w <= n : X[w] = min && numMax = # y : 0 <= y <= n : X[y] = max
N = n - N

*/

void temperaturasExtremas(long long int &min, long long int &numMin, long long int &max, long long int &numMax) {
	long long int aux;
	std::cin >> aux;

	while (aux != 0) {

		if (aux < min) { min = aux; numMin = 1; }
		else if (aux == min)  numMin++; 

		if (aux > max) { max = aux; numMax = 1; }
		else if (aux == max)  numMax++; 

		std::cin >> aux;
	}
}


void resuelveCaso() {
	long long int min = LLONG_MAX, numMin = 0, max = 0, numMax = 0;

	temperaturasExtremas(min, numMin, max, numMax);

	std::cout << min << " " << numMin << " " << max << " " << numMax << '\n';
}


int main() {
	int n;
	std::cin >> n;

	for (size_t i = 0; i < n; ++i){
		resuelveCaso();
	}
}