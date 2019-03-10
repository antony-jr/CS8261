#include <stdio.h>
#define BIN 17
#define OCT 55
#define HEX 79
#define BITS sizeof(int)*8
char *convert(int n , int mode){
	char static buf[BITS + 1],*p;
	int i = 0, mask = mode & 15;
	mode >>= 4;
	*(p = buf + BITS + 1) = '\0';
	do{
		*(--p) = (n >> i) & mask;
		*p += (*p < 10) ? '0' : ('A' - 10);
	}while((i+=mode) < BITS);
	return p;
}
void main(){
	int n = 0;
	printf("Enter a decimal number: ");
	scanf("%d" , &n);
	printf("Binary      : %s\n" , convert(n , BIN));
	printf("Octal       : %s\n" , convert(n , OCT));
	printf("Hexadecimal : %s\n" , convert(n , HEX));
}
