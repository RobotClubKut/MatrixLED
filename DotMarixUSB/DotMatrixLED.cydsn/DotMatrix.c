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
#define USB_DEBUG

const uint8 DATA_START[6] = "pcmat";
const uint8 DATA_END[4] = "end";

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

static void dotMatrix_dataToArray(dotMatrix* dotMat)
{
    uint8 i,j,h;
	
    for(h = 0;h < 16;h++)
    {
        for(i = 0;i < 3;i++)
        {
            for(j = 0;j < 32;j++)
            {
                if(dotMat->array[i * 32 + j][h][0])
                {
                    dotMat->data[h][i][0] |= (0x1 << j);
                }
                else
                {
                    dotMat->data[h][i][0] &= ~(0x1 << j);
                }
                if(dotMat->array[i * 32 + j][h][1])
                {
                    dotMat->data[h][i][1] |= (0x1 << j);
                }
                else
                {
                    dotMat->data[h][i][1] &= ~(0x1 << j);
                }
            }
        }
    }
}

static void dotMatrix_USBGetStrCmp(dotMatrix* dotMat,uint8* str)
{
	uint8 buffer[255];
	uint8 indata[255];
	uint8 count;
	uint8 i;
	uint8 j = 0;
	while(1)
	{
		if(USBUART_IsConfigurationChanged() != 0u) 
	    {
	        if(USBUART_GetConfiguration() != 0u)   
	        {
	            USBUART_CDC_Init();
	        }
	    }         
	    if(USBUART_GetConfiguration() != 0u)    /* Service USB CDC when device configured */
	    {
			if(USBUART_DataIsReady() != 0u)
			{
				count = USBUART_GetAll(buffer);
				#ifdef USB_DEBUG
				while(USBUART_CDCIsReady() == 0u);    /* Wait till component is ready to send more data to the PC */ 
	            USBUART_PutData(buffer, count);       /* Send data back to PC */
	            if(count == 255)
	            {
	                while(USBUART_CDCIsReady() == 0u); /* Wait till component is ready to send more data to the PC */ 
	                USBUART_PutData(NULL, 0u);         /* Send zero-length packet to PC */
	            }
				#endif
				for(i = 0;i < count;i++)
				{
					if(j <= strlen((char*)str))
					{
						indata[j] = buffer[i];
						j++;
					}
					if(buffer[i] == '\r')
					{
						indata[j-1] = '\0';
						j = 0;
						if(strcmp((char*)indata,(char*)str) == 0)
						{
							return;
						}
					}
				}
			} 
	    }
	}
}
void dotMatrix_init(dotMatrix* dotMat)
{
	uint8 str[10] = "start";
	CyGlobalIntEnable;
	
    dotMatrix_clear(dotMat);
	dotMatrix_print(dotMat);
	USBUART_Start(0, USBUART_5V_OPERATION);
	while (!USBUART_GetConfiguration());
    USBUART_CDC_Init();
	dotMatrix_USBGetStrCmp(dotMat,str);
}
void dotMatrix_print(dotMatrix* dotMat)
{
    uint8 i;
    static uint8 mem = 0;
	
    dotMatrix_dataToArray(dotMat);
	
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

void dotMatrix_getPcData(dotMatrix* dotMat)
{
	uint16 temp;
	uint8 buffer[255];
	uint8 indata[255];
	uint8* strerr;
	uint8 count;
	uint8 i;
	uint16 j = 0;
	uint16 data_size = 0;
	uint8 stage = STAGE_START;
	#ifdef USB_DEBUG
		char usb_debug_str[255];
	#endif
	while(stage != STAGE_DONE)
	{
		if(USBUART_IsConfigurationChanged() != 0u) 
	    {
	        if(USBUART_GetConfiguration() != 0u)   
	        {
	            USBUART_CDC_Init();
	        }
	    }         
	    if(USBUART_GetConfiguration() != 0u)    /* Service USB CDC when device configured */
	    {
			if(USBUART_DataIsReady() != 0u)
			{
				count = USBUART_GetAll(buffer);
				#ifdef USB_DEBUG
				while(USBUART_CDCIsReady() == 0u);    /* Wait till component is ready to send more data to the PC */ 
	            USBUART_PutData(buffer, count);       /* Send data back to PC */
	            if(count == 255)
	            {
	                while(USBUART_CDCIsReady() == 0u); /* Wait till component is ready to send more data to the PC */ 
	                USBUART_PutData(NULL, 0u);         /* Send zero-length packet to PC */
	            }
				#endif
				for(i = 0;i < count;i++)
				{
					if(stage == STAGE_START)
					{
						if(j <= strlen((char*)DATA_START))
						{
							indata[j] = buffer[i];
							j++;
						}
						if(buffer[i] == '\r')
						{
							indata[j-1] = '\0';
							j = 0;
							if(strcmp((char*)indata,(char*)DATA_START) == 0)
							{
								strcpy(dotMat->inData.head,(char*)indata);
								stage = STAGE_POINT_START;
								#ifdef USB_DEBUG
								while(!USBUART_CDCIsReady());
								USBUART_PutString("\rstart ok!\r");
								#endif
							}
						}
					}
					else if(stage == STAGE_POINT_START)
					{
						if(j < 3)
						{
							indata[j] = buffer[i];
							j++;
						}
						else if(buffer[i] == '\r')
						{
							indata[j] = '\0';
							j = 0;
							strcpy(dotMat->inData.start,(char*)indata);
							temp = (uint16)strtol(dotMat->inData.start,&strerr,16);
							dotMat->inData.start_point[0] = (temp >> 4) & 0xff;
							dotMat->inData.start_point[1] = temp & 0xf;
							stage = STAGE_POINT_END;
							#ifdef USB_DEBUG
							while(!USBUART_CDCIsReady());
							sprintf(usb_debug_str,"\rpoint %x,%x start ok!\r"
								,dotMat->inData.start_point[0]
								,dotMat->inData.start_point[1]);
							USBUART_PutString(usb_debug_str);
							#endif
							if((dotMat->inData.start_point[0] > 95) || (dotMat->inData.start_point[1] > 15))
							{
								stage = STAGE_ERR;
							}
						}
						else
						{
							#ifdef USB_DEBUG
							while(!USBUART_CDCIsReady());
							USBUART_PutString("\rpoint start err\r");
							#endif
							return;
						}
					}
					
					else if(stage == STAGE_POINT_END)
					{
						if(j < 3)
						{
							indata[j] = buffer[i];
							j++;
						}
						else if(buffer[i] == '\r')
						{
							indata[j] = '\0';
							j = 0;
							strcpy(dotMat->inData.end,(char*)indata);
							temp = (uint16)strtol(dotMat->inData.end,&strerr,16);
							dotMat->inData.end_point[0] = (temp >> 4) & 0xff;
							dotMat->inData.end_point[1] = temp & 0xf;
							stage = STAGE_DATA;
							data_size = ((dotMat->inData.end_point[0] - dotMat->inData.start_point[0] + 1) / 4)
									   * (dotMat->inData.end_point[1] - dotMat->inData.start_point[1] + 1)
									   * 2;
							#ifdef USB_DEBUG
							while(!USBUART_CDCIsReady());
							sprintf(usb_debug_str,"\rpoint %x,%x end ok!\r"
								,dotMat->inData.end_point[0]
								,dotMat->inData.end_point[1]);
							USBUART_PutString(usb_debug_str);
							#endif
							if((dotMat->inData.end_point[0] > 95) || (dotMat->inData.end_point[1] > 15) 
							|| ((dotMat->inData.end_point[0] - dotMat->inData.start_point[0]) < 4)
							|| ((dotMat->inData.end_point[1] - dotMat->inData.start_point[1]) < 0))
							{
								stage = STAGE_ERR;
							}
						}
						else
						{
							#ifdef USB_DEBUG
							while(!USBUART_CDCIsReady());
							USBUART_PutString("\rpoint end err\r");
							#endif
							return;
						}
					}
					else if(stage == STAGE_DATA)
					{
						if(j < data_size)
						{
							dotMat->inData.data[j] = buffer[i];
							j++;
						}
						else if(buffer[i] == '\r')
						{
							j = 0;
							stage = STAGE_END;
							#ifdef USB_DEBUG
							while(!USBUART_CDCIsReady());
							sprintf(usb_debug_str,"\rdata ok!\r");
							USBUART_PutString(usb_debug_str);
							#endif
						}
						else
						{
							#ifdef USB_DEBUG
							while(!USBUART_CDCIsReady());
							USBUART_PutString("\rpoint start err\r");
							#endif
							return;
						}
					}
					else if(stage == STAGE_END)
					{
						if(j < strlen((char*)DATA_END))
						{
							indata[j] = buffer[i];
							j++;
						}
						else if(buffer[i] == '\r')
						{
							j = 0;
							stage = STAGE_DONE;
							#ifdef USB_DEBUG
							while(!USBUART_CDCIsReady());
							sprintf(usb_debug_str,"\rdata end ok!\r");
							USBUART_PutString(usb_debug_str);
							#endif
							break;
						}
						else
						{
							#ifdef USB_DEBUG
							while(!USBUART_CDCIsReady());
							USBUART_PutString("\rpoint start err\r");
							#endif
							return;
						}
					}
					else if(stage == STAGE_ERR)
					{
						#ifdef USB_DEBUG
						while(!USBUART_CDCIsReady());
						USBUART_PutString("\rget pc data err\r");
						#endif
						return;
					}
				}
			} 
	    }
	}	
	#ifdef USB_DEBUG
	while(!USBUART_CDCIsReady());
	USBUART_PutString("\rdata DONE!!\r");
	#endif
}

/* [] END OF FILE */
