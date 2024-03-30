#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>

int target_value;
int num_refs;

void banner() {
    puts(
    " ______   _______  ______    _______  _______ \n"
    "|      | |       ||    _ |  |       ||       |\n"
    "|  _    ||    ___||   | ||  |    ___||    ___|\n"
    "| | |   ||   |___ |   |_||_ |   |___ |   |___ \n"
    "| |_|   ||    ___||    __  ||    ___||    ___|\n"
    "|       ||   |___ |   |  | ||   |___ |   |    \n"
    "|______| |_______||___|  |_||_______||___|    \n");
}

int menu() {
    puts("1. allocate");
    puts("2. write");
    puts("3. submit");

    int opt;
    printf("\nenter your choice: ");
    scanf("%d", &opt);
    return opt;
}

void generate() {
    getrandom(&target_value, 4, GRND_RANDOM);
    getrandom(&num_refs, 4, GRND_RANDOM);
    num_refs &= 0x7;
}

void print_target(int target_value, int num_refs) {
    printf("\nint");
    for (int i = 0; i < num_refs; ++i) {
        printf("*");
    }
    printf(" = %p\n", (int*)target_value);

    printf("a");
    for (int i = 0; i < num_refs; i++) {
        printf(" pointer to a");
    }
    printf("n int which is equal to %p\n\n", (int*)target_value);
}

void allocate() {
    int* p = malloc(4);
    printf("%p\n", p);
}

void write_to() {
    int* p;
    printf("address: ");
    scanf("%p", &p);

    int v;
    printf("value: ");
    scanf("%p", (int**)&v);

    *p = v;
}

void submit() {
    int* p;
    printf("address: ");
    scanf("%p", &p);

    for (int i = 0; i < num_refs; i++)
        p = *(int**)p;

    if (*p != target_value)
        *(int*)0 = 0xdeadbeef;

    puts("\n*********");
    puts("congrats!");
    puts("*********\n");

    generate();
}

int main(int argc, char** argv) {
    banner();

    generate();

    for ( ; ; ) {
        print_target(target_value, num_refs);

        switch (menu()) {
            case 1: {
                allocate();
                break;
            }

            case 2: {
                write_to();
                break;
            }

            case 3: {
                submit();
                break;
            }

            default: {
                puts("bye");
                exit(0);
            }
        }
    }

    return 0;
}
