#include<stdio.h>
#include<stdlib.h>
#include"fig8.5GetExit.h"
#include"fig8.22ApueSystem.h"
int main(int argc,char *argv[])
{
	int status;
	if(argc<2)printf("command-line argument required\n");

	if( (status=system(argv[1])) < 0)
		printf("system() error\n");
	
	pre_exit(status);
	exit(0);
}
