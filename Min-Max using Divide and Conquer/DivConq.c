#include<stdio.h>
#include<stdlib.h>

void divconq( int *ar , int left , int right , int* mini , int* maxi)
{

    if(ar[left]==ar[right])
    {
        if(ar[left]< *mini)
            *mini = ar[left];

        if(ar[left]> *maxi)
            *maxi = ar[left];

        return ;
    }

    int mid = (left + right)/2;

    divconq(ar , left , mid , mini , maxi);
    divconq(ar , mid+1 , right , mini , maxi);
}

int main()
{
    int n , i ;
    printf("\n Enter the number of elements");
    scanf("%d",&n);

    int *ar=(int*)malloc( n* sizeof(int));

    printf("\n Enter array elements");

    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }

    printf("\n The entered array is \n");

    for(i=0;i<n;i++)
    printf("%d ",ar[i]);

    int mini = ar[0] , maxi=ar[0];

    divconq(ar,1,n-1,&mini , &maxi);


    printf("\n The minimum element in array is %d" , mini);
    printf("\n The maximum element in array is %d" , maxi);

    return 0;
}
