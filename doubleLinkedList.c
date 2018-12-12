#include<stdio.h>
#include<malloc.h>

struct node
{
int data;
struct node *llink,*rlink;
};

typedef struct node * nodeptr;

nodeptr head;


void addHead(int x)
{
nodeptr temp;
if(!head)
{
head=(nodeptr)malloc(sizeof(struct node));
head->rlink=NULL;
head->data=x;
head->llink=NULL;
return;
}
temp=(nodeptr)malloc(sizeof(struct node));
temp->data=x;
temp->llink=NULL;
temp->rlink=head;
head->llink=temp;
head=temp;
}



void addTail(int x)
{
nodeptr temp;
if(!head)
{
head=(nodeptr)malloc(sizeof(struct node));
head->rlink=NULL;
head->data=x;
head->llink=NULL;
return;
}
temp=(nodeptr)malloc(sizeof(struct node));
temp->data=x;
nodeptr end;
for(end=head;end->rlink;end=end->rlink);
end->rlink=temp;
temp->llink=end;
temp->rlink=NULL;
}

nodeptr deleteEnd(){
nodeptr x;
if(!head)return NULL;
nodeptr end,temp;
for(end=head;end->rlink;end=end->rlink);
end->llink->rlink=NULL;
return end;
}

nodeptr deleteStart(){
nodeptr x;
if(!head->rlink){
x=head;
free(head);
printf("\nDELETED THE HEAD NODE !\n");
return x;
}
x=head;
head=head->rlink;
return x;
}



void displayS()
{
nodeptr temp;
for(temp=head;temp;temp=temp->rlink)
{
printf("\t-->%d\n",temp->data);
}
}

void displayE()
{
nodeptr end,temp;
for(end=head;end->rlink;end=end->rlink);

for(temp=end;temp;temp=temp->llink)
{
printf("\t-->%d\n",temp->data);
}
}





void main()
{
int ch,i;
nodeptr temp;
while(1)
{
printf("\n----------------------------\nEnter \n1.Add Node Head\n2.Add Tail node\n3.Delete End Node\n4.Delete start node\n5.Display From Start\n6.Display from end\n");
printf("\n\nEnter your choice : ");
scanf("%d",&ch);

switch(ch)
{
case 2:
printf("Enter the value you need to enter : ");
scanf("%d",&i);
addTail(i);
break;

case 1:
printf("Enter the value you need to enter : ");
scanf("%d",&i);
addHead(i);
break;


case 3:
temp=deleteEnd();
if(temp)
printf("The element deleted is : %d\n",temp->data);
else
printf("The list is empty ! \n");
break;

case 4:
temp=deleteStart();
if(temp)
printf("The element deleted is : %d\n",temp->data);
else
printf("The list is empty ! \n");
break;

case 5:
displayS();
break;

case 6:
displayE();
break;


default:
printf("Invalid choice \n");
break;
}
}
}

