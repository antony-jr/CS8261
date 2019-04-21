#include <stdio.h>
void main() {
    int s_odd,s_even,n;
    s_odd = s_even = n = 0;
    printf("Enter the upper limit: ");
    scanf("%d", &n);
    do {
        if(!(n % 2)) {
            s_even += n;
            continue;
        }
        s_odd += n;
    } while(--n);
    printf("The sum of odd numbers is %d.\n", s_odd);
    printf("The sum of even numbers is %d.\n", s_even);
    printf("The absolute difference is %d.\n",
           (s_odd>s_even)?s_odd-s_even:s_even-s_odd);
}
