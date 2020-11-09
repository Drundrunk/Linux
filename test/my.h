#include<stdio.h>
#include<stdlib.h>
//#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

#define NUM 2

typedef struct {
	char id[8];
	char name[8];
	char htel[12];
	char tel[12];
}user;

void input(user record[]);
void output(user record[]);
void save(user record[]);
void mysort();
void randdat();

