//https://pintia.cn/problem-sets/16/problems/696
#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    //PrintDeque(D);
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            //PrintDeque(D);
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            //PrintDeque(D);
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            //PrintDeque(D);
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            //PrintDeque(D);
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

/* Your function will be put here */
/*
Push(X,D): Insert item X on the front end of deque D.
Pop(D): Remove the front item from deque D and return it.
Inject(X,D): Insert item X on the rear end of deque D.
Eject(D): Remove the rear item from deque D and return it. 
Write routines to support the deque that take O(1) time per operation.
*/
Deque CreateDeque()
{	
	Deque pDeque=(Deque)malloc(sizeof(struct DequeRecord));
	if(!pDeque) 
	{
		return NULL;
	}	
	PtrToNode pNode=(PtrToNode)malloc(sizeof(struct Node));
	if(!pNode) 
	{ 
		free(pDeque); 
		return NULL;
	}	
	pNode->Element=ERROR;
	pNode->Last=pNode;
	pNode->Next=pNode;
	pDeque->Front=pNode;
	pDeque->Rear=pNode;
	return pDeque;
}

int Push( ElementType X, Deque D )
{	
	PtrToNode pNode=(PtrToNode)malloc(sizeof(struct Node));
	if(!pNode) 
	{
		return 0;
	}	
	pNode->Element=X;
	pNode->Last=D->Front;
	pNode->Next=D->Front->Next;
	D->Front->Next->Last=pNode; 
	D->Front->Next=pNode;
	D->Rear=D->Front->Last;
	return 1;
}

ElementType Pop( Deque D )
{
	ElementType x; 
	if(D==NULL)
	{
		return ERROR;
	}
	else if(D->Front==D->Rear)
	{		
		return ERROR;
	}
	else
	{
		PtrToNode p=D->Front->Next;
		p->Next->Last=p->Last;
		p->Last->Next=p->Next;
		D->Rear=D->Front->Last;
		x=p->Element;
		free(p); 
		return x; 
	}	
}

int Inject( ElementType X, Deque D )
{	
	PtrToNode pNode=(PtrToNode)malloc(sizeof(struct Node));
	if(!pNode) 
	{
		return 0;
	}	
	pNode->Element=X;
	pNode->Last=D->Rear;
	pNode->Next=D->Rear->Next;
	D->Rear->Next->Last=pNode;
	D->Rear->Next=pNode;
	D->Rear=D->Front->Last;
	return 1;
}

ElementType Eject( Deque D )
{
	ElementType x; 
	if(D==NULL)
	{
		return ERROR;
	}
	else if(D->Front==D->Rear)
	{		
		return ERROR;
	}
	else
	{
		PtrToNode p=D->Rear;
		p->Next->Last=p->Last;
		p->Last->Next=p->Next;
		D->Rear=D->Front->Last;
		x=p->Element;
		free(p); 
		return x; 
	}		
}

Operation GetOp()
{
	char op[15]={0};
	
	scanf("%s",op);
	if(op[0]=='P'&&op[1]=='o')
	{//Pop
		return pop;
	}
	else if(op[0]=='P'&&op[1]=='u')
	{//Push 
		return push;
	} 
	else if(op[0]=='E'&&op[1]=='j')
	{//Eject
		return eject;
	} 
	else if(op[0]=='I'&&op[1]=='n')
	{//Inject 
		return inject;
	} 
	else if(op[0]=='E'&&op[1]=='n')
	{//End 
		return end;
	} 
	else
	{
		return end; 
	} 
}

void PrintDeque( Deque D )
{
	if(D==NULL)
	{
		printf("Deque is Empty!\n");
	}
	else if(D->Front==D->Rear)
	{		
		printf("Deque is Empty!\n");
	}
	else
	{	
		printf("Inside Deque:");
		PtrToNode p=D->Front;
		while(p!=D->Rear)
		{
			p=p->Next;
			printf("%d ", p->Element);		
		} 
		printf("\n");
	}	
}
 

