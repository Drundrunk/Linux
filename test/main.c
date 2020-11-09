#include "my.h"

int main()
{
	user record[NUM];
	//	int n;

	input(record);
	//printf("input over!\n");
	save(record);
	//printf("save over!\n");
	output(record);
//	printf("output over!\n");

	/*
	record=(struct user *)malloc(sizeof(struct user));

	if(record==NULL)
	{
		exit(1);
	}
	if(int i=0,i<n,i++)
	{
		input();
		save();
	}
	*/

	return 0;
}
