/*
Author: Hisni Mohammed M.H.  (E/15/131)
CO222 | Project | Crossword Puzzle Solver
*/

#include<stdio.h>
#include<string.h>
#include <ctype.h>

char pattern[15][15];       //2D Array for save the Pattern
char words[15][15];         //2D Array for save the set of words
int wordLen[15];            //Array for save the length of words

int GetPattern();                           //Function to get the pattern from standard input
int InputPatternCheck( int RowNo );         //Function to check for validity of input Pattern input & manipulating
int getWords();                             //Function to get the set of words from standard input
int InputWordCheck( int WordNo );           //Function to check for validity of input words & manipulating
int compatibilityCheck( int numWords, int patternHeight, int patternWidth );    //Function to check the words and pattern for compatibility
void checkRow( int patternHeight, int patternWidth, int numWords );             //Function to cross-check pattern horizontally with words and replace if possible
void checkColumn( int patternHeight, int patternWidth, int numWords );          //Function to cross-check pattern vertically with words and replace if possible
int wordCheck( int numWords );              //Function to check whether all words are replaced & confirming puzzle solved or not
void printPattern();                        //Function to print the pattern

int main(){
    int returnVal, patternHeight, patternWidth, numWords;

    returnVal = GetPattern();           //Getting pattern from standard input
    if (returnVal == -1 ){
        return returnVal;               //Exiting the program if invalid input
    }else{
        patternHeight = returnVal;
        patternWidth = strlen( pattern[0] ) -1 ;
    }

    returnVal = getWords();             //Getting words from standard input
    if (returnVal == -1 ){
        return returnVal;               //Exiting the program if invalid input
    }else{
        numWords = returnVal;
    }

    returnVal = compatibilityCheck( numWords, patternHeight, patternWidth);     //Check whether given pattern is solvable with given words
    if (returnVal == -1 ){
        printPattern( patternHeight, numWords );                    //Printing the pattern without solving if there are more than one possible way to solve
    }else{
        checkRow( patternHeight, patternWidth, numWords );          //Crosschecking pattern horizontally
        checkColumn( patternHeight, patternWidth, numWords );       //Crosschecking pattern vertically

        returnVal = wordCheck( numWords );              //Checking whether puzzle is solved
        if (returnVal == -1 ){
            printf("IMPOSSIBLE");
        }else{
            printPattern( patternHeight, numWords );    //Printing solved Puzzled
        }
    }
    return 0;
}

int GetPattern(){
    int returnVal, rowCount = 0;
    while( 1 ){
        fgets(pattern[rowCount],sizeof(pattern[rowCount]),stdin);   //Read from standard input

        returnVal = InputPatternCheck( rowCount );          //Checking whether pattern is valid or not

        if (returnVal == -1 ){
            break;
        }
        else if( strcmp(pattern[rowCount],"\n") == 0 ){
            returnVal = rowCount;                          //Storing pattern height as return value
            break;
        }
        rowCount++;
    }
    return returnVal;       //Returning pattern height if valid or otherwise -1
}

int InputPatternCheck( int RowNo ){
    int patternX, returnVal = 0;

    for( patternX=0; patternX < (strlen(pattern[RowNo])-1); patternX++){    //Looping through the pattern horizontally
        if( (pattern[RowNo][patternX] != '*') && (pattern[RowNo][patternX] != '#') && (!isalpha(pattern[RowNo][patternX]))  ){     //Checking for invalid characters
            returnVal = -1;
            break;
        }
        else if( isalpha(pattern[RowNo][patternX]) ){
            pattern[RowNo][patternX] = toupper(pattern[RowNo][patternX]);   //changing lowercase letters to uppercase letters
        }
    }
    return returnVal;
}

int getWords(){
    int returnVal, WordNo = 0;

    while( 1 ){
        fgets(words[WordNo],sizeof(words[WordNo]),stdin);       //Read from standard input
        wordLen[WordNo] = strlen(words[WordNo])-1;              //Calculating word length

        returnVal = InputWordCheck( WordNo );                   //Checking whether words are valid or not

        if (returnVal == -1 ){
            break;
        }
        else if( strcmp(words[WordNo],"\n") == 0 ){
            returnVal = WordNo;     //Storing word count as return value
            break;
        }
        WordNo++;
    }
    return returnVal;               //Returning word count if valid or otherwise -1
}

int InputWordCheck(int WordNo){
    int wordsX, returnVal = 0 ;

    for( wordsX=0; wordsX < (strlen(words[WordNo])-1); wordsX++){       //Lopping through the characters of a word
        if( !isalpha(words[WordNo][wordsX]) ){                          //Checking for invalid characters
            returnVal =-1;
            break;
        }
        else{
            words[WordNo][wordsX] = toupper(words[WordNo][wordsX]);     //changing the case of the letters to uppercase
        }
    }
    return returnVal;
}

