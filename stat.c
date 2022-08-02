#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(){
    char path[100];
    struct stat *nfile;
    nfile = (struct stat *)malloc(sizeof(struct stat));
    printf("Enter name of the file: ");
    scanf("%s", &path);
    stat(path, nfile);
    printf("User id is %d\n", nfile->st_uid);
    printf("Block size is %ld\n", nfile->st_blksize);
    printf("Last access time is %ld\n", nfile->st_atime);
    printf("Time of last modification is %ld\n", nfile->st_mtime);
    printf("Production mode is %d\n", nfile->st_mode);
    printf("Size of the file is %ld\n", nfile->st_size);
    printf("Number of links to the file is %ld\n", nfile->st_nlink);
}