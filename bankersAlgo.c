#include<stdio.h>
int n, m, available[10], work[10], finish[10], max[10][10], allocation[10][10], need[10][10];
int main(){
    int i,j;
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    printf("Enter the no of resource types: ");
    scanf("%d", &m);
    printf("Enter the available resources: ");
    for(i=0; i<m; i++){
        scanf("%d", &available[i]);
        work[i] = available[i];
    }
    printf("Enter the max matrix: ");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &max[i][j]);
        }
        finish[i] = 0;
    }
    printf("Enter the allocation matrix: ");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &allocation[i][j]);
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("P\tAlloc\tMax\tNeed\tAvail");
    for(i=0; i<n; i++){
        printf("\nP%d\t",i+1);
        for(j=0; j<m; j++){
            printf("%d ",allocation[i][j]);
        }
        printf("\t");
        for(j=0; j<m; j++){
            printf("%d ",max[i][j]);
        }
        printf("\t");
        for(j=0; j<m; j++){
            printf("%d ",need[i][j]);
        }
        printf("\t");
        if(i==0){
            for(j=0; j<m; j++){
            printf("%d ",available[j]);
        }
        }
    }
    int flag=0;
    int count = 0;
    printf("\n");
    while(count<n-1){
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if (finish[i]==0 && (need[i][j] <= work[j])){
                    flag = 1;
                }else{
                    flag = 0;
                    break;
                }
            }
            if (flag==1){
                finish[i]=1;
                count ++;
                for(j=0; j<m; j++){
                    work[j] += allocation[i][j];
                }
                printf("P%d  ", i+1);
            }
        }
        if (flag==0){
            count++;
        }
    }
}