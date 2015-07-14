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

#define USE_USB

int main()
{
    dotMatrix dotMat;// 16行2色3ワード(3*32 = 96)
    uint8 x,y;
    uint8 i,j,n;
	uint8 buffer[255];
	uint8 grad = 5;
	double temp;
    double k[2];
    
	CyGlobalIntEnable;
	
	dotMatrix_init(&dotMat);
	#ifdef USE_USB
	dotMatrix_USBinit(&dotMat);

	while(!USBUART_CDCIsReady());
	USBUART_PutString("Success!\r");
	#endif
	
	for (;;)
    {
		#ifdef USE_USB
		dotMatrix_clear(&dotMat);
		dotMatrix_dataToArray(&dotMat);	
		dotMatrix_getPcData(&dotMat);
		while(!USBUART_CDCIsReady());
		USBUART_PutString("Success!\r");
        dotMatrix_print(&dotMat);
		#endif
		
        //CyDelay(10);
    }
}

/* [] END OF FILE */
