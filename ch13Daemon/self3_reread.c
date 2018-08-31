#include "apue.h"
#include <pthread.h>
#include <syslog.h>

sigset_t	mask;

extern int already_running(char*);

void
reread(void)
{
	/* ... */
}

void *
thr_fn(void *arg)
{
	int err, signo;

	for (;;) {
		err = sigwait(&mask, &signo);
		if (err != 0) {
			syslog(LOG_ERR, "sigwait failed");
			exit(1);
		}

		switch (signo) {
		case SIGHUP:
			syslog(LOG_INFO, "Re-reading configuration file");
			reread();
			break;

		case SIGTERM:
			syslog(LOG_INFO, "got SIGTERM; exiting");
			exit(0);

		default:
			syslog(LOG_INFO, "unexpected signal %d\n", signo);
		}
	}
	return(0);
}

void sighupHandler(int signo)
{
	pid_t pid;
	pid = getpid();
	printf("hangup, signo=%d\n", signo);
	syslog(LOG_ERR, "hangup, signo=%d, pid=%d", signo, pid);
	return ;
}
int
main(int argc, char *argv[])
{
	int					err;
	pthread_t			tid;
	char				*cmd;
	char LOCKFILE[200];
	struct sigaction	sa;

	if ((cmd = strrchr(argv[0], '/')) == NULL)
		cmd = argv[0];
	else
		cmd++;

	sprintf(LOCKFILE, "/tmp/%s.pid", cmd);
	/*
	 * Become a daemon.
	 */
	daemonize(cmd);

	/*
	 * Make sure only one copy of the daemon is running.
	 */
	if (already_running(LOCKFILE)) {
		syslog(LOG_ERR, "daemon already running");
		exit(1);
	}

	/*
	 * Restore SIGHUP default and block all signals.
	 */
//	sa.sa_handler = SIG_DFL;
//	sa.sa_handler = &sighupHandler;
//	sigemptyset(&sa.sa_mask);
//	sa.sa_flags = 0;
//	if (sigaction(SIGHUP, &sa, NULL) < 0)
//		err_quit("%s: can't restore SIGHUP default");
	sigfillset(&mask);
	if ((err = pthread_sigmask(SIG_BLOCK, &mask, NULL)) != 0)
		err_exit(err, "SIG_BLOCK error");

	/*
	 * Create a thread to handle SIGHUP and SIGTERM.
	 */
	err = pthread_create(&tid, NULL, thr_fn, 0);
	if (err != 0)
		err_exit(err, "can't create thread");
	while(1);
	/*
	 * Proceed with the rest of the daemon.
	 */
	/* ... */
	exit(0);
}
