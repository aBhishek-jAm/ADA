#include<stdio.h>
#include<stdlib.h>
int d,x[10],a[10];

void subset(int s,int k,int r){
    x[k] = 1;
    int i;
    if(s + a[k] == d){
        printf("\nsolution:\n");
        for(i = 0; i <= k ; i++){
            if(x[i] == 1)
        printf("%d\t",a[i]);
            
        }
    }
    else if(s + a[k] + a[k+1] <= d)
    subset(s + a[k] , k + 1 , r - a[k]);

    if(s + a[k + 1] <= d && s + r - a[k] >= d){
        x[k]=0;
        subset(s ,k + 1 ,r - a[k]);
    }

}


void main(){
int i,n,sum=0;

printf("enter the no. of elements\n");
scanf("%d",&n);
printf("\nenter teh elements\n");
for(i = 0;i < n; i++){
scanf("%d",&a[i]);
sum+=a[i];
}
printf("enter the max value\n");
scanf("%d",&d);
if(sum < d || a[0] > d)
exit(0);
else
subset(0,0,sum);

}
