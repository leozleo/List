#include "stack_list.h"
#include <stdio.h>
#include <stdlib.h>


struct Node
{
	ElementType Element;
	PtrToNode   Next;
};



int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack(void)
{
	Stack S = (Stack)malloc(sizeof(struct Node));
	if(S  != NULL)
	{
		S->Next = NULL;
		MakeEmpty(S);
		return S;
	}
	return NULL;
}

void MakeEmpty(Stack S)
{
	if(S == NULL)
	{
		printf("Must use CreateStack first\r\n");
		return;
	}
	else
	{
		while(!IsEmpty(S))
			Pop(S);
	}
}

void Push(ElementType X, Stack S)
{
	PtrToNode TmpCell = (PtrToNode)malloc(sizeof(struct Node));
	if(TmpCell == NULL)
	{
		printf("Out of space\r\n");
		return;
	}

	TmpCell->Element = X;
	TmpCell->Next    = S->Next;
	S->Next          = TmpCell;
}


ElementType Top(Stack S)
{
	if(IsEmpty(S))
	{
		printf("Empty Stack\r\n");
		return -1;
	}
	else
	{
		return S->Next->Element; 
	}
}

void Pop(Stack S)
{
	PtrToNode TmpCell;
	if(IsEmpty(S))
	{
		printf("Empty Stack\r\n");
	}
	else
	{
		TmpCell = S->Next;
		S = S->Next->Next;
		free(TmpCell);
	}
}


void PrintStack(Stack S)
{
	if(!IsEmpty(S))
	{
		printf("Top->");
		Stack Tmp = S->Next;
		while(Tmp != NULL)
		{
			printf("%d->", Tmp->Element);
			Tmp = Tmp->Next;
		}
		printf("\r\n");
	}
	else
	{
		printf("Empty Stack\r\n");
	}
	return;
}