void checkRow(int patternHeight, int patternWidth, int numWords){
    int patternY = 0, patternX, wordNo, tempX, wordsX;
    int count = 0, result;

    while( patternY < patternHeight ){              //Looping the pattern vertically
        patternX = 0;
        while( patternX < patternWidth ){           //Looping the pattern horizontally
            if( (pattern[patternY][patternX] != '*') && (pattern[patternY][patternX] != '\n') ){        //Looking for hashes and letters
                count=1;
                patternX++;
                while( (pattern[patternY][patternX] != '*') && (pattern[patternY][patternX] != '\n') && (patternX < patternWidth) ){      //Looking for continuous hashes and letters
                    count++;
                    patternX++;
                }
                for( wordNo=0; wordNo < numWords; wordNo++ ){           //Looping through set of words
                    if( count == wordLen[wordNo] ){                     //Crosschecking word length with hashes and letters count
                        wordsX = count -1;
                        result=0;
                        for( tempX = patternX-1; tempX > patternX-1-count; tempX-- ){
                            if( isalpha(pattern[patternY][tempX]) ){                                    //checking whether there are letters among hashes
                                if( pattern[patternY][tempX] != words[wordNo][tempX-patternX+count] ){  //Crosschecking with word if there are letters
                                    result = -1;
                                }
                            }
                        }
                        if( result == 0 ){
                            for( tempX = patternX-1; tempX > patternX-1-count; tempX-- ){
                                pattern[patternY][tempX] = words[wordNo][wordsX];               //Replacing the hashes with  letters of matched word
                                wordsX = wordsX-1;
                            }
                            wordLen[wordNo] = -1;   //After replacing word setting the word length as -1
                        }
                    }
                }
            }
            patternX++;
        }
        patternY++;
    }
}

void checkColumn(int patternHeight, int patternWidth, int numWords){
    int patternX = 0, patternY, wordNo, tempY, wordsX;
    int count = 0, result;

    while( patternX < patternWidth ){               //Looping the pattern horizontally
        patternY = 0;
        while( patternY < patternHeight ){          //Looping the pattern vertically
            if( (pattern[patternY][patternX] != '*') && (pattern[patternY][patternX] != '\n') ){        //Looking for hashes and letters
                count = 1;
                patternY++;
                while( (pattern[patternY][patternX] != '*') && (pattern[patternY][patternX] != '\n') && (patternY < patternHeight) ){     //Looking for continuous hashes and letters
                    count++;
                    patternY++;
                }
                for( wordNo=0; wordNo < numWords; wordNo++ ){
                    if( count == wordLen[wordNo] ){
                        wordsX = count -1;
                        result = 0;
                        for( tempY = patternY-1; tempY > patternY-1-count; tempY-- ){
                            if( isalpha(pattern[tempY][patternX]) ){                                    //checking whether there are letters among hashes
                                if( pattern[tempY][patternX] != words[wordNo][tempY-patternY+count] ){  //Crosschecking with word if there are letters
                                    result = -1;
                                }
                            }
                        }
                        if( result == 0 ){
                            for( tempY = patternY-1; tempY>patternY-1-count; tempY-- ){
                                pattern[tempY][patternX] = words[wordNo][wordsX];           //Replacing the hashes with  letters of matched word
                                wordsX = wordsX-1;
                            }
                            wordLen[wordNo] = -1;   //After replacing word setting the word length as -1
                        }
                    }
                }
            }
            patternY++;
        }
        patternX++;
    }
}

void printPattern(int patternHeight,int numWords ){
    int patternY;

    for( patternY=0; patternY<patternHeight ;patternY++){
        printf("%s",pattern[patternY]);     //Printing the pattern line by line
    }
}

int wordCheck( int numWords ){
    int returnVal = 0, wordNo;

    for(wordNo=0; wordNo<numWords; wordNo++){
        if(wordLen[wordNo] != -1 ){         //Checking word Length if there is a element not equal -1 then puzzle is not solved
            returnVal = -1;
        }
    }
    return returnVal;
}

int compatibilityCheck( int numWords,int patternHeight,int patternWidth){
    int x1 = 0, x2, returnVal = 0, patternX = 0, patternY;

    while(x1<numWords){                     //Looping through set of words
        x2=0;
        while(x2<numWords){
                if( (wordLen[x1] == wordLen[x2]) && (x1 != x2) && numWords == 2 ){      //Checking for same length words
                    returnVal = -1;
                }
            x2++;
        }
        x1++;
    }

    while( patternY < patternHeight ){      //Looping through pattern
        patternX=0;
        while( patternX < patternWidth-1 ){
            if( (isalpha(pattern[patternY][patternX])) && (returnVal == -1) ){          //Cross checking with patter whether puzzle is solvable if there are same length words
                returnVal = 0;
            }
            patternX++;
        }
        patternY++;
    }
    return returnVal;
}

