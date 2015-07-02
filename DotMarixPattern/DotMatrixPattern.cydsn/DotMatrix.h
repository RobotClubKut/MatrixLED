/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

#ifndef DOTMATRIX_H
#define DOTMATRIX_H

typedef struct {
    uint32 data[16][3][2];
    uint8 array[96][16][2];
} dotMatrix;

void dotMatrix_print(const dotMatrix*);
void dotMatrix_clear(dotMatrix*);
void dotMatrix_dataToArray(dotMatrix*);

    
#endif
/* [] END OF FILE */
