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
#include "DotMatrix.h"

static void dotMatrix_lineOut(const uint32* data,const uint8 addr)
{
    uint8 i,j;
    uint32 g_data;
    uint32 r_data;
    LED_CLK_Write(0);
    LED_ADDR_Write(addr & 0x0f);
    CyDelayUs(1);
    for(i = 0;i < 3;i++)
    {
        g_data = *(data+i*2);
        r_data = *(data+i*2+1);
        for(j = 0;j < 32;j++)
        {
            LED_DR_Write( (r_data >> j) & 0x01 );
            LED_DG_Write( (g_data >> j) & 0x01 );
            CyDelayUs(1);
            LED_CLK_Write(1);
            CyDelayUs(1);
            LED_CLK_Write(0);
        }
    }
    CyDelayUs(1);
    LED_ALE_Write(1);
    LED_WE_Write(1);
    CyDelayUs(1);
    LED_WE_Write(0);
    LED_ALE_Write(0);
}

void dotMatrix_dataToArray(dotMatrix* dotMat)
{
    uint8 i,j,h;
    uint32 g_data;
    uint32 r_data;
    for(h = 0;h < 16;h++)
    {
        for(i = 0;i < 3;i++)
        {
            for(j = 0;j < 32;j++)
            {
                if(dotMat->array[i * 32 + j][h][0])
                {
                    dotMat->data[h][i][0] |= (0x00000001 << j);
                }
                else
                {
                    dotMat->data[h][i][0] &= ~(0x00000001 << j);
                }
                if(dotMat->array[i * 32 + j][h][1])
                {
                    dotMat->data[h][i][1] |= (0x00000001 << j);
                }
                else
                {
                    dotMat->data[h][i][1] &= ~(0x00000001 << j);
                }
            }
        }
    }
}

void dotMatrix_print(const dotMatrix* dotMat)
{
    uint8 i;
    static uint8 mem = 0;
    
    LED_SE_Write(1);
    LED_ABB_Write(mem);
    for(i = 0;i < 16;i++){
        dotMatrix_lineOut((uint32*)dotMat->data[i],i);
    }
     LED_ALE_Write(0);
    if(mem)mem = 0;
    else mem = 1;
}
void dotMatrix_clear(dotMatrix* dotMat)
{
    uint8 i,j;
    /*
    for(i = 0;i < 16;i++)
    {
        for(j = 0;j < 3;j++)
        {
            dotMat->data[i][j][0] = 0;
            dotMat->data[i][j][1] = 0;
        }
    }
    */
    for(i = 0;i < 96;i++)
    {
        for(j = 0;j < 16;j++)
        {
            dotMat->array[i][j][0] = 0;
            dotMat->array[i][j][1] = 0;
        }
    }
}
/* [] END OF FILE */
