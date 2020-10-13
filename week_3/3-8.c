#include "3-1.h"

int main()
{
	FILE *fp;
	fp=fdopen(1,"w+");
	fprintf(fp,"test data %s\n"," hello world!");
	return 0;
}
