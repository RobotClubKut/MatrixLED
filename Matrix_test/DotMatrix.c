#include "DotMatrix.h"
#include <stdio.h>

void dotMatrix_print(const dotMatrix* dotMat)
{
	int x, y;
	for (y = 0; y < DispHeight; y++){
		for (x = 0; x < DispWidth; x++){
			if (dotMat->array[x][y][0] == 1 && dotMat->array[x][y][1] == 1){
				printf("@");
			}
			else if (dotMat->array[x][y][0] == 1){
				printf("*");
			}
			else if (dotMat->array[x][y][1] == 1){
				printf("#");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void dotMatrix_clear(dotMatrix* dotMat)
{
	int x, y;
	for (y = 0; y < DispHeight; y++){
		for (x = 0; x < DispWidth; x++){
			dotMat->array[x][y][0] = 0;
			dotMat->array[x][y][1] = 0;
		}
	}
}