#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *right, *left;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return newNode(data);

    else if (data < node->key)
    {
        node->left = insert(node->left, data);
    }

    else
    {
        node->right = insert(node->right, data);
    }

    return node;
}

int search(struct node *root, int x)
{
    if (root == NULL)
        return 0;

    int count = 0;
    if (root->key == x)
    {
        count = 1 + search(root->left, x) + search(root->right, x);
    }

    else
    {
        count += search(root->left, x) + search(root->right, x);
    }

    return count;
}

struct node *minvaluenode(struct node *root)
{
    struct node *current = root;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

struct node *deletefunction(struct node *root, int x)
{
    
        if (root == NULL)
            return;

        if (x < root->key)
        {
            root->left = deletefunction (root->left, x);
        }

        else if (x > root->key)
        {
            root->right = deletefunction(root->right, x);
        }

        else
        {

            if (root->left == NULL || root->right == NULL)
            {
                struct node *temp = root->left ? root->left : root->right;

                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }

                else
                    *root = *temp;
                free(temp);
            }

            else
            {
                struct node *temp = minvaluenode(root->right);
                root->key = temp->key;
                root->right = deletefunction (root->right, temp->key);
            }
        }
    
}

struct node *delete(struct node *root,int x){
    int k=search(root,x);
    if(k==0) return;

    else { int i;
        for(i=0;i<k;i++){
            deletefunction(root,x);
        }
    }

}

struct node *Buildtree(int *arr, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = left + (right - left) / 2;
    // the input is sorted so nthe logic of mergesort is used to find the mid elememt and a
    // add in the tree BST
    struct node *(root) = newNode(arr[mid]);
    (root)->left = Buildtree(arr, left, mid - 1);
    (root)->right = Buildtree(arr, mid + 1, right);

    return root;
}

void inorder(struct node *root)
{

    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main()
{
    int n;
    printf("enter the number of elements in the tree");
    scanf("%d", &n);

    int arr[n];
    printf("enter the elements of the tree:");

    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct node *root = NULL;

    // this is the function designed to build the tree and insert the elements of the array
    root = Buildtree(arr, 0, n - 1);
    printf("Inorder traversal of the tree after building it is:/n");
    inorder(root);

    printf("\n");

    printf("Enter the number of times you wan to insert");
    int insertimes;
    scanf("%d", &insertimes);
    for (i = 0; i < insertimes; i++)
    {
        int insertelement;
        printf("enter the element that you want to insert:");
        scanf("%d", &insertelement);
        insert(root, insertelement);
        printf("\n");
    }
    printf("inorder traversal after addding the elements");
    inorder(root);

    printf("Enter the no of times you want to search elements:");
    int searchtimes;
    scanf("%d", &searchtimes);
    for (i = 0; i < searchtimes; i++)
    {
        int searchelement;
        printf("enter the element to be searched");
        printf("/nSearch:");
        scanf("%d", &searchelement);
        int searchcount = search(root, searchelement);
        printf("the number of occurences are %d/n", searchcount);
        printf("\n");
    }

    printf("enter the times you want to delete the element");
    int deltimes;
    scanf("%d", &deltimes);
    for (i = 0; i < deltimes; i++)
    {
        int delelement;
        printf("enter the element to be deleted");
        printf("/nDelete:");
        scanf("%d", &delelement);
        delete (root, delelement);
    }
  printf("printing the inorder after deletion");
    inorder(root);
}