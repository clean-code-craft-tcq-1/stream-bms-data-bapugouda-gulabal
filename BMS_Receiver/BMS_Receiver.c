#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

void receiveBMSdata(void);

void receiveBMSdata() 
{
  char bmsData_a[2000] = {0};
  char temp_buffer[5] = {0};
  char *strIndexer_c = NULL;
  float temp_f;
  int cnt_i=0;
  for(int count = 0;count++ <= 7000; count++)
  {
	bmsData_a[0] = '\0';
	strIndexer_c = NULL;
		
	scanf("%s", bmsData_a);
	//printf("dddddddddd : %s \n", bmsData_a);		
	  
	strIndexer_c = strstr(bmsData_a, "Temperature:");
  
	if(NULL != strIndexer_c)
	{
    	while(strIndexer_c[cnt_i] != ',')
    	{
      		temp_buffer[cnt_i] = strIndexer_c[12+cnt_i];
		printf("Check ewrewdf : %c \n", temp_buffer[cnt_i]);
		cnt_i++;
    	}
    
        temp_f = atof(temp_buffer);
        printf("Check Temp : %f \n", temp_f);
	}
    
  }
}

int main ()
{
  receiveBMSdata();
  printf("\nCheck---------------------\n");
  return 0;	
}
