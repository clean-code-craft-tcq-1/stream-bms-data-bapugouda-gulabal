#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

void receiveBMSdata(void);

void receiveBMSdata() 
{
  char bmsData_a[500] = {0};
  char temp_buffer[5] = {0};
  char *strIndexer_c = NULL;
  float temp_f;
  int cnt_i=0;
  for(int count = 0;count++ <= 200; count++)
  {
	bmsData_a[0] = '\0';
	strIndexer_c = NULL;
	cnt_i = 0;
	temp_buffer[0] = '\0';
		
	scanf("%s", bmsData_a);		
	  
	strIndexer_c = strstr(bmsData_a, "Temperature:");
  
	if(NULL != strIndexer_c)
	{
	printf("dddddddddd : %s \n", bmsData_a);

    	while(strIndexer_c[12+cnt_i] != ',')
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
