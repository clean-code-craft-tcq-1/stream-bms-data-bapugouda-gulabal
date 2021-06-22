#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

void readBMSdata(void);

void readBMSdata() 
{
  char bmsData_a[500] = {0};
  char temp_buffer[5] = {0};
  char soc_buffer[2]  = {0};
  char *strIndexer_c = NULL;
  float temp_f;
	int soc_f;
  int cnt_i=0;
  for(int count = 0;count++ <= 200; count++)
  {
	bmsData_a[0] = '\0';
	strIndexer_c = NULL;
	cnt_i = 0;
	temp_buffer[0] = '\0';
	soc_buffer[0] = '\0';
		
	scanf("%s", bmsData_a);		
	  
	strIndexer_c = strstr(bmsData_a, "Temperature:");
  
	if(NULL != strIndexer_c)
	{
		printf("66666666666 : %s \n", strIndexer_c);
    	while(strIndexer_c[12+cnt_i] != ',')
    	{
      		temp_buffer[cnt_i] = strIndexer_c[12+cnt_i];
			cnt_i++;
    	}
		printf("Check SSSSvdfgfS : %s \n", soc_buffer);
		soc_buffer[0]  = strIndexer_c[12+15+cnt_i];
		soc_buffer[1]  = strIndexer_c[12+16+cnt_i];
		
		printf("Check SSSSS : %c \n", soc_buffer[0]);
		printf("Check SSSSS : %c \n", soc_buffer[1]);
		printf("Check SSSSS : %s \n", soc_buffer);
    
        temp_f = atof(temp_buffer);
		soc_f  = ato1(soc_buffer);
        printf("Check Temp : %f \n", temp_f);
		printf("Check SOC : %d \n", soc_f);
	}
  }
}

int main ()
{
  readBMSdata();
  printf("\nCheck---------------------\n");
  return 0;	
}
