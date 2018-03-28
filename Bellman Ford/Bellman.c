#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
	int i , j , n , z=0,v , ch=-1 , src , des , len , flag=0;
	printf("\nShortest Path using Bellman Ford Algorithm \n\n");
	
	// Accepting number of vertices
	do
	{

	printf("\n Enter number of vertices");
	scanf("%d",&v);	

	if(v>=3)
	{
		break;
	}

	printf("\n Error : Invalid number of vertices ");
	}while(v<3);

	int * distance = (int*)malloc ((v) * sizeof(int));


	//Initializing the dynamic array distance

	for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			distance[i]=INT_MAX;
		}


	// Accepting the number of edges

	do
	{
	printf("\n Enter the number of edges");
	scanf("%d",&n);

	if(n>=(v-1) || n<=(v*(v-1))/2)
	{
		break;
	}
	printf("\n Error : Invalid number of edges");

	}while(n<(v-1) || n>(v*(v-1))/2);


	// Initializing dynamic array edges	
	
	int * edges = (int*)malloc(n*3 * sizeof(int));


	// Accepting the edges in the graph
	
	for(i=0;i<n;i++)
	{
		flag =0;
		printf("\n Enter vertex1 , vertex2 , edge length\n");
		scanf("%d%d%d",&src,&des,&len);
		src--;
		des--;
		for(j=0;j<i;j++)
		{
			if(src== *(edges+i*3+j) && des == *(edges + j*3 +1))
			{
				printf("\n Edge already exists : Enter again");
				i--;
				flag=1;
				break;
			}
		}

		if(flag==0)
		{
			

			if(src>=0 && src <v && des>=0 && des<v)
				{
						*(edges + i*3 +0)=src;
						*(edges + i*3 +1)=des;
						*(edges + i*3 +2)=len;		
				}

			else
				{
					printf("\n Entered vertex does not exist : Enter again");
					i--;
				}
		}
	}

	// Accepting the source vertex

	do
	{
	printf("\n Enter source vertex");
	scanf("%d",&ch);
	ch--;

	if(!(ch<0 && ch>=v))
	{
		break;
	}

	printf("\n Error : Source vertex does not exit ");
	}while(ch <0 && ch >=v);
	

	distance[ch]=0;

	
	//Bellman Ford Algorithm

	while(z!=(v-1))
	{
		flag=0;
		for(i=0;i<n;i++)
		{
			if(distance[*(edges+i*3+0)]!=INT_MAX && (distance[*(edges+i*3+0)] + *(edges+i*3+2)) < distance[*(edges+i*3+1)])
			{ 
				distance[*(edges+i*3+1)]=distance[*(edges+i*3+0)] + *(edges+i*3+2);
				flag=1;				
			}
		}

		if(flag==0)
		{
			break;
		}
		z++;
	}

	//Checking for negative cycle in the graph

	if(z!=v)
	{	for(i=0;i<n;i++)
			{
				if(distance[*(edges+i*3+0)]!=INT_MAX && (distance[*(edges+i*3+0)] + *(edges+i*3+2) < distance[*(edges+i*3+1)]))
				{ 
					printf("\n Negative cycle exists in graph , solution cannot be found");
					return 0;
				}
			}
	}


	//Prining Solution

	printf("\n\n--------------------------------------------------------------------\n\n");
	for(i=0;i<v;i++)
		{
			if(distance[i]==INT_MAX)
				printf("\n Distance of Node %d from source is infinity \n",i);
			else	
				printf("\n Distance of Node %d from source = %d units\n",i,distance[i]);
		}

	printf("\n Solution was found in %d outer loop iterations\n",z+1);


	// Freeing Dynamically Allocated memory	

	free(distance);
	distance=NULL;
	free(edges);
	edges=NULL;

	return 0;
}
