#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
#include<errno.h>
void waitprocess();
int main()
{
	waitprocess();
return 0;
}
void waitprocess()
{
	int count=0;
	pid_t pid=fork();
	int status=-1;
	int value;
	if(pid<0)
	//printf("fork error for %m\n",errno);
	printf("fork error \n");
	else if(pid>0)
	{
		printf("this is parent, pid=%d\n",getpid());
		value=wait(&status); //父进程执行到此，马上阻塞自己，直到有子进程结束。当发现有子进程结束时，就会回收它的资源。
		printf("return of wait=%d\n",value);
		printf("status=%d\n",status);

	}
	else 
	{
		printf("this is child, pid=%d, ppid=%d\n",getpid(),getppid());
		int i;
		for(i=0;i<1;i++)
		{
			count++;
			sleep(1);
			printf("count=%d\n",count);
		}
		exit(6);
	}
	printf("end of program from pid=%d\n",getpid());
	printf("child exit status is %d\n",WEXITSTATUS(status));//status是按位存储的状态信息，需要调用相应的宏来还原一下

}
