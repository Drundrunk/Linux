#include "../ch08.h"

int main(){
  void *fpt = dlopen("./libd2lib.so",RTLD_NOW);
  if(!fpt){
   printf("dlopen failed!\n");
   exit(1);
  }
 // void (*fp)(void)=dlsym(fpt,"dynamic_lib_fun_call");
  void (*fp2)(void)=dlsym(fpt,"sort");
  if(!fp2)
  {
    printf("dlysm failed!\n");
	exit(1);
  }
 // fp();
  fp2();
  dlclose(fpt);
  return 0;
}
