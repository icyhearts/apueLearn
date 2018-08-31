/*
when:
Sun Sep 11 23:00:11 CST 2016
where:
https://en.wikipedia.org/wiki/Fork_(system_call)
what: simple test for fork()
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	pid_t pid=fork();
	if(pid==-1){
		printf("fork error");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0){
		printf("this is child\n");
		_exit(EXIT_SUCCESS);
	}
	else{
		int status;
		waitpid(pid,&status,0);
	}

	return EXIT_SUCCESS;
}
