#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>


typedef struct $
{
	char word[50][50];
	int length[50];

}strings;

int validinput1(char* word,int size){

int count=0;
int returnval=0;
for(count=0 ; count<size ; count++){
   if(word[count]!='\n' &&  word[count]!='*' && word[count]!='#'){
   	returnval=0;
   	break;
   	
   }else returnval++;

}

if(returnval==0){
	return 0;
} else return 1;

}

int validinput2(char* word,int size){

int count=0;
int returnval=0;
for(count=0 ; count<size ; count++){
   if(!isalpha(word[count]) && word[count]!='\n'){
   	returnval=0;
   	break;
   	
   }else {
            toupper(word[count]);
            returnval++;
     }

}

if(returnval==0){
	return 0;
} else return 1;

}



int isnewline(char* word){

if(word[0]=='\n'){
	return 1;
} else return 0;

}

int findmaxwidth(int* length,int size){

int max=0;
int count;
for (i = 0; i < size; ++i)
{
	if(length[i]>max){
		max=length[i];
	}

}

return max;

}



int main(){

int checkval1=1;
int checkval2=1;
int j=0;
int i=0;
int words_row=0;
int puzzle_row=0;
strings words={};
strings puzzle={};
char puzzleline[50]={};
printf("enter puzzle\n");   
    for(i=0 ; i<50 ; i++){
         fgets(puzzleline,50,stdin);
           
           if(!validinput1(puzzleline,strlen(puzzleline))){
           	//printf("invalid input\n");
           	checkval1=0;
           	break;
           }

            if (isnewline(puzzleline)){
            	//printf("exited from loop1\n");
           	break;
           }

           strcpy(puzzle.word[i],puzzleline);
           puzzle.length[i]=strlen(puzzle.word[i])-1;
           puzzle_row++;

          }

char wordline[50]={};
printf("enter words \n");   
    for(i=0 ; (i<50 ) && (checkval1==1) && (checkval2==1) ; i++){
         fgets(wordline,50,stdin);
            if(!validinput2(wordline,strlen(wordline))){
           	checkval2=0;
           	break;
           }

            if (isnewline(wordline)){
            	//printf("exited from loop2\n");
           	break;
           }

           strcpy(words.word[i],wordline);
           words.length[i]=strlen(words.word[i]);
           words_row++;
          }

//printf("puzzle size %d  words size %d\n" ,puzzle_col,words_col);

char temp[50]={};
int temp_size=0;
for(i=0;i<49 ;i++){
    for(j=0;j<49 ;j++){
    	if(words.length[i] < words.length[i+1]){
    		strcpy(temp,words.word[i]);
    		temp_size=words.length[i];
    		strcpy(words.word[i],words.word[i+1]);
    		words.length[i]=words.length[i+1];
    		strcpy(words.word[i+1],temp);
    		words.length[i+1]=temp_size;

    	}
    }

}

int count;
int placelenth[50];
for(i=0;i<puzzle_row ;i++){
	count=0;
    for(j=0;j<puzzle.length[i] ;j++){
          
          if(puzzle.word[i][j]=='#'){
          	count++;
          	j++;
          	  for(j;j<puzzle.length[i];j++){

          	  	if(puzzle.word[i][j]=='#'){
                 count++;
          	  	}else 
          	  	    j=50;
          	  	    placelenth[i]=count;
          	  	    break;

          	  }
          } 


	 }
}

int maxlength_puzzle=findmaxwidth(puzzle,puzzle_row);

printf("\n/////////////////\n");





/*

    for(i=0 ; (i<5 ) && (checkval1==1) ; i++){
      printf("%d\n",placelenth[i]);

    }
*/
	return 0;
}