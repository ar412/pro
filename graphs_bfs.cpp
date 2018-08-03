#include <iostream>

using namespace std;

int arr[10000][10000];

void dfs(int v,int n,bool vis[])
{
    //  int (*arr)[n] = static_cast<int (*)[n]>(x);
     
    vis[v]=1;
    cout<<v+1<<" ";
    for(int i=0;i<n;i++)
    {
        if(arr[v][i]==1 && vis[i]==0)
        {
            dfs(i,n,vis);
        }
    }
    
}

int main()
{
   int n,m,a,b;
   cin>>n>>m;
   
//   int arr[n][n];
   bool vis[n];
   
   for(int i=0;i<n;i++)
    vis[i]=0;
    
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           arr[i][j]=0;
       }
   }
   
   for(int i=0;i<m;i++)
   {
       cin>>a>>b;
       arr[a-1][b-1]=1;
       arr[b-1][a-1]=1;
   }
   
  for(int i=0;i<n;i++)
  {
      if(vis[i]==0)
        dfs(0,n,vis);
  }
   
    return 0;
}
