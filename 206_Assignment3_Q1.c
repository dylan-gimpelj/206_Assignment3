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

int main(){
ptr = fopen("scantest.txt", "r"); 
//printf("Opened file"); 
len=100;
//printf("Assigned len");
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
		{//print checked, it works!
			 
			name[i]=line[i]; //since name at beginning of line can assume at same point.   		 
		} 
		else if(line[i]==','||line[i]==NULL) //char[] ready to be converted into Double, clear entry[]
		{
			
			//need to reset entry, make it empty so next data entry after , can fill it 
			entptr = entry; 
			double add = atof(entptr);
			//add double to sum
			total = total+add; 
			leng++;
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
				for(k=0; k<10;k++){
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
	avg = total/(leng-1); 
	printf("%s", name);
	printf(" "); 
	printf("%.2f", avg); 
	}
fclose(ptr); 
return (0);
}
	
