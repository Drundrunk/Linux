#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>
#include<dlfcn.h>

void err_exit(char*s)
{
	printf("Usage: %s is failed!\n",s);
	exit(0);

}
