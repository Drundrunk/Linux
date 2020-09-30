#include"ch2.h"

int main(void){
	int ret;
	char buf[100];
	int fd;
	memset(buf,0,sizeof(buf));
	fd = open("./test.data",O_CREAT|O_TRUNC|O_RDWR,0644);
	printf("%d",fd);
	printf("2-4 is running  %d\n",getpid());
	fgets(buf,100,stdin);
	ret = write(fd,buf,sizeof(buf));
	printf("\n%d",ret);
	exit(0);

}
