#include "../ch08.h"
//test error
extern void dynamic_lib_fun_call(void);

int main(void)
{
	dynamic_lib_fun_call();
	return 0;
}
