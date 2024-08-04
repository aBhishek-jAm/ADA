#include <stdio.h>

/*int min(int a,int b){
    return (a < b) ? a : b;
}
*/
void main()
{
  int n, i, j, a[100][100];
  printf("enter the no. of elements\n");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  warshell(a, n);
}
void warshell(int a[][100], int n)
{
  int i, j, k;

  for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        a[i][j] = a[i][j] || (a[i][k] && a[k][j]);

  printf("the distance matrix is:\n");
  for (i = 0; i < n; i++)
  {
    printf("\n");
    for (j = 0; j < n; j++)
      printf("%d\t", a[i][j]);
  }
}
