#include <iostream>
#include <vector>
#include <algorithm>

void calculaCalidadMaxima(std::vector<std::vector<int>> const& Calidades, std::vector<int> const& anchuraM, std::vector<int> const& anchuraC, std::vector<bool>& carreteras, std::vector<bool>& maquinas, std::vector<int> const& sumasParciales, int calidad, int& calidadMax, size_t k) {
	for (size_t i = 0; i < anchuraC.size(); ++i){
		if (anchuraM[k] <= anchuraC[i] && carreteras[i] && maquinas[k]) {
			calidad += Calidades[k][i];
			carreteras[i] = false;
			maquinas[k] = false;
			
			calidadMax = std::max(calidadMax, calidad);
			
			if (k < anchuraM.size() - 1 && calidad + sumasParciales[k + 1] > calidadMax)
				calculaCalidadMaxima(Calidades, anchuraM, anchuraC, carreteras, maquinas, sumasParciales, calidad, calidadMax, k + 1);

			calidad -= Calidades[k][i];
			carreteras[i] = true;
			maquinas[k] = true;
		}
		else if (k < anchuraM.size() - 1 && calidad + sumasParciales[k + 1] > calidadMax)
			calculaCalidadMaxima(Calidades, anchuraM, anchuraC, carreteras, maquinas, sumasParciales, calidad, calidadMax, k + 1);
	}
}


void resuelveCaso() {
	int m, n, aux, calidadMax = 0;

	std::cin >> m >> n;

	std::vector<std::vector<int>> Calidades(m, std::vector<int>(n));
	std::vector<int> anchuraM(m);
	std::vector<int> anchuraC(n);
	std::vector<bool> carreteras(n, true);
	std::vector<bool> maquinas(n, true);
	std::vector<int> sumasParciales(m, 0);

	for (int i = 0; i < m; ++i){
		std::cin >> anchuraM[i];
	}

	for (int i = 0; i < n; ++i){
		std::cin >> anchuraC[i];
	}

	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			std::cin >> aux;
			Calidades[i][j] = aux;
			if (anchuraM[i] <= anchuraC[j])
				sumasParciales[i] = std::max(aux, sumasParciales[i]);
		}
	}

	for (int i = sumasParciales.size() - 1; i > 0; --i){
		sumasParciales[i - 1] += sumasParciales[i];
	}

	if (m > 0) {
		calculaCalidadMaxima(Calidades, anchuraM, anchuraC, carreteras, maquinas, sumasParciales, 0, calidadMax, 0);
	}

	std::cout << calidadMax << '\n';
}


int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i){
		resuelveCaso();
	}
	return 0;
}