#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	printf("before calling fork,calling process pid=%d\n",getpid());
	pid=fork();
	if(pid==-1)
		printf("fork error\n");
	if(pid==0)
		printf("this is child process and child's pid=%d,parent's pid=%d\n",getpid(),getppid());
	if(pid>0)
	{
	 sleep(1e-3);
	printf("this is parent process and pid=%d,child's pid=%d\n",getpid(),pid);
	}
	exit(0);
}
