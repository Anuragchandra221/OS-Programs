#include<stdio.h>
int main(){
    int at[10], bt[10], rt[10], completiontime, i, smallest, sbt=0;
    int count=0, n, time, sumWait=0, sumTurnaround=0;
    printf("Enter no of processes: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter arrival time of process p%d: ",i+1);
        scanf("%d", &at[i]);
        printf("Enter burst time of process p%d: ",i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    time = 0;
    printf("\nPId\tAt\tBt\tCt\tTat\tWt");
    int temp;
    while(count!=n){
        for(i=0; i<n; i++){
            if(at[i]<=time && rt[i]){
                smallest = i;
            }
        }
        temp = smallest;
        for(i=0; i<n; i++){
            if(at[i]==at[temp] && bt[i]<=bt[smallest]){
                smallest = i;
            }
        }
        rt[smallest] -=1;
        if(rt[smallest]==0){
            count++;
            completiontime = time+1;
            printf("\nP%d\t%d\t%d\t%d\t%d\t%d", smallest+1, at[smallest], bt[smallest], completiontime, completiontime-at[smallest], completiontime-at[smallest]-bt[smallest] );
        }
        time++;
    }
}