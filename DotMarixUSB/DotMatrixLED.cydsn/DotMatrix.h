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
#include <string.h>
#include <math.h>

#ifndef DOTMATRIX_H
#define DOTMATRIX_H

typedef struct {
	char head[6];
	char start[4];
	char end[4];
	char data[768];
	char dataEnd[4];
	uint8 start_point[2];
	uint8 end_point[2];
} pcData;

typedef struct {
	pcData inData;
    uint32 data[16][3][2];
    uint8 array[96][16][2];
} dotMatrix;

enum PC_DATA_STAGE
{
	STAGE_START = 0,
	STAGE_POINT_START,
	STAGE_POINT_END,
	STAGE_DATA ,
	STAGE_END ,
	STAGE_DONE ,
	STAGE_ERR
};
void dotMatrix_init(dotMatrix*);
void dotMatrix_USBinit(dotMatrix*);
void dotMatrix_print(dotMatrix*);
void dotMatrix_clear(dotMatrix*);
void dotMatrix_getPcData(dotMatrix*);
void dotMatrix_dataToArray(dotMatrix*);

#endif
/* [] END OF FILE */
