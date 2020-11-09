#include "head.h"

int main()
{
	int fd;
	FILE *fp;
	char *s="Hello World!\n";
	if((fd=open("test.1",O_CREAT|O_WRONLY,0644))==-1)
	{
		printf("Error to create file!\n");
		exit(1);
	}
	if((fd=open("test.2","w+"))==NULL)
        {
                printf("Error to create file!\n");
                exit(1);
        }
	sleep(20);
	write(fd,s,strlen(s));
	fwrite(s,sizeof(char),strlen(s),fp);
	printf("After write!\n");
	sleep(20);
	close(fd);
	return 0;
}
