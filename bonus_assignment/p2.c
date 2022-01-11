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
    if (state[num] == HUNGRY && sauce_bowls > 0) {
        state[num] = EATING;
        sauce_bowls--;
        sleep(2);
        printf("ph %d takes sauce bowl. Bowls left: %d\n", num + 1, sauce_bowls);
        printf("ph %d is Eating\n", num + 1);
        sem_post(&S[num]);
    }
}

// function for philosopher to take sauce bowl
void take_sauce(int num){
    sem_wait(&mutex);
    state[num] = HUNGRY;
    printf("ph %d is Hungry\n", num + 1);
    check(num);
    sem_post(&mutex);
    sem_wait(&S[num]);
    sleep(1);
}

// function for philosopher to put down sauce bowl
void put_sauce(int num){
    sem_wait(&mutex);
    if(state[num]==EATING){
        sauce_bowls++;
        printf("ph %d putting sauce down. Bowls left: %d\n", num + 1, sauce_bowls);
        printf("ph %d is thinking\n", num + 1);
    }
    state[num] = THINKING;
    check(LEFT);
    check(RIGHT);
    sem_post(&mutex);
}

// main loop
void* philosopher(void* i){
    while (1) {
        int num = *(int*)i;
        sleep(1);
        take_sauce(num);
        sleep(0);
        put_sauce(num);
    }
}

int main(){
    int i;
    pthread_t threads[5];
    sem_init(&mutex, 0, 1); 
    for (i = 0; i < 5; i++){
        sem_init(&S[i], 0, 0);
    }
    int arr[5] = { 0, 1, 2, 3, 4 };
    for (i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL,philosopher, &arr[i]);
        printf("ph %d is thinking\n", i + 1);
    }
    for (i = 0; i < 5; i++){
        pthread_join(threads[i], NULL);
    }
}