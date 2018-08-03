//bst
#include<iostream>
using namespace std;

typedef struct node
{
	int d;
	node *l;
	node *r;
};

node *newnode(int data)
{
	node *tmp=(node*)malloc(sizeof(node));
	tmp->d=data;
	tmp->l=NULL;
	tmp->r=NULL;
	return tmp;
}

void inorder(node *n)
{
    if(n!=NULL)
    {
        inorder(n->l);
        cout<<n->d<<" ";
        inorder(n->r);
    }
}

node* insertt(node *n,int key)
{
	if(n==NULL)
		return newnode(key);

	if(key > n->d)
		n->r=insertt(n->r,key);
	else n->l=insertt(n->l,key);

	return n;
}

node *search(node *n,int key)
{
	if(n==NULL || n->d == key)
		return n;

	if(key > n->d)
		return search(n->r,key);
	else return search(n->l,key);
	 
}

node *minval(node *n)
{
	if(n->l==NULL)
		return n;
	return minval(n->l);
}

node *deletet(node *n,int key)
{
	if(n==NULL)
		return n;

	if(key < n->d)
		n->l=deletet(n->l,key);
	else if(key > n->d)
	{
		n->r=deletet(n->r,key);
	}
	else
	{
		if(n->l == NULL)
		{
			node *tmp=n->r;
			free(n);
			return tmp;
		}
		else if(n->r ==NULL)
		{
			node *tmp=n->l;
			free(n);
			return tmp;
		}

		node *tmp=minval(n->r);
		n->d=tmp->d;
		n->r=deletet(n->r,tmp->d);
	}
	return n;
}

void prednsucc(node *n,node *&p,node *&s,int key)
{
	if(n==NULL)
		return;

	if(n->d==key)
	{
		if(n->l!=NULL)
		{
			node *tmp=n->l;
			while(tmp->r)
				tmp=tmp->r;
			p=tmp;
		}
		if(n->l!=NULL)
		{
			node *tmp=n->r;
			while(tmp->l)
				tmp=tmp->l;
			s=tmp;
		}
		return;
	}

	if(n->d > key)
	{
		s=n;
		prednsucc(n->l,p,s,key);
	}
	else 
	{
		p=n;
		prednsucc(n->r,p,s,key);
	}
}

int main()
{
	node *root=NULL;
	root=insertt(root,50);
	insertt(root,30);
	insertt(root,20);
	insertt(root,40);
	insertt(root,70);
	insertt(root,60);
	insertt(root,80);
    
    inorder(root);
    cout<<"\n";
	search(root,60);

	deletet(root,50);
    inorder(root);
    cout<<"\n";
    
    node *pre=NULL,*suc=NULL;
    prednsucc(root,pre,suc,100);
     if (pre != NULL)
      cout << "Predecessor is " << pre->d << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->d;
    else
      cout << "No Successor";

    
	return 0;
}


