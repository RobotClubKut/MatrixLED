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
#include "PS2_Controller.h"
#include "font_8x8.h"

#define widht   16
#define height  32 /* MAX 96 */
#define GREEN   0
#define RED     1

void DotMat_init();
void DotMat_paint();
void rotate2block();
void randomBlock();
void paintMap();
void paintBlock();
int check();
void mergeMatrix();
void rotate();
void clearRow();
void myprint();

uint8 isr_flg = 0;
CYBIT a=0;

dotMatrix dotMat, Map, str;// 16行2色3ワード(3*32 = 96)


CY_ISR(timer_isr){
    isr_flg = 1;
}

int main()
{
    PS2Controller psData;
    static uint8 c_flag = 0;
    static uint8 right_flag = 0;
    static uint8 left_flag = 0;
    static uint8 down_flag = 0;
    static uint8 up_flag = 0;
    uint8 counter = 0;
    uint8 cmax = 50;
    
    int blocks[7][4][4] = {  //ブロックの宣言
        {
            {0,0,0,0},
            {0,1,1,0},
            {0,0,1,0},
            {0,0,1,0}
        },
        {
            {0,0,0,0},
            {0,1,1,0},
            {0,1,0,0},
            {0,1,0,0}
        },
        {
            {0,0,0,0},
            {0,1,0,0},
            {0,1,1,0},
            {0,0,1,0}
        },
        {
            {0,0,0,0},
            {0,0,1,0},
            {0,1,1,0},
            {0,1,0,0}
        },
        {
            {0,0,0,0},
            {0,0,1,0},
            {0,1,1,0},
            {0,0,1,0}
        },
        {
            {0,0,0,0},
            {0,1,1,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {
            {0,0,1,0},
            {0,0,1,0},
            {0,0,1,0},
            {0,0,1,0}
        }
    };
    
    int i, j, bflg = 0, gflg = 1;
    int block[4][4] = {}, rotated[4][4];
    signed int slidex = 0, slidey = 0;
    char string[12] = {};

	CyGlobalIntEnable;
    PS2_Start();
    CyIntSetSysVector(SysTick_IRQn + 16, timer_isr);
    SysTick_Config(0x00ffff);

	//USBUART_Start(0, USBUART_5V_OPERATION);
	//while (USBUART_GetConfiguration() == 0);
    //USBUART_CDC_Init();

    DotMat_init();
    randomBlock(blocks, block);
    paintBlock(block[4][4], slidey, slidex);
    //DotMat_paint(&Map);
    
    CyDelay(100);
     
    for (;;){
        psData = PS2_Controller_get();
        dotMatrix_print(&Map);
        dotMatrix_print(&dotMat);
        if(isr_flg){
            if(gflg){
                if(counter == cmax){
                    if(check(block, slidey - 1, slidex) == 1){
                        slidey--;
                    } else{
                        mergeMatrix(block, slidey , slidex);
                        clearRow(&cmax);
                        dotMatrix_dataToArray(&Map);
                        if(slidey == 0){
                            myprint(string);
                            gflg = 0;
                        }
                        randomBlock(blocks, block);
                        slidey = 0;
                        slidex = 0;
                    }
                    if(gflg){
                        DotMat_paint(block, slidey, slidex);
                    }
                    counter = 0;
                }
                counter++;
            } else{
                myprint(string);
            }
            isr_flg = 0;
        }
        
        if(psData.CIRCLE || psData.CROSS){
            rand();
                if(c_flag){
                    if(psData.CIRCLE){
                        rotate(block, rotated, 1);
                    }
                    if(psData.CROSS){
                        rotate(block, rotated, 2);
                    }
                    if(check(rotated, slidey , slidex) == 1){
                        if(bflg == 1){
                            slidex--;
                            bflg = 0;
                        }
                        if(bflg == 2){
                            slidex++;
                            bflg = 0;
                        }
                        rotate2block(block, rotated);
                        DotMat_paint(block, slidey, slidex);
                    }
                    if(check(rotated, slidey , slidex) == 2){
                        bflg = 1;
                        if(check(rotated, slidey , slidex + 1) == 2){
                            if(check(rotated, slidey , slidex + 2) == 1){
                                slidex++;
                            }
                        }
                        if(check(rotated, slidey , slidex + 1) == 1){
                            slidex++;
                            rotate2block(block, rotated);
                            DotMat_paint(block, slidey, slidex);
                        }
                    }
                    if(check(rotated, slidey , slidex) == 3){
                        bflg = 2;
                        if(check(rotated, slidey , slidex - 1) == 3){
                            if(check(rotated, slidey , slidex - 2) == 1){
                                slidex--;
                            }
                        }
                        if(check(rotated, slidey , slidex - 1) == 1){
                            slidex--;
                            rotate2block(block, rotated);
                            DotMat_paint(block, slidey, slidex);
                        }
                    }
                }
                c_flag = 0;
        } else{
            c_flag = 1;
        }
        
        if(psData.LEFT){
            bflg = 0;
            rand();
            if(left_flag){
                if(check(block, slidey , slidex - 1) == 1){
                    slidex--;
                    DotMat_paint(block, slidey, slidex);
                }
            }
            left_flag = 0;
        } else{
            left_flag = 1;
        }
        
        if(psData.RIGHT){
            bflg = 0;
            rand();
            if(right_flag){
                if(check(block, slidey , slidex + 1) == 1){
                    slidex++;
                    DotMat_paint(block, slidey, slidex);
                }
            }
            right_flag = 0;
        } else{
            right_flag = 1;
        }
        
        if(psData.UP){
            rand();
            if(up_flag){
                while(check(block, slidey - 1, slidex) == 1){
                    slidey--;
                }
                DotMat_paint(block, slidey, slidex);
            }
            up_flag = 0;
        } else{
            up_flag = 1;
        }
        
        if(psData.DOWN){
            rand();
            if(psData.L1){
                if(psData.R1){
                    while(check(block, slidey - 1, slidex) == 1){
                        slidey++;
                        DotMat_paint(block, slidey, slidex);
                    }
                }
            }
            if(down_flag){
                while(check(block, slidey - 1, slidex) == 1){
                    slidey--;
                    DotMat_paint(block, slidey, slidex);
                }                
            }
            down_flag = 0;
        } else{
            down_flag = 1;
        }
        
        if(psData.SELECT){
            if(psData.START){
                slidey = 0;
                slidex = 0;
                DotMat_init();
                randomBlock(blocks, block);
                paintBlock(block[4][4], slidey, slidex);
                gflg = 1;
                cmax = 50;
            }
        }
    }
}

void paintMap(){
    int i, j;
    for(i = 0; i < height; i++){
        for(j = 0; j < widht; j++){
            if(i > 2){
                if(j < 3 || j > 12){
                    Map.array[i][j][1] = 1;
                    Map.array[i][j][0] = 1;
                }
            } else{
                Map.array[i][j][1] = 1;
                Map.array[i][j][0] = 1;
            }
        }
    }
}

void paintBlock(int block[4][4], signed int offsety, signed int offsetx){
    int y, x;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            if (block[y][x]) {
                dotMat.array[y + offsety + height - 4][x + offsetx + 6][0] = 1;
            }
        }
    }
}

