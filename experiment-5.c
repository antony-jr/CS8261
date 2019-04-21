#include <stdio.h>
#include <math.h>
void main() {
    int n=0,m=0,sum=0,digits=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(m=n; m; m/=10) {
        ++digits;
    }
    for(m=n; m; m/=10) {
        sum+=pow((m%10),digits);
    }
    printf("%d is %s an armstrong number\n",n,
           (!n||n!=sum)?"not":"\b");
}
