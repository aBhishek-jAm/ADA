#include <stdio.h>


int main() {
    int c[10][10], d[10], i, j, s, n;
    printf("Enter n value: ");
    scanf("%d", &n);
    printf("Enter the graph data:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &c[i][j]);
    printf("Enter the source node: ");
    scanf("%d", &s);
    dijkstra(c, n, s, d);
    for (i = 0; i < n; i++)
        printf("Shortest distance from %d to %d is %d\n", s, i, d[i]);
    return 0;
}

void dijkstra(int cost[][10], int n, int s, int dist[10]) {
    int visit[10], i, u, count;
    for (i = 0; i < n; i++) {
        visit[i] = 0;
        dist[i] = cost[s][i];
    }
    visit[s] = 1;
    dist[s] = 0;
    count = 1;
    while (count < n) {
        int min = 999;
        for (i = 0; i < n; i++) {
            if (dist[i] < min && visit[i] == 0) {
                min = dist[i];
                u = i;
            }
        }
        visit[u] = 1;
        count++;
        for (i = 0; i < n; i++) {
            if (dist[i] > dist[u] + cost[u][i]) {
                dist[i] = dist[u] + cost[u][i];
            }
        }
    }
}
