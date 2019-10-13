#include <stdio.h>
#include <string.h>

#define MAX 10001 

typedef struct _stack{
	int key;
}STACK;

int TOP = -1;
STACK stack[MAX];

void push(int X);
int pop();
int size();
int empty();
int top();

int main(){
	
	char command[10];
	int num,i;
	memset(command,'\0',sizeof(command));


	scanf("%d",&num);

	for(i=0; i<num ; i++)
	{
		stack[i].key = '\0';

		scanf("%s",command);

		if(strcmp(command,"push") == 0)
		{
			int x;
			scanf("%d",&x);

			if(x<1 || x>100000)
			{
				printf("[x : %d]x는 1~100000사이의 정수만 입력해주세요",x);
				break;
			}

			push(x);
		}
		else if(strcmp(command,"pop") == 0)
		{
			printf("%d\n",pop());
		}
		else if(strcmp(command,"size") == 0)
		{
			printf("%d\n",size());
		}
		else if(strcmp(command,"empty") == 0)
		{
			printf("%d\n",empty());
		}
		else if(strcmp(command,"top") == 0)
		{
			printf("%d\n",top());
		}
		else
			i--;
	}
	return 0;
}

void push(int X)
{
	stack[++TOP].key = X;
}

int pop()
{
	int result;
    
    if(TOP == -1)
	{
		return -1;
	}
    
	result = stack[TOP].key;
	stack[TOP].key = '\0';
    
    if(TOP > -1)
	    --TOP;

	return result;
}

int size()
{
	if(TOP == -1)
		return 0;
	else
		return TOP+1;
}

int empty()
{
	if(TOP == -1)
		return 1;
	else
		return 0;
}

int top()
{
	int result = -1;

	if(TOP == -1)
		return -1;
	else
		result = stack[TOP].key;

	return result;
}
