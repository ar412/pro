#include <iostream>
using namespace std;

int a[]={1,0,-1,0};
int b[]={0,1,0,-1};
int g[10000][10000];

void bfs(int x,int y,int n,int m,int l,int &ans)
{
    if(x<0 || y<0 || x>=n || y>=m || g[x][y] )
        return;
        
    if(x==n-1 && y==m-1)
    {
        ans=l;
        return;
    }
    
    for(int i=0;i<4;i++)
    {
        bfs(x+a[i],y+b[i],n,m,l+1,ans);
    }
    
}

int main()
{
    cout<<"DAfvd\n";
    int n,m,aa,bb;
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            g[i][j]=0;
        }
    }
    
    int k;
    cin>>k;
    
    for(int i=0;i<k;i++)
    {
        cin>>aa>>bb;
        g[aa][bb]=1;
    }
    
    int ans=0;
    bfs(0,0,n,m,0,ans);
    
    cout<<ans;
    
    
    return 0;
}
