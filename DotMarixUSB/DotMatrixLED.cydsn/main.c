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
#include "DotMatrix.h"

#define BUFFER_LEN 255

int main()
{
    dotMatrix dotMat;// 16行2色3ワード(3*32 = 96)
    uint8 x,y[2];
    uint8 i,j,n;
	uint16 count;
	uint8 buffer[BUFFER_LEN];
	double temp;
    double k[2];
    
	CyGlobalIntEnable;
	
	USBUART_Start(0, USBUART_5V_OPERATION);
	while (USBUART_GetConfiguration() == 0);
    USBUART_CDC_Init();
    dotMatrix_clear(&dotMat);
	dotMatrix_print(&dotMat);
	for (;;)
    {
        dotMatrix_clear(&dotMat);
        if(USBUART_IsConfigurationChanged() != 0u) /* Host could send double SET_INTERFACE request */
        {
            if(USBUART_GetConfiguration() != 0u)   /* Init IN endpoints when device configured */
            {
                USBUART_CDC_Init();
            }
        }         
        if(USBUART_GetConfiguration() != 0u)    /* Service USB CDC when device configured */
        {
			/*
			if(USBUART_DataIsReady() != 0u)
			{
				USBUART_GetChar();
			} 
			*/
			
            while(USBUART_CDCIsReady() == 0u);    /* Wait till component is ready to send more data to the PC */ 
            USBUART_PutData(buffer, count);       /* Send data back to PC */
			
            if(count == BUFFER_LEN)
            {
                while(USBUART_CDCIsReady() == 0u); /* Wait till component is ready to send more data to the PC */ 
                USBUART_PutData(NULL, 0u);         /* Send zero-length packet to PC */
            }
        }
        dotMatrix_print(&dotMat);
        //CyDelay(10);
    }
}

/* [] END OF FILE */
