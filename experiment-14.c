#include <stdio.h>
#include <stdlib.h>
struct employee_salary_slip_t {
    char name[100];
    char designation[100];
    int net_salary;
    int loan;
    int dd;
    int salary;
    struct employee_salary_slip_t *next;
};
int main() {
    int n = 0, i =0;
    struct employee_salary_slip_t *to_free = NULL;
    struct employee_salary_slip_t *head = NULL;
    struct employee_salary_slip_t **p = &head;
    printf("Enter the no. of employees: ");
    scanf("%d", &n);
    for(; i < n; ++i) {
        *p = calloc(1, sizeof **p);
        printf("Enter employee name: ");
        scanf("%s", (*p)->name);
        printf("Enter employee designation: ");
        scanf("%s", (*p)->designation);
        printf("Enter loan: ");
        scanf("%d", &((*p)->loan));
        printf("Enter dd: ");
        scanf("%d", &((*p)->dd));
        printf("Enter salary: ");
        scanf("%d", &((*p))->salary);
        (*p)->net_salary = (*p)->salary + (*p)->dd - (*p)->loan;
        p = &((*p)->next);
    }
    p = &head;
    printf("\n\n");
    while(*p) {
        to_free = *p;
        printf("\n\n==== SALARY SLIP ====\n");
        printf("Enter employee name: %s\n", (*p)->name);
        printf("Enter employee designation: %s\n", (*p)->designation);
        printf("Enter loan: %d\n", ((*p)->loan));
        printf("Enter dd: %d\n", ((*p)->dd));
        printf("Enter salary: %d\n", ((*p)->salary));
        printf("Net salary: %d\n", (*p)->net_salary);
        printf("==== *** ====\n\n");
        p = &((*p)->next);
        free(to_free);
    }
}
