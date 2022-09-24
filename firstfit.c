#include<stdio.h>
struct block{
    int size;
}b[10];
struct process{
    int size;
    int flag;
    int no;
}p[10];
int main(){
    int n, m, i, j;
    printf("Enter the no of blocks: ");
    scanf("%d", &n);
    printf("Enter the no of files: ");
    scanf("%d", &m);
    printf("Enter the size of blocks: ");
    for(i=0; i<n; i++){
        scanf("%d", &b[i].size);
    }
    printf("Enter the size of files: ");
    for(i=0; i<m; i++){
        scanf("%d", &p[i].size);
        p[i].flag = 0;
    }
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(p[i].flag!=1){
                if(p[i].size<=b[j].size){
                    b[j].size -= p[i].size;
                    p[i].flag = 1;
                    p[i].no = j+1;
                    break;
                }
            }
        }
    }
    printf("file_no    file_size    block_no\n" );
    for(i=0; i<m; i++){
        if(p[i].flag!=0){
            printf("%d\t    %d\t    %d\n", i+1, p[i].size, p[i].no );
        }
        else{
            printf("%d\t    %d\t    %s\n", i+1, p[i].size, "nill" );
        }
    }
}