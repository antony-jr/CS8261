#include <stdio.h>
#include <string.h>
void swapc(char *p1 , char *p2){
	char c = *p1;
	*p1 = *p2;
	*p2 = c;
}
short isspecial(char c){
	return !((c >= 'a' && c <= 'z') ||
	         (c >= 'A' && c <= 'Z'));
}
void main(){
	char s[100],*front = s,*back = NULL;
	printf("Enter a string: ");
	scanf("%s" , s);
	back = strlen(s) - 1 + s;
	while(front < back){
		if(isspecial(*front)){
			++front;
		}else if(isspecial(*back)){
			--back;
		}else{
			swapc(front++ , back--);
		}
	}
	printf("The reversed string: %s\n" , s);
}
