#include "./ch09.h"

int main(int argc,char **argv)
{
	int pid;
	int s;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("child : pid =%d,ppid =%d\n",getpid(),getppid());
		exit(23);
	}
	else
	{
		int y;
		y=wait(&s);
		if(WIFEXITED(s))
		{
			printf("child %d is normal back, the exit code =%d\n",y,WIFEXITED(s));
			return 0;
		}
	}
}          
