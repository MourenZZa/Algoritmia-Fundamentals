#include <iostream>
#include <vector>

bool esValida(const std::vector<int> sol, const int pos, const std::vector<int> usados, const int seguidas, const int consumoAc, const int consumoMax, const int &i) {
	if (seguidas > 2) return false;
	else if (consumoAc > consumoMax) return false;
	else if (pos + 1 - usados[i] < (pos + 1) / 2) return false; //Si la suma de las luces de un color supera en mas de uno la suma de los demas colores
	else return true;
}

void construyeTiras(const std::vector<int> &C, std::vector<int> &sol, std::vector<int> &usados, int pos, const int &colores, int seguidas,  int consumoAc, const int &consumoMax, int& combinaciones) {
	for (int i = 0; i < colores; ++i){
		sol[pos] = i;
		consumoAc += C[i];
		usados[i]++;
		int temp = seguidas;

		if (pos > 0 && sol[pos] != sol[pos - 1]) {
			seguidas = 1;
		}
		else seguidas++;

		if (esValida(sol, pos, usados, seguidas, consumoAc, consumoMax, i)) {
			if (pos == sol.size() - 1) 
				combinaciones++;
			else construyeTiras(C, sol, usados, pos + 1, colores, seguidas, consumoAc, consumoMax, combinaciones);
		}

		seguidas = temp;
		consumoAc -= C[i];
		usados[i]--;
	}
}

bool resuelveCaso() {
	int N, Colores, Consumo, combinaciones = 0;

	std::cin >> N;

	if (N == 0) return false;

	std::cin >> Colores >> Consumo;

	std::vector<int> C(Colores), sol(N), usados(Colores, 0);

	for (int i = 0; i < Colores; ++i)	{
		std::cin >> C[i];
	}

	construyeTiras(C, sol, usados, 0, Colores, 0, 0, Consumo, combinaciones);

	std::cout << combinaciones << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}