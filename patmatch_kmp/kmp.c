#include<stdio.h>
#include<string.h>
#define max_string_size 100
#define max_pat_size 100
int pmatch();
void fail();

int failure[max_pat_size];
char string[max_string_size];
char pat[max_pat_size];

int pmatch(char *string,char *pat){
	int i=0,j=0;
	int lens=strlen(string);
	int lenp=strlen(pat);
	while(i<lens && j<lenp)
	{
	if(string[i]==pat[j]){
		i++;
		j++;
	}
	else if(j==0)
		i++;
	else
		j=failure[j-1]+1;
	}
	return ((j==lenp)?(i-lenp):-1);
}


void fail(char *pat){
	int i,j,n=strlen(pat);
	failure[0]=-1;
	for(j=1;j<n;j++)
	{
		i=failure[j-1];
		while((pat[j]!=pat[i+1])&&(i>=0))
			i=failure[i];
		if(pat[j]==pat[i+1])
			failure[j]=i+1;
		else
			failure[j]=-1;
	}
}



int main()
{
int x;
printf("Enter the string : ");
scanf("%s",string);
printf("Enter the pattern : ");
scanf("%s",pat);

fail(pat);
x=pmatch(string,pat);
printf("\nThe position is %d\n",x);
return 0;
}
