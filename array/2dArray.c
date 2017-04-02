#include <stdio.h>

int main()
{
	int array[5][4]; //array of 5 row and 4 column
	int row;
	int col;
	int num;
	for(row = 0; row < 5; row++) { //iterate over row
		for(col = 0; col < 4; col++) { // each row has 4 column
			scanf("%d", &num);
			array[row][col] = num;
		}
	}

	//Printing
	printf("array output\n");
	for (row = 0; row < 5; row++) {
		for(col = 0; col < 4; col++) {
			printf("%d ", array[row][col]);
		}
		printf("\n");
	}

return 0;
}
