#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* right;
    struct node* left;

    int info;

}Node;

void printArray(int array[])
{
    printf("Path: ");
    for(int i = 0; array[i] != 0; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void clearArray(int array[], int Size)
{
    for(int i = 0; i < Size; i++) // doesnt clear head
    {
        array[i] = 0;
    }
}

/*void freeTree(Node head)
{
    
}*/

int main()
{
    Node head;
    head.right = NULL;
    head.left = NULL;
    int path[50] = {0};

    int total;
    printf("How many nodes?\n");
    scanf("%d", &total);

    printf("Head info\n");
    scanf("%d", &head.info);

    int info;
    for(int i = 0; i < total-1; i++)
    {
        Node* current = &head;
        printf("Add another node. \n");
        scanf("%d", &info);

        int c = 0;
        while(1)
        {
            path[c] = current->info;

            if(info > current->info)
            {
                if(current->right == NULL)
                {
                    current->right = (Node*)malloc(sizeof(Node));
                    current->right->info = info;

                    printArray(path);
                    clearArray(path, 50);
                    break;
                }else{
                    current = current->right;
                }
            }
            if(info < current->info)
            {
                if(current->left == NULL)
                {
                    current->left = (Node*)malloc(sizeof(Node));
                    current->left->info = info;
                    
                    printArray(path);
                    clearArray(path, 50);
                    break;
                } else{
                current = current->left;
                }
            }
            c++;
        }
    }

    //freeTree(head);

}