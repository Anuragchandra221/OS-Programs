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
        p[i].rt = p[i].bt;
        p[i].completed = 0;
        p[i].id = i+1;
    }
    time = 0;
    printf("\nPId\tAt\tPrio\tBt\tCt\tTat\tWt");
    int temp;
    int smallAt = 0;
    while(count!=n){
        smallest = 0;
        temp = smallest;
        
        for(i=0; i<n; i++){
            if(p[i].completed==0){
                smallAt = p[i].at;
                break;
            }
        }
        for(i=0; i<n; i++){
            if(p[i].at<=time && p[i].at<=smallAt && p[i].completed==0){
                smallAt = p[i].at;
                smallest = i;
            }
        }
        if(p[smallest].at>=time){
            p[smallest].rt += (time - p[smallest].at);
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