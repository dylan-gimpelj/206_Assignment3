#include <stdlib.h>
#include <stdio.h>

//display custom prompt when start
//shell has two commands SET PROMPT and QUIT
char *prompt;
char *command;
char *command1; 
char *sub1;
char *sub2; 
int i;
int x;

int main(){
prompt = "enter something after seeing this promptly, HA!"; 
x=5; 
while(x==5){
	printf("%s", prompt); 
	command = (char*)malloc(100); 
	command1=(char*)malloc(100);
	fgets(command, 100, stdin);
	printf("%s", command); 
	i =0; 
	//put in lowercase to evaluate properly without case sensitivity
		while(command[i]){
			command1[i]=tolower(command[i]);
			i++; 
			}
	i=0;
	if(strncmp(command1,"set prompt", 10)==0)
	{
		i=11;
		while(command[i]!=NULL){
			sub1[i-11] = command[i];
			i++;
		}
		prompt = sub1; 
	}
	else if(strncmp(command1, "quit", 4)==0){
		x=0; 
	}
	else {
		printf("Something else"); 
	}
}
return(0); 
}

