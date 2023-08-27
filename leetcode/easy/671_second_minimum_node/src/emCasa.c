#include<stdio.h>
#include<stdlib.h>
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void findSmallest(struct TreeNode* node, int* smallestValue, int* secondSmallest);

int findSecondMinimumValue(struct TreeNode* root);

int main()
{
    struct TreeNode Tree1;
    struct TreeNode node2;
    struct TreeNode node3;
    node2.left = NULL;
    node2.right = NULL; 
    node3.left = NULL;
    node3.right = NULL;
       
    Tree1.val = 1;
    Tree1.left = &node2;
    Tree1.right = &node3;
    node2.val = 2;
    node3.val = 3;
    printf("%d\n", findSecondMinimumValue(&Tree1));
}

void findSmallest(struct TreeNode* node, int* smallestValue, int* secondSmallest)
{
    if(node->val != *smallestValue && *secondSmallest <= *smallestValue)
    {
        *secondSmallest = node->val;
    }

    if(node->val > *smallestValue && node->val < *secondSmallest)
    {
        *secondSmallest = node->val;
    }

    if(node->left != NULL)
    {
        findSmallest(node->left, smallestValue, secondSmallest);
    }
    if(node->right != NULL)
    {
        findSmallest(node->right, smallestValue, secondSmallest);
    }
}

int findSecondMinimumValue(struct TreeNode* root){
    int smallestValue = root->val;
    int secondSmallest = -1;

    findSmallest(root, &smallestValue, &secondSmallest);
    return secondSmallest;

}
