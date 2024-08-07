#include <stdio.h>
#include <stdlib.h>

int maxi(int a, int b)
{
    return (a > b) ? a : b;
}

void main()
{
    int n, i, profit[10], weight[10], m, j, a[11][11];

    printf("Enter the number of items\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter the weight and profit for item %d\n", i);
        scanf("%d%d", &weight[i], &profit[i]);
    }

    printf("Enter the capacity\n");
    scanf("%d", &m);

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                a[i][j] = 0;
            }
            else if (weight[i] <= j)
            {
                a[i][j] = maxi(a[i - 1][j], (profit[i] + a[i - 1][j - weight[i]]));
            }
            else
            {
                a[i][j] = a[i - 1][j];
            }
        }
    }
    for (i = 0; i <= n; i++)
    {
        printf("\n");
        for (j = 0; j <= m; j++)
        {
            printf(" %d\t", a[i][j]);
        }
    }
}
