#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	
	int i,j,k,l;
	int row,col;
	char block[20][20];
	char word_list[20][20];
	int count;
	int letter_count=0;
	int width=0,height=0;
	int block_width[20];

	i=0;
	int max=0;
	fgets(block[i],100,stdin);
	i++;
	for(i; i<25 ;i++)
	{
		fgets(block[i],100,stdin);
		++height;
        if(block[i][0]=='\n'){
			//printf("%d\n",isspace(block[i][0]));
			break;
		}else if(strlen(block[i])-1>=max){
			max=strlen(block[i]);
		}
		block_width[i]=strlen(block[i])-1;
		
	}
	//printf("exited the 1st loop\n");
	height=height-1;
	width=max-1;
	
	i=0;
	while(1)
	{
		//printf("inside 2nd loop\n");
		fgets(word_list[i],100,stdin);
		letter_count = letter_count + strlen(word_list[i])-1;
		if(strlen(word_list[i])==1){
			break;
		}
		++i;
	}
	int length = i;
	for(i=0;i<height;++i)
	{
		for(j=0;j<width;++j)
		{
			if(block[i][j] != '*' && block[i][j] != '#'){
					block[i][j] = '*';
			}
		}
	}

	for(i=0;i<height;++i)
	{
		count=0;
		for(j=0;j<width;++j)
		{
			if(block[i][j]!='*'){
				if(j==0){
					if(block[i][j+1] != '*')
						++count;	
				}
				else if(j==width){
					if(block[i][j-1] != '*')
						++count;
				}
				else{
					if(block[i][j-1] != '*' || block[i][j+1] != '*')
						++count;
				}
			}
		}

		for(k=0;k<length;++k)
		{
			if(strlen(word_list[k])-1==count){
				l=0;
				for(col=0;l!=count;++col)
				{
					if(block[i][col]!='*'){
						if(block[i][col]!='#' && block[i][col]!=word_list[k][l]){
								printf("1-IMPOSSIBLE\n");
								//return 0;
						}
						--letter_count;
						block[i][col]=word_list[k][l];
						++l;
					}
				}
			if(strlen(word_list[k]) == strlen(word_list[k+1])){
				strcpy(word_list[k],"AAAAAAAAAAAA");
			}
			break;
			}
		}

	}
	for(j=0;j<width;++j)
	{
		count=0;
		for(i=0;i<height;++i)
		{
			if(block[i][j]!='*'){
				if(i==0){
					if(block[i+1][j] != '*')
						++count;	
				}
				else if(i==height-1){
					if(block[i-1][j] != '*')
						++count;
				}
				else{
					if(block[i-1][j] != '*' || block[i+1][j] != '*')
						++count;
				}
			}
		}

		for(k=0;k<length;++k)
		{
			if(strlen(word_list[k])-1==count){
				l=0;
				for(row=0;l!=count;++row)
				{
					if(block[row][j]!='*'){
						if(block[row][j]!='#' && block[row][j] != word_list[k][l]){
							printf("2-IMPOSSIBLE\n");
							//return 0;
						}
						--letter_count;
						block[row][j]=word_list[k][l];
						++l;
					}
				}
			if(strlen(word_list[k]) == strlen(word_list[k+1])){
				strcpy(word_list[k],"AAAAAAAAAAAA");
			}
			break;
			}
		}
	}
	if(letter_count!=0){
		printf("3-IMPOSSIBLE\n");
		//return 0;
	}

	for(i=0;i<2;++i)
	{
		printf("%s\n", word_list[i]);
	}
	for(i=0;i<height;++i)
	{
		for(j=0;j<block_width[i];++j)
		{
			printf("%c", block[i][j]);
		}
	printf("\n");
	}
	
	return 0;
}
