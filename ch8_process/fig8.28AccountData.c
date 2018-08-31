#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	if((pid=fork()) < 0)printf("fork error\n");
	else if(pid!=0){ // parent
			printf("parent\n");
			sleep(2);
			exit(2);
	}

	if( (pid=fork()) < 0)printf("fork error\n"); // first child
	else if (pid!=0){
		printf("first child\n");
		sleep(4);
		abort();
	}
	if( (pid=fork()) < 0)printf("fork error\n"); // second child
	else if(pid!=0){
		printf("second child\n");
		execl("/bin/dd","dd","if=/tmp/tmp.txt","of=/dev/null",NULL);
		exit(7);
	}

	if( (pid=fork()) < 0)printf("fork error\n"); // third child
	else if(pid!=0){
		sleep(8);
		exit(0);
	}

	sleep(6);
	kill(getpid(),SIGKILL);
	exit(6);
}

