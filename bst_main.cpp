//avl

#include<iostream>
using namespace std;

typedef struct node
{
	int d,h;
	node *l;
	node *r;
};

int height(node *n)
{
	if(n==NULL)
		return 0;

	return n->h;
}

node *newnode(int data)
{
	node *tmp=(node*)malloc(sizeof(node));
	tmp->d=data;
	tmp->l=NULL;
	tmp->r=NULL;
	tmp->h=1;
	return tmp;
}

void inorder(node *n)
{
    if(n!=NULL)
    {
        cout<<n->d<<" ";
         
        inorder(n->l);
       
        inorder(n->r);
    }
}

node *rr (node *y)
{
	node *x=y->l;
	node *t2=x->r;

	x->r=y;
	y->l=t2;

	y->h=1+max(height(y->l),height(y->r));
	x->h=1+max(height(x->l),height(x->r));

	return x;
}

node *ll(node *x)
{
	node *y=x->r;
	node *t2=y->l;

	y->l=x;
	x->r=t2;

	x->h=1+max(height(x->l),height(x->r));
	y->h=1+max(height(y->l),height(y->r));

	return y;
}

int bal(node *n)
{
	if(n==NULL)
		return 0;
	return height(n->l)-height(n->r);
}

node *insert(node *n,int key)
{
	if(n==NULL)
		return newnode(key);

	if(key > n->d)
		n->r=insert(n->r,key);
	else if(key < n->d)
		n->l=insert(n->l,key);
	else return n;

	n->h=1+max(height(n->l),height(n->r));

	int b=bal(n);

	if(b>1 && key < n->l->d)
		return rr(n);
	
	else if(b>1 && key > n->l->d)
	{
		n->l=ll(n->l);
		return rr(n);
	}

	else if(b<-1 && key < n->r->d)
	{
		n->r=rr(n->r);
		return ll(n);
	}
	else if(b<-1 && key > n->r->d)
		return ll(n);

	return n;
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
		n->r=deletet(n->r,key);
	else 
	{
		if(n->l==NULL)
		{
			node *tmp=n->r;
			free(n);
			return tmp;
		}
		else if(n->r==NULL)
		{
			node* tmp=n->l;
			free(n);
			return tmp;
		}

		node* tmp=minval(n->r);
		n->d=tmp->d;
		n->r=deletet(n->r,tmp->d);
	}

	n->h=1+max(height(n->l),height(n->r));
	
	int b=bal(n);

	if(b>1 && bal(n->l)>=0)
		return rr(n);
	
	else if(b>1 && bal(n->l)<0)
	{
		n->l=ll(n->l);
		return rr(n);
	}

	else if(b<-1 && (n->r)>0)
	{
		n->r=rr(n->r);
		return ll(n);
	}
	else if(b<-1 && bal(n->r)<=0)
		return ll(n);

	return n;

}

int main()
{
	node *root=NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    inorder(root);
    cout<<"\n";
    
    root = deletet(root, 10);
    
    inorder(root);
    cout<<"\n";
    
    
	return 0;
}

