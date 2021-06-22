/******************************************************************************/
/*!
***     \file        BMS_Receiver.h
***     \author      Abinesh KanjiKovil Thatchinamoorthy 
***
***
***     \brief       Local header for BMS Receiver
***
*\n*/
/*****************************************************************************/

/* Inclusions */
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

/* Constants and Macros */

#define BMS_PARAM_READ_INDEX 12

const char bmsParam_a[2][20] = {"Temperature", "StateOfChar"};

typedef struct {
    float bmsParamVal_f[15][2];
	  int valCount_i;
}bmsReceiver_t;

/* EOF */
