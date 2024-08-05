

#include <stdio.h>
#include <stdlib.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10], parent[10];

int find(int p) {
    while (parent[p])
        p = parent[p];
    return p;
}

int uni(int r, int s) {
    if (r != s) {
        parent[s] = r;
        return 1;
    }
    return 0;
}

int main() {
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    for (i = 0; i < n; i++) {
        parent[i] = 0;
    }

    while (ne < n) {
        for (i = 0, min = 999; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("\n%d: (%d -> %d) cost = %d", ne++, a+1, b+1, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n Minimum cost = %d\n", mincost);

    return 0;
}
