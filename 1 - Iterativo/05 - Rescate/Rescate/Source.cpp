#include <iostream>
#include <vector>
#include <fstream>

struct tSol {
    int ini;
    int fin;
};

tSol resuelve(std::vector<int> const& v, const int& alien) {

    tSol sol = { 0, -1 };

    int ini = 0, fin = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > alien) {
            if (ini == -1) {
                fin = i;
                ini = i;
            }
            else
                fin = i;

            if (fin - ini > sol.fin - sol.ini) {
                sol.fin = fin;
                sol.ini = ini;
            }
        }
        else {
            fin = -1;
            ini = -1;
        }
    }
    return sol;

}

void resuelveCaso() {

    int n, t;
    std::cin >> n >> t;

    std::vector<int> v(n);

    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    tSol sol = resuelve(v, t);

    std::cout << sol.ini << " " << sol.fin << "\n";
}

int main() {
	int n;
	std::cin >> n;

	for (size_t i = 0; i < n; ++i){
		resuelveCaso();
	}
}