							

#include<stdio.h>

struct process
{
	int time ;
	int pid;

};

void Merge(struct process p[] , int l , int mid , int r)
{
	int i,j,temp,k;
	int lsize = mid - l +1;
	int rsize = r - mid;


	struct process L[lsize] ,R[rsize];

	temp = l;
	for (i = 0; i < lsize; i++ , temp++)
	{
		L[i].time = p[temp].time;
		L[i].pid = p[temp].pid;
	}
	
	temp = mid +1;
    	for (i = 0; i < rsize; i++,temp++)
	{
			R[i].time = p[temp].time;
			R[i].pid = p[temp].pid;
	}

    i=0,j=0;k=l;

    do
    {
    	if(L[i].time < R[j].time)
    	{
    			p[k].time=L[i].time;
			p[k++].pid=L[i++].pid;
    	}
    	else if(R[j].time <= L[i].time)
    	{
    			p[k].time=R[j].time;
			p[k++].pid=R[j++].pid;
    	}
    }while(i<lsize && j<rsize);

    while(i<lsize)
    {
    	p[k].time=L[i].time;
	p[k++].pid=L[i++].pid;
    }

    while(j<rsize)
    {
    	p[k].time=R[j].time;
	p[k++].pid=R[j++].pid;
    }

}

void MSort(struct process p[],int l , int r)
{
	if(l<r)
	{
		int mid = (l+r )/2;

		MSort(p,l,mid);
		MSort(p,mid+1,r);

		Merge(p,l,mid,r);
	}
}


int main()
{
	int n, i;
	
	int sum_of_running_time=0 , sum_of_retreival_time=0 ;

	printf("\n Enter the number of processes");
	scanf("%d",&n);
	
	struct process p[n];
	int ar[n];

	printf("\n Enter information about processes");
	for(i=0;i<n;i++)
	{
		printf("\n Enter process id , process length ");
		scanf("%d",&p[i].pid);
		scanf("%d",&p[i].time);
		
		printf("\n Process Entered \n");
		printf("\tID:	%d",p[i].pid);
		printf("\tLength	%d\n",p[i].time);
		
	}

	MSort(p,0,n-1);

	printf("\n\n\nProcessID	Process Running Time	Process Retreival Time");
	for(i=0;i<n;i++)
	{	
		sum_of_running_time+=p[i].time;
		sum_of_retreival_time+=sum_of_running_time;

		printf("\n%d	\t\t%d	\t\t%d",p[i].pid,p[i].time,(int)sum_of_running_time);
		
	}

	printf("\n\nBest Average Retreival Time = %f\n",(float)sum_of_retreival_time/n);
	
}
