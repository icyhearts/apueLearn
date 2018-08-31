#include<stdio.h>
#include<unistd.h> // for fork() getpid
#include<stdlib.h>
#include<likeapue.h>
int glob=6;
int main()
{
	int var;
	pid_t pid;
	var=88;
	//if(write(1,buf,sizeof(buf)-1)!=(sizeof(buf)-1))
	//printf("write error");

	printf("before vfork\n");
	if((pid=vfork())<0)
	{
	printf("vfork error\n");
	}
	else if(pid==0)
	{
	glob++;
	var++;
	printf("this is child, my pid=%d\n",getpid());
	_exit(0); // _exit != exit _exit will not flush I/O
	//exit(0);
	}
	printf("pid=%d,glob=%d,var=%d\n",getpid(),glob,var);
	exit(0);
}
