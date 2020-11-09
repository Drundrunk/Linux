#include "6.h"

#define N 10

int a[10],i;

int main(){
   for(i =0; i<N; i++){
    a[i]  =i +1;
    }
  a[N] = 789456123;
   printf("i = %d\n",i);
	
	//printf("%d \n", a[i]);
    printf("%d \n", a[N]);

  return 0;
}
