#include <stdio.h>

int mini(int *arr, int x, int n, int count)
{
    if (x == 0)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 1 && arr[i] != -1)
                flag = 1;
        }
        if (flag)
            return mini(arr, n - 1, n, count);
        else
            printf("%d", count);
        return;
    }
    if (arr[x] == -1)
        mini(arr, x - 1, n, count);
    else if (arr[x] == 0)
    {
        if (arr[(x - 1) / 2] > 1)
        {
            arr[(x - 1) / 2] -= 1;
            arr[x] = 1;
            count += 1;
            return mini(arr, x - 1, n, count);
        }
        else
            return mini(arr, x - 1, n, count);
    }
    else if (arr[x] == 1)
        return mini(arr, x - 1, n, count);
    else if (arr[x] > 1)
    {
        arr[(x - 1) / 2] += arr[x] - 1;
        count += arr[x] - 1;
        arr[x] = 1;
        return mini(arr, x - 1, n, count);
    }
    else
        return mini(arr, x - 1, n, count);
    return count;
}

int main()
{
    int n;
    printf("No. of Nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the Tree: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Minimum no of steps: ");
    mini(arr, n - 1, n, 0);
    return 0;
}