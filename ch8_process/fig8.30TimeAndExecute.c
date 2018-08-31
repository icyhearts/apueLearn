#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/times.h>
#define MYFLAG
static void pr_time(clock_t real,struct tms *tmsstart, struct tms *tmsend);
static void do_cmd(char *cmd);
void pre_exit(int status);
int main(int argc, char *argv[])
{
	int i;
	setbuf(stdout,NULL);
	for(i=1; i<argc; i++){
		do_cmd(argv[i]);
	}
	exit(0);
return 0;
}
static void do_cmd(char *cmd)
{
	struct tms tmsstart,tmsend;
	clock_t start,end;
	int status;
	printf("\ncommand: %s\n",cmd);
	if( (start=times(&tmsstart)) == -1)printf("times error");
	if( (status=system(cmd)) == -1)printf("system() error");
	if( (end=times(&tmsend)) == -1)printf("times error");
	pr_time(end-start,&tmsstart,&tmsend);
	pre_exit(status);
}
static void pr_time(clock_t real,struct tms *tmsstart, struct tms *tmsend)
{
	static long clktck=0;
	if(clktck == 0)
		if((clktck=sysconf(_SC_CLK_TCK)) < 0)printf("sysconf error");
#ifdef MYFLAG
	printf("clktck=%lf\n",(double)clktck);
#endif
	printf("real: %7.2f\n",real/(double)clktck);
	printf("user: %7.2f\n",
		(tmsend->tms_utime - tmsstart->tms_utime)/(double)clktck);
	printf("sys: %7.2f\n",
		(tmsend->tms_stime - tmsstart->tms_stime)/(double)clktck);
	printf("child user: %7.2f\n",
		(tmsend->tms_cutime - tmsstart->tms_cutime)/(double)clktck);
	printf("child sys: %7.2f\n",
		(tmsend->tms_cstime - tmsstart->tms_cstime)/(double)clktck);


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
