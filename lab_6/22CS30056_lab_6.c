/*
   Name:Sumit Kumar
   Roll No.-22CS30056
   Assignment-6
*/
#include <stdio.h>

int median;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// this is the max heapify function for the special heap
void max_heapify(int H[], int size, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < size && H[left] > H[largest])
        largest = left;

    if (right < size && H[right] > H[largest])
        largest = right;

    if (largest != i)
    {
        swap(&H[largest], &H[i]);
        max_heapify(H, size, largest);
    }
}

// this is min heapify function for thre min heap
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
        swap(&H[smallest], &H[i]);
        min_heapify(H, size, smallest);
    }
}

// this function builds the min_hepa part of the special heap
void build_MinHeap(int H[], int size)
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        min_heapify(H, size, i);
}

// this function builds the max_heap part of the special heap
void build_MaxHeap(int H[], int size)
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        max_heapify(H, size, i);
}

// this is insert function for pushing in the min heap
void push_minHeap(int H[], int x, int *size)
{
    H[*size] = x;
    int i = *size;
    int parent = (i - 1) / 2;
    (*size)++;
    while (parent >= 0 && H[parent] > H[i])
    {
        swap(&H[parent], &H[i]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

// this is the insert function for pushing in max heap
void push_maxHeap(int H[], int x, int *size)
{
    H[*size] = x;
    int i = *size;
    int parent = (i - 1) / 2;
    (*size)++;
    while (parent >= 0 && H[parent] < H[i])
    {
        swap(&H[parent], &H[i]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

int top(int H[])
{
    return H[0];
}

int isEmpty(int H[])
{
    return H[0] == 0 ? 1 : 0;
}

// this is the deletemin function for the special heap
void pop_minHeap(int H[], int *size)
{
    swap(&H[0], &H[*size - 1]);
    (*size)--;
    min_heapify(H, *size, 0);
}

// this is deletemax function for the special heap
int pop_maxHeap(int H[], int *size)
{
    int remove = H[0];
    swap(&H[0], &H[*size - 1]);
    (*size)--;
    max_heapify(H, *size, 0);
    return remove;
}

// this function justs prints the special array
void print(int H[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", H[i]);
    printf("\n");
}

// this function is used to find the medain of the complete function in the array
int findmedian(int H[])
{
    int count;
    int i;
    for (i = 0; i < sizeof(H) / sizeof(H[0]); i++)
    {
        if (H[i] != -1)
            count++;
    }

    int arr[count];
    int x = 0;
}

// this is special heap function creates which checks the conditions and then inserts accordinly
// to the max heap or the min heap part of the array
void insertspecialheap(int *h, int val, int size, int *minpos, int *maxpos, int *minsize, int *maxsize)
{   //this is the special heap creates as per the conditions
    if (val <= median)
    {
        if (minsize == maxsize)  // as the size of both the heaps was known we checked their size
        {
            int rem = pop_maxHeap(h, maxsize);  // we  removed from the max heap
            minpos--;
            push_minHeap(h, rem, minpos);  // the remov ed elem,ent was pushed to the minheap

            //after this the value was added to the maxheap
            push_maxHeap(h, val, maxpos);
        }

        else 
        {   //a s it was greater than the medain we added directly to the min heap back of the aaray
            push_maxHeap(h, val, maxpos);
        }
    }

    else
    {
        push_minHeap(h, val, minpos);
    }
}

// this code returns the dellete median function from the heap;
int deletemedian(int *h, int size, int *minpos, int *maxpos, int *minsize, int *maxsize)
{
    int rem = pop_maxHeap(h, maxsize);
    //this function removes the meadin from satrting 


    maxpos--;
    return rem;
}

// thi is medsort function which deleteds the root aand stores in the sorted part of the array
void medHeapsort(int *h, int size, int *minpos, int *maxpos, int *minsize, int *maxsize)
{
    if (maxpos == 0)
        return;

    int rem = pop_maxHeap(h, maxsize);  //this function removes the meadin from satrting 

    maxpos--;
    h[*maxpos + 1] = rem; // after deleting we added the median in the empty space as we
                          //alreasdy knew th eposition of the maxheap 

    medHeapsort(h, size, minpos, maxpos, minsize, maxsize);  
    //calling the function recursively to sort the array
}

int main()
{
    int n;  //scanning the value of size of the heap

    //these two are the storing the positions of the heap
    int maxpos = 0;
    int minpos = n - 1;

    scanf("%d", &n);  //scanning the value of the size

    //storint the sizes of the maxheap and the minheap
    int minsize = 0;
    int maxsize = 0;

    int heap[n];
    int i;

    // making the heap
    for (i = 0; i < n; i++)
    {
        printf("enter the value of x:");
        int x;
        scanf("%d", &x);

        if (i == 0)
        {   //as the inital median is the first element only so no change
            heap[0] = x;
            median = x;
            printf("median is:%d\n", median);
        }

        else
        {
            // this is the special heap function which builds the heap
            insertspecialheap(heap, x, n, &minpos, &maxpos, &minsize, &maxsize);

            //the findmedian is used to store and find the median
            median = findmedian(heap);
            printf("median is:%d\n", median);
        }
    }
    // printing the heap
    print(heap, n);

    // code for deletion of the meadian
    deletemedian(heap, n, &minpos, &maxpos, &minsize, &maxsize);
    // printing the heap
    print(heap, n);

    // the heap sort function
    medHeapsort(heap, n, &minpos, &maxpos, &minsize, &maxsize);
    // printing the heap
    print(heap, n);
}