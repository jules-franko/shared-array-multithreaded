#define ARRAY_IMPORT
#include "array.h"

int array_init(array *s) {
    s->size = 0;
    s->front = 0;
    sem_init(&s->mutex, 0, 1);
    sem_init(&s->space_avail, 0, ARRAY_SIZE);
    sem_init(&s->items_avail, 0, 0);
    return 0;
}

int array_put(array *s, char *hostname) {
    sem_wait(&s->space_avail);

    sem_wait(&s->mutex);
    /*Critical Section*/
    int put = (s->front+s->size) % ARRAY_SIZE;
    s->array[put] = hostname;
    s->size++;
    /*Critical Section*/
    sem_post(&s->mutex);

    sem_post(&s->items_avail);
    return 0;
}

int array_get(array *s, char **hostname) {
    sem_wait(&s->items_avail);

    sem_wait(&s->mutex);
    /*Critical Section*/
    *hostname = s->array[s->front];
    s->front = (s->front+1)%ARRAY_SIZE;
    s->size--;
    /*Critical Section*/
    sem_post(&s->mutex);

    sem_post(&s->space_avail);
    return 0;
}

void array_free(array *s) {
    sem_destroy(&s->mutex);
    sem_destroy(&s->space_avail);
    sem_destroy(&s->items_avail);
    return;
}             
