#include <stdlib.h>
#include <stdio.h>

//display custom prompt when start
//shell has two commands SET PROMPT and QUIT
char *prompt;
char *command;
char *command1; 
char *subcmd1;
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
	
	if(strncmp(command1,"set prompt", 10)==0)
	{
		prompt = command; 
	}
	else if(strncmp(command1, "quit", 4)==0){
		x=0; 
	}
	else {
		printf("Something else"); 
	}
	
//have to also split string to check "set prompt"
//memcpy(subcmd1, &command1[0], 9); 
//subcm1[9]= '\0';
// potword = siphonstring(10-end);
 //need efficient way to scan until end of words/input 
//also could siphon to check if ==quit
	//memcpy(cmdquit, &command1[0], 3);
	//cmdquit[3]='\0';
	
	
	//if(subcmd1.equals("set prompt"))
	//{//get substring of scanned char[] only word-simply siphon the original scanf string, take the second part!
		//prompt = potword;
	//}
	//else if(cmdquit.equals("quit")
	//{
		//break; //return to unix command line
	//}
	//else{//export to unix command line through system() fx
		//char cmd[50];
		//strcpy(cmd, scanf("c", &command1)); 
		//system(cmd); ?
	//}
}
return(0); 
}

