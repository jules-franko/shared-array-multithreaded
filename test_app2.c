#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char* hostnames[12] = {
	    "www.google.com",
	    "www.test.com",
	    "www.bing.com",
	    "www.computers.com",
	    "www.pthreads.com",
	    "www.posix.com",
	    "www.linux.com",
	    "www.books.com",
	    "www.cprogramming.com",
        "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
        "www.kernel.org",
        "www.mango.org",
    };

void* thread(void* args) {
	char* hostname = "www.google.com";
	array_put(args, hostnames[0]);
    printf("PUT [%s]\n", hostnames[0]);
}

void* thread2(void* args) {
	char* hostname = "www.google.com";
	array_put(args, hostnames[1]);
    printf("PUT [%s]\n", hostnames[1]);
}

void* thread3(void* args) {
	char* hostname = "www.google.com";
	array_put(args, hostnames[2]);
    printf("PUT [%s]\n", hostnames[2]);
}

void* thread4(void* args) {
	char* hostname = "www.google.com";
	array_put(args, hostnames[3]);
    printf("PUT [%s]\n", hostnames[3]);
}

void* thread5(void* args) {
	char* hostname = "www.google.com";
	array_put(args, hostnames[4]);
    printf("PUT [%s]\n", hostnames[4]);
}

void* thread6(void* args) {
	char* hostname = "www.google.com";
	array_put(args, hostnames[5]);
    printf("PUT [%s]\n", hostnames[5]);
}

void* thread7(void* args) {
	char* hostname = "www.google.com";
	array_put(args, hostnames[6]);
    printf("PUT [%s]\n", hostnames[6]);
}

void* thread8(void* args) {
	char* hostname = "www.google.com";
	array_put(args, hostnames[7]);
    printf("PUT [%s]\n", hostnames[7]);
}

void* thread9(void* args) {
	char* hostname = "www.google.com";
	array_put(args, hostnames[8]);
    printf("PUT [%s]\n", hostnames[8]);
}

void* thread10(void* args) {
	char* hostname = "www.google.com";
	array_put(args, hostnames[9]);
    printf("PUT [%s]\n", hostnames[9]);
}

void* thread_get(void* args) {
    char* tmp;
    array_get(args, &tmp);
	printf("GET [%s]\n", tmp);
}

int main() {
    printf("===SHARED ARRAY TEST 2===\n");

    array s;
    array_init(&s);

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_t tid;
    pthread_t tid2;
    pthread_t tid3;
    pthread_t tid4;
    pthread_t tid5;
    pthread_t tid6;
    pthread_t tid7;
    pthread_t tid8;
    pthread_t tid9;
    pthread_t tid10;

    pthread_t tid_get;
    pthread_t tid_get2;
    pthread_t tid_get3;
    pthread_t tid_get4;
    pthread_t tid_get5;
    pthread_t tid_get6;
    pthread_t tid_get7;
    pthread_t tid_get8;
    pthread_t tid_get9;
    pthread_t tid_get10;

	pthread_create(&tid, &attr, &thread, &s);
    pthread_create(&tid2, &attr, &thread2, &s);
    pthread_create(&tid3, &attr, &thread3, &s);
    pthread_create(&tid4, &attr, &thread4, &s);
    pthread_create(&tid5, &attr, &thread5, &s);
    pthread_create(&tid6, &attr, &thread6, &s);
    pthread_create(&tid7, &attr, &thread7, &s);
    pthread_create(&tid8, &attr, &thread8, &s);
    pthread_create(&tid9, &attr, &thread9, &s);
    pthread_create(&tid10, &attr, &thread10, &s);

    pthread_create(&tid_get, &attr, &thread_get, &s);
    pthread_create(&tid_get2, &attr, &thread_get, &s);
    pthread_create(&tid_get3, &attr, &thread_get, &s);
    pthread_create(&tid_get4, &attr, &thread_get, &s);
    pthread_create(&tid_get5, &attr, &thread_get, &s);
    pthread_create(&tid_get6, &attr, &thread_get, &s);
    pthread_create(&tid_get7, &attr, &thread_get, &s);
    pthread_create(&tid_get8, &attr, &thread_get, &s);
    pthread_create(&tid_get9, &attr, &thread_get, &s);
    pthread_create(&tid_get10, &attr, &thread_get, &s);

    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_join(tid5, NULL);
    pthread_join(tid6, NULL);
    pthread_join(tid7, NULL);
    pthread_join(tid8, NULL);
    pthread_join(tid9, NULL);
    pthread_join(tid10, NULL);

    pthread_join(tid_get, NULL);
    pthread_join(tid_get2, NULL);
    pthread_join(tid_get3, NULL);
    pthread_join(tid_get4, NULL);
    pthread_join(tid_get5, NULL);
    pthread_join(tid_get6, NULL);
    pthread_join(tid_get7, NULL);
    pthread_join(tid_get8, NULL);
    pthread_join(tid_get9, NULL);
    pthread_join(tid_get10, NULL);

    array_free(&s);
    return 0;
}
