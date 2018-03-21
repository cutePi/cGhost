#include <stdio.h>
#include <stdbool.h>

#define N 4

void printMaze(int maze[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
}

bool isSafeMove(int maze[N][N], int xPosition, int yPosition) {
	if (xPosition >= 0 && xPosition < N && yPosition >= 0 && yPosition < N && maze[xPosition][yPosition]){
		return true;
	}
	return false;
	
}
bool solveMazeUtil(int maze[N][N], int xPosition, int yPosition, int sol[N][N]) {
	if (xPosition == N-1 && yPosition ==  N-1) {
		sol[xPosition][yPosition] = 1;
		return true;
	}
	if (isSafeMove(maze, xPosition, yPosition)) {

		sol[xPosition][yPosition] = 1; // asuming as a valid move but as of now
		if (solveMazeUtil(maze, xPosition+1, yPosition, sol)) {
			return true;
		}
		if (solveMazeUtil(maze, xPosition, yPosition+1, sol)) {
			return true;
		}
		sol[xPosition][yPosition] = 0; // this move is not a valid move
		return false;

	}
	return false;

}

bool solveMaze(int maze[N][N]) {
	int sol[N][N] = {0};
	if (!solveMazeUtil(maze, 0, 0, sol)) {
		printf("solution dosen't exist\n");
		return false;
	}
	printf("printing solution\n");
	printMaze(sol);
	return true;
}

int main() {
	int maze[N][N] = {
		{1, 0, 0, 0},
		{1, 1, 0, 1},
		{0, 1, 0, 0},
		{1, 1, 1, 1}
	};
	printMaze(maze);
	solveMaze(maze);
}
