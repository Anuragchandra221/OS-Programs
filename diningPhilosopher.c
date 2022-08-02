#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#define num_philosophers 5
#define num_chopsticks 5
void dine(int n);
pthread_t philosophers[num_philosophers];
pthread_mutex_t chopsticks[num_chopsticks];
int main(){
    int i, status_msg;
    void *msg;
    for(i=1; i<=num_chopsticks; i++){
        status_msg = pthread_mutex_init(&chopsticks[i], NULL);
        if(status_msg==-1){
            printf("\n Mutex initialization failed");
            exit(1);
        }
    }
    for(i=1; i<=num_philosophers; i++){
        status_msg = pthread_create(&philosophers[i], NULL, (void *)dine, (int *)i);
        if(status_msg!=0){
            printf("\n Thread creation failed");
            exit(1);
        }
    }
    for(i=1; i<=num_philosophers; i++){
        status_msg = pthread_join(philosophers[i], &msg);
        if(status_msg!=0){
            printf("\n Thread join failed");
            exit(1);
        }
        
    }
    for(i=1; i<=num_chopsticks; i++){
        status_msg = pthread_mutex_destroy(&chopsticks[i]);
        if(status_msg!=0){
            printf("\n Mutex destroyed");
            exit(1);
        }
    }
    return 0;

}   
void dine(int n){
    printf("\nPhilosopher %d is thinking", n);
    pthread_mutex_lock(&chopsticks[n]);
    pthread_mutex_lock(&chopsticks[(n+1)%num_chopsticks]);

    printf("\nPhilosopher %d is eating", n);
    sleep(3);
    pthread_mutex_unlock(&chopsticks[n]);
    pthread_mutex_unlock(&chopsticks[(n+1)%num_chopsticks]);
    printf("\nPhilosopher %d is finished eating", n);
} 