signed int check(int block[4][4], signed int offsety, signed int offsetx){
    int y, x;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            if(block[y][x]){
                if (Map.array[y + offsety + height - 4][x + offsetx + 6][1] == 1) {
                    if(x + offsetx + 6 < 4 || x == 0){
                        return 2; 
                    }
                    if(x + offsetx + 6 > 12 || x == 3){
                        return 3;
                    }
                    return -1;
                }
            }
        }
    }
    return 1;
}

void mergeMatrix(int block[4][4], signed int offsety, signed int offsetx){
    int y, x;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            if (block[y][x]) {
                dotMat.array[y + offsety + height - 4][x + offsetx + 6][0] = 0;
                Map.array[y + offsety + height - 4][x + offsetx + 6][1] = 1;
            }
        }
    }
}

void randomBlock(int blocks[7][4][4], int block[4][4]){
    int i, j;
    int random = rand() % 7;
    
    for (i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            block[i][j] = blocks[random][i][j];
        }
    }
    /*
    r = rand() % 7;
    for (i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            Map.array[i + height + 1][j][GREEN] = blocks[r][i][j];
        }
    }
    *random = r;
    */
}

void rotate(int block[4][4], int rotated[4][4], int rflg){
    int y, x;
    if(rflg == 1){
        for(x = 0; x < 4; x++){
            for(y = 0; y < 4; y++){
                rotated[x][4 - y - 1] = block[y][x];//0-0 0-3  0-1 1-3  0-2 2-3  0-3 3-3
            }
        }
    }
    if(rflg == 2){
        for(x = 0; x < 4; x++){
            for(y = 0; y < 4; y++){
                rotated[4 - x - 1][y] = block[y][x]; //0-0 3-0  0-1 2-0  0-2 1-0  0-3 0-0 
            }
        }
    }
}

