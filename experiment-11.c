#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int count(const char *s) {
    int r = 0;
    while(*s) {
        if(!isspace(*s++) &&
                (isspace(*s) || *s == '\0')) {
            ++r;
        }
    }
    return r;
}

void capitalize(char *dest, const char *src) {
    char *cpy = calloc(strlen(src) + 1, sizeof(src[0]));
    strcpy(cpy, src);
    char *p = strtok(cpy, "\n");
    while(p) {
        *p = toupper(*p);
        strcpy(dest, p);
        dest += strlen(p);
        *dest++ = '\n';
        p = strtok(NULL, "\n");
    }
    *dest = '\0';
    free(cpy);
}

void replace(char *dest, const char *src, const char *search, const char *rep) {
    const char *start = src;
    const char *end = src + strlen(src);
    char *p = strstr(src, search);
    int search_len = strlen(search);
    int rep_len = strlen(rep);
    while(p) {
        while(start < p) {
            *dest++ = *start++;
        }
        start += search_len;
        strcpy(dest, rep);
        dest += rep_len;
        p = strstr(start, search);
    }
    if(start < end) {
        strcpy(dest, start);
    }
}

void main() {
    char input[200];
    char buf[200];
    char rep[50];
    char search[50];
    int c = 0;
    int p = 0;
    printf("Enter a paragraph(Max 200): \n\n");
    while((c = getchar()) != '|') {
        input[p++] = c;
    }
    input[p] = '\0';
    printf("\nEnter the word to search in the paragraph: ");
    scanf("%s", search);
    printf("Enter the word to replace with in the paragraph: ");
    scanf("%s", rep);

    printf("\nTotal number of words: %d\n", count(input));
    capitalize(buf, input);
    printf("\nCapitalized Paragraph: \n\n%s\n", buf);
    replace(buf, input, search, rep);
    printf("\nReplaced Paragraph: \n\n%s\n", buf);
}
