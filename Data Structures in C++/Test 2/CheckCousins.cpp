#include<bits/stdc++.h>
using namespace std;
int level(BinaryTreeNode<int> *root, int node) 
{
    if (root == NULL)
        return 0;
    if (root->data == node)
        return 1;
    int l = level(root->left, node);
    int r = level(root->right, node);
}
bool checkCousin(BinaryTreeNode<int> *root, int a, int b) 
{
    if (level(root, a) == level(root, b) and !isSibling(root, a, b))
        return true;
    else
        return false;
}}
int main()
{
    
}