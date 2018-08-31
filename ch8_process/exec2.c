#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){ 			
	int ret;
	char *envp[]={"PATH=/tmp","USER=wang",NULL};
	if(fork()==0)
	{
		printf("child pid=%d\n",getpid());
		if(execle("/usr/bin/env","env",NULL,envp)<0)
			printf("execlp error\n");
		
	}
}
