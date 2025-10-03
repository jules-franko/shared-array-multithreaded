#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct p_args {
	char* hostname;
	array* s;
} p_args;

void* thread(void* args) {
	p_args *args2 = (p_args *)args;
	int randval = rand() % (8 + 1);
	int randval2 = rand() % (8 + 1);
	char* tmp;

	sleep(randval);
	printf("PUT [%s]\n", args2->hostname);
	array_put(args2->s, args2->hostname);

	sleep(randval2);
	array_get(args2->s, &tmp);
	printf("GET [%s]\n", tmp);
}

int main() {
    printf("===SHARED ARRAY TEST===\n");

    void* hostnames[10] = {
	    "www.google.com",
	    "www.test.com",
	    "www.bing.com",
	    "www.computers.com",
	    "www.pthreads.com",
	    "www.posix.com",
	    "www.linux.com",
	    "www.books.com",
	    "www.cprogramming.com",
	    "www.kernel.org",
    };

    array s;
    array_init(&s);

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_t tid[10];
    p_args args[10];

    for (int i = 0; i < 10; i++){
	    args[i].hostname = hostnames[i];
	    args[i].s = &s;
	    pthread_create(&tid[i], &attr, &thread, &args[i]);
    }

    for (int i = 0; i < 10; i++) {
    	    pthread_join(tid[i], NULL);
    }

    array_free(&s);
    return 0;
}
