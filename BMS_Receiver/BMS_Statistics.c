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
/*!    \brief       To find min,max and average
 *
 *     \param       int count_i - index of BMS data
 *     \returns     void
 *
*//*------------------------------------------------------------------------*/
void calDataRanges_v(int count_i)
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
