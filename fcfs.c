#include<stdio.h>
#include<stdlib.h>

struct process
{
	int pid, at, bt, ct, wt, tat, rt, idle;
};

int compare(const void *p , const void *q)
{
	struct process* ps0 = (struct process*) p;
	struct process* ps1 = (struct process*) q;
	if(ps0->at >= ps1->at)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int n;
	printf("Enter number of Processes: ");
	scanf("%d",&n);
	struct process p[n];
	
	int sum_tat = 0;
	int sum_wt = 0;
	int sum_rt = 0;
	int sum_it = 0;
	
	for(int i = 0; i < n; i++)
	{
		p[i].pid = i+1;
		printf("Enter ariival time and burst time for process P%d: ",i+1);
		scanf("%d%d", &p[i].at, &p[i].bt);
	}
	
	qsort(p ,n ,sizeof(struct process), compare);
	
	p[0].ct = p[0].at + p[0].bt;
	p[0].tat = p[0].ct - p[0].at;
	p[0].wt = p[0].tat - p[0].bt;
	p[0].rt = (p[0].ct - p[0].bt) - p[0].at;
	sum_tat += p[0].tat;
	sum_wt += p[0].wt;
	sum_rt += p[0].rt;
	
	for(int i = 1; i < n; i++)
	{
		if(p[i].at >= p[i-1].ct)
		{
			p[i].ct = p[i].at + p[i].bt;
		}
		else
		{
			p[i].ct = p[i-1].ct + p[i].bt;
		}
		
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
		p[i].rt = (p[i].ct - p[i].bt) - p[i].at;
		sum_tat += p[i].tat;
		sum_wt += p[i].wt;
		sum_rt += p[i].rt;
		
		if(p[i].at > p[i-1].ct)
		{
			p[i].idle = p[i].at - p[i-1].ct;
			sum_it += p[i].idle;
		}
		else
		{
			p[i].idle = 0;
		}
	}
	
	
	
	printf("Pn\tAT\tBT\tCT\tWT\tTAT\tRT\tIT\n");
	
	for(int i = 0; i < n; i++)
	{
		printf("%d",p[i].pid);
		printf("\t%d",p[i].at);
		printf("\t%d",p[i].bt);
		printf("\t%d",p[i].ct);
		printf("\t%d",p[i].wt);
		printf("\t%d",p[i].tat);
		printf("\t%d",p[i].rt);
		printf("\t%d\n",p[i].idle);
	}
	float s = (float)sum_wt / (float)n;
	float t = (float)sum_tat / (float)n;
	float r = (float)sum_rt / (float)n;
	float l = p[n-1].ct - p[0].at;
	float util = ((l - sum_it)/l) * 100;
	float tp = (float)n * l;
	
	printf("Average waiting time: %f",s);
	printf("\n");
	printf("Average turn around time: %f\n",t);
	printf("Average response time: %f\n",r);
	printf("Length Cycle: %f\n",l);
	printf("CPU Utilization(in percentage): %f\n",util);
	printf("ThroughPut: %f\n\n",tp);
	
	return 0;
}
