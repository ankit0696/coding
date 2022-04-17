#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int t[100][100];

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (t[W][n] != -1)
        return t[W][n];

    if (wt[n - 1] <= W)
    {
        return t[W][n] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }
    else
    {
        return t[W][n] = knapsack(wt, val, W, n - 1);
    }
}

int main()
{
    memset(t, -1, sizeof(t));

    int wt[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int val[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(wt) / sizeof(wt[0]);

    printf("%d", knapsack(wt, val, 8, 8));

    return 0;
}