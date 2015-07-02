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
#include "DotMatrix.h"

int main()
{
    dotMatrix dotMat;// 16行2色3ワード(3*32 = 96)
    uint8 i,j,h;
	
	CyGlobalIntEnable;
	
	//USBUART_Start(0, USBUART_5V_OPERATION);
	//while (USBUART_GetConfiguration() == 0);
    //USBUART_CDC_Init();
    CyDelay(100);
    dotMatrix_clear(&dotMat);
	dotMatrix_print(&dotMat);
	for (;;)
    {
        for(h = 1;h < 16;h++)
        {
            for(i = 0;i < 16;i++)
            {
                if(h == i)
                {
                    for(j = 0;j < 3;j++)
                    {
                        dotMat.data[i][j][0] = 0xffffffff;
                        dotMat.data[i][j][1] = 0;
                    }
                }
                else if((15 - h) == i)
                {
                    for(j = 0;j < 3;j++)
                    {
                        dotMat.data[i][j][0] = 0x00000000;
                        dotMat.data[i][j][1] = 0xffffffff;
                    }
                }
                else
                {
                    for(j = 0;j < 3;j++)
                    {
                        dotMat.data[i][j][0] = 0x00000000;
                        dotMat.data[i][j][1] = 0x00000000;
                    }
                
                }
            }
            dotMatrix_print(&dotMat);
            CyDelay(100);
        }
        for(h = 1;h < 16;h++)
        {
            for(i = 0;i < 16;i++)
            {
                if(h == i)
                {
                    for(j = 0;j < 3;j++)
                    {
                        dotMat.data[i][j][0] = 0;
                        dotMat.data[i][j][1] = 0xffffffff;
                    }
                }
                else if((15 - h) == i)
                {
                    for(j = 0;j < 3;j++)
                    {
                        dotMat.data[i][j][0] = 0xffffffff;
                        dotMat.data[i][j][1] = 0;
                    }
                }
                else
                {
                    for(j = 0;j < 3;j++)
                    {
                        dotMat.data[i][j][0] = 0x00000000;
                        dotMat.data[i][j][1] = 0x00000000;
                    }
                
                }
            }
            dotMatrix_print(&dotMat);
            CyDelay(100);
        }
    }
}

/* [] END OF FILE */
