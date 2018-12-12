
#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) ((x==y)?0:(x>y)?1:-1)
struct node
{
        int coef;
        int expo;
        struct node*link;
};

typedef struct node* polyptr;

void attach(int coeffi,int deg,polyptr *ptr)
{
        polyptr t;
        t=(polyptr)malloc(sizeof(struct node));
        t->coef=coeffi;
        t->expo=deg;
        (*ptr)->link=t;
        *ptr=t;
        (*ptr)->link=NULL;
}

polyptr add(polyptr a,polyptr b)
{
        polyptr c,lastC,startA;
        int sum,done=0;
        startA=a;
        a=a->link;
        b=b->link;
        c=(polyptr)malloc(sizeof(struct node));
        c->expo=-1;
        lastC=c;
        do
        {
                switch(COMPARE(a->expo,b->expo))
                {
                case 1:attach(a->coef,a->expo,&lastC);
                        a=a->link;
                        break;
                case 0:if(startA==a)
                        done=1;
                        else
                        {
                        sum=a->coef+b->coef;
                        if(sum)
                        attach(sum,a->expo,&lastC);
                        a=a->link;
                        b=b->link;
                        }
                        break;
                case -1:attach(b->coef,b->expo,&lastC);
                        b=b->link;
                        break;
                }
}while(!done);
lastC->link=c;
return c;
}
void printpoly(polyptr k)
{k=k->link;
while(((k->link)->expo)!=-1)
{
printf("%dx^%d+",k->coef,k->expo);
k=k->link;
}
printf("%dx^%d",k->coef,k->expo);
printf("\n");
}

void main()
{
        polyptr a,b,c,endA,endB;
        int n,i,expon;
        int coef;
        a=(polyptr)malloc(sizeof(struct node));
        a->expo=-1;
        b=(polyptr)malloc(sizeof(struct node));
        b->expo=-1;
        printf(">Enter the no of terms for first poly : ");
        scanf("%d",&n);
        endA=a;
        for(i=0;i<n;i++)
        {
                printf("\tEnter coefficient : ");
                scanf("%d",&coef);
                printf("\tEnter the exponent : ");
                scanf("%d",&expon);
                attach(coef,expon,&endA);
        }
endA->link=a;
printf(">Enter the no of terms for second poly : ");
scanf("%d",&n);
endB=b;
for(i=0;i<n;i++)
{
printf("\tEnter the coefficient : ");
scanf("%d",&coef);
printf("\tEnter the exponent : ");
scanf("%d",&expon);
attach(coef,expon,&endB);
}
endB->link=b;
c=add(a,b);
printpoly(a);
printpoly(b);
printpoly(c);

}








