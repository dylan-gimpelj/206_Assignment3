#include <stdlib.h>
#include <stdio.h>
#define ENGLISH 
#define FRENCH
//So I know my code doesn't print out the words correctly, but I put in some printf checks
//and it does assign the words properly in each loop to the latest node, but for some reason
//on the last loop when ***END*** is entered it overwrites them all and prints it out as many times as there are 
//nodes  
struct node {
	char *word;
	struct node *next; 
};

char *input;
int i; 
struct node* conduct; 
struct node* tail; 
struct node* root;  

int main(){
	root = (struct node*)malloc(sizeof(struct node)); //set it "null", just as a initial start to the list
	root->next = 0; 
	root->word = "";
	tail = (struct node*)malloc(sizeof(struct node)); 
	tail = NULL;
	input =(char*)malloc(100); 
	printf("Welcome to the infinite string storage program!"); 
	while(input != "***END***")
	{
		printf("Please input a single word."); 
		scanf("%s", input); //assume no word longer than 100 characters 
		if(strcmp(input,"***END***") == 0)
		{
			break;
		}
		struct node *conduct = (struct node*)malloc(sizeof(struct node));
		conduct->word = (char*)malloc(100);
		conduct->word = input;
		conduct->next = NULL; 
		if(tail==NULL){
				root = conduct;
				tail = conduct;
				//printf("Tail was null now filled with input"); 
				}
		else{
			tail->next = conduct; 
			tail = conduct; 
			//printf("Tail changed to newest node"); 
			}	
		//printf("%s", input); //it does print input 
		//printf("%s", tail->word);  
	}
	//printf("%s", root->word); 
	//print out all words
	conduct = root;
	//printf("%s", conduct->word); 
	while(conduct !=NULL){
		printf("%s", conduct->word); 
		conduct= conduct->next; 
		}
		printf("Done!"); 
		free(conduct);
		free(input);
		free(root);
		
	return(0);
}

