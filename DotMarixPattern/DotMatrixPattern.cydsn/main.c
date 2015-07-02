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
#include "DotMatrix.h"

int main()
{
    dotMatrix dotMat;// 16行2色3ワード(3*32 = 96)
	uint8 x = 0,y[2];
    double k;
	CyGlobalIntEnable;
	
	//USBUART_Start(0, USBUART_5V_OPERATION);
	//while (USBUART_GetConfiguration() == 0);
    //USBUART_CDC_Init();
    CyDelay(100);
    dotMatrix_clear(&dotMat);
	dotMatrix_print(&dotMat);
	for (;;)
    {
        dotMatrix_clear(&dotMat);
        for(x = 0;x < 96;x++)
        {
            y[0] = (uint8)(7.5*(sin(x*0.2 + k)+1) + 0.5);
            dotMat.array[x][y[0]][0] = 1;
            y[1] = (uint8)(7.5*(cos(x*0.15 - k)+1) + 0.5);
            dotMat.array[x][y[1]][1] = 1;
            dotMat.array[x][(int)((y[0] + y[1])*0.5)][0] = 1;
            dotMat.array[x][(int)((y[0] + y[1])*0.5)][1] = 1;
        }
        if(k < 6)
        {
            k+= 0.1;
        }
        else
        {
            k = 0;
        }
        //y = (uint8)(0.2*x);
        dotMatrix_dataToArray(&dotMat);
        dotMatrix_print(&dotMat);
        //CyDelay(10);
    }
}

/* [] END OF FILE */
