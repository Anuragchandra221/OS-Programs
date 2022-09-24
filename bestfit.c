#include<stdio.h>
struct block{
    int size;
    int no;
}b[10];
struct process{
    int size;
    int flag;
    int no;
}p[10];
void sort(int n){
    int i, j, temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(b[j].size > b[j+1].size){
                temp = b[j].size;
                b[j].size = b[j+1].size;
                b[j+1].size = temp;

                temp = b[j].no;
                b[j].no = b[j+1].no;
                b[j+1].no = temp;
            }
        }
    }
}
int main(){
    int n, m, i, j, temp;
    printf("Enter the no of blocks: ");
    scanf("%d", &n);
    printf("Enter the no of files: ");
    scanf("%d", &m);
    printf("Enter the size of blocks: ");
    for(i=0; i<n; i++){
        scanf("%d", &b[i].size);
        b[i].no = i+1;
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
                    sort(n);
                    printf("\n%d on %d", p[i].size, b[j].size);
                    b[j].size -= p[i].size;
                    printf("  %d\n",b[j].no);
                    p[i].flag = 1;
                    p[i].no = b[j].no;
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