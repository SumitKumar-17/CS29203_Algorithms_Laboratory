#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printarray(int *arr)
{
    int size = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    // printf("%d&&", size);

    for (i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }

    printf("\n");
}

void min_heapify(int H[], int size, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < size && H[left] < H[smallest])
        smallest = left;

    if (right < size && H[right] < H[smallest])
        smallest = right;

    if (smallest != i)
    {
        int temp = H[smallest];
        H[smallest] = H[i];
        H[i] = temp;
        // swap(&H[smallest], &H[i]);
        min_heapify(H, size, smallest);
    }
}

void build_MinHeap(int H[], int size)
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        min_heapify(H, size, i);
}

void kthlargest(int *arr, int k, int n)
{

    int heap[k];

    int i;
    for (i = 0; i < k; i++)
    {
        heap[i] = arr[i];
    }

    build_MinHeap(heap, k);
    // printf("%d&&", k);

    for (i = k; i < n; i++)
    {
        if (arr[i] > heap[0])
        {
            heap[0] = arr[i];
            min_heapify(heap, k, 0);
        }
    }

    printf("the k largest elements are:");

    for (i = 0; i < k; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");
}

int main()
{
    int n;
    int k;
    printf("enter the vaue of k:");
    scanf("%d", &k);

    printf("enter the size of array:");
    scanf("%d", &n);
    printf("enter the elements:");

    int arr[n];
    int i;
    for (i = 0; i < n; i++)
    {

        scanf("%d ", &arr[i]);
    }

    kthlargest(arr,k,n);
}