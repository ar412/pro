#include<iostream>

using namespace std;

void updateut(long long int *st,int ss,int se,int ind,int diff,int si)
{
    if(ind<ss || ind>se)
        return;
        
    st[si]+=diff;
    
    if(ss==se)
        return;
        
    int mid=ss+(se-ss)/2;
    updateut(st,ss,mid,ind,diff,si*2+1);
    updateut(st,mid+1,se,ind,diff,si*2+2);
    
}

void update(int ar[],int ind,int x,long long int *st,int n)
{
    if(ind<0 || ind >=n)
        return;
        
    int diff=x-ar[ind];
    ar[ind]+=diff;
    
    updateut(st,0,n-1,ind,diff,0);
}

int findsumut(long long int *st,int ss,int se,int l,int r,int si)
{
   // cout<<"ss "<<ss<<" se "<<se<<" si "<<si<<"\n";
    if(l<=ss && r>=se)
        {
     //       cout<<"st "<<st[si]<<"\n";
            return st[si];
        }
    if(se<l || ss>r)
        {
       //     cout<<"st "<<0<<"\n";
            return 0;
        }
    int mid=ss+(se-ss)/2;
    
    int a= findsumut(st,ss,mid,l,r,si*2+1);
    int b= findsumut(st,mid+1,se,l,r,si*2+2);
    
    //cout<<"a "<<a<<" b "<<b<<"\n";
    return a+b;
}

int findsum(int s,int e,int n,long long int *st)
{
    if(s<0 || e>=n)
        return -1;
        
    return findsumut(st,0,n-1,s,e,0);
}

int buildtree(int ar[],int ss,int se,long long int *st,int si)
{
    if(ss==se)
    {
        st[si]=ar[ss];
        return ar[ss];
    }
 
    int mid=ss+(se-ss)/2;
    st[si]=buildtree(ar,ss,mid,st,si*2+1)+buildtree(ar,mid+1,se,st,si*2+2);
 
    return st[si];
}


int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    
    long long int st[3000000];
    buildtree(ar,0,n-1,st,0);
    
    int k,l,r;
	char ch;
    cin>>k;
    
   // cout<<" ss  se si a b \n";
    
    for(int i=0;i<k;i++)
    {
        cin>>ch>>l>>r;

		if(ch=='U')
			 update(ar,l-1,r,st,n);
		else cout<<findsum(l-1,r-1,n,st)<<endl;  

         
    }  
    return 0;
}