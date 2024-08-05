#include<stdio.h>
#include<stdlib.h>
int i,n,j,u,k,v,a[10][10],t[10],in[10]={0};
int stack[10],top=-1;
void main(){
    printf("enter the no. of elemets\n");
    scanf("%d",&n);
    printf("\nenter the matrix\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);

    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(a[i][j]==1)
    in[j]++;
    
    for(i=0;i<n;i++)
    if(in[i]==0)
    stack[++top] = i;
    
    while(top!=-1){
        u = stack[top--];
        t[k++] = u;
        for(v=0;v<n;v++)
        if(a[u][v]==1){
            in[v]--;
            if(in[v]==0)
            stack[++top]=v;
        }
    }
    printf("\n the sorted elements are\n");
    for(i=0;i<n;i++)
    printf("%d",t[i]+1);
    
}
