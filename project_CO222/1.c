#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>


typedef struct $
{
	char word[50][50];
	int length[50];

}strings;

enum bool {FALSE,TRUE};
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

void printpuzzle(strings* puzzle,int puzzle_row){
int i;
for(i=0 ;i<puzzle_row;i++){
  printf("%s",puzzle->word[i]);
}

}

void make_upper_case(char * word ,int size){
int i=0;
//printf("started to make upper cases\n");
for(i=0 ; i<size ;i++){
	word[i]=toupper(word[i]);
	//printf("%c\n",word[i] );
}

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
int max=0;
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

           if(puzzle.length[i]>max){
               max=puzzle.length[i];
            }

           puzzle_row++;

          }
 strings original_puzzle=puzzle;         

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
            make_upper_case(wordline,strlen(wordline)-1);
           strcpy(words.word[i],wordline);
           words.length[i]=strlen(words.word[i])-1;
           words_row++;
          }

printf("puzzle size %d  words size %d max=%d\n" ,puzzle_row,words_row,max);



    int row_counter1 = 0, col_counter1, currnt_word_row, crrnt_lttr_num, lttr_num;
    int num_hashes= 0;
    int ismatch=0;

    while(1){
              
   			 if(row_counter1 >= puzzle_row ){
        		break;
   			 }

        	col_counter1 = 0;

       		 while(1){
                        
        				if(col_counter1 >= max){
          					break;
        				}

                        
            			if( puzzle.word[row_counter1][col_counter1]== '#'){        //Looking for hashes and letters
                			
                			col_counter1++;
                			num_hashes=1;
               					 while(1){
                                         
                						if((puzzle.word[row_counter1][col_counter1] != '#') || (col_counter1 >= max)){      //Looking for continuous hashes and letters
                  								break; 
                						}
                  						num_hashes++;
                  						col_counter1++;

                						 } //Looping through set of words
                                            currnt_word_row=0;
                  						while(1){

                  							if(currnt_word_row>=words_row){
                  								break;
                  							}

                  							
                    						if( num_hashes == words.length[currnt_word_row] ){                     //Crosschecking word length with hashes and letters count
                        						lttr_num = num_hashes-1;
                       				 			ismatch=TRUE;

                       				 	 
  													crrnt_lttr_num = col_counter1-1;
                                              		while(1){

                                              			if(crrnt_lttr_num <= col_counter1-1-num_hashes){
                                              				break;
                                              			}
                        					    			if(puzzle.word[row_counter1][crrnt_lttr_num]!='*' && puzzle.word[row_counter1][crrnt_lttr_num]!='#' && puzzle.word[row_counter1][crrnt_lttr_num]!='\n') {                                    //checking whether there are letters among hashes
                                								if( puzzle.word[row_counter1][crrnt_lttr_num] != words.word[currnt_word_row][crrnt_lttr_num-col_counter1+num_hashes] ){  //Crosschecking with word if there are letters
                                  						  				ismatch = -1;
                                									}
                            								}
                            							crrnt_lttr_num--;
                        							}		


                       		
                        					if( ismatch == TRUE){
                            					//for( crrnt_lttr_num = col_counter1-1; crrnt_lttr_num > col_counter1-1-num_hashes; crrnt_lttr_num-- ){
                                					crrnt_lttr_num = col_counter1-1;

                                					while(1){

                                						if(crrnt_lttr_num <= col_counter1-1-num_hashes){
                                							break;

                                						}

                                					puzzle.word[row_counter1][crrnt_lttr_num] = words.word[currnt_word_row][lttr_num];               //Replacing the hashes with  letters of matched word
                                						lttr_num--;
                                						crrnt_lttr_num--;
                            						}
                            					words.length[currnt_word_row] = 100;   //After replacing word setting the word length as -1
                        
                    						
                }
                
            }
            currnt_word_row++;
        }
        
    }
 col_counter1++;   
}


row_counter1++;
}

