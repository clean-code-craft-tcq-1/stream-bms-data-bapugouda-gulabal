/******************************************************************************/
/*!
***     \file        BMS_Statistics.c
***     \author      Abinesh KanjiKovil Thatchinamoorthy 
***
***
***     \brief       Implementation for statistcs of BMS data
***
*\n*/
/*****************************************************************************/

/* Inclusions */
#include "BMS_Receiver.h"

extern bmsReceiver_t bmsReceiverData_s;
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
		calDataRanges_v();
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

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    analyseBMSData_v
 */
/*!    \brief       To find min,max and average
 *
 *     \param       void
 *     \returns     void
 *
*//*------------------------------------------------------------------------*/
void calDataRanges_v(void)
{
	if(bmsReceiverData_s.bmsParamVal_f[count_i][0] < bmsReceiverData_s.tempStat_e.minVal_f) {
		bmsReceiverData_s.tempStat_e.minVal_f = bmsReceiverData_s.bmsParamVal_f[count_i][0];
	}
	if(bmsReceiverData_s.bmsParamVal_f[count_i][1] < bmsReceiverData_s.socStat_e.minVal_f) {
		bmsReceiverData_s.socStat_e.minVal_f = bmsReceiverData_s.bmsParamVal_f[count_i][1];
	}
	if(bmsReceiverData_s.bmsParamVal_f[count_i][0] > bmsReceiverData_s.tempStat_e.maxVal_f) {
		bmsReceiverData_s.tempStat_e.maxVal_f = bmsReceiverData_s.bmsParamVal_f[count_i][0];
	}
	if(bmsReceiverData_s.bmsParamVal_f[count_i][1] > bmsReceiverData_s.socStat_e.maxVal_f) {
		bmsReceiverData_s.socStat_e.maxVal_f = bmsReceiverData_s.bmsParamVal_f[count_i][1];
	}		

	bmsReceiverData_s.tempStat_e.avg_f = bmsReceiverData_s.tempStat_e.avg_f + bmsReceiverData_s.bmsParamVal_f[0][count_i];
	bmsReceiverData_s.socStat_e.avg_f = bmsReceiverData_s.socStat_e.avg_f + bmsReceiverData_s.bmsParamVal_f[1][count_i];
}

/* EOF */
