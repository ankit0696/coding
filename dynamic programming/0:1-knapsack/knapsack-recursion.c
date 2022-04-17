#include <stdio.h>
int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }
    else
    {
        return knapsack(wt, val, W, n - 1);
    }
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