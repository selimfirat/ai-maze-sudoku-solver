typedef struct {
	int x, y;
} point;

typedef struct {
	int sizeX;
	int sizeY;
	bool isFinished = false;

	int m[50][50];
	point moves[50 * 50];
} mazetype;

void backtrack(point a[], int k, mazetype * maze);
bool is_a_solution(point a[], int k, mazetype * maze);
void process_solution(point a[], int k, mazetype * maze);
void make_move(point a[], int k, mazetype * maze);
void unmake_move(point a[], int k, mazetype * maze);
void construct_candidates(point a[], int k, mazetype * maze, point c[], int* nCandidates);
void processIfPossible(int x, int y, mazetype * maze, int * nCandidates, point * c);
void print_maze(mazetype * maze);