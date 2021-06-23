/******************************************************************************/
/*!
***     \file        BMS_Receiver.c
***     \author      Abinesh KanjiKovil Thatchinamoorthy 
***
***
***     \brief       Source for BMS Receiver implementation
***
*\n*/
/*****************************************************************************/

/* Inclusions */
#include "BMS_Receiver.h"

/* Declarations */
bmsReceiver_t bmsReceiverData_s = {0};

void readBMSdata(char *bmsData_a)
{
	int cnt_i = 0;
	char temp_buffer[4] = {0};
	char *strIndexer_c = NULL;
	
	for(int cntParam = 0;cntParam < 1; cntParam++)
	{
		strIndexer_c = strstr(bmsData_a, bmsParam_a[cntParam]);
		if(NULL != strIndexer_c)
		{
			cnt_i = 0;
			//temp_buffer[0] ='\0';
			printf("strIndexer_c %s \n",strIndexer_c);
			printf("temp_buffer %s \n",temp_buffer);
			temp_buffer[0] = 'a';
			printf("temp_buffer %s \n",temp_buffer);
			printf("------------cnt_i :: %d \n", cnt_i);
			while(strIndexer_c[12+cnt_i] != ',')
			{
				temp_buffer[0] = strIndexer_c[12+cnt_i];
				printf("asdfsdfdsfsfsd %c \n",strIndexer_c[12+cnt_i]);
				cnt_i++;
			}
			bmsReceiverData_s.bmsParamVal_f[bmsReceiverData_s.valCount_i][cntParam] = atof(temp_buffer);
			printf("%s : %f \n ", bmsParam_a[cntParam], bmsReceiverData_s.bmsParamVal_f[bmsReceiverData_s.valCount_i][cntParam]);
			bmsReceiverData_s.valCount_i++;
		}
	}	
}

int main ()
{
  char bmsData_a[500] = {0};
  
  for(int count = 0;count++ <= 200; count++)
  {
	scanf("%s", bmsData_a);	
	readBMSdata(bmsData_a);
  }
	
  return 0;	
}
