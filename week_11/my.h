#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>
#include<dlfcn.h>
#include<setjmp.h>
#include<sys/wait.h>
#include<errno.h>

#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH

void err_exit(char*s)
{
	printf("Usage: %s is failed!\n",s);
	exit(0);

}

void MyWrite(char id[],int pid,int ppid)
{
	FILE *fp;
	time_t t=time(&t);
	fp=fopen("log.dat","a+");
	fprintf(fp,"%s  %d  %d  %s",id,pid,ppid,asctime(localtime(&t)));
	fclose(fp);
}

/*void MyRead()
{
	FILE *fp;
	fp=fopen("log.dat","r+");
	while(!feof(fp))
	{
		char id[10];
		int pid;
		int ppid;
		char t[20];
		fscanf(fp,"%s  %d  %d  %s",id,pid,ppid,t);
		printf("%s  %d  %d  %s\n",id,pid,ppid,t);
	}
}*/
