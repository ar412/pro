#include<iostream>
#define NULL 0
using namespace std;

typedef struct node
{
	char data;
	node *child[50];
};

node* newnode(char d)
{
	node *tmp=(node*)malloc(sizeof(node));
	tmp->data=d;
	for(int i=0;i<50;i++)
		tmp->child[i]=NULL;
	return tmp;
}

node *search(node *n,char d)
{
    // cout<<n->data<<" ";
	if(n==NULL)
	    return NULL;
	
	if(n->data==d)
		{
		  //  cout<<"d\n";
		    return n;
		}
    
	node *tmp=NULL;

	for(int i=0;i<50;i++)
	{
		if(n->child[i]!=NULL)
		{
		  //  cout<<" i "<<i<<" ";
			tmp=search(n->child[i],d);
			if(tmp==NULL)
			    continue;
			if(tmp!=NULL);
				{
				    // cout<<"mill gaya ";
				    return tmp;}
		}
	}
// 	cout<<"child null\n";
    return tmp;
}

node *parent(node *n,char d)
{
    if(n==NULL)
        return n;
    
    if(n->data==d)
    {
        return n;
    }
    
    node *tmp=NULL;

	for(int i=0;i<50;i++)
	{
		if(n->child[i]!=NULL)
		{
			tmp=parent(n->child[i],d);
			if(tmp==NULL)
			    continue;
			if(tmp!=NULL);
				{
				    return n;
				}
		}
	}
    return NULL;
}

void pre(node *n)
{
	if(n==NULL)
		return;

	cout<<n->data;

	for(int i=0;i<50;i++)
		pre(n->child[i]);

}

node* delete_key(node *n)
{
	if(n==NULL)
		return NULL;

	for(int i=0;i<50;i++)
	{
		if(n->child[i]!=NULL)
		{
	    	n->child[i]=delete_key(n->child[i]);
		}
	}

	delete(n);
	return NULL;
}

/*   Let us create below tree
   *             A
   *         / /  \  
   *       B  c   D  
   *      / \    |  /|\
   *     K  J    G  C H I
   *      /\            \
   *    N   M            L
   */

int main()
{
	node *root = newnode('A');
    root->child[0] = newnode('B');
    root->child[1] = newnode('C');
    root->child[2] = newnode('D');
    root->child[0]->child[0] = newnode('E');
    root->child[0]->child[1] = newnode('F');
    root->child[2]->child[0] = newnode('G');
    root->child[2]->child[1] = newnode('H');
    root->child[2]->child[2] = newnode('I');
    root->child[2]->child[3] = newnode('J');
    root->child[0]->child[1]->child[0] = newnode('K');
	
	node *tmp=NULL;
	tmp=parent(root,'H');
	cout<<tmp->data;
    
// 	if(tmp!=NULL)
// 	cout<<tmp->data<<"\n";
// 	else cout<<"NULL\n";
// 	pre(root);
// // 	delete_key(root);
//     tmp=search(root,'I');
// 	delete_key(tmp);
// 	cout<<"\n";
    // pre(root);
	return 0;
}