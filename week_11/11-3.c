#include "ch11.h"

int main()
{
	pid_t pid;
	pid =fork();
	if(pid<0)
	{	
		perror("fork pid1 error!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("child1 :pid=%d,ppid=%d\n",getpid(),getppid());
		exit(0);
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
	printf("child2 :pid=%d,ppid=%d\n",getpid(),getppid());
			while(1);
			exit(0);
		}
		else
		{	
			int s1,r1,s2,r2;
			r1=wait(&s1);
			r2=wait(&s2);
			if(WIFEXITED(s1))
			{
				printf("parent wait for child1, pid:%d， exit code %d\n",r1,WEXITSTATUS(s1));
			}
			else
			{
				if(WIFSIGNALED(s1))
				{
					printf("pid :%d exit with  signal %d\n",r1,WEXITSTATUS(s1));
				}
			}


			if(WIFEXITED(s2))
			{
				printf("parent wait for child2, pid:%d， exit code %d\n",r2,WEXITSTATUS(s2));
			}
			else
			{
				if(WIFSIGNALED(s1))
				{
					printf("pid :%d exit with  signal %d\n",r2,WEXITSTATUS(s2));
				}
			}


			printf("parent finish\n");


			
			return 0;
		}
	}
	
}
