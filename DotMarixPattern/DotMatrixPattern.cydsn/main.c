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

#define N 16
#define VMIN 0.05

typedef struct{
    double x[3];
    double y[3];
    double dx;
    double dy;
} dot;

int main()
{
    dotMatrix dotMat;// 16行2色3ワード(3*32 = 96)
    uint8 x,y[2];
    uint8 i,j,n;
    double k[2];
    
	dot a[N];
    for (i = 0;i < N;i++)
    {
        a[i].x[0] = a[i].x[1]= rand()%92+1;
        a[i].y[0] = a[i].y[1]= rand()%12+1;
        a[i].dx = (double)rand()/(RAND_MAX*0.5) - 1;
        a[i].dy = (double)rand()/(RAND_MAX*0.5) - 1;
        if(((a[i].dx < VMIN) && (a[i].dx > -VMIN)) || ((a[i].dy < VMIN) && (a[i].dy > -VMIN))){
            i--;
        }
    }
    
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
            y[0] = (uint8)(7.5*(sin(x*0.2 + k[0])+1) + 0.5);
            dotMat.array[x][y[0]][0] = 1;
            y[1] = (uint8)(7.5*(cos(x*0.15 - k[1])+1) + 0.5);
            dotMat.array[x][y[1]][1] = 1;
            dotMat.array[x][(int)((y[0] + y[1])*0.5)][0] = 1;
            dotMat.array[x][(int)((y[0] + y[1])*0.5)][1] = 1;
        }
        if(k[0] < 2 * 3.14)
        {
            k[0] += 0.05;
        }
        else
        {
            k[0] -= 2 * 3.14;
        }
        if(k[1] < 2 * 3.14)
        {
            k[1] += 0.1;
        }
        else
        {
            k[1] -= 2* 3.14;
        }
        
        for(n = 0;n < N;n++)
        {   
            if((a[n].x[0] < 94) && (a[n].x[0] > 0))
            {
                a[n].x[0]+=a[n].dx;
            }
            else
            {
                a[n].dx *= -1;
                a[n].x[0]+=a[n].dx;
            }
            if((a[n].y[0] < 14) && (a[n].y[0] > 0))
            {
                a[n].y[0]+=a[n].dy;
            }
            else
            {
                a[n].dy *= -1;
                a[n].y[0]+=a[n].dy;
            }
            for(i = 0;i < 2;i++){
                for(j = 0;j < 2;j++){
                    dotMat.array[(int)a[n].x[0]+i][(int)a[n].y[0]+j][n&1] = 1;
                }
            }
        }
        dotMatrix_dataToArray(&dotMat);
        dotMatrix_print(&dotMat);
        //CyDelay(10);
    }
}

/* [] END OF FILE */
