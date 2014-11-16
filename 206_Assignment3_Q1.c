#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

//use FILE ptr to locate txt file
//use fopen function 
FILE *ptr;
char *line; 
size_t len;
int read; 
int c;
char entry[10]; 
double total[100]; 
char name[30];
int leng;
int leng1; 
int i;

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

int lengthdoub(const double array[]) {
  int count = 0;
  while(array[count]) count++;
  return count;
}

int main(){
ptr = fopen("scantest.txt", "r"); 
len=1000;
line = (char *)malloc(100); 
while((c = fgetc(ptr)) != EOF){ /*while readable char still in file do program*/
	if(ptr==NULL){
	exit(EXIT_FAILURE);
		}
	while(fgets(line, len, ptr)!=NULL){
		 
		leng = length(line);
		
		for(i=0;i<leng;i++){
		//until first ,  add into name char*
		//once first comma, start adding into entry, parse into double, add to total.
		//once endline reached, add sum of total, divide by number of entries, printf(string+number)
		//repeat for all lines of the txt file. 
		//name: 32-47, 58-126
		if(((line[i]>31&&line[i]<48)||(line[i]>57&&line[i]<127))&&(line[i]!=44)) /* if name of researcher */
		{
			 
			name[i]=line[i]; //since name at beginning of line can assume at same point.  
		
		 //does this work? 
		} 
		else if(line[i]==',') //char[] ready to be converted into Double, clear entry[]
		{
			//printf("Is a comma"); 
			//need to reset entry, make it empty so next data entry after , can fill it 
			double add = atof(entry);
			//add double to []
			for(i=0;i<100;i++){
				if(total[i]==0.0){
					total[i]=add;
				}
			for(i=0;i<10;i++){//clear the entry [] for the next entry
			entry[i]==NULL;
			}
		}
		}
		else if(line[i]>47&&line[i]<58)
			{ //it's part of a data entry (if it's >9 basically (48-57 ascii ) 
				for(i=0; i<10;i++){
					if(entry[i]==NULL){
					entry[i]=line[i];
					break;
					}
				}	
		}
		leng1= lengtharr(name); 
	for(i=0; i<leng1;i++){
	printf("%c", name[i]);
	}
	//now find average of values and print out with name of researcher
	//double sum=0;
	//double avg=0;
	//leng=lengthdoub(total);
	//for(int i =0; i<leng;i++){
		//sum = sum + total[i];
	//}
	//avg=(sum/leng); 
	//printf(name + " " + sum); 
	//clear all arrays/pointers
	}
	 
}

}
return (0);
}
	