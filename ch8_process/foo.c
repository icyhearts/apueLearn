#include<stdio.h>
void foo(int *p);
int main()
{
int a;
a=3;
printf("a=%d\n",a);
foo(&a);
printf("a=%d\n",a);
}
void foo(int *p)
{
*p=(*p)*2;
}
