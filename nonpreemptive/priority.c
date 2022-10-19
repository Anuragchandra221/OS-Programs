#include<stdio.h>
int n;
struct process{
    int id,at,bt,completed,priority, rt;
}p[10];
int main(){
    int  completiontime, i, smallest;
    int count=0, time;
    float sumWait=0, sumTurnaround=0;
    printf("Enter no of processes: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter arrival time of process p%d: ",i+1);
        scanf("%d", &p[i].at);
        printf("Enter burst time of process p%d: ",i+1);
        scanf("%d", &p[i].bt);
        printf("Enter priority of process p%d: ",i+1);
        scanf("%d", &p[i].priority);
        p[i].rt = p[i].bt;
        p[i].completed = 0;
        p[i].id = i+1;
    }
    time = 0;
    printf("\nPId\tAt\tPrio\tBt\tCt\tTat\tWt");
    int temp;
    int maxPrio;
    while(count!=n){
        for(i=0; i<n; i++){
            if( p[i].at<=time && p[i].completed==0){
                maxPrio = p[i].priority;
                break;
            }
        }
        for(i=0; i<n; i++){
            if(p[i].at<=time && p[i].priority<=maxPrio && p[i].completed==0){
                maxPrio = p[i].priority;
                smallest = i;
            }
        }
        if(p[smallest].at>=time){
            p[smallest].rt += ( p[smallest].at - time);
        }
        time += p[smallest].rt;
        p[smallest].rt -= p[smallest].rt;
        p[smallest].completed = 1;
        if(p[smallest].rt==0){
            count++;
            completiontime = time;
            sumWait = sumWait + (completiontime-p[smallest].at-p[smallest].bt);
            sumTurnaround = sumTurnaround + (completiontime-p[smallest].at);
            printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d\t", p[smallest].id, p[smallest].at, p[smallest].priority, p[smallest].bt, completiontime, completiontime-p[smallest].at, completiontime-p[smallest].at-p[smallest].bt );
        }
    }
    printf("\nAvg wt = %.2lf\nAvg tat = %.2lf\n", sumWait/n, sumTurnaround/n);
}