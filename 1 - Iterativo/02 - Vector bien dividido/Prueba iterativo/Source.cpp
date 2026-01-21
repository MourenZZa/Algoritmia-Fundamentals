#include <iostream>

/*

{N>0}
bool bienDividido(X[0..N): ent, pos: ent) dev b: bool
{b ⇔ ∀a∀b : pos < a < N , 0 < b <= pos : X[a] > X[b]}

I = n < N && (mayor = max p : 0 <= p <= n : X[p]) 
N = n - N

*/

bool bienDividido(int N, int pos) {
	int mayor, aux;
	bool ok = true;

	std::cin >> mayor;

	for (size_t i = 1; i < N; ++i) {
		std::cin >> aux;

		if (i <= pos && mayor < aux) mayor = aux;
		else if (i > pos && aux <= mayor) {
			ok = false;
		}
	}

	if (pos == N - 1) return true;
	else if (ok)  return true;
	else return false;
}

void resuelveCaso() {
	int N, pos;

	std::cin >> N >> pos;

	bool ok = bienDividido(N, pos);

	if (ok) std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int n;
	std::cin >> n;

	for (size_t i = 0; i < n; ++i){
		resuelveCaso();
	}
}