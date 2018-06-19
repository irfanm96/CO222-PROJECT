#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>


typedef struct $
{
	char word[50][50];
	int length[50];

}strings;



int main(){

int checkval1=1;
int checkval2=1;
int j=0;
int i=0;
strings str={};
strings puzzle={};
char puzzleline[25]={};
printf("%s",puzzleline);
printf("enter puzzle\n");
while(checkval1 && checkval2){

    
    for(i=0 ; i<25 ; i++){
         scanf("%c",&puzzleline[i]);
         scanf("%c",&puzzleline[i+1]);
         //printf("%s\n",puzzleline);
 
         if( puzzleline[i]!='*'  && puzzleline[i]!='#'  && puzzleline[i]!='\n'){
         	printf("invalid inputs\n");
         	checkval1=0;
         	break;
         } else if(puzzleline[i+1]!='*' && puzzleline[i+1]!='#'  && puzzleline[i+1]!='\n'){
         	
         	printf("invalid inputs\n");
         	checkval1=0;

         	break;

         }else if (puzzleline[i]=='\n' && puzzleline[i+1]=='\n') {
         	checkval2=0;
         	//printf("head to enter words\n");
         	break ;
         } else {

            
           			if(isspace(puzzleline[i])){

           				strcpy(puzzle.word[j],puzzleline);
           				printf("%s",puzzleline);
           				//printf("%s\n",puzzle.word[j] );
           				i=0;
           				break;
           			} else if(isspace(puzzleline[i+1])){
           				strcpy(puzzle.word[j],puzzleline);
           				printf("%s",puzzleline);
           				i=0;
           				break;
           			} else i=i+2;


           		     



         }

j++;


    }



}


//-----------------------------------//
int k=0;
// TAKING INPUT FOR PUZZLE WORDS 
printf("enter words\n");
char temp[25]={};
while(!checkval2){
//printf("%d",j); 
//printf("inside 2nd loop\n");
       
		
		for(i=0 ; i<25 ; i++){
           scanf("%c",&temp[i]);
           scanf("%c",&temp[i+1]);

           if(isspace(temp[i]) && isspace(temp[i+1])){
           	checkval2=1;
           //	printf("broken form 2nd loop\n");
           	break;
           } else { 
           

           if(isspace(temp[i])){
           	//printf("you pressed enter\n");
           	strcpy(str.word[k],temp);
           	str.length[k]=strlen(temp);
           	break;
           }
           
           if(isspace(temp[i+1])){
           	//printf("you pressed enter\n");
           	strcpy(str.word[k],temp);
           	str.length[k]=strlen(temp);
           	//printf("%c",temp[i+1] );
           	break;
           }


           i++;
          }
		}
//printf("%d\n",k);
       k++;
      
	}

int count1;


//printf("height of puzzle %d\n",j);
//printf("height of words %d\n",k);

int chckval3=1;

	for(i=0 ; i<50 ;i++){
    if(strlen(puzzle.word[i])==0){
    	printf("%d",i);
    	break;
    }
   }

//printf("height of puzzle %d\n",i);

for(i=0 ;i<50;i++){

printf("%s",puzzle.word[i]);
}



	return 0;
}