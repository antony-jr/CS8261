#include <stdio.h>
void towerOfHanoi(int n, char src, char dest, char spare) {
    if(!n)
        return;
    towerOfHanoi(n - 1, src, spare, dest);
    printf("Move disk %d from peg %c to peg %c.\n", n, src, dest);
    towerOfHanoi(n - 1, spare, dest, src);
}
void main() {
    int n;
    printf("Enter the number of disk(s): ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
}
