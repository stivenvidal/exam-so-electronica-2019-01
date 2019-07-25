#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"

volatile int counter = 0;
cerradura acceso;
int loops;
                                                             
void *worker(void *arg) {
    int i;
    cerrar_puerta(acceso);
    for (i = 0; i < loops; i++) {
	    counter++;
    }
    abrir_puerta(acceso);
    return NULL;
}
                       
int main(int argc, char *argv[]) {

    clock_t tiempo_inicio,tiempo_final;
    double segundos;
    tiempo_inicio = clock();

    crear_puerta(acceso);
    if (argc != 2) { 
	fprintf(stderr, "usage: threads <loops>\n"); 
	exit(1); 
    } 
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL);//crea un hilo 
    Pthread_create(&p2, NULL, worker, NULL); //crea el segundo hilo
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    destruir_puerta(acceso);

    tiempo_final = clock();
    segundos = (double)(tiempo_final-tiempo_inicio)/CLOCKS_PER_SEC;
    printf ("El programa tardo: %f segundos.\n", segundos);

    return 0;
}
                          
