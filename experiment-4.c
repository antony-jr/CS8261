#include <stdio.h>
void main(){
	int a , b;
	printf("Enter value for 'a': ");
	scanf("%d" , &a);
	printf("Enter value for 'b': ");
	scanf("%d" , &b);
	printf("Sum        (a+b) = %d\n" , a+b);
	printf("Difference (a-b) = %d\n" , a-b);
	printf("Product    (axb) = %d\n" , a*b);
	printf("Square     (a^2) = %d\n" , a*a);
	printf("Square     (b^2) = %d\n" , b*b);
}
