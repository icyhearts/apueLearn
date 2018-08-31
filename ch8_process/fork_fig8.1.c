#include<stdio.h>
#include<unistd.h> // for fork() getpid
#include<stdlib.h>
#include<likeapue.h>
int glob=6;
char buf[]="a write to stdout\n";
int main()
{
	int var;
	pid_t pid;
	var=88;
	//if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=(sizeof(buf)-1))
	//if(write(STDOUT,buf,sizeof(buf)-1)!=(sizeof(buf)-1))
	if(write(1,buf,sizeof(buf)-1)!=(sizeof(buf)-1))
	printf("write error");

	printf("before fork\n");
	//pid=fork();
	//if(pid<0)
	if((pid=fork())<0)
	{
	printf("fork error\n");
	}
	else if(pid==0)
	{
	glob++;
	var++;
	printf("this is child, my pid=%d\n",getpid());
	}
	else
	{
	printf("this is parent,my pid=%d\n",getpid());
	sleep(1);
	}
	printf("pid=%d,glob=%d,var=%d\n",getpid(),glob,var);
	exit(0);
}
