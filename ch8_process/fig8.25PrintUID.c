#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	printf("real uid=%d,effective uid=%d\n",getuid(),geteuid());
	exit(0);
}
