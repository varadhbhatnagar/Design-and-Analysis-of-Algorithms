#include<stdio.h>
#include<stdlib.h>

int glo=0;
void print(int sol[], int n)
{
    int i, j;

    printf("\n\n-----------------------------------------------------------------------------\n\n");
    for(j=0; j<2*n + 1; j++)
        printf("-");
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("|");
        for(j=0; j<n; j++)
        {
            if(sol[i]==j)
                printf("Q|");
            else
                printf(" |");
        }
        printf("\n");
        for(j=0; j<2*n + 1; j++)
            printf("-");
        printf("\n");
    }
    printf("\n");
}

int place(int solution[] ,int current )
{
    int i;

    for(i=0;i<current;i++)
    {
        if((solution[i]==solution[current]) || ((i + solution[i]) == (current + solution[current]) || ((i-solution[i])==(current-solution[current]))))
           {
               return 0;
           }

    }

    return 1;

}

int nqitertive( int n , int ch )
{
    int i, current=0;
    int *solution = malloc (n * sizeof(int));
    for(i=0;i<n;i++)
    	solution[i]=-1;
    
    int ct=0;

    while(current!=-1)
    {
        solution[current] = solution[current]+1;

        while(solution[current]<n && place(solution,current)==0)
        {
            solution[current]+=1;
        }

         if(solution[current] <n)
        {
            if(current==(n-1))
            {
            	ct++;
            	 
                print(solution,n);
                printf("\n Solution number %d for %d-queen problem\n" ,ct , n);

                if(ch==1)
                {
                	break;
                }
            }
            else
                {
                    current +=1;
                    solution[current]= -1;
                }

        }
        else
        {
            current --;
        }

    }

    return ct;
}

int nqrecursive(int row , int limit , int sol[] , int ch , int *ct)
{
     int i,j,k,s=0 , flag=0;


        for(j=0;j<limit;j++)
        {
              if(glo==1)
                        	printf("xxxxx\n");  
                sol[row]=j;
                if(place(sol , row)==1)
                {
                	

                	 sol[row]=j;
                        if(row==limit-1)
                        {
                        	*ct = *ct +1 ;
                        	
                           print(sol,limit);
                           glo =1;

                        }

                        if(row+1==limit)
                        {
                        	if(ch==1)
                        		return 1;

                        	return  0;
                        }

                        if(nqrecursive(row+1,limit,sol,ch,ct)==1)
                        {
                            return 1;
                        }
                        else
                        {
                            sol[row]=-1;
                        }

                }
                	
              
        }
        		
        return 0;

}

void solver(int n , int ch)
{
	system("clear");
	int no_of_queens,i;

	if(n==1)
		printf("*****Iterative Solution*****\n\n");

	else if(n==2)
		printf("*****Recursive Solution*****\n\n");

	do
	{
		printf("\n\n Enter the number of queens:  ");
		scanf("%d",&no_of_queens);

		if(no_of_queens<=3)
			printf("No solution exists for this input : Enter again");
	}while(no_of_queens<=3);


	system("clear");
	if(n==1)
		{

			printf("*****Iterative Solution*****\n\n");
			ch == 2 ? printf("\n Total number of solutions of %d queen problem :  %d",no_of_queens, nqitertive(no_of_queens ,ch)) : nqitertive(no_of_queens,ch);


		}


	else if(n==2)
		{
			printf("*****Recursive Solution*****\n\n");
			//int * ct ;
			int a =0;

			int * solution = malloc (no_of_queens * sizeof(int));
			for(i=0;i<n;i++)
				solution[i]=-1;
			nqrecursive(0,no_of_queens ,solution,ch, &a);
			ch==2 ? printf("\n Total number of solutions of %d queen problem :  %d",no_of_queens, a ) : a;

		}

	

	
}


int main()
{
	int n , ch ,y;
	do
	{
		system("clear");
		printf("\n*****N Queen Problem using Backtracking. Please select one of the options***** \n\n");
		printf("\n 1.Iterative \n");
		printf("\n 2.Recursive \n");
		printf("\n 3.Exit \n");
		printf("\n Enter your choice:    ");

		scanf("%d",&n);
		if(n==1 || n==2)
		{
			system("clear");

			if(n==1)
				printf("*****Iterative Solution*****\n");
			if(n==2)
				printf("*****Recursive Solution*****\n");

			printf("\n 1. One Solution\n");
			printf("\n 2. All Solutions\n");
			printf("\n 3. Return to previous menu\n ");
			printf("\n Enter your choice:    ");

			scanf("%d",&ch);

			if(ch!=3)
				{
					solver(n,ch);
					printf("\n\n Press 1 to return to main menu, else press any key");
					scanf("%d",&y);
					if(y==1)
					ch=3;

				}

		}
		else
			return 0;

	}while(ch==3);

return 0;
}
