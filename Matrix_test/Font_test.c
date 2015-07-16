#include <stdio.h>
#include "DotMatrix.h"
#include "jiskan_lib.h"

int main(){

	dotMatrix dotMat;
	int x, y;
	unsigned int jis_num = 319;
	dotMatrix_clear(&dotMat);

	for(y=0;y<15;y++){
		for(x=0;x<15;x++){
			if(jis_font[16*jis_num+y] & (1 << x)){
				dotMat.array[15-x][y][0] = 1;
			}
			else{
				dotMat.array[15-x][y][0] = 0;
			}
 		}
	}

	dotMatrix_print(&dotMat);
}