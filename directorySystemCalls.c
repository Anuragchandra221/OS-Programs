#include<stdio.h>
#include<dirent.h>
struct dirent *dptr;
int main(){
    char buff[200];
    printf("Enter the directory name: ");
    scanf("%s", &buff);
    DIR *dir = opendir(buff);
    if(dir==NULL){
        printf("Error opening the directory");
    }else{
        while(dptr=readdir(dir)){
            printf("%s\n", dptr->d_name);
            printf("%d\n", dptr->d_type);
            printf("%d\n", dptr->d_reclen);
            printf("%ld\n", dptr->d_ino);
        }
    }
}