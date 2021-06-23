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
	int cnt_i = 0, socCnt_i = 0;
	char *strIndexer_c = NULL;
	char chTempBuf_a[3],chSOCBuff_a[3];
	
	strIndexer_c = strstr(bmsData_a, bmsParam_a[0]);
	if(NULL != strIndexer_c)
	{
		cnt_i = 0;
		while(strIndexer_c[12+cnt_i] != ',')
		{
			chTempBuf_a[cnt_i]= strIndexer_c[12+cnt_i];
			cnt_i++;
		}
		chTempBuf_a[cnt_i] = '\0';
		while(strIndexer_c[25+cnt_i+socCnt_i] != ',')
		{
			chSOCBuff_a[socCnt_i]= strIndexer_c[25+cnt_i+socCnt_i];
			socCnt_i++;
		}	
		chSOCBuff_a[socCnt_i] = '\0';
		bmsReceiverData_s.bmsParamVal_f[bmsReceiverData_s.valCount_i][0] = atof(chTempBuf_a);
		bmsReceiverData_s.bmsParamVal_f[bmsReceiverData_s.valCount_i][1] = atof(chSOCBuff_a);
		bmsReceiverData_s.valCount_i++;
	}
}

void analyseBMSData(void)
{
	bmsReceiverData_s.tempStat_e.minVal_f = bmsReceiverData_s.bmsParamVal_f[0][0];
	bmsReceiverData_s.tempStat_e.maxVal_f = bmsReceiverData_s.bmsParamVal_f[0][0];
	bmsReceiverData_s.socStat_e.minVal_f  = bmsReceiverData_s.bmsParamVal_f[1][0];
	bmsReceiverData_s.socStat_e.maxVal_f  = bmsReceiverData_s.bmsParamVal_f[1][0];
	
	for(int count_i=0;count_i < bmsReceiverData_s.valCount_i; count_i++)
	{
		printf("%s : %f \n ", bmsParam_a[0], bmsReceiverData_s.bmsParamVal_f[bmsReceiverData_s.valCount_i][0]);
		printf("%s : %f \n ", bmsParam_a[1], bmsReceiverData_s.bmsParamVal_f[bmsReceiverData_s.valCount_i][1]);
		
		if(bmsReceiverData_s.bmsParamVal_f[0][count_i] < bmsReceiverData_s.tempStat_e.minVal_f) {
			bmsReceiverData_s.tempStat_e.minVal_f = bmsReceiverData_s.bmsParamVal_f[0][count_i];
		}
		if(bmsReceiverData_s.bmsParamVal_f[1][count_i] < bmsReceiverData_s.socStat_e.minVal_f) {
			bmsReceiverData_s.socStat_e.minVal_f = bmsReceiverData_s.bmsParamVal_f[1][count_i];
		}
		if(bmsReceiverData_s.bmsParamVal_f[0][count_i] > bmsReceiverData_s.tempStat_e.maxVal_f) {
			bmsReceiverData_s.tempStat_e.maxVal_f = bmsReceiverData_s.bmsParamVal_f[0][count_i];
		}
		if(bmsReceiverData_s.bmsParamVal_f[1][count_i] > bmsReceiverData_s.socStat_e.maxVal_f) {
			bmsReceiverData_s.socStat_e.maxVal_f = bmsReceiverData_s.bmsParamVal_f[1][count_i];
		}		

		bmsReceiverData_s.tempStat_e.avg_f = bmsReceiverData_s.tempStat_e.avg_f + bmsReceiverData_s.bmsParamVal_f[0][count_i];
		bmsReceiverData_s.socStat_e.avg_f = bmsReceiverData_s.socStat_e.avg_f + bmsReceiverData_s.bmsParamVal_f[1][count_i];
	}
	bmsReceiverData_s.tempStat_e.avg_f = bmsReceiverData_s.tempStat_e.avg_f / bmsReceiverData_s.valCount_i;
	bmsReceiverData_s.socStat_e.avg_f = bmsReceiverData_s.socStat_e.avg_f / bmsReceiverData_s.valCount_i;
	
	printf("Minimum Temperature value : %f \n", bmsReceiverData_s.tempStat_e.minVal_f);
	printf("Maximum Temperature value : %f \n", bmsReceiverData_s.tempStat_e.maxVal_f);
	printf("Minimum SOC value : %f \n", bmsReceiverData_s.socStat_e.minVal_f);
	printf("Maximum SOC value : %f \n", bmsReceiverData_s.socStat_e.maxVal_f);
	printf("Average Temperature value : %f \n", bmsReceiverData_s.tempStat_e.avg_f);
	printf("Average SOC value : %f \n", bmsReceiverData_s.socStat_e.avg_f);
}

int main ()
{
  char bmsData_a[500] = {0};
  
  bmsReceiverData_s.valCount_i = 0;
  for(int count = 0;count++ <= 200; count++)
  {
	scanf("%s", bmsData_a);	
	readBMSdata(bmsData_a);
  }
  
  analyseBMSData();
	
  return 0;	
}

/* EOF */
