

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>



int main(){
	char s[50]={};
int i;
for(i=0; i<5 ;i++){
	fgets(s,50,stdin);
	printf("%s",s);
}
}
