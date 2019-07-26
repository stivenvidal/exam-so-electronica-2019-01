#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int v, resultado;

void *worker1(void *arg) {

    int z = 25, y = 350;

    v = (z/y);

    return NULL;
}

void *worker2(void *arg) {

    sleep(2);

    int x = 1250;

    resultado = (x*v);


    return NULL;
}


int main(int argc, char *argv[]) {

    pthread_t p1, p2;

    Pthread_create(&p1, NULL, worker1, NULL);
    Pthread_create(&p2, NULL, worker2, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);

    printf("resultado = %d\n",resultado);
    return 0;
}
