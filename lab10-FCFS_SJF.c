#include<stdio.h>

int main()
{
	int i,j,temp,n,b[10],totw=0,tott=0,wt[10],tat[10];
	float avgwt, avgtat;
	printf("FCFS scheduling\n");
	printf("Enter the number of processes \n");
	scanf("%d",&n);
	printf("Enter the burst time of %d processes\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++)
	{
		if (i==0)
		{
			wt[0]=0;
			tat[0]=b[0];
			continue;
		}
		else
		{
			wt[i]=b[i-1]+wt[i-1];
			tat[i]=wt[i]+b[i];
			totw+=wt[i];
			tott+=tat[i];
		}
	}
	avgwt=(float)totw/n;
	avgtat=(float)tott/n;
	printf("In FCFS \naverage waiting time is %f \naverage turnaround time is %f\n",avgwt,avgtat);
	
	printf("SJF scheduling\n");
	totw=0;
	tott=0;
	for(i=0;i<n;i++)
	{
	
		for(j=0;j<n-i-1;j++)
		{
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if (i==0)
		{
			wt[0]=0;
			continue;
		}
		wt[i]=b[i-1]+wt[i-1];
		tat[i]=wt[i]+b[i];
		totw+=wt[i];
		tott+=tat[i];
	}
	avgwt=(float)totw/n;
	avgtat=(float)tott/n;
	printf("In SJF \naverage waiting time is %f \naverage turnaround time is %f\n",avgwt,avgtat);
	return 0;	
	
}
