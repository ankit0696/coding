#include <stdio.h>

int subsetSum(int arr[], int sum, int n)
{
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
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 10;
    int n = 5;

    printf("%d", subsetSum(arr, sum, n));
    return 0;

    return 0;
}