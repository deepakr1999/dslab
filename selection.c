#define swap(x,y,temp) temp=x; x=y; y=temp;
#include<stdio.h>
void select(int a[],int n);
void main(){
int n,a[30],i;
printf("Enter the number of elements : ");
scanf("%d",&n);
printf("Enter the elements :\n");
for(i=0;i<n;i++){
printf("> ");
scanf("%d",&a[i]);
}
printf("\n--Sorted list--\n");
select(a,n);
for(i =0;i<n;i++)
{
printf("> %d\n",a[i]);
}
printf("\n");
}


void select(int a[],int n){
int i,j,temp,min;
for(i=0;i<n;i++){
min=i;
for(j=i;j<n;j++)
{
if(a[min]>a[j]){
min=j;
}//end if
}//end j
swap(a[i],a[min],temp);
}//end i
}
