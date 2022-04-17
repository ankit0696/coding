#include <stdio.h>
int subsetSum(int arr[], int sum, int n)
{
    int t[sum + 1][n + 1];
    for (int i = 0; i < sum + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                if (j == 0)
                    t[i][j] = 0;
                if (i == 0)
                    t[i][j] = 1;
            }
            else if (arr[j - 1] <= i)
            {
                t[i][j] = t[i - arr[j - 1]][j - 1] || t[i][j - 1];
            }
            else
            {
                t[i][j] = t[i][j - 1];
            }
        }
    }

    return t[sum][n];
}

int equalSum(int arr[], int n)
{
    if (n == 0)
    {
        return 1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return 0;
    }

    return subsetSum(arr, sum / 2, n);
}

int main()
{
    int arr[] = {1, 5, 11, 5};
    int n = 4;
    printf("%d", equalSum(arr, n));
    return 0;
}