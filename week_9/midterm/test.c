#include "./ch09.h"
int g=0;

int main()
{
        int fd_in,fd_out;
        char buf[1024];
        pid_t pid,pid1,pid2,pid11,pid12;
        memset(buf,0,1024);
        fd_in=open(INFILE,O_RDONLY);
        if(fd_in<0)
        {
                fprintf(stderr,"failed to open %s,reason(%s)\n",INFILE,strerror(errno));
                return 1;
        }
        fd_out=open(OUTFILE,O_WRONLY|O_CREAT|O_TRUNC,MODE);
        if(fd_out<0)
        {
                fprintf(stderr,"failed to open %s,reason(%s)\n",OUTFILE,strerror(errno));
                return 1;
        }
        pid=fork();
        if(pid<0)
        {
                fprintf(stderr,"failed to fork %s,reason(%s)\n",strerror(errno));
                return 1;
        }
		
		
	else if(pid==0)
	{	
		printf("child1 : pid1 = %d, ppid1 = %d, return form fork() = %d\n",getpid1(),getppid1(),pid1);
		printf("child1 : init g = %d\n",g);
		g++;
		printf("child2 : pid2 = %d, ppid2 = %d, return form fork() = %d\n",getpid2(),getppid2(),pid2);
		printf("child2 : init g = %d\n",g);
		g++;
		if(pid1=(getppid()+1))
		{	
		printf("child11 : pid11 = %d, ppid11 = %d, return form fork() = %d\n",getpid11(),getppid11(),pid11);
		printf("child11 : init g = %d\n",g);
		g++;
		}
		else
		{
		sleep(2);
		printf("parent1 ：pid1 = %d, ppid1 = %d, return form vfork() = %d\n",getpid1(),getppid1(),pid1);
		printf("parent1 : init g = %d\n",g);
        g++;
		}
		exit(0);
	}
	else
	{
		sleep(2);
		printf("parent ：pid = %d, ppid = %d, return form vfork() = %d\n",getpid(),getppid(),pid);
		printf("parent : init g = %d\n",g);
        g++;
		return 0;
	}
		
        while(read(fd_in,buf,2)>0)
        {
                printf("%d: %s",getpid(),buf);
                sprintf(buf,"%d hello word!\n",getpid());
                write(fd_out,buf,strlen(buf));
                sleep(1);
                memset(buf,0,1024);
        }
}

