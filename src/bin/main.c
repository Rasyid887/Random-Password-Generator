#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void  init_random();
int   generate_random(int min, int max);
char *generate_password(int lenght, const char *symbol_1, const char *symbol_2, const char *symbol_3, const char *symbol_4);
void  fisher_yates(int lenght, char *array);

int main() {
    const char *uppercase_symbol = "QZJCLYMTBSAHVGFKIPRODWXNEU";
    const char *lowercase_symbol = "qjntvexyzlsckmrgabwhipdfou";
    const char *special_symbol   = "!@#$^&*";
    const char *number_symbol    = "0123456789";

    bool isExit    = false;
    bool isReset   = false;
    bool isContain = false;
    char response  = '\0';
    char data[50];

    init_random();

    while (!isExit) {
        puts("\n=========================================");
        puts("======= RANDOM PASSWORD GENERATOR =======");
        puts("=========================================\n");

        do {
            printf("What is an interesting? ");
            fgets(data, sizeof(data), stdin);
            data[strlen(data) - 1] = '\0';

            if (strchr(data, ' ') != NULL) {
                puts("[ERROR] Data contains spaces\n");
                isContain = true;
            } else {
                isContain = false;
            }
        } while (isContain);

        char *password = generate_password(12, uppercase_symbol, lowercase_symbol, special_symbol, number_symbol);

        printf("Password: %s_%s\n", data, password);

        free(password);
        password = NULL;

        do {
            printf("\nWould you want to reset your password? (Y/N) ");
            scanf(" %c", &response);
            getchar();

            if (response == 'Y' || response == 'y') {
                isReset = false;
                isExit  = false;
            } else if (response == 'N' || response == 'n') {
                isReset = false;
                isExit  = true;

                puts("Thankyou for using the program!");
                puts("=========================================");
            } else {
                isReset = true;
                isExit  = false;

                puts("\n[ERROR] Invalid response");
            }
        } while (isReset);
    }

    getchar();
    return 0;
}

void fisher_yates(int lenght, char *array) {
    for (int i = lenght - 1; i > 0; i--) {
        int  j    = rand() % (i + 1);
        char temp = array[i];
        array[i]  = array[j];
        array[j]  = temp;
    }
}

char *generate_password(int lenght, const char *symbol_1, const char *symbol_2, const char *symbol_3, const char *symbol_4) {
    char *password     = malloc(lenght + 1);
    int   group_lenght = lenght / 4;

    if (password == NULL) {
        puts("Error memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < group_lenght; i++) {
        password[i] = symbol_1[generate_random(0, 25)];
    }
    for (int i = group_lenght; i < group_lenght * 2; i++) {
        password[i] = symbol_2[generate_random(0, 25)];
    }
    for (int i = group_lenght * 2; i < group_lenght * 3; i++) {
        password[i] = symbol_3[generate_random(0, 6)];
    }
    for (int i = group_lenght * 3; i < group_lenght * 4; i++) {
        password[i] = symbol_4[generate_random(0, 9)];
    }

    password[lenght] = '\0';

    fisher_yates(strlen(password), password);

    return password;
}

void init_random() { srand((unsigned int)time(NULL)); }

int generate_random(int min, int max) {
    int count = max - min + 1;
    int limit = RAND_MAX - (RAND_MAX % count);

    int data;
    do {
        data = rand();
    } while (data >= limit);

    return min + (data % count);
}