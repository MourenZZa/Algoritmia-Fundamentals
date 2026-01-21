# Algoritmia Fundamentals (UCM)

This repository contains C++ solutions for the Algoritmia course at Universidad Complutense de Madrid (UCM).
Author: Santiago Mourenza Rivero.

## Structure

Each unit groups exercises by technique. Inside each exercise folder you will usually find a `Source.cpp`
file and, in some cases, a Visual Studio project (`.sln` / `.vcxproj`).

- 1 - Iterativo
  - 02 - Vector bien dividido
  - 03 - Avituallamiento en las etapas ciclistas
  - 04 - Picos y valles
  - 05 - Rescate
  - 06 - Temperaturas extremas
  - 07 - Caminando voy
- 2 - Recursion
  - 08 - Gritos en halloween
  - 09 - Vector Parcialmente ordenado
  - 10 - Numeros polidivisibles
  - 11 - Numeros sin unos
  - 12 - Moviles
- 3 - Divide y venceras
  - 13 - Fuga de la prision
  - 14 - Perfil de una curva concava
  - 15 - Obtener minimo de un vector
  - 16 - Libro Perdido
  - 17 - El juego del bongo
  - 18 - BattleStarGalactica
  - 19 - Cruce de lineas
- 4 - Backtracking
  - 20 - N reinas
  - 21 - Compra de la semana
  - 22 - Torres de colores
  - 23 - Luces de navidad
  - 24 - Blanca Navidad
  - 25 - Los funcionarios del ministerio
  - 26 - Torres y reinas
  - 27 - Pepe Casanova
  - 28 - Que vienen los reyes magos
  - 29 - Backtracking-Diciembre2019

## Build and run

All solutions read from standard input and write to standard output. You can compile any exercise with a
standard C++ compiler, for example:

```bash
cd "4 - Backtracking/20 - N reinas/N reinas"
g++ -std=c++17 -O2 -Wall -Wextra Source.cpp -o app
./app < input.txt
```

On Windows, run `.\app.exe` instead of `./app`. If a Visual Studio solution is available, open the `.sln`
file and build the project directly.
