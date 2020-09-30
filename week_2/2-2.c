#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
	int ret;
	char buf[101];

	int fd;
	memset(buf,0,sizeof(buf));
	fd=open("./test.data",O_CREAT|O_TRUNC|O_RDWR,0644);
	
	printf("New file description %d\n",fd);
	
	printf("%d:2-2 is running!\n",getpid());
	ret=write(1,"hello world!\n",13);
	printf("ret = %d\n",ret);

	sleep(10);
	printf("Please input data <=100:\n");
	fgets(buf,100,stdin);
	ret=write(fd,buf,sizeof(buf));
	printf("ret = %d\n",ret);


	exit(0);
}
