#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
int pref[256];
struct Stack{
	char* str;
	int top;
};
Stack* createStack(int length)
{
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->str  =(char*)malloc(sizeof(char)*length);
	s->top  =-1;
	return s;
}
int isEmpty(Stack* stack)
{
	if(stack->top<0)
		return 1;
	return 0;
}
char peek(Stack* stack)
{
	return stack->str[stack->top];
}
char pop(Stack* stack)
{
	char c=' ';
	if(!isEmpty(stack))
	{
		c=stack->str[stack->top];
		stack->top--;
	}
	return c;
}
void push(Stack* stack,char op)
{
	stack->top++;
	stack->str[stack->top]=op;
}
int isOperand(char* ch)
{
	char c=*ch;
	if(c>='0'&&c<='9')
		return 1;
	return 0;
}
int precedence(char op1,char op2)
{
	return pref[op1]>=pref[op2];
}
char* convert(char* exp)
{
	char* file=(char*)malloc(sizeof(char)*200);
	char* buff=(char*)malloc(sizeof(char)*100);
	file[0]='\0';
	buff[0]='\0';
	int len=strlen(exp);
	Stack* stack=createStack(len);
	int i=0;int j=0;
	for(i=0;i<len;i++)
	{
		if(exp[i]==' '||exp[i]=='\n')
			continue;
		else if(isOperand(exp+i))
		{
			while(i<len&&isOperand(exp+i))
			{
				sprintf(buff,"%d",exp[i]-'0');
				strcat(file,buff);
				i++;
			}
			sprintf(buff,"%c",' ');
			i--;
			strcat(file,buff);
		}
		else
		{
			if(isEmpty(stack))
				push(stack,exp[i]);
			else
			{
				if(exp[i]=='(')
					push(stack,'(');
				else if(exp[i]==')')
				{
					while(!isEmpty(stack)&&peek(stack)!='(')
					{
						sprintf(buff,"%c ",peek(stack));
						strcat(file,buff);
						pop(stack);
					}
					pop(stack);
				}
				else
				{
					while(!isEmpty(stack)&&peek(stack)!='('&&precedence(peek(stack),exp[i]))
					{
						sprintf(buff,"%c ",peek(stack));
						strcat(file,buff);
						pop(stack);
					}
					push(stack,exp[i]);
				}
			}
		}
	}
	while(!isEmpty(stack))
	{
		sprintf(buff,"%c ",peek(stack));
		strcat(file,buff);
		pop(stack);
	}
	return file;
}
int main()
{
	FILE* file=fopen("input.txt","r");
	FILE* outfile=fopen("part1-output.txt","w");
	char* exp=(char*)malloc(sizeof(char)*100);
	size_t read;size_t len;
	pref['+']=pref['-']=1;
	pref['*']=pref['/']=pref['%']=2;
	pref['(']=pref[')']=3;
	char* res;
	while((read=getline(&exp,&len,file))!=-1)
	{
		res=convert(exp);
		fprintf(outfile,"%s\n",res);
	}
	fclose(file);
	fclose(outfile);
	return 0;
}