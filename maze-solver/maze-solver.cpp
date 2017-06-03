#include<iostream>
#include<fstream>
#include <string>

#include "maze-solver.h"
using namespace std;

const int MAX_CANDIDATES = 4;
bool finished = false;

void backtrack(point a[], int k, mazetype * maze) {
	point c[MAX_CANDIDATES];
	int nCandidates;

	if (is_a_solution(a, k, maze))
		process_solution(a, k, maze);
	else {
		k++;
		construct_candidates(a, k, maze, c, &nCandidates);
		cout << "nCandidates: " << nCandidates << endl;
		for (int i = 0; i < nCandidates; i++)
		{
			a[k] = c[i];
			make_move(a, k, maze);
			backtrack(a, k, maze);
			unmake_move(a, k, maze);
			if (finished)
				return;
		}
	}
}

bool is_a_solution(point a[], int k, mazetype * maze)
{
	return maze->isFinished;
}

void process_solution(point a[], int k, mazetype * maze)
{
	print_maze(maze);

	finished = true;
}

void make_move(point a[], int k, mazetype * maze)
{
	int x = a[k].x;
	int y = a[k].y;
	maze->m[y][x] = 2;
	maze->moves[k].x = x;
	maze->moves[k].y = y;

	if (y == maze->sizeY - 1)
		maze->isFinished = true;
}

void unmake_move(point a[], int k, mazetype * maze)
{
	int x = a[k].x;
	int y = a[k].y;
	maze->m[y][x] = 1;
}

void construct_candidates(point a[], int k, mazetype * maze, point c[], int * nCandidates)
{
	*nCandidates = 0;
	if (k == 1)
		for (int i = 0; i < maze->sizeX; i++) {
			if (maze->m[0][i] == 1)
			{
				c[*nCandidates].x = i;
				c[*nCandidates].y = 0;
				(*nCandidates)++;
				return;
			}
		}

	int x = maze->moves[k - 1].x;
	int y = maze->moves[k - 1].y;

	processIfPossible(x - 1, y, maze, nCandidates, c);
	processIfPossible(x, y - 1, maze, nCandidates, c);
	processIfPossible(x + 1, y, maze, nCandidates, c);
	processIfPossible(x, y + 1, maze, nCandidates, c);
}

void processIfPossible(int x, int y, mazetype * maze, int * nCandidates, point * c) {
	if (maze->m[y][x] == 1)
	{
		c[*nCandidates].x = x;
		c[*nCandidates].y = y;
		(*nCandidates)++;
	}
}

void print_maze(mazetype * maze)
{
	for (int i = 0; i < maze->sizeX; i++)
	{
		for (int j = 0; j < maze->sizeY; j++)
		{
			if (maze->m[i][j] == 2)
				cout << "x";
			else
				cout << maze->m[i][j];

			cout << " ";
		}
		cout << endl;
	}
}

int main()
{
	fstream mazeFile("maze.txt", ios_base::in);

	int sizeX, sizeY;
	mazeFile >> sizeX >> sizeY;

	mazetype maze;
	maze.sizeX = sizeX;
	maze.sizeY = sizeY;

	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			mazeFile >> maze.m[i][j];
		}
	}

	print_maze(&maze);

	point x[50*50];

	backtrack(x, 0, &maze);
	if (!finished)
	{
		cout << "Solution not found!";
	}

	int a;
	cin >> a;
    return 0;
};