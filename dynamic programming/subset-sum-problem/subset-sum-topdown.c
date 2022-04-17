#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 6;
    int n = 5;

    printf("%d", subsetSum(arr, sum, n));
    return 0;
}