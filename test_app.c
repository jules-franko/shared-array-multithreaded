#include "array.h"
#include <stdio.h>

int main() {
    printf("SHARED ARRAY\n");
    array* s;

    array_init(s);
    char* hostname1 = "www.oalgo.com";
    array_put(s, hostname1);
    array_free(s);
    return 0;
}