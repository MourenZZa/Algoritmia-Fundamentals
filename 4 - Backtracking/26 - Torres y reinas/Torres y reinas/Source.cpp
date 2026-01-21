#include <iostream>
#include <fstream>

typedef struct {
	int fila, col;
}tCoords;

const int N = 14;

typedef unsigned int uint;

using namespace std;


//Comprueba si una casilla no esta rota, ni apuntada por alguna ficha para poder colocar una dama
bool casilla_valida_dama(
	tCoords* forbiden,
	const int casillas_malas,
	uint* columnas,
	uint* diagonales_torre_1,
	uint* diagonales_torre_2,
	const int fila,
	const int columna,
	const int total
)
{
	if (
		!columnas[columna] &&
		!diagonales_torre_1[fila - columna + total] &&
		!diagonales_torre_2[fila + columna]
		)
	{

		for (int i = 0; i < casillas_malas; i++)
			if (fila == forbiden[i].fila && columna == forbiden[i].col)
				return false;
		return true;
	}
	return false;
}

//Comprueba si una casilla no esta rota, no apuntada por algiuna ficha para poder colocar una torre
bool casilla_valida_torre(
	tCoords* forbiden,
	const int casillas_malas,
	uint* columnas,
	uint* diagonales_dama_1,
	uint* diagonales_dama_2,
	const int fila,
	const int columna,
	const int total
)
{
	if (
		!columnas[columna] &&
		!diagonales_dama_1[fila - columna + total] &&
		!diagonales_dama_2[fila + columna]
		)
	{

		for (int i = 0; i < casillas_malas; i++)
			if (fila == forbiden[i].fila && columna == forbiden[i].col)
				return false;
		return true;
	}
	return false;
}

//Funcion recursiva que realiza el calculo de las posibles posiciones
void posibilidades(
	tCoords* forbiden,
	const int casillas_malas,
	uint* columnas,
	uint* diagonales_dama_1,
	uint* diagonales_dama_2,
	uint* diagonales_torre_1,
	uint* diagonales_torre_2,
	const int total,
	const int damas,
	const int torres,
	const int fila,
	int& sol
)
{
	if (fila == total) sol++;
	else {
		for (int i = 0; i < total; i++) {
			//comprobar si la casilla es válida para colocar una dama y si tenemos damas suficientes
			if (damas && casilla_valida_dama(forbiden, casillas_malas, columnas, diagonales_torre_1, diagonales_torre_2, fila, i, total)) {
				//Si estamos en el ultimo caso y la casilla es valida hemos encontrado una solucion
				/*if(fila == total - 1)
					return 1;*/
					//Si el caso no es trivial marcamos nuestra eleccion y avanzamos
				columnas[i]++;
				diagonales_dama_1[fila - i + total]++;
				diagonales_dama_2[fila + i]++;
				diagonales_torre_1[fila - i + total]++;
				diagonales_torre_2[fila + i]++;

				posibilidades(
					forbiden,
					casillas_malas,
					columnas,
					diagonales_dama_1,
					diagonales_dama_2,
					diagonales_torre_1,
					diagonales_torre_2,
					total,
					damas - 1,
					torres,
					fila + 1,
					sol
				);

				//Al volver desmarcamos nuestra eleccion
				columnas[i]--;
				diagonales_dama_1[fila - i + total]--;
				diagonales_dama_2[fila + i]--;
				diagonales_torre_1[fila - i + total]--;
				diagonales_torre_2[fila + i]--;
			}
			//Si tenemos torres y la casilla es valida para colocar seguimos un procedimiento analogo a las damas
			if (torres && casilla_valida_torre(forbiden, casillas_malas, columnas, diagonales_dama_1, diagonales_dama_2, fila, i, total)) {
				//Marcar con torre
				columnas[i]++;
				diagonales_torre_1[fila - i + total]++;
				diagonales_torre_2[fila + i]++;

				posibilidades(
					forbiden,
					casillas_malas,
					columnas,
					diagonales_dama_1,
					diagonales_dama_2,
					diagonales_torre_1,
					diagonales_torre_2,
					total,
					damas,
					torres - 1,
					fila + 1,
					sol
				);

				//Desmarcar con torre
				columnas[i]--;
				diagonales_torre_1[fila - i + total]--;
				diagonales_torre_2[fila + i]--;
			}
		}
	}
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int total, casillas_malas, damas, torres, solucion;
	tCoords* forbiden = new tCoords[N * N];
	uint* columnas = new uint[N];
	//Inicilizar los marcadores a vacios
	for (int i = 0; i < N; i++)
		columnas[i] = 0;

	uint* diagonales_dama_1 = new uint[2 * N];
	for (int i = 0; i < 2 * N; i++)
		diagonales_dama_1[i] = 0;

	uint* diagonales_dama_2 = new uint[2 * N];
	for (int i = 0; i < 2 * N; i++)
		diagonales_dama_2[i] = 0;

	uint* diagonales_torre_1 = new uint[2 * N];
	for (int i = 0; i < 2 * N; i++)
		diagonales_torre_1[i] = 0;

	uint* diagonales_torre_2 = new uint[2 * N];
	for (int i = 0; i < 2 * N; i++)
		diagonales_torre_2[i] = 0;
	cin >> torres >> damas;
	while (cin) {
		//para no tener que calcular todo el rato el total de fichas
		total = damas + torres;

		cin >> casillas_malas;
		for (int i = 0; i < casillas_malas; i++) {
			cin >> forbiden[i].fila >> forbiden[i].col;
			forbiden[i].fila--;
			forbiden[i].col--;
		}
		//RESULTADO
		solucion = 0;
		posibilidades(
			forbiden,
			casillas_malas,
			columnas,
			diagonales_dama_1,
			diagonales_dama_2,
			diagonales_torre_1,
			diagonales_torre_2,
			total,
			damas,
			torres,
			0,
			solucion
		);
		cout << solucion << '\n';
		cin >> torres >> damas;
	}
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}