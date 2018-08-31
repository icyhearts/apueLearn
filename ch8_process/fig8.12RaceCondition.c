#include"apue.h"
static void charatatime(char *str);
int main()
{
	pid_t pid;
	if( (pid=fork() ) < 0 ){
		perror("fork error");
	}else if(pid == 0){
		charatatime("output from child\n");
	}else{
	charatatime("output from parent\n");
	}
}
static void charatatime(char *str)
{

	 char *ptr;
	 int c;
	 setbuf(stdout, NULL); // set unbuffered. The setbuf() function is exactly equivalent to the call:
//setvbuf(stream, buf, buf ? _IOFBF : _IONBF, BUFSIZ);
	for(ptr=str; (c=*ptr++) != 0; )
		putc(c,stdout);
}
