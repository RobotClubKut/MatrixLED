#include <stdio.h>
#include <math.h>


int main (){

	int Matrix [96][16][2] = {0};
	int x,y;


	for(x=0;x<96;x++){
		Matrix[x][(int)(8*sin(x*0.1)+8)][0] = 1;
	}
	
	
	

	for(y=0;y<16;y++){
		for(x=0;x<96;x++){
			if(Matrix[x][y][0] == 1){
				printf ("*");
			}
			else if(Matrix[x][y][0] == 0){
				printf(" ");
			}
		}
		printf("\n");
	}


	return 0;
}