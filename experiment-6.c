#include <stdio.h>
#define MAX_LEN 100
short is_perfect_cube(int);
void isort(int (*)[2], int);
void main(){
	int array[MAX_LEN][2],
	    n = 0,
	    m = 0;
	printf("Enter the upper limit: ");
	scanf("%d" , &n);
	for(; m < n ; ++m){
		printf("Enter Value[%d]: " , m + 1);
		scanf("%d" , &array[m][0]);

		/* Set weight. */
		array[m][1] = 0;
		if(is_perfect_cube(array[m][0])){
			array[m][1] += 5;
		}
		if(!(array[m][0] % 4) && !(array[m][0] % 6)){
			array[m][1] += 4;
		}
		if(array[m][0] == 2 || array[m][0] % 2){
			array[m][1] += 3;
		}
	}
	isort(array , m);
	printf("Sorted Sum of Weights: ");
	for(m = 0; m < n-1 ; ++m){
		printf(" <%d , %d> ," , 
			array[m][0] , array[m][1]);
	}
	printf(" <%d , %d>.",array[n-1][0] , array[n-1][1]);
	printf("\n");
}

short is_perfect_cube(int n){
	int m = 0,
	    j = 1;
	m = j * j * j;
	while(m < n){
		++j;
		m = j * j * j;
	}
	return (m == n) ? 1:0;
}

void isort(int (*array)[2] , int n)
{
	int i = 1,
	    v[2],
	    pos = 0;
	while(i < n){
		v[0] = array[i][0];
		v[1] = array[i][1];
		pos = i;
		while(pos > 0 && array[pos-1][1] > v[1]){
			array[pos][0] = array[pos-1][0];
			array[pos][1] = array[pos-1][1];
			pos -= 1;
		}
		array[pos][0] = v[0];
		array[pos][1] = v[1];
		++i;
	}
}
