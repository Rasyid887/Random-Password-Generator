#include "genpass.h"

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

int generate_random(int min, int max) {
    int count = max - min + 1;
    int limit = RAND_MAX - (RAND_MAX % count);

    int data;
    do {
        data = rand();
    } while (data >= limit);

    return min + (data % count);
}