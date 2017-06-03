# Maze & Sudoku solver

This project consists of 2 different programs.

## Maze Solver

Solves the given maze through DFS backtracing algorithm. 

## Sudoku Solver

Solves the given through DFS backtracing algorithm and some CSP techniques like forward checking.


### Maze Input
```
0 0 0 0 0 0 0 0 0 0 0 1 0 0 0
0 1 0 1 1 1 1 1 1 1 0 1 1 1 0
0 1 0 1 0 0 0 0 0 1 0 0 0 1 0
0 1 1 1 0 1 1 1 0 1 1 1 0 1 0
0 1 0 1 0 1 0 1 0 0 0 1 0 1 0
0 1 0 1 0 1 0 1 0 1 0 1 1 1 0
0 1 0 0 0 0 0 1 0 1 0 0 0 1 0
0 1 0 1 1 1 1 1 0 1 1 1 0 1 0
0 1 0 1 0 0 0 1 0 0 0 1 0 1 0
0 1 0 1 1 1 0 1 1 1 1 1 0 1 0
0 1 0 0 0 1 0 0 0 0 0 1 0 1 0
0 1 1 1 0 1 1 1 1 1 0 1 1 1 0
0 1 0 1 0 0 0 0 0 1 0 0 0 0 0
0 1 0 1 1 1 1 1 0 1 1 1 1 1 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
```

### Maze Output
```
0 0 0 0 0 0 0 0 0 0 0 x 0 0 0
0 1 0 x x x x x x x 0 x x x 0
0 1 0 x 0 0 0 0 0 x 0 0 0 x 0
0 x x x 0 1 1 1 0 x x x 0 x 0
0 x 0 1 0 1 0 1 0 0 0 x 0 x 0
0 x 0 1 0 1 0 1 0 1 0 x x x 0
0 x 0 0 0 0 0 1 0 1 0 0 0 1 0
0 x 0 1 1 1 1 1 0 1 1 1 0 1 0
0 x 0 1 0 0 0 1 0 0 0 1 0 1 0
0 x 0 1 1 1 0 1 1 1 1 1 0 1 0
0 x 0 0 0 1 0 0 0 0 0 1 0 1 0
0 x x x 0 1 1 1 1 1 0 1 1 1 0
0 1 0 x 0 0 0 0 0 1 0 0 0 0 0
0 1 0 x x x x x 0 1 1 1 1 1 0
0 0 0 0 0 0 0 x 0 0 0 0 0 0 0
```

### Sudoku Input
```
0 1 0 6 0 7 0 0 4
0 4 2 0 0 0 0 0 0
8 7 0 3 0 0 6 0 0
0 8 0 0 7 0 0 2 0
0 0 0 8 9 3 0 0 0
0 3 0 0 6 0 0 1 0
0 0 8 0 0 6 0 4 5
0 0 0 0 0 0 1 7 0
4 0 0 9 0 8 0 6 0
```

### Sudoku Output

```
9 1 3 6 2 7 5 8 4
6 4 2 5 8 9 7 3 1
8 7 5 3 4 1 6 9 2
5 8 9 1 7 4 3 2 6
2 6 1 8 9 3 4 5 7
7 3 4 2 6 5 8 1 9
1 2 8 7 3 6 9 4 5
3 9 6 4 5 2 1 7 8
4 5 7 9 1 8 2 6 3
```
