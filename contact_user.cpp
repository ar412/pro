#include<iostream>

#define N 50021 

typedef enum
{
	NAME,
	NUMBER,
	BIRTHDAY,
	EMAIL,
	MEMO
} FIELD;

typedef struct
{
	int count;
	char str[20];
} RESULT;

using namespace std;

int ind;

typedef struct dbnode
{
	char rec[5][20];
	bool valid;
};

typedef struct hnode
{
	int index;
	hnode* next;
	hnode()
	{
		index = -1;
		next = 0;
	}
};

dbnode db[N];
hnode ht[N][5];

void InitDB()
{
	ind=0;
}

int hashfun(char *s)
{
	int i=0,hash=5381;

	while(s[i])
		hash=(hash*33+s[i++])%N;

	return hash;
}

void mystrcpy(char *s,char *d)
{
	int j=0;
	while(d[j])
	{
		s[j]=d[j];
		j++;
	}
}

void Add(char* name, char* number, char* birthday, char* email, char* memo)
{
	char *ptr[5]={name,number,birthday,email,memo};

	for(int i=0;i<5;i++)
	{
		char * src = ptr[i];
		mystrcpy(db[ind].rec[i],src);
	}
	db[ind].valid=1;

	for(int i=0;i<5;i++)
	{
		int I=hashfun(db[ind].rec[i]);
		if(ht[I][i].index==-1)
		{	ht[I][i].index=ind;}
		else 
		{
			hnode *tmp=ht[I][i].next;
			hnode* node=new hnode;
			ht[I][i].next=node;
			node->next=tmp;
			node->index=ind;
		}
	}

	ind++;
}

int Delete(FIELD field, char* str)
{
	int I=hashfun(str);
	int res=0;
	hnode* temp = &ht[I][field];

	while(temp)
	{
		if(mystrcmp(db[temp->index].rec[field],str))
		{
			db[temp->index].valid=0;
			res++;
		}
		
		temp=temp->next;
	}

	ind--;
	return res;
}

RESULT Search(FIELD field, char* str, FIELD returnfield)
{
	int I=hashfun(str);
	int res=0;
	char ch[20];
	hnode* temp = &ht[I][field];
	while(temp)
	{
		if(mystrcmp(db[temp->index].rec[field],str) && db[temp->index].valid)
		{
			mystrcpy(ch,db[temp->index].rec[returnfield]);
			res++;
		}
		
		temp = temp->next;
	}

	RESULT r;
	r.count=res;	
	mystrcpy(r.str,ch);
	return r;
}

int Change(FIELD field, char* str, FIELD changefield, char* changestr)
{
	int I=hashfun(str);
	int res=0;
	hnode *temp=&ht[I][field];
	while(temp)
	{
		if(mystrcmp(db[temp->index].rec[field],str))
		{
			
			int J=hashfun(db[temp->index].rec[changefield]);
			
			//delete
			hnode *t=&ht[J][changefield];
			while(t)
			{
				if(mystrcmp(db[temp->index].rec[changefield],db[t->index].rec[chengefield]))
				{

				}
			}

			J=hashfun(changestr);
			//add
			ht[J][changestr]

			
			mystrcpy(db[temp->index].rec[changefield],changestr);
			res++;
		}
		
		temp=temp->next;
	}

	return res;
}