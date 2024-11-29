#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
// For Queue Size
#define SIZE 5000

// A tree node
struct node
{
    int data;
    struct node *right, *left;
};

// A queue node
struct Queue
{
    int front, rear;
    int size;
    struct node **array;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Queue *createQueue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    int i;
    queue->front = queue->rear = -1;
    queue->size = size;

    queue->array = (struct node **)malloc(queue->size * sizeof(struct node *));

    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;

    return queue;
}

int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

int isFull(struct Queue *queue)
{
    return queue->rear == queue->size - 1;
}

int hasOnlyOneItem(struct Queue *queue)
{
    return queue->front == queue->rear;
}

void Enqueue(struct node *root, struct Queue *queue)
{
    if (isFull(queue))
        return;

    queue->array[++queue->rear] = root;

    if (isEmpty(queue))
        ++queue->front;
}

struct node *Dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return NULL;

    struct node *temp = queue->array[queue->front];

    if (hasOnlyOneItem(queue))
        queue->front = queue->rear = -1;
    else
        ++queue->front;

    return temp;
}

struct node *getFront(struct Queue *queue)
{
    return queue->array[queue->front];
}

int hasBothChild(struct node *temp)
{
    return temp && temp->left && temp->right;
}

void insert(struct node **root, int data, struct Queue *queue)
{

    struct node *temp = newNode(data);

    if (!*root)
        *root = temp;
    else
    {
        struct node *front;
        front = getFront(queue);
        while (front->data == -1)
        {
            Dequeue(queue);
            front = getFront(queue);
        }
        if (!front->left)
            front->left = temp;

        else if (!front->right)
            front->right = temp;

        if (hasBothChild(front))
        {
            if (front->left->data == -1)
            {
                front->left = NULL;
            }
            if (front->right->data == -1)
            {
                front->right = NULL;
            }
            Dequeue(queue);
        }
    }

    Enqueue(temp, queue);
}

void levelOrder(struct node *root)
{
    struct Queue *queue = createQueue(SIZE);

    Enqueue(root, queue);

    while (!isEmpty(queue))
    {
        struct node *temp = Dequeue(queue);

        printf("%d ", temp->data);

        if (temp->left)
            Enqueue(temp->left, queue);

        if (temp->right)
            Enqueue(temp->right, queue);
    }
    printf("\n");
}

struct node *lowestCommonAncestorRecursively(struct node *root, struct node *node1, struct node *node2)
{

    if (root->data > node1->data && root->data > node2->data)
    {
        return lowestCommonAncestorRecursively(root->left, node1, node2);
    }

    else if (root->data < node1->data && root->data < node2->data)
    {
        return lowestCommonAncestorRecursively(root->right, node1, node2);
    }

    else
    {
        return root;
    }
}

struct node *findNodeRecursively(struct node *root, int data)
{
    if (!root)
    {
        return NULL;
    }
    if (root->data == data)
    {
        return root;
    }
    else if (root->data < data)
    {
        return findNodeRecursively(root->right, data);
    }
    else
    {
        return findNodeRecursively(root->left, data);
    }
}

struct node *findNodeIteratively(struct node *root, int data)
{
    while (root)
    {
        if (data == root->data)
        {
            return root;
        }
        else if (data > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
}

int findSuitableNode(struct node *root, struct node *toFind, int sum[], int height, int threshold)
{
    if (!root)
    {
        return 0;
    }
    int child;
    if (root->data == toFind->data)
    {
        if (sum[height] < threshold)
        {
            return root->data;
        }
        else
        {
            return -1;
        }
    }
    else if (root->data < toFind->data)
    {
        child = findSuitableNode(root->right, toFind, sum, height + 1, threshold);
    }
    else
    {
        child = findSuitableNode(root->left, toFind, sum, height + 1, threshold);
    }
    if (child == -1)
    {
        if (sum[height] < threshold)
        {
            return root->data;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return child;
    }
}

int findHeightOfNode(struct node *root, struct node *toFind)
{
    if (!root)
    {
        return -1;
    }
    if (root == toFind)
    {
        return 0;
    }
    else if (root->left->data < toFind->data)
    {
        return (findHeightOfNode(root->right, toFind) + 1);
    }
    else
    {
        return (findHeightOfNode(root->left, toFind) + 1);
    }
}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
         
        // Compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        // Use the larger one
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL){
        printf("%d ",-1);
        return;
    }
        
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
// Print nodes at a current level

int getHeightOfTreeRecursively(struct node *root)
{
    if (!root->left && !root->right)
    {
        return 0;
    }
    int left;
    if (root->left)
    {
        left = getHeightOfTreeRecursively(root->left);
    }
    int right;
    if (root->right)
    {
        left = getHeightOfTreeRecursively(root->right);
    }
    return (MAX(left, right) + 1);
}

struct node* deleteNode(struct node* root, int k)
{

    if (root == NULL)
        return root;

    if (root->data > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
 
   
    if (root->left == NULL) {
        struct node* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        struct node* temp = root->left;
        free(root);
        return temp;
    }

    else {
 
        struct node* succParent = root;

        struct node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        root->data = succ->data;
 
    
        free(succ);
        return root;
    }
}



void deleterange(struct node *root,int min,int max,struct node *rootcpy){
    if(root==NULL) return;

    else if(root->data>max||root->data<min) deleteNode(rootcpy,root->data);

    deleterange(root->left,min,max,rootcpy);
    deleterange(root->right,min,max,rootcpy);
}
int main()
{

    int m,i;
    struct node *root = NULL;
    struct Queue *queue = createQueue(SIZE);
    scanf("%d", &m); //enter the size of array
    
    int *array = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
    {
        scanf("%d", &array[i]);
    }
    int min;
    printf("\nmin:");
    scanf("%d",&min);
    int max;
    printf("\nmax:");
    scanf("%d",&max);
    printf("\n");

    for (i = 0; i < m; ++i)
    {
        insert(&root, array[i], queue);
    }
     
     //this p[rintorder was to check the that tree is correctly printed or not
    // printf("Level Order traversal of binary tree is \n");
    // printLevelOrder(root);
    deleterange(root,min,max,root);
     printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);

    return 0;
}