//printf("Passed check 1\n");


 int row_counter2 = 0, col_counter2;
   num_hashes= 0;
  int ismatch2;

    while(1){
 		
 		if(row_counter2 >= puzzle_row ){
 			break;
 		}


        col_counter2 = 0;

        while(1){

         if( col_counter2>= max ){
         	break;
         }

            if( puzzle.word[row_counter2][col_counter2] == '#'){        //Looking for hashes and letters
                col_counter2++;
                num_hashes = 1;
                while(1){

                  if(puzzle.word[row_counter2][col_counter2] != '#' || row_counter2 >= puzzle_row ){
                  	break;

                  }
                    num_hashes++;
                    col_counter2++;
                }
                currnt_word_row=0;
                while(1){

                	if(currnt_word_row >= words_row){
                		break;
                	}


                    if( num_hashes == words.length[currnt_word_row]){
                        lttr_num = num_hashes -1;
                        ismatch2 = 0;
                        crrnt_lttr_num = row_counter2-1;
                        while(1){

                        	if(crrnt_lttr_num <= row_counter2-1-num_hashes){
                        		break;
                        	}	

                            if( puzzle.word[crrnt_lttr_num][col_counter2] !='*' && puzzle.word[crrnt_lttr_num][col_counter2] !='#' && puzzle.word[crrnt_lttr_num][col_counter2] !='\n'){                                    //checking whether there are letters among hashes
                                if( puzzle.word[crrnt_lttr_num][col_counter2] != words.word[currnt_word_row][crrnt_lttr_num-row_counter2+num_hashes] ){  //Crosschecking with word if there are letters
                                    ismatch2 = -1;
                                }
                            }
                            crrnt_lttr_num--;
                        }
                        if( ismatch2 == 0 ){

                        	crrnt_lttr_num = col_counter2-1;
                            while(1){
                            	if(crrnt_lttr_num<=row_counter2-1-num_hashes){
                            		break;
                            	}

                                puzzle.word[crrnt_lttr_num][col_counter2] = words.word[currnt_word_row][lttr_num];           //Replacing the hashes with  letters of matched word
                                lttr_num--;
                                crrnt_lttr_num--;
                            }
                            words.length[currnt_word_row] = 100;   //After replacing word setting the word length as -1
                       }
                    }currnt_word_row++;
                }
            }
            col_counter2++;
        }
        row_counter2++;

    }   


 





//int compatibilityCheck( int words_row,int puzzle_row,int patternWidth){
    int i1,i2;
    i1=i2=0;
    int check1=0; 
    int  col_counter3 = 0, row_counter3;

    for(i1;i1<words_row;i1++){                     //Looping through set of words
        i2=0;
        for(i2;i2<words_row;i2++){
                if( (words.length[i1] == words.length[i2]) && (i1 != i2) && words_row == 2 ){ 
                     //Checking for same length words

               //printf("entered\n");
                    check1 =FALSE;
                }
            //i2++;
        }
        //i1++;
    }

    while(1){
          
    	if( row_counter3 >= puzzle_row){
    		break;
    	}

        col_counter3=0;
        while(1){

        	if(col_counter3 >= max-1){
        		break;
        	}

            if( puzzle.word[row_counter3][col_counter3]!='*' && puzzle.word[row_counter3][col_counter3]!='#' &&puzzle.word[row_counter3][col_counter3]!='\n' && (check1 ==FALSE) ){          //Cross checking with patter whether puzzle is solvable if there are same length words
                check1 =TRUE;
            }
            col_counter3++;
        }
        row_counter3++;
    }
  




 
    int returnVal2 =TRUE;
       currnt_word_row=0;
    while(1){

    	if(currnt_word_row>=words_row){
    		break;
    	}

        if(words.length[currnt_word_row] != 100 ){         //Checking word Length if there is a element FALSEt equal -1 then puzzle is FALSEt solved
            returnVal2 =FALSE;
            //printf("going to break\n");
            break;

        }
        currnt_word_row++;
    }
   



if(check1==FALSE){
	//printf("original puzzle\n");
printpuzzle(&original_puzzle,puzzle_row);

} else if(returnVal2==FALSE){
  printf("IMMPOSIBLE\n");
 }else {
//printf("changed puzzle\n");
  printpuzzle(&puzzle,puzzle_row);
 } 


	return 0;
}



