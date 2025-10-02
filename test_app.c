#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("SHARED ARRAY\n");
    array s;

    array_init(&s);
    char* hostname1 = "www.oalgo.com";
    char* hostname2 = "www.google.com";
    char* hostname3 = "www.parenthesis.com";
    char* hostname4 = "www.cprogramming.com";
    array_put(&s, hostname1);
    char* hostname7;
    char* hostname8;
    char* hostname9;
    char* hostname10;
    char* hostname11;
    array_get(&s, &hostname7);
    printf("HOSTNAME: %s\n", hostname7);
    array_put(&s, hostname2);
    array_put(&s, hostname3);
    array_put(&s, hostname4);
    array_get(&s, &hostname8);
    printf("HOSTNAME: %s\n", hostname8);
    array_get(&s, &hostname9);
    printf("HOSTNAME: %s\n", hostname9);
    array_get(&s, &hostname10);
    printf("HOSTNAME: %s\n", hostname10);
    array_get(&s, &hostname11);
    printf("HOSTNAME: %s\n", hostname11);
    array_free(&s);
    return 0;
}