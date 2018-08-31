#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	if(pid=fork() < 0){
		printf("error\n");
	}
	else if(pid==0){
		if( execl("/bin/ls","ls","/tmp",NULL)<0){
			printf("execl error");
		}
	}
	if(waitpid(pid,NULL,0) < 0 ){
		printf("waitpid error");
	}
	exit(0);
//return 0;
}
