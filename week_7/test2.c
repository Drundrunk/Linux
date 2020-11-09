#include "6.h"
#define LIBPATH "./libtest2.so"

int main(){
  void *handle = dlopen(LIBPATH,RTLD_LAZY);
  if(handle == NULL){
   printf("error\n");
   return 0;
  }
  void (*inc)() = (void (*)())dlsym(handle,"two");
  if(inc == NULL){
   printf("NULL\n");
   return 0;
  }
  inc();
}
