#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<limits.h>
static void pr_sysconf(char *,int);
static void pr_pathconf(char *,char *,int);
int main(int argc,char *argv[])
{
	if(argc!=2)
			printf("useage: ");
#ifdef ARG_MAX
	printf("ARG_MAX defined to be %d\n",ARG_MAX);
#else
	printf("no symbol for ARG_MAX\n");
#endif

#ifdef _SC_ARG_MAX
	pr_sysconf("ARG_MAX =",_SC_ARG_MAX);
#else
	printf("no symbol for _SC_ARG_MAX\n");
#endif
	return 0;
}
static void pr_sysconf(char * mesg,int name)
{
long val;
	fputs(mesg,stdout);
	errno=0;
	if( (val=sysconf(name))<0)
	{
		if(errno!=0)
		{
			if(errno==EINVAL)
					fputs(" (not supported)\n",stdout);
			else
					printf("sysconf error\n");
		}
		else
		{
		fputs(" (no limit) \n",stdout);
		}
	}
	else
	{
			printf("%ld\n",val);
	}
}
