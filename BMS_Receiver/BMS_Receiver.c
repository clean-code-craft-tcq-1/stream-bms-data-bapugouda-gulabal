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

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    readBMSdata_v
 */
/*!    \brief       Reads the BMS data and stores it
 *
 *     \param       char *bmsData_a - scanned sender data from console
 *     \returns     void
 *
*//*------------------------------------------------------------------------*/
void readBMSdata_v(char *bmsData_a)
{
	char *strIndexer_c = NULL;
	
	strIndexer_c = strstr(bmsData_a, bmsParam_a[0]);
	if(NULL != strIndexer_c)
	{
	     storeBMSData_v(strIndexer_c);
	}
} /* EO readBMSdata_v */

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    storeBMSData_v
 */
/*!    \brief       Stores the BMS data
 *
 *     \param       char *bmsData_a - scanned sender data from console
 *     \returns     void
 *
*//*------------------------------------------------------------------------*/
void storeBMSData_v(char *strIndexer_c)
{
	int cnt_i = 0, socCnt_i = 0;
	char chTempBuf_a[3],chSOCBuff_a[3];
	
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
	printf("bmsReceiverData_s.valCount_i %d \n ", bmsReceiverData_s.valCount_i);	
}/* EO storeBMSData_v */

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    analyseBMSData_v
 */
/*!    \brief       Analyze the received BMS data to report the statistics
 *
 *     \param       void
 *     \returns     void
 *
*//*------------------------------------------------------------------------*/
void analyseBMSData_v(void)
{
	bmsReceiverData_s.tempStat_e.minVal_f = bmsReceiverData_s.bmsParamVal_f[0][0];
	bmsReceiverData_s.tempStat_e.maxVal_f = bmsReceiverData_s.bmsParamVal_f[0][0];
	bmsReceiverData_s.socStat_e.minVal_f  = bmsReceiverData_s.bmsParamVal_f[0][1];
	bmsReceiverData_s.socStat_e.maxVal_f  = bmsReceiverData_s.bmsParamVal_f[0][1];
	
	for(int count_i=0;count_i < bmsReceiverData_s.valCount_i; count_i++)
	{
		calDataRanges_v(count_i);
	}
	bmsReceiverData_s.tempStat_e.avg_f = bmsReceiverData_s.tempStat_e.avg_f / bmsReceiverData_s.valCount_i;
	bmsReceiverData_s.socStat_e.avg_f = bmsReceiverData_s.socStat_e.avg_f / bmsReceiverData_s.valCount_i;
	
	printf("Minimum Temperature value : %f \n", bmsReceiverData_s.tempStat_e.minVal_f);
	printf("Maximum Temperature value : %f \n", bmsReceiverData_s.tempStat_e.maxVal_f);
	printf("Minimum SOC value : %f \n", bmsReceiverData_s.socStat_e.minVal_f);
	printf("Maximum SOC value : %f \n", bmsReceiverData_s.socStat_e.maxVal_f);
	printf("Average Temperature value : %f \n", bmsReceiverData_s.tempStat_e.avg_f);
	printf("Average SOC value : %f \n", bmsReceiverData_s.socStat_e.avg_f);
}/* EO analyseBMSData_v */

int main ()
{
  char bmsData_a[500] = {0};
  
  bmsReceiverData_s.valCount_i = 0;
  for(int count = 0;count++ <= 200; count++)
  {
	scanf("%s", bmsData_a);	/* Reads the sender's BMS data from console */
	readBMSdata_v(bmsData_a);
  }
  
  analyseBMSData();
	
  return 0;	
}

/* EOF */
