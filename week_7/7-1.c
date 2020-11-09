#include "head.h"
static void __attribute__ ((constructor)) before_main()
{
	printf("-----before main-----\n");
}
static void __attribute__ ((destructor)) after_main()
{
	printf("-----after mian-----\n");
}

int main()
{
	printf("-----main function-----\n");
	return 0;
}
