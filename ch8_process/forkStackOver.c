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
#define SIZE 5
int num[SIZE]={0,1,2,3,4};
int main()
{
	int i;
	pid_t pid=fork();
	if(pid==0){
		for(i=0;i<SIZE;i++){
			printf("child:%d \n",num[i]);
		}
	}
	else if(pid>0){
		wait(NULL);
		for(i=0;i<SIZE;i++){
			printf("parent:%d\n",num[i]);
		}
	}
}
