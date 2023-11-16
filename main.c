#include "mutex.h"
#include "semaphore.h"
#include "thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_VALORES 20

int valpointer;
int valores[MAX_VALORES] = {7,2,9,23,1, 4,7,3,0,2, 4,9,2,5,7, 9,7,1,2,6};

int fifocounter;
int fifo[5];

pthread_t p;
pthread_t c1, c2, c3;

void *consumer(){
    while(1){
        while(fifocounter < 3);
        




        if (valpointer == 19){
            break;
        }
    }
}

void *producer(){
    while(1){
        while(fifocounter <= 3){
            fifo[fifocounter] = valores[valpointer];
            printf("stored %i... ", fifo[fifocounter]);

            valpointer++;
            fifocounter++;
        }

        while(fifocounter > 0);



        if (valpointer == 19){
            break;
        }
    }
}

int main(){
    fifocounter, valpointer = 0;

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c1, NULL, consumer, NULL);
    pthread_create(&c2, NULL, consumer, NULL);
    pthread_create(&c3, NULL, consumer, NULL);
    
    pthread_join(p, NULL);
    pthread_join(c1, NULL);
    pthread_join(c2, NULL);
    pthread_join(c3, NULL);

    return 0;
}