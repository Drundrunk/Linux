#include "./ch09.h"
int g=0;

int main()
{
        int fd_in,fd_out;
        char buf[1024];
        pid_t pid;
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
		printf("child  :  pid = %d   , ppid = %d   , return form fork() = %d\n",getpid(),getppid(),pid);
		printf("child : init g = %d\n",g);
		exit(0);
	}
	else
	{
		printf("parent ： pid = %d   , ppid = %d   , return form fork() = %d\n",getpid(),getppid(),pid);
		printf("child : init g = %d\n",g);
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

