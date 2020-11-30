#include "my.h"

int main()
{
	pid_t pid1;
	pid1 =fork();
	if(pid1<0)
	{	
		perror("fork pid1 error!\n");
		exit(-1);
	}
	else if(pid1==0)
	{
		pid_t pid11;
		pid11=fork();
		
		if(pid11<0)
		{	
			perror("fork pid11 error!\n");
			exit(-1);
		}
		else if(pid11==0)
		{
			printf("child11 :pid=%d,ppid=%d\n",getpid(),getppid());
			MyWrite("pid11 ",getpid(),getppid());
			exit(0);
		}
		else
		{
			wait(&pid11);
			printf("child1 :pid=%d,ppid=%d\n",getpid(),getppid());
			MyWrite("pid1  ",getpid(),getppid());
			exit(0);
		}
	}
	
	else
	{	
		pid_t pid2;
		pid2=fork();
		if(pid2<0)
		{	
			perror("fork pid2 error!\n");
			exit(-1);
		}
		else if(pid2==0)
		{
			pid_t pid21;
			pid21=fork();
			
			if(pid21<0)
			{	
				perror("fork pid21 error!\n");
				exit(-1);
			}
			else if(pid21==0)
			{
				printf("child21 :pid=%d,ppid=%d\n",getpid(),getppid());
				MyWrite("pid21 ",getpid(),getppid());
				exit(0);
			}
			else
			{
				wait(&pid21);
				printf("child2 :pid=%d,ppid=%d\n",getpid(),getppid());
				MyWrite("pid2  ",getpid(),getppid());
				exit(0);
			}
		}
		else
		{			
			wait(NULL);
			printf("parent :pid=%d,ppid=%d\n\n",getpid(),getppid());
			MyWrite("parent ",getpid(),getppid());
			
			return 0;
		}
	}
}
