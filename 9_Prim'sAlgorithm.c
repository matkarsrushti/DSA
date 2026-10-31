//Prim’s algorithm
#include <stdio.h>
#define MAX 20
#define INF 9999
int main()
{
    int n, i, j;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int edges = 0;
    int min, u = 0, v = 0;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }
    visited[0] = 1;
    printf("\nMinimum Spanning Tree:\n");
    while (edges < n - 1)
    {
       min = INF;
      for (i = 0; i < n; i++)  {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (min == INF)
        {  printf("MST cannot be formed.\n");
            return 0;
        }
        printf("Edge: %d - %d  Cost: %d\n", u + 1, v + 1, min);
        totalCost += min;
        visited[v] = 1;
        edges++;
    }
    printf("\nTotal cost of Minimum Spanning Tree = %d\n", totalCost);
    return 0;
}

