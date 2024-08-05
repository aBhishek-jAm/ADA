#include<stdio.h>

int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W, int wt[], int p[], int n)
{
   int i, j;
   int V[10][10];

   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= W; j++)
       {
           if (i==0 || j==0)
               V[i][j] = 0;
           else if (wt[i] <= j)
                 V[i][j] = max( V[i-1][j],p[i] + V[i-1][j-wt[i]]);
           else
                 V[i][j] = V[i-1][j];
       }
   }

   return V[n][W];
}

int main()
{
    int i, n, p[20], wt[20], W;

    printf("Enter number of items:");
    scanf("%d", &n);

    printf("Enter value and weight of items:\n");
    for(i = 1;i <= n; ++i){
    	scanf("%d%d", &p[i], &wt[i]);
    }

    printf("Enter size of knapsack:");
    scanf("%d", &W);

    printf("Max Profit=%d", knapSack(W, wt, p, n));
    return 0;
}
