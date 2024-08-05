#include<stdio.h>
int x[100];
int c = 1;
void main(){
    int n;
    printf("enter  the no. of queens\n");
    scanf("%d",&n);
    nqueen(1,n);
}
void nqueen(int k,int n){
    for(int i=1;i<=n;i++){
        if(place(k,i)){
            x[k]=i;
            if(k==n){
                printboard(n);
            }
            else
            nqueen(k+1,n);
        }
    }
}

int place(int k, int i){
    for(int j=1;j<=k;j++){
        if((x[j]==i)||abs(x[j]-i) == abs(j-k))
        return 0;
    }
    return 1;
}

void printboard(int n){
    for(int i=1;i<=n;i++){
    for(int j =1;j<=n;j++){
        if(x[i]==j)
        printf("Q\t");
        else printf("-\t");
    }
      printf("\n"); }
}
