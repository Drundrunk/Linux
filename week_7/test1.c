#include "head.h"

//extern void dynamic_lib_call(void);

int mian()
{       
        void *dlib=dlopen("./libdlib.so",RTLD_NOW);
        if(!dlib)
        {
                printf("dlopen failed!\n");
                exit(-1);
        }
        void(*dfunc) (void)=dlsym(dlib,"dynamic_lib_call");
        if(!dfunc)
        {
                printf("dfunc failed!\n");
                exit(-1);
        }

	dfunc();
	dlclose(dlib);

        return 0;
}       
~                                                                               
~                  
