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
#define BALL_SIZE 1
#define VMIN 0.05

typedef struct{
    double x[3];
    double y[3];
    double dx;
    double dy;
} dot;

void ball_updateBall(dot* ball)
{
	if((ball->x[0] < 96 - BALL_SIZE) && (ball->x[0] > 1))
    {
        ball->x[0]+=ball->dx;
    }
    else
    {
        ball->dx *= -1;
        ball->x[0]+=ball->dx;
    }
    if((ball->y[0] < 16 - BALL_SIZE) && (ball->y[0] > 1))
    {
        ball->y[0]+=ball->dy;
    }
    else
    {
        ball->dy *= -1;
        ball->y[0]+=ball->dy;
    }
}

int main()
{
    dotMatrix dotMat;// 16行2色3ワード(3*32 = 96)
    uint8 x = 0;
	uint8 y[2] = {0};
    uint8 i,j,n;
	double temp;
    double k[2] = {0.0};
    
	dot a[N];
    for (i = 0;i < N;i++)
    {
        a[i].x[0] = a[i].x[1]= rand()%(92-BALL_SIZE)+2;
        a[i].y[0] = a[i].y[1]= rand()%(12-BALL_SIZE)+2;
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
            k[0] = 0;
        }
        if(k[1] < 2 * 3.14)
        {
            k[1] += 0.1;
        }
        else
        {
            k[1] = 0;
        }
        
        for(n = 0;n < N;n++)
        {   
			ball_updateBall(&a[n]);
			//ボール間の衝突検知
			for(i = 0;i < N;i++)
			{
				if(n != i)
				{
					if(((int)a[n].x[0] == (int)a[i].x[0]) && ((int)a[n].y[0] == (int)a[i].y[0]))
					{
						temp = a[n].dx;
						a[n].dx = a[i].dx;
						a[i].dx = temp;
						temp = a[n].dy;
						a[n].dy = a[i].dy;
						a[i].dy = temp;
						ball_updateBall(&a[n]);
						
						if(((int)a[n].x[0] == (int)a[i].x[0]) && ((int)a[n].y[0] == (int)a[i].y[0]))
						{
							ball_updateBall(&a[n]);
						}
					}
				}
			}
            for(i = 0;i < BALL_SIZE;i++){
                for(j = 0;j < BALL_SIZE;j++){
					if(n%3 == 2){
                    	dotMat.array[(int)a[n].x[0]+i][(int)a[n].y[0]+j][0] = 1;
                    	dotMat.array[(int)a[n].x[0]+i][(int)a[n].y[0]+j][1] = 1;
					}
					else
					{
                    	dotMat.array[(int)a[n].x[0]+i][(int)a[n].y[0]+j][n%3] = 1;
                    	dotMat.array[(int)a[n].x[0]+i][(int)a[n].y[0]+j][~(n%3)] = 0;
					}
                }
            }
        }
        dotMatrix_dataToArray(&dotMat);
        dotMatrix_print(&dotMat);
        //CyDelay(10);
    }
}

/* [] END OF FILE */
