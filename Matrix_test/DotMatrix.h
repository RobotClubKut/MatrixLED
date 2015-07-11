#ifndef DOTMATRIX_H
#define DOTMATRIX_H

#define DispHeight 16
#define DispWidth 96

typedef struct {
	unsigned int data[16][3][2];
	unsigned char array[96][16][2];
} dotMatrix;

void dotMatrix_print(const dotMatrix*);
void dotMatrix_clear(dotMatrix*);
void dotMatrix_dataToArray(dotMatrix*);


#endif