#include <stdio.h>
#include <stdlib.h>

int minSubsetSumDiff(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                if (i == 0)
                    t[i][j] = 0;
                if (j == 0)
                    t[i][j] = 1;
            }

            else if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    int size = 0;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (t[n][i] == 1)
        {
            size++;
        }
    }

    int V[size];
    int k = 0;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (t[n][i] == 1)
        {
            V[k] = i;
            k++;
        }
    }

    return sum - 2 * V[k - 1];
}

int main()
{
    int arr[] = {1, 9, 7, 4};
    int n = 4;

    printf("%d", minSubsetSumDiff(arr, n));
    return 0;
}