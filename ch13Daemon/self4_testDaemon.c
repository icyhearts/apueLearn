#include "apue.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>
void hupHandler(int signo)
{

	printf("in hupHandler\n");
}
void
daemonize(const char *cmd)
{
	int					i, fd0, fd1, fd2;
	pid_t				pid;
	pid_t _pid, _ppid, _pgid, _sid;
	struct rlimit		rl;
	struct sigaction	sa;

	if ((pid = fork()) < 0)
		err_quit("%s: can't fork", cmd);
	else if (pid != 0) /* parent */
		{
			_pid = getpid();
			_ppid = getppid();
			_pgid = getpgrp();
			_sid = getsid(0);
			printf("after 1st fork, parent, func=%s(),line=%d,_pid=%d, _ppid=%d, _pgid=%d, _sid=%d\n", 
								__func__,__LINE__,_pid,    _ppid,     _pgid,    _sid);
			exit(0);
		}
	printf("after 1st fork, child, returned pid of fork=%d\n", pid);
	_pid = getpid();
	_ppid = getppid();
	_pgid = getpgrp();
	_sid = getsid(0);
	printf("after 1st fork, child, func=%s(),line=%d,_pid=%d, _ppid=%d, _pgid=%d, _sid=%d\n", 
						__func__,__LINE__,_pid,    _ppid,     _pgid,    _sid);
	setsid();
						/*
	_pid = getpid();
	_ppid = getppid();
	_pgid = getpgrp();
	_sid = getsid(0);
	printf("after 1st fork, child, after setsid, func=%s(),line=%d,_pid=%d, _ppid=%d, _pgid=%d, _sid=%d\n", 
						__func__,__LINE__,_pid,    _ppid,     _pgid,    _sid);
						*/
}
int main(int argc, char **argv)
{
	pid_t pgid, pid;
	pgid = getpgrp();
	printf("%s(),line=%d, pgid=%d\n", __func__, __LINE__, pgid);
	pid = getpid();
	printf("%s(),line=%d, pid=%d\n", __func__, __LINE__, pid);
	daemonize("ls");
	sleep(600);
	return 0;
}
