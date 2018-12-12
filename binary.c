#include<stdio.h>
void main(){
int a[30],i,n,k;
printf("Enter the number of elements :");
scanf("%d",&n);
printf("Enter the elemetns \n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the element to find :");
scanf("%d",&k);
k=binary(a,0,n,k);
if(k>-1)
printf("Element at %d\n",k+1);
else
printf("Element not found in list!\n");
}

int binary(int a[],int l,int h,int k){
int m,temp;
if(l<h){
m=(l+h)/2;

if(k==a[m]){
return m;
}
else if(a[m]>k){
return binary(a,l,m-1,k);
}
else if(k>a[m]){
return binary(a,m+1,h,k);
}
}
else
return -1;
}
