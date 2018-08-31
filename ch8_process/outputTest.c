#include<stdio.h>
int main()
{
	char buf[BUFSIZ];
	setbuf(stdout,buf);
	puts("this is toturialspoint");
	//printf("%d\n",BUFSIZ);
	fflush(stdout);
	FILE *fp;
	int ch;
	fp=fopen("file.txt","w");
	for(ch='a';ch<='z';ch++){
		putc(ch,fp);
	}
	fclose(fp);
	return 0;
}
