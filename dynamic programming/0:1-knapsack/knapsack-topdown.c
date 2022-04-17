#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsack(int wt[], int val[], int W, int n)
{
    int t[W + 1][n + 1];
    for (int i = 0; i < W + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (wt[j - 1] <= i)
            {
                t[i][j] = max(val[j - 1] + t[i - wt[j - 1]][j - 1], t[i][j - 1]);
            }
            else
            {
                t[i][j] = t[i][j - 1];
            }
        }
    }
    return t[W][n];
}

int main()
{
    int wt[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int val[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int capacity = 8;
    int n = 8;

    printf("%d", knapsack(wt, val, capacity, n));
    return 0;
}