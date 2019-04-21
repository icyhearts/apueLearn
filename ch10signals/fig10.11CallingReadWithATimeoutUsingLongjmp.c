#include<myapue.h>
#include<setjmp.h>
static void sig_alrm(int signo);
static jmp_buf env_alrm;
int main()
{
	int n;
	char line[MAXLINE];
	if(signal(SIGALRM,sig_alrm) == SIG_ERR)perror("signal(SIGALRM) error");
	if(setjmp(env_alrm) != 0){
		printf("read timeout\n");
//		exit(0);
	}
	
//		perror("read timeout");
	alarm(1);
	if( (n = read(STDIN_FILENO, line, MAXLINE)) < 0)
		perror("read error");
	alarm(0);
	write(STDOUT_FILENO,line,n);
	exit(0);

}
static void sig_alrm(int signo)
{
	longjmp(env_alrm,1);
}
