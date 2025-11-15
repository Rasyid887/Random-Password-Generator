#include "shuffle.h"

void fisher_yates(int lenght, char *array) {
    for (int i = lenght - 1; i > 0; i--) {
        int  j    = rand() % (i + 1);
        char temp = array[i];
        array[i]  = array[j];
        array[j]  = temp;
    }
}