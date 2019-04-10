#include<stdio.h>

int mutex,empty, full;

int wait(int s)
{
	s--;
	return s;
}

int signal(int s)
{
	s++;
	return s;
}

int producer(x)
{
	mutex=wait(mutex);
	empty=wait(empty);
	full=signal(full);
	printf("Producer produced item %d and full = %d\n", x,full);
	x++;
	mutex=signal(mutex);
	return x;
}

int consumer(y)
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("Consumer consumed item %d\n",y);
	y++;
	mutex=signal(mutex);
	return y;
}

int main()
{
	int ch,x=1,y=1;
	mutex=1, full=0, empty=5;
	while(1)
	{
	printf("Enter 1:Producer 2:Consumer 3:Exit\n");
	scanf("%d",&ch);
	
		switch(ch)
		{
			case 1: if(mutex==1 && full!=5)
						x=producer(x);
					else
						printf("Buffer is full\n");
					break;
			case 2: if(mutex==1 && empty!=5)
						y=consumer(y);
					else
						printf("Buffer is empty\n");
					break;
			default: return 0;	
		}
	}
	return 0;
}
