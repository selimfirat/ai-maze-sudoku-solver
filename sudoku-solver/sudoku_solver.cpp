#include<iostream>
#include<fstream>
#include <string>

#include "sudoku_solver.h"
using namespace std;


void backtrack(int a[], int k, boardtype * board) {
	int c[MAX_CANDIDATES];
	int nCandidates;

	if (is_a_solution(a, k, board))
		process_solution(a, k, board);
	else {
		k++;
		construct_candidates(a, k, board, c, &nCandidates);
		//cout << "free count: " << board->freecount << endl;
		for (int i = 0; i < nCandidates; i++)
		{
			a[k] = c[i];
			make_move(a, k, board);

			backtrack(a, k, board);
			if (finished)
				return;
			unmake_move(a, k, board);
		}
	}
}

void possible_values(int x, int y, boardtype *board, bool * possible) {
	int i, j, xlow, ylow;			/* origin of box with (x,y) */
	bool init;			/* is anything/everthing possible? */

	if ((board->m[x][y] != 0) || ((x<0) || (y<0)))
		init = false;
	else
		init = true;


	for (i = 1; i <= DIMENSION; i++)
		possible[i] = init;

	possible[0] = false;

	for (i = 0; i < DIMENSION; i++)
		possible[board->m[x][i]] = false;

	for (i = 0; i < DIMENSION; i++)
		possible[board->m[i][y]] = false;

	xlow = BW * ((int)(x / BW));
	ylow = BW * ((int)(y / BW));

	for (i = xlow; i < xlow + BW; i++)
		for (j = ylow; j < ylow + BW; j++)
			possible[board->m[i][j]] = false;

}

int possible_count(int x, int y, boardtype *board) {
	int i, cnt = 0;
	bool possible[DIMENSION + 1];     /* what is possible for the square */

	possible_values(x, y, board, possible);
	for (i = 0; i <= DIMENSION; i++)
		if (possible[i]) cnt++;
	return cnt;
}

void next_square(int *x, int *y, boardtype* board) {
	int i, j;
	int bestcnt, newcnt;		/* the best and latest square counts */
	bool doomed;			/* some empty square without moves? */

	bestcnt = DIMENSION + 1;
	doomed = false;
	*x = *y = -1;

	for (i = 0; i < DIMENSION && !doomed; i++) {
		for (j = 0; j < DIMENSION && !doomed; j++) {
			if (board->m[i][j] != 0)
				continue;

			newcnt = possible_count(i, j, board);

			if ((newcnt == 0))
				doomed = true;
			else if (newcnt < bestcnt) {
				*x = i; 
				*y = j;
			}
		}
	}

	if (doomed) {
		*x = *y = -1;		/* initialize to non-position */
	}

}

bool is_a_solution(int a[], int k, boardtype *board)
{
	return board->freecount == 0;
}

void process_solution(int a[], int k, boardtype * board)
{
	cout << "Solution: " << endl;
	print_board(board);

	finished = true;
}

void make_move(int a[], int k, boardtype *board)
{
	int x = board->move[k].x;
	int y = board->move[k].y;

	if (board->m[x][y] == 0)
		board->freecount--;
	else {
		cout << "already filled" << endl;
	}

	board->m[x][y] = a[k];
}

void unmake_move(int a[], int k, boardtype *board)
{
	int x = board->move[k].x;
	int y = board->move[k].y;

	if (board->m[x][y] != 0)
		board->freecount++;
	else
		cout << " not filled to unmake";

	board->m[x][y] = 0;
}

void construct_candidates(int a[], int k, boardtype *board, int c[], int *ncandidates)
{
	int x, y; /* position of next move */
	int i; /* counter */
	bool possible[DIMENSION + 1]; /* what is possible for the square */

	next_square(&x, &y, board); /* which square should we fill next? */

	board->move[k].x = x; /* store our choice of next position */
	board->move[k].y = y;
	*ncandidates = 0;
	if ((x < 0) && (y < 0))
		return; /* error condition, no moves possible */

	possible_values(x, y, board, possible);
	for (i = 0; i <= DIMENSION; i++)
		if (possible[i]) {
			c[*ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
}

void print_board(boardtype * board)
{
	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
				cout << board->m[i][j];

			cout << " ";
		}
		cout << endl;
	}
}

int main()
{
	fstream boardFile("sudoku.txt", ios_base::in);

	boardtype board;

	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			boardFile >> board.m[i][j];
			if (board.m[i][j] !=  0)
			{
				board.freecount--;
			}
		}
	}

	print_board(&board);
	cout << "Solving the puzzle..." << endl;

	int x[NCELLS + 1];

	backtrack(x, 0, &board);

	if (!finished)
		cout << "No solution found!" << endl;

	int a;
	cin >> a;
	return 0;
};