#include"3-1.h"
int main(void){
	int fd;
	fd = open("./test1.txt",O_CREAT,0644);
	printf("file fd = %d \n",fd);
	close(fd);
	return 0;
}
