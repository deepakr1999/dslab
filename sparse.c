#define max 100
#include<stdio.h>

typedef struct{
int col,row,val;
} sparse;
sparse a[max];
sparse b[max];
void transpose();
void main(){
int i,n;
printf("----SPARSE MATRIX---\n");
printf("Enter the number of elements(R|C|V) :");
scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].val);
n=a[0].val;
printf("--Enter the elements--\n");
for(i=1;i<n+1;i++)
{
printf("ROW | COL | VAL \n");
scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].val);
}
printf("Matrix value :\n");
for(i=0;i<n+1;i++){
printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].val);
}
transpose();
printf("Transpose : \n");
for(i=0;i<n+1;i++){
printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].val);
}
}

void transpose(){
int i,j,k,n;
b[0].val=a[0].val;
b[0].row=b[0].col;
b[0].col=b[0].row;
n=a[0].val;
if(n>=1){
k=1;
for(i=0;i<n;i++){
for(j=1;j<=n;j++)
{
if(a[j].col==i)
{
b[k].row=a[j].col;
b[k].col=a[j].row;
b[k].val=a[j].val;
k++;
}
}//end j
}//end i
}
}

