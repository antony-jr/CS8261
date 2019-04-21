#include <stdio.h>
void isort(int *arr, int n) {
    int i = 1,
        pos = 0,
        value = 0;
    while(i < n) {
        value = arr[i];
        pos = i;
        while(pos > 0 && arr[pos - 1] > value) {
            arr[pos] = arr[pos-1];
            --pos;
        }
        arr[pos] = value;
        ++i;
    }
}
void print_array(int *arr, int n) {
    int i = 0;
    printf("(");
    for(; i < n - 1; ++i) {
        printf(" %d ,", arr[i]);
    }
    printf("%d )\n", arr[i]);
}
int main() {
    int array[100],
        n = 0,
        i = 0;
    printf("Enter upper limit: ");
    scanf("%d", &n);
    for(; i < n ; ++i) {
        printf("Enter value[%d]: ", i+1);
        scanf("%d", array + i);
    }
    printf("Given Array: ");
    print_array(array, n);
    isort(array, n);
    printf("Sorted Array: ");
    print_array(array, n);
}
