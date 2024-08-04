#include <stdio.h>
#include<time.h>
#include<stdlib.h>
// Swap function to swap two elements
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for QuickSort
int myfunc(int a[], int lb, int ub){
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    
    while(start < end){
        while(a[start] <= pivot)
            start++;
        while(a[end] > pivot)
            end--;
        if(start < end)
            swap(&a[start], &a[end]);
    }
    swap(&a[lb], &a[end]);
    return end;
}

// QuickSort function
void quicksort(int a[], int lb, int ub){
    if(lb < ub){
        int pos = myfunc(a, lb, ub);
        quicksort(a, lb, pos - 1);
        quicksort(a, pos + 1, ub);
    }
}

int main()
{
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[10000];
    
    printf("Enter the array elements: ");
    for(i = 0; i < n; i++){
        a[i] = rand()%10;
    }
    
    int lb = 0;
    int ub = n - 1;
    clock_t start = clock();
    quicksort(a, lb, ub);
    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, timeTaken);

    printf("The sorted array elements are: ");
    for(i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }

    return 0;
}
