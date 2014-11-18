#include <stdlib.h>
#include <stdio.h>

//DYLAN GIMPELJ 260519772 
//free all malloc variables
char *prompt;
char *command;
char *command1; 
char *sub1;
int i;
int x;

int main(){
prompt = "enter something after seeing this 'promptly', HA!"; 
x=5; //arbitrary number value as boolean (I like the number 5)
while(x==5){
	printf("%s", prompt); 
	command = (char*)malloc(100); 
	command1=(char*)malloc(100);
	sub1=(char*)malloc(100); 
	fgets(command, 100, stdin);
	printf("%s", command); 
	i =0; 
	//put in lowercase to evaluate properly without case sensitivity
		while(command[i]){
			command1[i]=tolower(command[i]);
			i++; 
			}
	i=0; //if the first part of the input is set prompt, we know the user wants the rest of the input to be the new prompt (after one space)
	if(strncmp(command1,"set prompt", 10)==0)
	{ //take the input from one space after "set prompt", make prompt = to it. 
		i=11;
		while(command[i])
		{ 
			sub1[i-11] = command[i];
			i++;
		}
		prompt=sub1; 
	}
	else if(strncmp(command1, "quit", 4)==0){ //quit program by making boolean x false
		x=0; 
	}
	else {
		system(command); 
	}
}

free(command);
free(command1);
free(sub1);
return(0); 
}

