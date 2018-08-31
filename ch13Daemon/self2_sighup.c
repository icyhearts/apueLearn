#include "apue.h"
#include<strings.h>
#include <pthread.h>
#include <syslog.h>
void sighupHandler(int signo)
{
	pid_t pid;
	pid = getpid();
	printf("hangup, signo=%d\n", signo);
	syslog(LOG_ERR, "hangup, signo=%d, pid=%d", signo, pid);
	return ;
}
void sigintHandler(int signo)
{
	pid_t pid;
	pid = getpid();
	printf("interrupt, signo=%d\n", signo);
	syslog(LOG_ERR, "interrupt, signo=%d, pid=%d", signo, pid);
	return ;
}
int
main(int argc, char *argv[])
{
	struct sigaction	sa;
	sa.sa_handler = &sighupHandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGHUP, &sa, NULL) < 0)
		err_quit("%s: can't restore SIGHUP default");

	memset(&sa,0, sizeof(sa));
	sa.sa_handler = &sigintHandler;
//	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) < 0)
		err_quit("%s: can't restore SIGHUP default");
	openlog(argv[0], LOG_CONS, LOG_DAEMON);
	while(1);
	exit(0);
}
