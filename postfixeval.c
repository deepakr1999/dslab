#include<stdio.h>
typedef enum {lparan,rparan,plus,minus,times,divide,mod,eos,operand} precedence;

char expr[34];
int stack[100];
int top=-1;


void push(int x)
{
stack[++top]=x;
}

int pop(){
return stack[top--];
}




precedence getToken(char *s,int *n)
{
*s=expr[(*n)++];
switch(*s)
{
case '(':
return lparan;
case ')':
return rparan;
case '+':
return plus;
case '-':
return minus;
case '*':
return times;
case '/':
return divide;
case '%':
return mod;
case '#':
return eos;
default:
return operand;
}
}



int calc()
{
int op1,op2,n=0;
char symbol;
precedence token;
token=getToken(&symbol,&n);
while(token!=eos)
{
	if(token==operand)
	push(symbol-'0');
	else {
	op1=pop();
	op2=pop();
	if(token==plus)push(op1+op2);
	if(token==times)push(op1*op2);
	if(token==divide)push(op1/op2);
	if(token==minus)push(op2-op1);
	}
token=getToken(&symbol,&n);
}
return pop();
}


int main()
{
printf("Enter the postfix : ");
scanf("%s",expr);
int x;
x=calc();
printf("The answer is : %d\n",x);
return 0;
}
