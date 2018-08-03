#include<iostream>
#define MAX 100000
using namespace std;

int ar[MAX];
int dr[MAX][2];
int heap_size;
int L[MAX], R[MAX];

void swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    for (i = 0; i < n1; i++)
        L[i] = dr[l + i][0];
    for (j = 0; j < n2; j++)
        R[j] = dr[m + 1+ j][0];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            dr[k][0] = L[i];
            i++;
        }
        else
        {
            dr[k][0] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        dr[k][0] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        dr[k][0] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        mergeSort( l, m);
        mergeSort( m+1, r);
 
        merge( l, m, r);
    }
}

int parent(int i)
{
	return (i-1)/2;
}

void inserth(int ele)
{
	if(heap_size==MAX)
		return;

	int i=heap_size;
	heap_size++;
	ar[heap_size]=ele;

	while(i!=0 && ar[i]>ar[parent(i)])
	{
		swap(ar[i],ar[parent(i)]);
		i=parent(i);
	}

}

void heapify(int i,int n)
{
	int large=i;
	int l=2*i+1;
	int r=2*i+2;

	if(l<n && ar[l]>ar[large])
		large=l;
	if(r<n && ar[r]>ar[large])
		large=r;

	if(large!=i)
	{
		swap(ar[large],ar[i]);
		heapify(large,n);
	}
}

int extractmax()
{
	if(heap_size<=0)
		return -100000;

	if(heap_size==1)
	{
		heap_size=0;
		return ar[0];
	}

	int m=ar[0];
	swap(ar[0],ar[heap_size-1]);
	heap_size--;
	heapify(0,heap_size);
	return m;
}

int main()
{
	int n,d,p;
	cin>>n;
	
	for(int i=0;i<n;i++)
    {
        cin>>dr[i][0]>>dr[i][1];
    }
    cin>>d>>p;
	mergeSort(0, n - 1);
	heap_size=0;

	for(int i=0;i<n;i++)
		dr[i][0]=d-dr[i][0];

	int i=0,c=0;
	while(i<n)
	{
		if(p>=d)
			break;
		if(p-dr[i][0]>=0)
			{
				inserth(dr[i][1]);
				i++;
			}
		else 
		{
			if(heap_size<=0)
			{
				c=-1;
				break;
			}
			p+=extractmax();
			c++;
		}
	}

	cout<<c<<endl;
    return 0;

}