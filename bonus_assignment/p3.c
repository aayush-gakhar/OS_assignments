#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
#include <sys/resource.h>

#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (num + 4) % 5
#define RIGHT (num + 1) % 5

int state[5];

// these are the semaphores
sem_t mutex;
sem_t S[5];

// counter for sauce bowls
int sauce_bowls = 4;

// function to check if the given philosopher can eat
void check(int num){
    if (state[num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING && sauce_bowls > 0) {
        state[num] = EATING;
        sauce_bowls--;
        sleep(2);
        printf("ph %d takes fork %d and %d. Bowls left: %d\n", num + 1, LEFT + 1, num + 1, sauce_bowls);
        printf("ph %d is Eating\n", num + 1);
        sem_post(&S[num]);
    }
}

// function for philosopher to take fork
void take_fork(int num){
    sem_wait(&mutex);
    state[num] = HUNGRY;
    printf("ph %d is Hungry\n", num + 1);
    check(num);
    sem_post(&mutex);
    sem_wait(&S[num]);
    sleep(1);
}

// function for philosopher to put down fork
void put_fork(int num){
    sem_wait(&mutex);
    if(state[num]==EATING){
        sauce_bowls++;
        printf("ph %d putting fork %d and %d down. Bowls left: %d\n", num + 1, LEFT + 1, num + 1, sauce_bowls);
        printf("ph %d is thinking\n", num + 1);
    }
    state[num] = THINKING;
    check(LEFT);
    check(RIGHT);
    sem_post(&mutex);
}

// main loop
void* philosopher(void* num){
    while (1) {
        int* i = num;
        sleep(1);
        take_fork(*i);
        sleep(0);
        put_fork(*i);
    }
}

int main(){
    int i;
    pthread_t thread_id[5];
    sem_init(&mutex, 0, 1); 
    for (i = 0; i < 5; i++){
        sem_init(&S[i], 0, 0);
    }
    int phil[5] = { 0, 1, 2, 3, 4 };
    for (i = 0; i < 5; i++) {
        pthread_create(&thread_id[i], NULL,philosopher, &phil[i]);
        printf("ph %d is thinking\n", i + 1);
    }
    for (i = 0; i < 5; i++){
        pthread_join(thread_id[i], NULL);
    }
}