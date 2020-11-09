#include <stdio.h>
#include "head.h"

int main(void){
   char m[2];
   printf("input m:");
   gets(m);
   printf("m<100,m=%s\n",m);
   
   char n[2];
   printf("input n:");
   fgets(n,2,stdin);
   printf("\n");
   printf("n<100,n=%s",n);

   return 0;
}

