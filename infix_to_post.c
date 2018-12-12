#include<stdio.h>
typedef enum {lparan,rparan,times,divide,mod,plus,minus,operand,eos} precedence;
int isp[]={0,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};

precedence stack[10];
char expr[10];
int top=0;

void printToken(precedence token)
{
	switch(token)
	{
	case plus:
	printf("+");
	break;
	case minus:
	printf("-");
	break;
	case times:
	printf("*");
	break;
	case divide:
	printf("/");
	break;
	}
}

precedence getToken(char *s,int *n){
	*s=expr[(*n)++];
	switch(*s)
	{
	case '+':
	return plus;
	case '-':
	return minus;
	case '*':
	return times;
	case '/':
	return divide;
	case '(':
	return lparan;
	case ')':
	return rparan;
	case '#':
	return eos;
	default:
	return operand;
	}
}


precedence pop(){
	if(top>-1)
	return stack[top--];
	else
	return eos;
}

void push(precedence token){
	stack[++top]=token;
}



void postfix()
{
int n=0;
char symbol;
precedence token;
stack[0]=eos;
top=0;
for(token=getToken(&symbol,&n);token!=eos;token=getToken(&symbol,&n))
{
if(token==operand)
{
	printf("%c",symbol);
}
else if(token==rparan){
	while(stack[top]!=lparan)
		printToken(pop());
	pop();
}
else{
	while(isp[stack[top]]>=icp[token])
	{
		printToken(pop());
	}
	push(token);
}
}//end for
while((token=pop())!=eos)
{
	printToken(token);
}
}//end postfix fnc



int main()
{
printf("Enter the infix : ");
scanf("%s",expr);
printf("The postfix is : ");
postfix();
printf("\n---------------\n");
return 0;
}
