#include <stdio.h>
void selection(int arr[], int n)
{
    int j, i, min_i, temp;
    for (j = 0; j < n - 1; j++)
    {
        min_i = j;
        for (i = j + 1; i < n; i++)
        {
            if (arr[i] < arr[min_i])
            {
                min_i = i;
            }
        }
        temp = arr[j];
        arr[j] = arr[min_i];
        arr[min_i] = temp;
    }
}
int main()
{
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selection(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

