#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

void receiveBMSdata() 
{
	char bmsData_a[50] = {0};
  char temp_buffer[5] = {0};
	char *strIndexer_c = NULL;
  flot temp_f;
	for(int count = 0;count++ <= 15; count++)
	{
		bmsData_a[0] = '\0';
		strIndexer_c = NULL;
		
		scanf("%s", bmsData_a);
		
		strIndexer_c = strstr(bmsData_a, "\"Temperature\":");
  
    for(int tempCnt_i = 13;strIndexer_c[tempCnt] != '|'; tempCnt_i++)
    {
      temp_buffer[tempCnt_i++] = strIndexer_c[tempCnt_i++];
    }
    
    *temp_f = atof(temp_buffer);
    printf("Check Temp : %f \n", temp_f);
    
	}
}
