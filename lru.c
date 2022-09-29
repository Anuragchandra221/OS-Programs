#include<stdio.h>
int pages[100], n, np, hit=0, top=0, queue[10], distance[10];
int findtop(int stop){
    int i, j, count;
    for(i=0; i<n; i++){
        distance[i]=0;
        for(j=stop; j>=0; j--){
            
        if(queue[i]==pages[j]){
            distance[i]++;
            break;
        }else{
            distance[i]++;
        }
    }
    }
    int max = distance[0], pos=0;
    for(i=0; i<n; i++){
        if(distance[i]>max){
            max = distance[i];
            pos = i;
        }
    }
    return pos;
}
void push(int x, int stop){
    int i, flag=0;
    
    for(i=0; i<n; i++){
        
        if(queue[i]==x){
            flag = 1;
            hit++;
            break;
        }
    }
    if(flag==0){
        top = findtop(stop);
        queue[top] = x;
        
    }
    printf("\n");
    for(i=0; i<n; i++){
        printf("%d  ", queue[i]);
    }
}
int main(){
    int i;
    printf("Enter no of pages: ");
    scanf("%d", &np);
    printf("Enter no of frames: ");
    scanf("%d", &n);
    printf("Enter the pages: ");
    for(i=0; i<np; i++){
        scanf("%d", &pages[i]);
    }
    
    for(i=0; i<np; i++){
        if (i<n){
            queue[i] = pages[i];
            printf("%d  ", queue[i]);
        }else{
            push(pages[i], i);
        }
    }
    printf("\nHit is %d", hit);
    printf("Fault is %d", np-hit);
}