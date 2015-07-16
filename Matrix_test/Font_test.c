#include <stdio.h>
#include "DotMatrix.h"

int main(){

	dotMatrix dotMat;
	int x, y;

	unsigned int fnt_a[16]= {
	  0x0200,
	  0x0200,
	  0x3ff8,
	  0x0400,
	  0x0440,
	  0x07f0,
	  0x1c5c,
	  0x3444,
	  0x2446,
	  0x6482,
	  0x4482,
	  0x4506,
	  0x4604,
	  0x381c,
	  0x0070,
	  0x0000
	};

	dotMatrix_clear(&dotMat);

	for(y=0;y<15;y++){
		for(x=0;x<15;x++){
			if(fnt_a[y] & (1 << x)){
				dotMat.array[15-x][y][0] = 1;
			}
			else{
				dotMat.array[15-x][y][0] = 0;
			}
 		}
	}

	dotMatrix_print(&dotMat);
}