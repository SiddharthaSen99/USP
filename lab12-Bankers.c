#include<stdio.h>

int test(int finish[10], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if (finish[i]==0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int max[10][10], need[10][19], allocation[10][10], finish[10], res[10], avail[10], work[10],i,j,n,m,k=0, safe[10];
	
//getting data	
	
	printf("Enter the number of process\n");
	scanf("%d",&n);
	printf("Enter the number of resources\n");
	scanf("%d",&m);
	printf("Enter the max matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the allocation matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("Enter the number of instances of each resource currently available\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}
	printf("Enter the maximum number of instances of each resource\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&res[i]);
	}
	
//need matrix

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	
	printf("The need matrix is :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}


//initialisation
	
	for(i=0;i<m;i++)
	{
		work[i]=avail[i];
	}
	for(i=0;i<n;i++)
		finish[i]=0;
	int c=1;
	int num;
	
//algorithm
	
	while(c)
	{
		c=1;
		for(i=0;i<n;i++)
		{
			num=0;
			for(j=0;j<m;j++)
			{
				if (need[i][j] <= work[j] && finish[i]==0)
					num++;
			}

			if(num==m)
			{
				finish[i]=1;
				safe[k++]=i;
				for(j=0;j<m;j++)
					work[j]+=allocation[i][j];
			}

			for(j=0;j<m;j++)
			{
				if( work[j]>res[j])
				{
					c=0;
					break;
				}
			}

			if (c==0 || !test(finish,m))
			{
				break;
			}			
		}
		if (c==0 || !test(finish,m))
		{
			break;
		}
	}
	num=0;			
	for(i=0;i<n;i++)
	{
		if (finish[i]==1)
			num++;
	}	
	if (num==n)
	{
		printf("safe state reached\n");
		for(i=0;i<n;i++)
			printf("%d ",safe[i]);	
		printf("\n");		
	}
	else
		printf("no safe state\n");
	return 0;
}
