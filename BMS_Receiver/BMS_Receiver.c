#include "BMS_Receiver.h"

void readBMSdata(void);
void analyzeBMSData(char *strIndexer_c);

void readBMSdata() 
{
  char bmsData_a[500] = {0};
  char *strIndexer_c = NULL;
  
  for(int count = 0;count++ <= 200; count++)
  {
	strIndexer_c = NULL;
		
	scanf("%s", bmsData_a);		
	  
	strIndexer_c = strstr(bmsData_a, "Temperature:");
  
	if(NULL != strIndexer_c)
	{
		analyzeBMSData(strIndexer_c);
	}
  }
}

void analyzeBMSData(char *strIndexer_c)
{
	int cnt_i=0;
	char temp_buffer[5] = {0};
	char soc_buffer[2]  = {0};
	float temp_f;
	int soc_i;
	
	while(strIndexer_c[12+cnt_i] != ',')
	{
		temp_buffer[cnt_i] = strIndexer_c[12+cnt_i];
		cnt_i++;
	}
	soc_buffer[0]  = strIndexer_c[12+15+cnt_i];
	soc_buffer[1]  = strIndexer_c[12+16+cnt_i];

	temp_f = atof(temp_buffer);
	soc_i  = ato1(soc_buffer);
	printf("Check Temp : %f \n", temp_f);
	printf("Check SOC : %d \n", soc_i);
}

int main ()
{
  readBMSdata();
  printf("\nCheck---------------------\n");
  return 0;	
}
