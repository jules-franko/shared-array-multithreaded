#define ARRAY_IMPORT
#include "array.h"

int array_init(array *s) {
    s->size = 0;
    s->front = 0;
    return 0;
}

int array_put(array *s, char *hostname) {
    while(s->size == ARRAY_SIZE);

    int put = (s->front+s->size) % ARRAY_SIZE;
    s->array[put] = hostname;
    s->size++;

    return 0;
}

int array_get(array *s, char **hostname) {
    while (s->size==0);

    *hostname = s->array[s->front];
    s->front = (s->front+1)%ARRAY_SIZE;
    s->size--;

    return 0;
}

void array_free(array *s) {
    return;
}             