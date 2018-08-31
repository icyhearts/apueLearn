#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
/*
Sat Oct  8 13:19:40 CST 2016
*/
int main(){
	pid_t pid;
	pid=fork();
	if( pid==0)
	{
		printf("child pid=%d\n",getpid());
		printf(" child hello\n");
//		if(execl("/bin/ls","ls","/tmp","-l","-t",NULL)<0)
		if(execl("/bin/ls","ls","/tmp","-lt",NULL)<0)
			printf("execl error\n");
	}
	else{// parent, waitpid call is very important
		if(waitpid(pid,NULL,0)<0)printf("wait error\n");
	}
	return 0;
}
