#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_handler(int signum)
{
	printf("The error caught is SIGFPE and the signal number for that is %d\n",signum);
	abort();
}

int main()
{
	int i;
	signal(SIGFPE,sig_handler);
	printf("Enter the numerator\n");	
	scanf("%d",&i);
	i=i/0;
	printf("This line shouldn't be executed\n");
	return 0;
}
