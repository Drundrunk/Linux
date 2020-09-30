#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int ret;
	ret = write(1,"hello world!\n",13);
	exit(0);
}
