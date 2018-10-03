#define swap(x,y,temp)temp=x; x=y; y=temp;
#include<stdio.h>
void selectSort(int [],int);
void main(){
int arr[20],i,n;
printf("-----Selection Sort-----\n");
printf("Enter the number of elements :");
scanf("%d",&n);
printf("Enter the elements : \n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("The sorted array is  : \n");
selectSort(arr,n);
for(i=0;i<n;i++)
{
printf(">%d\n",arr[i]);
}
printf("\n");
}

void selectSort(int arr[],int n){
int temp,i,j,min;
for(i=0;i<n;i++)
{
min=i;
for(j=i;j<n;j++)
{
if(arr[j]<arr[min]){
min=j;
}
}//end j
//temp=arr[i];
//arr[i]=arr[min];
//arr[min]=temp;
swap(arr[i],arr[min],temp);
}//end i
}

