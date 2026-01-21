//Santiago Mourenza Rivero
//FAL DG:: Pepe casanova

#include <iostream>
#include <vector>
#include <fstream>

using tMatriz = std::vector<std::vector<int>>;

void vueltaAtras(std::vector<bool>& sol, const int& k, const tMatriz& canciones, const int& n, const int& t1, const int& t2, int& mejorSolucion, bool& haySol, int tiempoAc1, int puntAc1, int tiempoAc2, int puntAc2) {

    sol[k] = true;
    tiempoAc1 += canciones[k][0];
    puntAc1 += canciones[k][1];

    if (tiempoAc1 <= t1) {
        if (k + 1 == n) {
            if (mejorSolucion < puntAc1 + puntAc2 && (tiempoAc1 == t1 && tiempoAc2 == t2)) {
                mejorSolucion = puntAc1 + puntAc2;
                haySol = true;
                /*std::cout << "Canciones Ida: ";
                for (int z = 0; z < n; ++z)
                    if (sol1[z]) std::cout << z << " ";
                std::cout << "\n";
                std::cout << "Canciones Vuelta: ";
                for (int z = 0; z < n; ++z)
                    if (sol2[z]) std::cout << z << " ";
                std::cout << "\n";*/
            }
        }
        else
            vueltaAtras(sol, k + 1, canciones, n, t1, t2, mejorSolucion, haySol, tiempoAc1, puntAc1, tiempoAc2, puntAc2);
    }

    /*sol1[k] = false;
    sol2[k] = true;*/
    tiempoAc1 -= canciones[k][0];
    puntAc1 -= canciones[k][1];
    tiempoAc2 += canciones[k][0];
    puntAc2 += canciones[k][1];

    if (tiempoAc2 <= t2) {
        if (k + 1 == n) {
            if (mejorSolucion < puntAc1 + puntAc2 && (tiempoAc1 == t1 && tiempoAc2 == t2)) {
                mejorSolucion = puntAc1 + puntAc2;
                haySol = true;
                /*std::cout << "Canciones Ida: ";
                for (int z = 0; z < n; ++z)
                    if (sol1[z]) std::cout << z << " ";
                std::cout << "\n";
                std::cout << "Canciones Vuelta: ";
                for (int z = 0; z < n; ++z)
                    if (sol2[z]) std::cout << z << " ";
                std::cout << "\n";*/
                //for (int z = 0; z < n; ++z) solMejor[z] = sol[z];
            }
        }
        else
            vueltaAtras(sol, k + 1, canciones, n, t1, t2, mejorSolucion, haySol, tiempoAc1, puntAc1, tiempoAc2, puntAc2);
    }

    sol[k] = false;
    tiempoAc2 -= canciones[k][0];
    puntAc2 -= canciones[k][1];

    if (k + 1 == n) {
        if (mejorSolucion < puntAc1 + puntAc2 && (tiempoAc1 == t1 && tiempoAc2 == t2)) {
            mejorSolucion = puntAc1 + puntAc2;
            haySol = true;
        }
    }
    else
        vueltaAtras(sol, k + 1, canciones, n, t1, t2, mejorSolucion, haySol, tiempoAc1, puntAc1, tiempoAc2, puntAc2);
}


bool resuelveCaso() {
    int n, t1, t2;
    std::cin >> n >> t1 >> t2;

    if (n == 0 && t1 == 0 && t2 == 0) return false;

    tMatriz mat(n, std::vector<int>(2));

    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < 2; ++c)
            std::cin >> mat[i][c];
    }

    std::vector<bool> sol(n);
    int mejorSol = 0;
    bool haySol = false;

    vueltaAtras(sol, 0, mat, n, t1, t2, mejorSol, haySol, 0, 0, 0, 0);

    if (!haySol) std::cout << "Imposible\n";
    else std::cout << mejorSol << "\n";


    return true;
}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}