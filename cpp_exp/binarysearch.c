#include<stdio.h>
int main(){
int n,i,arr[50],k;
printf("------BINARY SEARCH-------\n");
printf("Enter the number of elements  : ");
scanf("%d",&n);
printf("----------------------------\n");
printf("Enter the elements in sorted order : \n");
for(i=0;i<n;i++)
{
printf("Enter the element at %d :",i+1);
scanf("%d",&arr[i]);
}
printf("Enter the key value : ");
scanf("%d",&k);
int res=binary(arr,0,n,k);
if(res==-1){
printf("Element is not present in the list!\n");
}
else{
printf("The element is present at  : %d\n",res+1);
}
}

int binary(int a[],int l,int h,int k){
int mid;
if(h>l){
mid=(l+h)/2;
if(k==a[mid]){
return mid;
}
else if(k<a[mid]){
return binary(a,l,mid-1,k);
}
else if(k>a[mid]){
return binary(a,mid+1,h,k);
}
}
else
return -1;
}
