#include<stdio.h>
#define MAX_TERMS 100
#define COMPARE(x,y) (x==y)?0:(x>y?1:-1)
int avail;
void attach(float,int);
typedef struct{float coef;int expon;}term;
term terms[MAX_TERMS];


void padd(int startA,int finishA,int startB,int finishB,int *startD,int *finishD){
*startD=avail;
float coef;
while(startA<=finishA && startB<=finishB)
	switch(COMPARE(terms[startA].expon,terms[startB].expon)){
		case -1:
		attach(terms[startB].coef,terms[startB].expon);
		startB++;
		break;
		case 0:
		coef=terms[startA].coef+terms[startB].coef;
		if(coef)
			attach(coef,terms[startA].expon);
		startA++;
		startB++;
		break;
		case 1:
		attach(terms[startA].coef,terms[startA].expon);
		startA++;
	}
for(;startA<=finishA;startA++)
attach(terms[startA].coef,terms[startA].expon);
for(;startB<=finishB;startB++)
attach(terms[startB].coef,terms[startB].expon);
}


void attach(float coef,int exponent){
	if(avail>=MAX_TERMS){
		printf("Too man terms in polynomial");
	}
	terms[avail].coef=coef;
	terms[avail++].expon=exponent;
}



int main(){
int sa,fa,sb,sb,*sd,*fd;
sd=(int *)malloc(sizeof(int));
fd=(int *)malloc(sizeof(int));

}
