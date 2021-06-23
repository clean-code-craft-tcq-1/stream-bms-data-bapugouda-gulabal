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
	char *strIndexer_c = NULL;
	char chTempBuf_a[2],chSOCBuff_a[2];
	
	strIndexer_c = strstr(bmsData_a, bmsParam_a[0]);
	if(NULL != strIndexer_c)
	{
		cnt_i = 0;
		printf("strIndexer_c %s \n",strIndexer_c);
		while(strIndexer_c[12+cnt_i] != ',')
		{
			/*chTempBuf_a[cnt_i]= strIndexer_c[12+cnt_i];
			chSOCBuff_a[cnt_i]= strIndexer_c[25+cnt_i];*/
			cnt_i++;
		}
		/*bmsReceiverData_s.bmsParamVal_f[bmsReceiverData_s.valCount_i][0] = atof(chTempBuf_a);
		bmsReceiverData_s.bmsParamVal_f[bmsReceiverData_s.valCount_i][1] = atof(chSOCBuff_a);
		printf("%s : %f \n ", bmsParam_a[0], bmsReceiverData_s.bmsParamVal_f[bmsReceiverData_s.valCount_i][0]);
		printf("%s : %f \n ", bmsParam_a[1], bmsReceiverData_s.bmsParamVal_f[bmsReceiverData_s.valCount_i][1]);*/
		bmsReceiverData_s.valCount_i++;
	}
}

int main ()
{
  char bmsData_a[35] = {0};
  
  for(int count = 0;count++ <= 150; count++)
  {
	scanf("%s", bmsData_a);	
	readBMSdata(bmsData_a);
  }
	
  return 0;	
}

/* EOF */
