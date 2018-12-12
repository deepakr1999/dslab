#include<stdio.h>
#include<string.h>
int main(){
char s[50],pat[50];
int x;
printf("Enter the string : ");
scanf("%s",s);
printf("Enter the pattern : ");
scanf("%s",pat);
x=nfind(s,pat);

printf("String :%s\nPattern :%s\nPattern starts from :%d\n",s,pat,x);
return 0;
}


int nfind(char *string , char * pat){
	int i,j,start=0;
	int lasts=strlen(string)-1;
	int lastp=strlen(pat)-1;
	int endmatch=lastp;
	for(i=0;endmatch<=lasts;endmatch++,start++){
		if(string[endmatch]==pat[lastp])
			for(j=0,i=start;string[i]==pat[j]&&j<lastp;i++,j++);
			if(j==lastp)
				return start;
			}
				return -1;
}