void clearRow(uint8 *c){
    int y, x, i, j;
    int full;
    for(y = 3; y < height; y++){
        full = 1;
        for(x = 3; x < widht - 3; x++){
            if(Map.array[y][x][1] == 0){
                full = 0;
            }
        }
        if(full){
            for(i = 3; i < widht - 3; i++){
                Map.array[y][i][0] = 1;
                dotMatrix_dataToArray(&Map);
                dotMatrix_print(&Map);
                CyDelay(50);
            }
            for(i = 3; i < widht - 3; i++){
                Map.array[y][i][0] = 0;
                Map.array[y][i][1] = 0;
            }
            for(i = y; i < height; i++){
                for(j = 3; j < widht - 3; j++){
                    Map.array[i][j][1] = Map.array[i + 1][j][1];
                    Map.array[i + 1][j][1] = 0;
                }
            }
            if(*c != 2){
                if(*c > 10){
                    *c -= 2;
                } else{
                    *c -= 1;
                }
            }
            y--;
        }
    }
}

void DotMat_paint(int block[4][4], int slidey, int slidex){
    dotMatrix_clear(&dotMat);
    paintBlock(block, slidey, slidex);
    dotMatrix_dataToArray(&dotMat);
    dotMatrix_print(&dotMat);
    dotMatrix_print(&Map);
}

void DotMat_init(){
    dotMatrix_clear(&Map);
    dotMatrix_clear(&dotMat);
    paintMap();
    dotMatrix_dataToArray(&Map);
    dotMatrix_dataToArray(&dotMat);
    dotMatrix_print(&dotMat);
    dotMatrix_print(&Map);
}

void rotate2block(int block[4][4], int rotated[4][4]){
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            block[i][j] = 0;
            block[i][j] = rotated[i][j];
        }
    }
}

void myprint(char *string){
    dotMatrix_clear(&dotMat);
    dotMatrix_clear(&Map);
    dotMatrix_clear(&str);
    dotMatrix_dataToArray(&dotMat);
    dotMatrix_dataToArray(&Map);
    
    string = "GAME OVER";
    int x = 0, y = 0, offsetx = 4, offsety = 76, i = 0;
    while(string[i]){
        string[i] -= 0x20;
        for(y = 0; y < 8; y++){
       		for(x = 0; x < 8; x++){
       			if(font[8 * string[i] + y] & (1 << x)){
       				//str.array[y + offsety][x + offsetx][0] = 1;
                    str.array[8 - x + offsety - 1][y + offsetx][RED] = 1;
       			}
       			else{
      				//str.array[y + offsety][x + offsetx][0] = 0;
                    str.array[8 - x + offsetx - 1][y + offsety][RED] = 0;
       			}
      		}
      	}
        offsety -= 8;
        i++;
    }
    dotMatrix_dataToArray(&str);
  	dotMatrix_print(&str);
}

/* [] END OF FILE */
