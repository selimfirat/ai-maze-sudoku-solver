#pragma once
#define BW 3 /* block width */
#define DIMENSION 9 /* 9*9 board */
#define NCELLS DIMENSION*DIMENSION /* 81 cells in a 9*9 problem */

const int MAX_CANDIDATES = 100;
bool finished = false;

typedef struct {
	int x, y;
} point;

typedef struct {
	int m[DIMENSION + 1][DIMENSION + 1]; /* matrix of board contents */
	int freecount = NCELLS; /* how many open squares remain? */
	point move[NCELLS + 1]; /* how did we fill the squares? */
} boardtype;

void backtrack(int a[], int k, boardtype * maze);

void possible_values(int x, int y, boardtype * board, bool * possible);

int possible_count(int x, int y, boardtype * board);

void next_square(int * x, int * y, boardtype * board);

bool is_a_solution(int a[], int k, boardtype * board);

void process_solution(int a[], int k, boardtype * board);

void make_move(int a[], int k, boardtype * board);

void unmake_move(int a[], int k, boardtype * board);

void construct_candidates(int a[], int k, boardtype * board, int c[], int * ncandidates);

void print_board(boardtype * board);
