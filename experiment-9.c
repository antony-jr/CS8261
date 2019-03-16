#include <stdio.h>
#include <string.h>
#include <ctype.h>
void swapc(char *p1 , char *p2){
	char c = *p1;
	*p1 = *p2;
	*p2 = c;
}
void main(){
	char s[100],*front = s,*back = NULL;
	printf("Enter a string: ");
	scanf("%s" , s);
	back = strlen(s) - 1 + s;
	while(front < back){
		if(!isalpha(*front)){
			++front;
		}else if(!isalpha(*back)){
			--back;
		}else{
			swapc(front++ , back--);
		}
	}
	printf("The reversed string: %s\n" , s);
}
