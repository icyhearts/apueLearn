#include<stdio.h>
#include<stdio.h>
#include<errno.h>
#include<sys/wait.h>
#include<unistd.h>
int system(const char *cmdstring);
void pre_exit(int status);
int main()
{
	int status;
	if( (status=system("date")) < 0)printf("system() error\n");
	pre_exit(status);

	if((status=system("nosuchcommand")) < 0)printf("system() error\n");
	pre_exit(status);

	if((status=system("who;exit 44")) < 0)printf("system() error\n");
	pre_exit(status);
	return 0;
}
int system(const char *cmdstring)
{
	pid_t pid;
	int status;
	if(cmdstring == NULL) return 1; // always a command processor with UNIX
	if( (pid=fork() )<0) status=-1;
	else if(pid==0){ // child
		execl("/bin/bash","sh","-c",cmdstring,(char *)0);
		_exit(127); // execl error
	}
	else{ // parent
		while(waitpid(pid,&status,0)<0){
			if(errno!=EINTR){
				status=-1; // error other than EINTR from waitpid()
				break;
			}
		}
	}
	return status;
}
void pre_exit(int status)
{
	if(WIFEXITED(status))
		printf("normal termination, exit status=%d\n",WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("abnormal termination, signal number=%d%s\n",WTERMSIG(status),
#ifdef WCOREDUMP
	WCOREDUMP(status) ? "core file generated" : "");
#else
	"");
#endif
	else if(WIFSTOPPED(status))
		printf("child stopped, signal number=%d\n",WSTOPSIG(status));

}
