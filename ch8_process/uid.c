#include<stdio.h>
#define MYFLAG -1
int main()
{
#if _POSIX_SAVED_IDS
	printf("set");
#endif
#if MYFLAG
printf("myflag");
#endif
return 0;
}
