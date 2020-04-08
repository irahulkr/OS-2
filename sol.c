
#include<stdio.h>

void sort();
void calcwt();
void printq();

int burst_time[10],waiting_time[10],pdata[10],priority[10];
int n, average_waiting_time=0;
float avgtat=0;

int main()
{
	int i,j;
	printf("\nShortest Job First Scheduling:\n");
	printf("\nEnter the number of process: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter burst time for process P%d : ",i+1);
		scanf("%d",&burst_time[i]);
		pdata[i] = i;
	}
	sort();
	printf("\nProcess\t\tWaiting time\tTurn around time\tPriority");
	calcwt();
	printf("\n\nOrder of process execution: ");
	printq();
	printf("Average waiting time : %f\nAverage Turn around time : %f\n\n",average_waiting_time/(float)n,avgtat/(float)n);
}
void sort()
{
	int x,y,temp;
	for(x=0;x<n;x++)
	{
		for(y=x;y<n;y++)
		{
			if(burst_time[x]>burst_time[y])
			{
				priority[x]=x;
				temp = burst_time[x];
				burst_time[x] = burst_time[y];
				burst_time[y] = temp;
				temp = pdata[x];
				pdata[x] = pdata[y];
				pdata[y] = temp;
			}
		}
	}
}

void calcwt()
{
	int j=0,z;
	for(z=0;z<n;z++)
	{
		waiting_time[z] = j;
		j = burst_time[z] + j;
		printf("\nP%d\t\t\t%d\t\t%d\t\t\t%d",pdata[z]+1,waiting_time[z],waiting_time[z]+burst_time[z],priority[z]);
		average_waiting_time+=waiting_time[z];
		avgtat+=waiting_time[z]+burst_time[z];
	}
}

void printq()
{
	int p;
	for(p=0;p<n;p++)
	{
		printf("P%d -> ",pdata[p]);
	}
	printf("End\n");
}
