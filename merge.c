#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void conquer(int a[],int low,int mid,int high){
int i = low;
int j = mid+1;
int k = low;
int c[10000];
while(i<=mid && j<= high){
    if(a[i]<a[j])
    c[k++] = a[i++];
    else
    c[k++] = a[j++];
    }
while(i<=mid)
c[k++] = a[i++];
while( j<= high)
c[k++] = a[j++];
for(i=low;i<=high;i++)
a[i] = c[i];
}

void divide(int a[],int low,int high){
    int mid;
    if(low<high){
        mid = (low + high) /2;
        divide(a,low,mid);
        divide(a,mid+1,high);
        conquer(a,low,mid,high);
    }
}

void main(){
    int  n;
    printf("enter the n value\n");
    scanf("%d",&n);
    int a[100022];
    for(int i=0;i<n;i++){
        a[i] = rand()%10;
    }
    clock_t start = clock();
    divide(a,0,n-1);
    clock_t end = clock();
double timetaken = ((double)end - start)/CLOCKS_PER_SEC;
    printf("%d elemets are sorted in %f\n",n,timetaken);
}
