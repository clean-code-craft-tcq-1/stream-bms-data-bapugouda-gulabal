#include "BMS_Receiver.h"

void readBMSdata(void);
void analyzeBMSData(char *strIndexer_c);

const char bmsParam_a[2][20] = {"Temperature:", "StateOfCharge"};
float bmsParamVal[15][2] = {0};
int valCount_i = 0;

void readBMSdata() 
{
  char bmsData_a[500] = {0};
  char *strIndexer_c = NULL;
  
  for(int count = 0;count++ <= 200; count++)
  {
	scanf("%s", bmsData_a);		
	analyzeBMSData(char *bmsData_a);
  }
}

void analyzeBMSData(char *bmsData_a)
{
	int cnt_i=0;
	char temp_buffer[5] = {0};
	float temp_f;
	
	strIndexer_c = NULL;
	
	for(int cntParam = 0;cntParam++ <= 2; cntParam++)
	{
		strIndexer_c = strstr(bmsData_a, bmsParam_a[cntParam]);
		if(NULL != strIndexer_c)
		{
			while(strIndexer_c[14+cnt_i] != ',')
			{
				temp_buffer[cnt_i] = strIndexer_c[14+cnt_i];
				cnt_i++;
			}
			bmsParamVal[valCount_i][cntParam] = atof(temp_buffer);
			printf("Check %s %f \n ", bmsParam_a[cntParam], bmsParamVal[valCount_i][cntParam]);
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
