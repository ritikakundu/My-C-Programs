#include <stdio.h>
void mergesort(int *, int, int);
void merge(int *, int, int, int);
int main()
{
    int i, j, n;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements->");
    for (i = 0; i < n; i++)
    {
        scanf("\n%d", &a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("Final array:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
void mergesort(int *a, int beg, int end)
{
    if(beg < end)
    {
        int mid = (beg + end) / 2;
        mergesort(a, beg, mid);
        mergesort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}
void merge(int *a, int beg, int mid, int end)
{
    int n, i = beg, j = mid + 1, index = 0, temp[end-beg+1];
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            temp[index] = a[i];
            i++;
            index++;
        }
        else
        {
            temp[index] = a[j];
            j++;
            index++;
        }
    }
    if (i > mid)
    {
        while (j <= end)
        {
            temp[index] = a[j];
            index++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[index] = a[i];
            index++;
            i++;
        }
    }
    int k = 0;
    while (k < index)
    {
        a[k] = temp[k];
        k++;
    }
}
