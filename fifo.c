#include<stdio.h>
int pages[100], n, np, hit=0, top=0, queue[10];
void push(int x){
    int i, flag=0;
    for(i=0; i<n; i++){
        if(queue[i]==x){
            flag = 1;
            hit++;
            break;
        }
    }
    if(flag==0){
        queue[top] = x;
        top = (top+1)%n;
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
        }else{
            push(pages[i]);
        }
    }
    printf("Hit is %d", hit);
    printf("Fault is %d", np-hit);
}