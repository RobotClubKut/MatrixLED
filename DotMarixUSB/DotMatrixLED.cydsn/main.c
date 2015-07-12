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
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "DotMatrix.h"


int main()
{
    dotMatrix dotMat;// 16行2色3ワード(3*32 = 96)
    uint8 x,y[2];
    uint8 i,j,n;
	uint8 buffer[255];
	double temp;
    double k[2];
    
	CyGlobalIntEnable;
	
	dotMatrix_init(&dotMat);

	while(!USBUART_CDCIsReady());
	USBUART_PutString("Success!\r");

	for (;;)
    {
		dotMatrix_getPcData(&dotMat);
		while(!USBUART_CDCIsReady());
		USBUART_PutString("Success!\r");
        dotMatrix_clear(&dotMat);
        dotMatrix_print(&dotMat);
        //CyDelay(10);
    }
}

/* [] END OF FILE */
