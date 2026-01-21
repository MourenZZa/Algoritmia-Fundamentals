#include <iostream>
#include <algorithm>
#include <vector>

bool esValida(const std::vector<int> JuguetesN, const int M) {
	for (size_t i = 0; i < JuguetesN.size(); ++i){
		if (JuguetesN[i] < M) return false;
	}
	return true;
}

void calculaSatisfaccionMax(std::vector<std::vector<int>> const& gradoSatisfaccion, size_t k, std::vector<int>& JuguetesN, std::vector<bool>& Juguetes, std::vector<int> const& edadesR, std::vector<int> const& edadesN, std::vector<int> const& SumasParciales, int calidad, int& satisfaccionMax, const int estJug, const int M) {
	for (size_t i = 0; i < edadesN.size(); ++i){
		if (Juguetes[k] && JuguetesN[i] <= estJug && edadesN[i] >= edadesR[k]) {
			calidad += gradoSatisfaccion[i][k];
			Juguetes[k] = false;
			JuguetesN[i]++;

			if (k == Juguetes.size() - 1) {
				if (esValida(JuguetesN, M)) {
					satisfaccionMax = std::max(calidad, satisfaccionMax);
				}
			}
			else if (calidad + SumasParciales[k + 1] > satisfaccionMax)
				calculaSatisfaccionMax(gradoSatisfaccion, k + 1, JuguetesN, Juguetes, edadesR, edadesN, SumasParciales, calidad, satisfaccionMax, estJug, M);

			calidad -= gradoSatisfaccion[i][k];
			Juguetes[k] = true;
			JuguetesN[i]--;
		}
		else if(k < Juguetes.size() - 1 && calidad + SumasParciales[k + 1] > satisfaccionMax)
			calculaSatisfaccionMax(gradoSatisfaccion, k + 1, JuguetesN, Juguetes, edadesR, edadesN, SumasParciales, calidad, satisfaccionMax, estJug, M);
	}
}

bool resuelveCaso() {
	size_t J, N, M;

	std::cin >> J >> N >> M;

	if (J == 0 && N == 0 && M == 0) return false;

	int satisfaccionMax = 0, aux, estJug;
	std::vector<int> edadesR(J);
	std::vector<int> edadesN(N);
	std::vector<std::vector<int>> gradoSatisfaccion(N, std::vector<int>(J));
	std::vector<int> JuguetesN(N, 0);
	std::vector<bool> Juguetes(J, true);
	std::vector<int> SumasParciales(J, 0);

	if ((float)J / N > J / N) estJug = (J / N) + 1;
	else {
		estJug = J / N;
		if (estJug > M) estJug += estJug - M;
	}

	for (int i = 0; i < J; ++i){
		std::cin >> edadesR[i];
	}

	for (size_t i = 0; i < N; ++i){
		std::cin >> edadesN[i];
	}

	for (size_t i = 0; i < N; ++i){
		for (size_t j = 0; j < J; ++j){
			std::cin >> aux;
			gradoSatisfaccion[i][j] = aux;
			if (edadesN[i] >= edadesR[j])
				SumasParciales[j] = std::max(SumasParciales[j], aux);
		}
	}

	for (size_t i = SumasParciales.size() - 1; i > 0; --i){
		SumasParciales[i - 1] += SumasParciales[i];
	}

	calculaSatisfaccionMax(gradoSatisfaccion, 0, JuguetesN, Juguetes, edadesR, edadesN, SumasParciales, 0, satisfaccionMax, estJug, M);

	std::cout << satisfaccionMax << '\n';
	
	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}