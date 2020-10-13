#include"3-1.h"
int main(void){
	FILE *fd;
	fd = fopen("./test1.txt","w");
	printf("file fd = %d \n",fd->_fileno);
	fclose(fd);
	return 0;
}
