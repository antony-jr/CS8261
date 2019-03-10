#include <stdio.h>
char *isLeap(int n){
	if((!(n%4) && (n%100)) ||
	    (!(n%100)  && !(n%400))){
		return "\b";
	}
	return "not";
}
void main() {
	int year = 0;
	printf("Enter a year: ");
	scanf("%d" , &year);
	printf("Year %d is %s a leap year.\n" , year , isLeap(year));
}
