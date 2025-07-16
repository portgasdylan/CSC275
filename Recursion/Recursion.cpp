// ConsoleApplication24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
using namespace std;

const int SIZE_25 = 25;
const int SIZE_30 = 30;

void generateMaze(char maze[][SIZE_30], int size, int x, int y) {
	maze[y][x] = ' ';
	int directions[4][2] = { {0, 2}, {2, 0}, {0, -2}, {-2, 0}};

	//Seed random number generator
	random_device rd;
	mt19937 gen(rd());
	shuffle(begin(directions), end(directions), gen);
	

	for (auto& dir : directions) {
		int nx = x + dir[0], ny = y + dir[1];
		if (ny > 0 && ny < size - 1 && nx > 0 && nx < size - 1 && maze[ny][nx] == '#') {
			maze[y + dir[1] / 2][nx - dir[0] / 2] = ' ';
			generateMaze(maze, size, nx, ny);
		}
	}
}

void printMaze(char maze[][SIZE_30], int size) {
	for (int y = 0; y < size; ++y) {
		for (int x = 0; x < size; ++x) {
			cout << maze[y][x];
		}
		cout << '\n';
	}
}

int main()
{
	int size;
	cout << "Enter maze dimension (25 or 30): ";
	cin >> size;

	if (size != SIZE_25 && size != SIZE_30) {
		cout << "Invalid dimension\n";
		return 1;
	}

	//Intialize maze with walls
	char maze[SIZE_30][SIZE_30];
	for (int y = 0; y < size; ++y)
		for (int x = 0; x < size; ++x)
			maze[y][x] = '#';

	generateMaze(maze, size, 1, 1);

	//Print maze
	printMaze(maze, size);

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
