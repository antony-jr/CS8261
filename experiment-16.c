#include <stdio.h>
#include <string.h>

typedef struct {
    char name[250];
    char number[100];
    int is_empty : 1;
} teldir_entry_t;

int teldir_entry_write(FILE *fp, long pos, teldir_entry_t *e) {
    if(!fp || !e || pos < 0) {
        return -1;
    }
    fseek(fp, pos, SEEK_SET);
    return !fwrite(e, 1, sizeof *e, fp);
}

long teldir_entry_find_empty(FILE *fp) {
    teldir_entry_t buf;
    long pos = -1;
    memset(&buf, 0, sizeof buf);
    if(!fp) {
        return pos;
    }
    rewind(fp);
    while(fread(&buf, 1, sizeof buf, fp)) {
        if(buf.is_empty) {
            pos =  ftell(fp) - sizeof(buf);
            break;
        }
        pos = ftell(fp);
    }
    return !ftell(fp) ? 0 : pos;
}

long teldir_entry_find(FILE *fp, const char *name) {
    teldir_entry_t buf;
    long pos = -1;
    memset(&buf, 0, sizeof buf);
    if(!fp || !name) {
        return pos;
    }
    rewind(fp);
    while(fread(&buf, 1, sizeof buf, fp)) {
        if(buf.is_empty) {
            continue;
        }
        if(!strcmp(buf.name, name)) {
            pos = ftell(fp) - sizeof(buf);
            break;
        }
    }
    return pos;
}

int teldir_entry_delete(FILE *fp, const char *name) {
    teldir_entry_t buf;
    memset(&buf, 0, sizeof buf);
    if(!fp || !name) {
        return -1;
    }
    rewind(fp);
    while(fread(&buf, 1, sizeof buf, fp)) {
        if(buf.is_empty) {
            continue;
        }
        if(!strcmp(buf.name, name)) {
            buf.is_empty = 1;
            teldir_entry_write(fp, ftell(fp) - sizeof(buf), &buf);
            return 0;
        }
    }
    return -1;
}

int teldir_entry_append(FILE *fp, teldir_entry_t *e) {
    return teldir_entry_write(fp, teldir_entry_find_empty(fp), e);
}

int teldir_entry_read(FILE *fp, long pos, teldir_entry_t *e) {
    if(!fp || pos < 0 || !e) {
        return -1;
    }
    fseek(fp, pos, SEEK_SET);
    fread(e, 1, sizeof *e, fp);
    return 0;
}

int main() {
    int opt = 0;
    FILE *fp = NULL;
    teldir_entry_t buf;
    memset(&buf, 0, sizeof buf);
    if(!(fp = fopen("teldir.db", "r+"))) {
        fp = fopen("teldir.db", "w+");
        if(!fp) {
            return -1;
        }
    }
    while(opt > -1) {
        printf("*** TELEPHONE DIRECTORY ***\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
        case 1:
            printf("\n\n");
            printf("** NEW CONTACT DIALOG **\n");
            memset(&buf, 0, sizeof buf);
            printf("Enter name: ");
            scanf("%s", buf.name);
            printf("Enter phone number: ");
            scanf("%s", buf.number);
            printf("--* *** *--\n\n");
            teldir_entry_append(fp, &buf);
            break;
        case 2:
            printf("\n\n");
            printf("** CONTACT SEARCH DIALOG **\n");
            printf("Enter contact name: ");
            scanf("%s", buf.name);
            putchar('\n');
            if(-1 == teldir_entry_read(fp, teldir_entry_find(fp, buf.name), &buf)) {
                printf("NO ENTRY FOUND!\n");
            } else {
                printf("Name: %s\n", buf.name);
                printf("Phone Number: %s\n", buf.number);
            }
            printf("--* *** *--\n\n");
            break;
        case 3:
            printf("\n\n");
            printf("** CONTACT DELETE DIALOG **\n");
            printf("Enter contact name: ");
            scanf("%s", buf.name);
            putchar('\n');
            if(-1 == teldir_entry_delete(fp, buf.name)) {
                printf("NO ENTRY FOUND!\n");
            } else {
                printf("ENTRY SUCCESSFULLY DELETED!\n");
            }
            printf("--* *** *--\n\n");
            break;
        default:
            opt = -1;
            break;
        }
    }
    fclose(fp);
    return 0;
}
