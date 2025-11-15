#include "genpass.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void init_random();

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

void init_random() { srand((unsigned int)time(NULL)); }