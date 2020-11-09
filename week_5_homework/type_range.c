#include "head.h"
#include <float.h>
int main(void){
 int a = 1<<31;
 float b = 0;
 char *p = (char *)&b;
  *p=0xff;  
    *(p+1)=0xff;  
    *(p+2)=0x7f;  
    *(p+3)=0x7f;  
 double c = 1<<31;
 printf("int max = %d min = %d \n",~a,a);
 printf("float max = %f \n",b);
  *p=0x00;  
    *(p+1)=0x00;  
    *(p+2)=0x00;  
    *(p+3)=0x10;  
 printf("float min = %e \n",FLT_MIN);
 printf("double max = %e\n",DBL_MAX);
 printf("double min = %e \n", DBL_MIN);
}
