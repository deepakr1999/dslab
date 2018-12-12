#include<stdio.h>
#include<malloc.h>

#define CAP 5
typedef struct cq{
int key;
}element;

int f,r,capacity=CAP;
void queuefull();
element *q;

void addq(element item)
{
r=(r+1)%capacity;
if(r==f)
queuefull();
else
*(q+r)=item;
}


element deleq()
{
if(f==r){
element temp;
temp.key=-1;
return temp;
}

f=(f+1)%capacity;
return q[f];

}


void copy(element *s,element *e,element *p)
{
while(s<=e)
{
*p=*s;
++s;
++p;
}
}

void queuefull()
{
int start;
start=(f+1)%capacity;

element *nq;
nq=(element *)malloc(sizeof(element)*2*capacity);
if(start<2)
{
copy(q+start,q+start+capacity-1,nq);
}
else
{
copy(q+start,q+capacity,nq);
copy(q,q+r+1,nq+capacity-start);
}
f=2*capacity-1;
r=capacity-1;
capacity=capacity*2;
free(q);
q=nq;

}


void display()
{
if(f==r)
{
printf("\nEmpty queue\n");
return;
}
int i;
if(f<r)
{
for(i=f+1;i<=r;++i)
printf("\t->%d\n",q[i].key);
}

else
{
for(i=(f+1)%capacity;i<capacity;i++)
printf("%d ->",q[i].key);

}

}

int main(){
element x;
f=r=0;
int n;
q=(element *)malloc(sizeof(element)*5);
element temp;
int i=0,ch;
while(1)
{
printf("Enter \n1.Insert\n2.Delete\n3.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the element to insert : ");
scanf("%d",&temp.key);
addq(temp);
break;
case 2:
x=deleq();
if(x.key!=-1)printf("Element deleted is : %d\n",x.key);
if(x.key==-1)printf("The queue is empty\n");
break;
case 3:
display();
break;
default:
printf("!!!!Invalid Input!!!\n");
}
}
return 0;
}
