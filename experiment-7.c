#include <stdio.h>
void main() {
    int array[100],
        n = 0,
        m = 0,
        average = 0,
        above_avg = 0,
        sum = 0;
    printf("Enter upper limit: ");
    scanf("%d", &n);
    for(; m<n; ++m) {
        printf("Enter height(in cm)[%d]: ", m + 1);
        scanf("%d", &array[m]);
    }
    for(m=0; m<n; ++m) {
        sum+=array[m];
    }
    average = sum/n;
    for(m=0; m<n; ++m) {
        if(array[m] > average) {
            ++above_avg;
        }
    }
    printf("Average height: %d.\n", average);
    printf("Total person(s) above average height: %d.\n", above_avg);
}
