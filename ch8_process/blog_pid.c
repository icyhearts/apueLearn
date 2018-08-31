#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
pid_t pid1;
pid_t pid2;
pid1=fork();
pid2=fork();
	printf("pid1:%d,pid2:%d\n",pid1,pid2);
	//sleep(1);
	exit(0);
}
