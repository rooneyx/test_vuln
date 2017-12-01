#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "test.h"
#ifdef MM_USE_STUBS
	return calloc(1, 100);
#endif

int bar(char *arg, char *out)
{
	char* buf2 = arg;  
	//@ slice pragma stmt;
	strcpy(out, buf2);
	test();
	return 0;
}

int foo(char *arg)
{
	char buf1[400]="There is always a text, a vulnerable text!\n";
	char buf2[200];
	bar(arg, buf2);
	printf("%s",buf1);
	return 0;
}

int main(int argc, char *argv[])
{
	//@ slice pragma stmt;
	if (argc != 2)
	{
		//@ slice pragma stmt;
		exit(EXIT_FAILURE);
	}
	foo(argv[1]);
	return 0;
}
