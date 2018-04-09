 #include<bits/stdc++.h>
using namespace std;

void print_all( int n , map < pair< int , pair < vector <int> , int > > , int > &dp)
{
    cout<<"\n-----------------------------------------------------------------------------------------------------\n";
    cout<<" All possible paths are \n\n";
    int i , j;

    map < pair< int , pair < vector <int> , int > > , int > :: iterator it;

    for(i=0 ;i < n ;i++ )
        {
            for( it = dp.begin () ; it!= dp.end() ;it++)
                {
                    if( it->first.second.first.size() == i)
                           {
                                cout<<"Cost of ( "<<it->first.first+1 <<" , { ";

                                for( j=0 ; j < it->first.second.first.size();j ++)
                                {
                                    cout<<it->first.second.first[j]+1<<",";
                                }

                                cout<<" } , 1 ) = "<<it->second<<endl<<endl;
                            }


                }
         }
 }


void print_path( int a , vector < int > v , int b , int * distance , int * ptr ,int * path , int n, map < pair< int , pair < vector <int> , int > > , int > &dp)
    {

         int i;

         for(i=0 ;i < v.size();i++)
            {
                vector <int> v2 = v;
                v2.erase(v2.begin() + i);

                if( dp[{a,{v,b}}] == distance[a*(n)+v[i]] + dp[{v[i],{v2,b}}])
                    {
                        path[*ptr] = v[i]+1;

                        (*ptr)+=1;
                        print_path( v[i] , v2 , b , distance ,ptr,path , n , dp);
                    }

            }
    }



int TSP ( int a , vector<int > v , int b , int * distance , int n , map < pair< int , pair < vector <int> , int > > , int > &dp)
{

    int i;
    if( dp[{a,{v,b}}] )
        {
                  return dp[{a,{v,b}}];
        }

     dp[{a,{v,b}}] = INT_MAX;

     if(v.size()==0)
        {
            dp[{a,{v,b}}] = distance[a*(n)+b];
        }
     else
     {

         for(i = 0 ; i<v.size();i++ )
            {
              if(distance[a * (n)+v[i]]!= INT_MAX)
                   {
                         vector < int > v2 = v;
                         v2.erase(v2.begin() + i);

                         int temp = TSP( v[i] , v2 , b , distance ,n , dp);
                         if( temp != INT_MAX)
                         dp[{a,{v,b}}] = min(dp[{a,{v,b}}], distance[a *(n)+v[i]] + temp );



                 }
            }
     }

     return dp[{a,{v,b}}];
}




int main()
{
  int n , i , cost=0, j , src , dest , weight , e;
  system("clear");
  map < pair< int , pair < vector <int> , int > > , int > dp;
  cout<<"\n ****TRAVELLING SALESMAN PROBLEM USING DYNAMIC PROGRAMMING**** \n";

  cout<<"\n Enter the number of nodes \n";
  cin>>n;


  // 2 D array dynamic memory allocation using row major strategy

  int * dist = (int*) malloc (sizeof(int ) * (n)*(n));
  vector < int > v;

  int a=0;
  int * ptr = & a;
  int * path = (int*) malloc ( sizeof(int) * (n+1));


  // Entering the adjacency matrix


  for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
                dist[i*(n) +j]= INT_MAX;

            }

   do
   {
        cout<<("\n \n Enter the number of Edges ");
        cin>>e;

        if(e < 3 || e > (n * (n-1))/2 )
            {
                cout<<"Error : Invalid number of edges. Enter again ";
            }

   } while ( e <3 || e > (n * (n-1))/2);


   {
        for(i=0;i<e;i++)
                {
                    int flag=0;

                    cout<<"\n Enter the source , destination and edge length ";

                    do
                    {
                        cin>>src>>dest>>weight;

                        flag =0;
                        if( src <= 0 || dest <= 0 || src > (n*(n-1))/2 || dest > (n*(n-1))/2  || weight <=0 )
                            {
                                cout<<(" \n Error : The vertices entered are invalid. Enter again ");
                            }

                          else if( dist[ (src-1)*n + (dest-1)] != INT_MAX )
                            {
                                cout<<(" \n Error : This edge already exists ");
                                flag=1;
                            }
                            else
                                break;

                    } while( 1);


                        src--;
                        dest--;

                    dist[src*n + dest] = weight;

                }
   }

  for(i=1;i<n;i++)
        v.push_back(i);

  cost = TSP ( 0, v , 0, dist , n , dp);

  if(cost == INT_MAX)
  {
    cout<<"\n \n No path is possible \n ";
    free(dist);
    free(path);
    dist = NULL;
    path = NULL;
    return 0;
  }


  print_all(n , dp);

  cout<<endl;

  cout<<"\nShortest path length = ";
  cout<<cost<<endl;

  cout<<"-------------------------------------------------------------------------------------------------------";
  cout<<"\nShortest path for solution of TSP \n\n";

  print_path( 0 , v , 0 , dist , ptr , path , n , dp);

  cout<<1<<"-->";
  for(i=0;i< (n-1) ;i++)
  cout<<path[i]<<"-->";
  cout<<1<<endl<<endl;

  free(dist);
  free(path);
  dist = NULL;
  path = NULL;


 }

 /*
5
8
1 4 3
1 3 5
2 5 3
3 4 1
3 1 3
4 2 2
5 1 2
5 3 1
 */

 /*
3
3
1 2 1
1 3 2
3 2 2
 */
