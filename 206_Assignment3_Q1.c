#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
//DYLAN GIMPELJ 260519772
//I decided to max out some of the variables like the length of the line, the name, and the potential data entries 
//As you can see down in the main, with malloc, I hope that's okay! 

FILE *ptr;
char *usrfile; 
char *line; 
size_t len;
char entry[10]; 
char *entptr;
double total; 
char *name;
int leng;
int i;
int j;
int k; 
double avg;

int lengtharr(char array[]) {
  int count = 0;
  while(array[count]) count++;
  return count;
}

int length(const char *array) {
  int count = 0;
  while(array[count]) count++;
  return count;
}

int main(int argc, char *argv[]){
usrfile = (char *)malloc(50); //assume text file name won't be >50 chars
usrfile = argv[1]; 
ptr = fopen(usrfile, "r");  
len=100;
line = (char *)malloc(100);
name = (char *)malloc(50);
entptr = (char*)malloc(10); 
total=0.0;
avg=0.0; 
	while((fgets(line, len, ptr)!=NULL)){
		total =0.0;
		leng=0; 
		for(i=0;i<100;i++){
		if(((line[i]>31&&line[i]<48)||(line[i]>57&&line[i]<127))&&(line[i]!=44)) /* if name of researcher */
		{
			 
			name[i]=line[i]; //since name at beginning of line can assume at same point.   		 
		} 
		else if(line[i]==','||line[i]==NULL) //char[] ready to be converted into Double, clear entry[]
		{
			//convert entry which is a char* to double
			entptr = entry; 
			double add = atof(entptr);
			//add double to sum
			total = total+add; 
			leng++; //track for averaging purposes
			for(j=0;j<10;j++){//clear the entry [] for the next entry
			entry[j]=NULL;
			}
			if(line[i]==NULL){
				i=100;
				}
		}
		else if(line[i]>47&&line[i]<58)
			{ //it's part of a data entry (if it's >9 basically (48-57 ascii ) 
				//printf("%c", line[i]); 
				for(k=0; k<10;k++){ //we know the first null spot will be the next multiple of 10 space
					if(entry[k]==NULL){
					entry[k]=line[i];
					k=10; 
					}
				}	
			 
			}
		else{ //some other irrelevant character 
		i++;
		}
		
	}
	avg = total/(leng-1); //get the average for the experimenter
	printf("%s", name); //print their name, then their average
	printf(" "); 
	printf("%.2f", avg); 
	}

fclose(ptr); //close the file we're done!
free(usrfile);
free(line);
free(name);
free(entptr); 
return (0);
}
	
