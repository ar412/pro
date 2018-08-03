#include<iostream>
#define NULL 0
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define MAX_KEY_LENGTH     15
#define MAX_VALUE_LENGTH   127
#define MAX_MESSAGE_LENGTH 81920

typedef struct node
{
	int keylen,vallen,entity,type;
	string keyval,value;
	node *child[130];
};

node* newnode(int t,int k,string kk)
{
	node *tmp=(node*)malloc(sizeof(node));
	tmp->type=t;
	tmp->keylen=k;
	tmp->keyval=kk;
	tmp->vallen=0;
	tmp->value=0;
	tmp->entity=0;
	for(int i=0;i<130;i++)
		tmp->child[i]=NULL;

	return tmp;
}


void stringtype(int key_len,int val_len,char in[],node *root,int index)
		
		string val="";

		for(int i=index;i<index+val_len;i++)
		{
			val+=in[i];
		}
		
		root->vallen=val_len;
		root->value=val;
}

void parse(char in[MAX_MESSAGE_LENGTH], int size)
{
	int index=0;
	int ty=in[index];
	int key_len=in[1]*256+in[2];
	string key_val="";
	for(int i=3;i<3+key_val;i++)
	{
		key_val+=in[i];
	}
	
	int val_len=in[key_len+3]*256+in[key_len+4];
	
	node *root=newnode(ty,key_len,key_val);

	if(ty==1)
	{	
		index=5+key_val;
		stringtype(key_len,val_len,in,root,index);
	}
	else
	{
		int en=0;
		root->entity=en;
		for(int i=0;i<en;i++)
		{
			val_len=
			stringtype(key_len,val_len,in,root,index);
			index+=val_len;
		}
	}
	
}

void set(char targetkey[MAX_KEY_LENGTH + 1], char newvalue[MAX_VALUE_LENGTH + 1])
{

}

void add(char parentkey[MAX_KEY_LENGTH + 1], char childkey[MAX_KEY_LENGTH + 1], char childvalue[MAX_VALUE_LENGTH + 1])
{

}

void erase(char targetkey[MAX_KEY_LENGTH + 1])
{

}

int generate(char targetkey[MAX_KEY_LENGTH + 1], char out[MAX_MESSAGE_LENGTH])
{
	return 0;
}
//https://9gag.com/gag/aW1A2wx