#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
char *env_init[]={"USER=unknown","PATH=tmp",NULL};
int main()
{
	pid_t pid;
	// first child
	if((pid=fork())<0){
		printf("fork error\n");
	} else if (pid == 0){ // child of main()
		if(execle("/bin/echo","echo","child1Arg","MY ARG2", (char*)0,env_init ) <0 ){
			printf("execle error\n");
		}
	}
	if ( waitpid(pid,NULL,0)<0){
		printf("wait error\n");
	}
	//@2
	if( (pid=fork()) <0 ){
		printf("fork error");
	}
	else if(pid==0){
		if(execlp("echo","echo","child2Arg",NULL)<0 ){
			printf("execlp error\n");
		}
	}
	if ( waitpid(pid,NULL,0)<0){
		printf("wait error\n");
	}
return 0;
}
