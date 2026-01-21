#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
			| c0             si n = 1
	 T(n) = |
			| 2T(n/2) + c0   si n > 1
	Donde n es la longitud del vector
	O(nlogn)
*/

int mezcla(vector<int>& X, vector<int>& temp, const int& ini, const int& fin, const int& m) {
	int i = ini, j = m, k = ini;
	int cambios = 0;

	while ((i <= m - 1) && (j < fin)) {
		if (X[i] <= X[j])
			temp[k++] = X[i++];
		else {
			temp[k++] = X[j++];
			cambios += (m - i);
		}
	}

	while (i < m)
		temp[k++] = X[i++];

	while (j < fin)
		temp[k++] = X[j++];

	for (i = ini; i < fin; i++)
		X[i] = temp[i];

	return cambios;
}

int mergeSort(vector<int>& X, vector<int>& temp, int ini, int fin) {
	int m, cambios = 0;
	if (ini < fin - 1) { //Dos o mas elementos
		m = (ini + fin - 1) / 2;
		cambios = mergeSort(X, temp, ini, m + 1);
		cambios += mergeSort(X, temp, m + 1, fin);
		cambios += mezcla(X, temp, ini, fin, m + 1);
	}
	return cambios;
}

bool resuelveCaso() {
	vector<int> X;
	int n, aux, res = 0;
	cin >> n;

	if (!cin) return false;

	for (int i = 0; i < n; ++i) {
		cin >> aux;
		X.push_back(aux);
	}

	vector<int> temp(n);
	cout << mergeSort(X, temp, 0, n) << endl;

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}