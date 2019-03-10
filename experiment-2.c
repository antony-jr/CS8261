#include <stdio.h>
void main(){
	int a , b , c , d;
	printf("Enter value for 'a': ");
	scanf("%d" , &a);
	printf("Enter value for 'b': ");
	scanf("%d" , &b);
	printf("Enter value for 'c': ");
	scanf("%d" , &c);
	if(a == b && b == c){
		printf("no greatest because all are equal.\n");
	}else{
		if(a > b && a > c){
			printf("'a' is greater than 'b' and 'c'.\n");
		}else if(b > c){
			printf("'b' is greater than 'a' and 'c'.\n");
		}else{
			printf("'c' is greater than 'a' and 'b'.\n");
		}
	}

	switch(a + b + c){
		case 9:
		       printf("all three values may be three.\n");
	       	       break;
		case 6:
		       printf("all three values may be six.\n");
		       break;
		case 3:
		       printf("all three values may be one.\n");
		       break;
		default:
		       printf("no patterns found.\n");
		       break;
	}
	d = (a > b) ? a - b : b - a;
	printf("The absolute difference is %d.\n",
		(d > c) ? d - c : c - d);

}
