#include "my.h"
#include <math.h>

void input(user *record)
{
	int i;
	for (i = 0; i < NUM; i++)
	{
		printf("input id:");
		scanf("%s", &record[i].id);

		printf("input name:");
		scanf("%s", &record[i].name);
		
		printf("input telephone number:");
		scanf("%s", &record[i].htel);
		
		printf("input phone number:");
		scanf("%s", &record[i].tel);
		printf("\n");
	}
//	printf("input success!\n");
}

void output(user *record)
{
	int i=0;
	int j;
	FILE* fp;
	fp = fopen("./user.dat", "r");
	
	if (fp == NULL)
	{
		printf("can't open!	read failed!\n");
		exit(-1);
	}
	while(!feof(fp))                     
	{ 
		fscanf(fp,"%s\t%s\t%s\t%s\n",&record[i].id,&record[i].name,&record[i].htel,&record[i].tel);
		i++;
	}              
	j=i;
	for(i=0;i<j;i++)
	{
		printf("%s\t%s\t%s\t%s\n",&record[i].id,&record[i].name,&record[i].htel,&record[i].tel);
	}
	fclose(fp);	
	//	printf("output success!\n");			
}

void save(user *record)
{
	printf("start save......\n");
	
	FILE* fp;
	fp = fopen("./user.dat", "a+");
	printf("fp open......\n");
	if (fp == NULL)
	{
		printf("can't open!	write failed!\n");
		exit(-1);
	}
	int i=0;
	//printf("%d\n",i);
	for(i=0;i<NUM;i++)
	{
				fprintf(fp,"%s\t%s\t%s\t%s\n",&record[i].id,&record[i].name,&record[i].htel,&record[i].tel);
					printf("save %d\n",i);
	}
	
	
	/*while (!feof(fp))//ÕâÀïÓÐ´íÎó 
	{
		fprintf(fp,"%d\t%s\t%s\t%s\n",&record[i].id,&record[i].name,&record[i].htel,&record[i].tel);
		i++;
		printf("%d\n",i);
	}	
	*/
	fclose(fp);
	//printf("save success!\n");
}

void mysort()
{

}

void randdat()
{

}
