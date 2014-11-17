#include <stdlib.h>
#include <stdio.h>
#IF ENGLISH
#define ENGLISH
#ELSE 
#define FRENCH
//need to make a linked-list struct
//with char[] word and struct linked-list *next 
struct node {
	char *word;
	struct node *next; 
	srtruct node *prev; 
};

typedef struct node userswords; 
char *input;
int i;

void main(){
	struct node *root;
	struct node *conduct; 
	input =(char*)malloc(100); 
	printf("Welcome to the infinite string storage program!"); 
	while(input != "***END***")
	{
		printf("Please input a single word."); 
		fgets(input,100,stdin); //assume no word longer than 100 characters 
		if(strcmp(input,"***END***, 9) == 0)
		{
			break;
		}
		conduct.word = (char*)malloc(100); 
		for(i=0; i<100;i++)
		{
			//65-90, 97-122
			if((input[i]>64&&input[i]<91)||(input[i]>96&&input[i]<123)){
				word[i] = input[i];
				}
			else{//stop adding to the word char*
				i=100; 
			}
		}
		//need to make new struct node, with no next, empty word*
		
	}
	//print out all words
	while(conduct!=NULL){
		printf("%s", conduct.word); 
		conduct= conduct.next; 
		}
//

