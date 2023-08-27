/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

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
