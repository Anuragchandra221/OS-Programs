#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    // fork();
    // printf("Hello world");
    // if(fork()==0){
    //     printf("Child process running");
    // }else{
    //     printf("Parent process running");
    // }
    pid_t ret_value;
    printf("The process id is %d\n", getpid());
    ret_value = fork();
    if(ret_value<0){
        printf("Fork failure");
    }else if(ret_value==0){
        printf("Child process running of id %d\n", getpid());
    }else{
        printf("Parent process running of id %d\n", getpid());
    }
} 