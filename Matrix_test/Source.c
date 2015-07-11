#include <stdio.h>
#include "DotMatrix.h"

int main(){


	dotMatrix dotMat;

	int x, y;

	dotMatrix_clear(&dotMat);

	for (y = 0; y < DispHeight; y++){
		for (x = 0; x < DispWidth; x++){
			dotMat.array[x][y][0] = 0;
			dotMat.array[x][y][1] = 0;
		}
	}

	dotMatrix_print(&dotMat);

	printf("\n");

	for (y = 0; y < DispHeight; y++){
		for (x = 0; x < DispWidth; x++){
			dotMat.array[x][y][0] = 1;
			dotMat.array[x][y][1] = 0;
		}
	}

	dotMatrix_print(&dotMat);

	printf("\n");

	for (y = 0; y < DispHeight; y++){
		for (x = 0; x < DispWidth; x++){
			dotMat.array[x][y][0] = 0;
			dotMat.array[x][y][1] = 1;
		}
	}

	dotMatrix_print(&dotMat);

	printf("\n");

	for (y = 0; y < DispHeight; y++){
		for (x = 0; x < DispWidth; x++){
			dotMat.array[x][y][0] = 1;
			dotMat.array[x][y][1] = 1;
		}
	}

	dotMatrix_print(&dotMat);

	printf("\n");

	return 0;
}