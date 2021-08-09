#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
int pref[256];
struct Stack{
	int* str;
	int top;
};
Stack* createStack(int length)
{
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->str  =(int*)malloc(sizeof(int)*length);
	s->top  =-1;
	return s;
}
int isEmpty(Stack* stack)
{
	if(stack->top<0)
		return 1;
	return 0;
}
int peek(Stack* stack)
{
	return stack->str[stack->top];
}
int pop(Stack* stack)
{
	int c=0;
	if(!isEmpty(stack))
	{
		c=stack->str[stack->top];
		stack->top--;
	}
	return c;
}
void push(Stack* stack,int op)
{
	stack->top++;
	stack->str[stack->top]=op;
}
int evaluate(char* exp)
{
	Stack* stack=createStack(100);
	int len=strlen(exp);
	int d=0,d1,d2;int i=0;
	for(i=0;i<len;i++)
	{
		if(exp[i]==' '||exp[i]=='\n')
			continue;
		else if(exp[i]>='0'&&exp[i]<='9')
		{
			d=0;
			while(i<len&&exp[i]>='0'&&exp[i]<='9')
			{
				d=d*10+exp[i]-'0';
				i++;
			}
			i--;
			push(stack,d);
		}
		else
		{
			d2=pop(stack);
			d1=pop(stack);
			if(exp[i]=='+')
				d=d1+d2;
			else if(exp[i]=='-')
				d=d1-d2;
			else if(exp[i]=='*')
				d=d1*d2;
			else if(exp[i]=='/')
				d=d1/d2;
			else if(exp[i]=='%')
				d=d1%d2;
			push(stack,d);
		}
	}
	return pop(stack);
}
int main()
{
	FILE* file=fopen("part1-output.txt","r");
	FILE* outfile=fopen("part2-output.txt","w");
	char* exp=(char*)malloc(sizeof(char)*100);
	size_t read;size_t len;int ans;
	while((read=getline(&exp,&len,file))!=-1)
	{
		ans=evaluate(exp);
		fprintf(outfile,"%d\r",ans);
	}
	fclose(file);
	fclose(outfile);
	return 0;
}