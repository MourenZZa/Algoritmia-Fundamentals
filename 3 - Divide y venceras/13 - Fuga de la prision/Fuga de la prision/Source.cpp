#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


/*		| Caso base: c0
   T(n) |
		| Caso recursvo: T(n/2) + c1

   Coste O(logn)
*/

char Fugitivo(vector<char> X, const int& ini, const int& fin, char primero, char ultimo) {
	int m = (ini + fin - 1) / 2;

	//Si solo hay un elemento en el vector
	if (ini + 1 == fin) {
		if (fin == X.size() && X[fin - 1] != ultimo) {
			//Si se ha fugado el ultimo preso
			return char(X[ini] + 1);
		}
		return char(X[ini] - 1);
	}

	//Si se ha fugado un preso de la primera mitad del vector
	if (X[m] - primero != m) {
		return Fugitivo(X, ini, m + 1, primero, ultimo);
	}
	else {
		return Fugitivo(X, m + 1, fin, primero, ultimo);
	}
}

void resuelveCaso() {
	vector<char> X;
	char primero, ultimo;
	string letras;

	cin >> primero >> ultimo;
	cin.ignore();
	getline(cin, letras);

	while (letras != "") {
		X.push_back(letras[0]);
		letras.replace(0, 1, "");
		letras.replace(0, 1, "");
	}

	cout << Fugitivo(X, 0, X.size(), primero, ultimo) << endl;
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}