////Santiago Mourenza Rivero
//FAL DG::Numeros sin unos

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
		   | co              si n = 1
	T(n) = |
		   | T(n - 1) + c1   si n > 1
	Donde n es la longitud del numero
	O(n)
*/


//Devuelve la longitud del numero y un vector con su descomposici�n
long long int divide_cifras(long long int n, vector<long long int>& X) {
	long long int l = 0, c = 1;

	//P.ej : 563 -> {3, 60, 500}
	while (c != 0) {
		c = n / 10;
		X.push_back((n % 10) * pow(10, l));
		n /= 10; l++;
	}
	return l;
}

long long int sin_Unos(int x, int y, long long int num, bool& uno, int l) {
	long long int sol = 0;

	//Caso Base potencia
	if (y == 0) { return 1; }
	//Caso recursivo potencia
	if (y > 0) { sol = x * sin_Unos(x, y - 1, num, uno, l); }

	if (y == l) {
		if ((num + 0.0) / pow(10, y) == 1) {
			uno = true; return sol;
		}
		else if (num != 0) {
			return sol * ((num / (long long int)pow(10, y)) - 1);
		}
		else { return 0; }
	}
	return sol;
}

long long int resolver(long long int n) {
	vector<long long int> X;
	long long int sol = 0, longitud;
	bool uno = false;
	int i;

	longitud = divide_cifras(n, X);
	i = longitud - 1;

	while (!uno && i > 0) {
		sol += sin_Unos(9, i, X[i], uno, i);
		i--;
	}

	if (!uno) {
		if (X[0] != 0) {
			sol += X[0];
		}
		else { sol += 1; }
	}
	return sol;
}

bool resuelveCaso() {
	unsigned long long int n, sol;
	cin >> n;
	if (!std::cin) // fin de la entrada
		return false;
	sol = resolver(n);
	cout << sol << endl;
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}