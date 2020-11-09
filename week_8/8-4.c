#include "./ch08.h"

static void func1(void);
static void func2(void);
static jmp_buf g_stack_env;

int main()
{
	if(setjmp(g_stack_env)==0)
	{
		printf("main normal flow!\n");
		func1();
	        printf("normal flow back from long jmp!\n");
	}
	else
	{
		printf("back from long jmp!\n");
	}
	return 0;
}

static void func1(void)
{
	printf("enter func1!\n");
	func2();
	printf("leave func1!\n");
}

static void func2(void)
{
	printf("enter func2!\n");
//	longjmp(g_stack_env,1);
	printf("leave func2!\n");
}
