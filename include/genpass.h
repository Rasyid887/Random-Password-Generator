#ifndef GENPASS_H
#define GENPASS_h

#include "shuffle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int   generate_random(int min, int max);
char *generate_password(int lenght, const char *symbol_1, const char *symbol_2, const char *symbol_3, const char *symbol_4);

#endif