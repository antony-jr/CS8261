#include <stdio.h>
void main(){
	float buf[100][2];
	int n = 0,m = 0;
	printf("Enter the upper limit: ");
	scanf("%d" , &n);
	for(; m < n; ++m){
		printf("Enter Height(in meters)[%d]: " , m + 1);
		scanf("%f" , &buf[m][0]);
		printf("Enter Weight(in kg)[%d]: " , m + 1);
		scanf("%f" , &buf[m][1]);
	}
	printf("\n");
	for(m = 0; m < n; ++m){
		printf("(%d) BMI for (Height = %f , Weight = %f): %f.\n",
			m + 1 , buf[m][0] , buf[m][1] , 
			buf[m][1]/(buf[m][0] * buf[m][0]));
	}
}
