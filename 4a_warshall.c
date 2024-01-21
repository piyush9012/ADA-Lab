#include <stdio.h>
#include <stdlib.h>

void warshall(int a[][20], int n)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = (a[i][j] || a[i][k] && a[k][j]);
}

void main()
{
    int n, a[20][20];
    printf("Enter number of nodes in the graph: \n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix for the graph: \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    warshall(a, n);
    printf("\nThe path matrix is: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf(" \n");
    }
}