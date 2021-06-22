#include "BMS_Receiver.h"

void readBMSdata(void);
void analyzeBMSData(char *strIndexer_c);

bmsReceiver_t bmsReceiverData_s = {{0}, 0};

void readBMSdata() 
{
  char bmsData_a[50] = {0};
  char *strIndexer_c = NULL;
  
  for(int count = 0;count++ <= 200; count++)
  {
	scanf("%s", bmsData_a);	
	analyzeBMSData(bmsData_a);
  }
}

void analyzeBMSData(char *bmsData_a)
{
	int cnt_i=0;
	char temp_buffer[5] = {0};
	char *strIndexer_c = NULL;
	
	for(int cntParam = 0;cntParam < 2; cntParam++)
	{
		strIndexer_c = strstr(bmsData_a, bmsParam_a[cntParam]);
		if(NULL != strIndexer_c)
		{
			printf("strIndexer_c %s \n",strIndexer_c);
			while(strIndexer_c[BMS_PARAM_READ_INDEX+cnt_i] != ',')
			{
				temp_buffer[cnt_i] = strIndexer_c[BMS_PARAM_READ_INDEX+cnt_i];
				cnt_i++;
			}
			bmsParamVal_f[valCount_i][cntParam] = atof(temp_buffer);
			printf("%s : %f \n ", bmsParam_a[cntParam], bmsReceiverData_s.bmsParamVal_f[bmsReceiverData_s.valCount_i][cntParam]);
		}
	}	
	
	valCount_i++;
}

int main ()
{
  readBMSdata();
  printf("\nCheck---------------------\n");
  return 0;	
}
