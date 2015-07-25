#include <stdio.h>
#include "DotMatrix.h"
#include "font_8x8.h"


int main(){

	dotMatrix dotMat;
	int x, y;
	char mozi = 'z'-0x20;
	dotMatrix_clear(&dotMat);

	for(y=0;y<8;y++){
		for(x=0;x<8;x++){
			if(font[8*mozi+y] & (1 << x)){
				dotMat.array[y][x][0] = 1;
			}
			else{
				dotMat.array[y][x][0] = 0;
			}
 		}
	}

	dotMatrix_print(&dotMat);
}