#include "apue.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>

void
daemonize(const char *cmd)
{
	int					i, fd0, fd1, fd2;
	pid_t				pid;
	struct rlimit		rl;
	struct sigaction	sa;

	/*
	 * Clear file creation mask.
	 */
	umask(0);

	/*
	 * Get maximum number of file descriptors.
	 */
	if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
		err_quit("%s: can't get file limit", cmd);

	/*
	 * Become a session leader to lose controlling TTY.
	 */
	if ((pid = fork()) < 0)
		err_quit("%s: can't fork", cmd);
	else if (pid != 0) /* parent */
		{
			pid_t _pgid, _pid;
			_pgid = getpgrp();
			printf("parent, %s(),line=%d, _pgid=%d\n", __func__, __LINE__, _pgid);
			_pid = getpid();
			printf("parent, %s(),line=%d, _pid=%d\n", __func__, __LINE__, _pid);
			exit(0);
		}
	printf("after 1st fork, first child, returned pid of fork=%d\n", pid);
	pid_t _pgid, _pid;
	_pgid = getpgrp();
	printf("%s(),line=%d, _pgid=%d\n", __func__, __LINE__, _pgid);
	_pid = getpid();
	printf("%s(),line=%d, _pid=%d\n", __func__, __LINE__, _pid);
	setsid();
	pid_t sid;
	sid = getsid(0);
	printf("%s(),line=%d, sid=%d\n", __func__, __LINE__, sid);
	/*
	 * Ensure future opens won't allocate controlling TTYs.
	 */
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGHUP, &sa, NULL) < 0)
		err_quit("%s: can't ignore SIGHUP", cmd);
	if ((pid = fork()) < 0)
		err_quit("%s: can't fork", cmd);
	else if (pid != 0) {/* parent */ 
		exit(0);
		
		}

	/*
	 * Change the current working directory to the root so
	 * we won't prevent file systems from being unmounted.
	 */
	if (chdir("/") < 0)
		err_quit("%s: can't change directory to /", cmd);

	/*
	 * Close all open file descriptors.
	 */
	if (rl.rlim_max == RLIM_INFINITY)
		rl.rlim_max = 1024;
	for (i = 0; i < rl.rlim_max; i++)
		close(i);

	/*
	 * Attach file descriptors 0, 1, and 2 to /dev/null.
	 */
	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);

	/*
	 * Initialize the log file.
	 */
	openlog(cmd, LOG_CONS, LOG_DAEMON);
	if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
		syslog(LOG_ERR, "unexpected file descriptors %d %d %d",
		  fd0, fd1, fd2);
		exit(1);
	}
}
int main(int argc, char **argv)
{
	pid_t pgid, pid;
	pgid = getpgrp();
	printf("%s(),line=%d, pgid=%d\n", __func__, __LINE__, pgid);
	pid = getpid();
	printf("%s(),line=%d, pid=%d\n", __func__, __LINE__, pid);
	daemonize("ls");
	sleep(1);
	return 0;
}
