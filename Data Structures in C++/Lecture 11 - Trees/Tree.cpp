#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children; // by default TreeNode is TreeNode<int>
    TreeNode(T data)
    {
        this->data = data;
    }
};
void printTree(TreeNode<int> *root)
{
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data: ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    cout << "Enter no. of children: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes; // queue is used to  maintain nodes for which we'll take input level wise and pop when its done
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter no. of children of " << front->data << ": ";
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            cout << "Enter data of " << i << "th child: ";
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData); // if child creadted statically then memory will be deallocated when scope ends
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}
void printTreeLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ", ";
            pendingNodes.push(front->children[i]);
        }
        pendingNodes.pop();
    }
}
int main()
{
    /*
    TreeNode<int> *root = new TreeNode<int>(10);
    TreeNode<int> *node1 = new TreeNode<int>(20);
    TreeNode<int> *node2 = new TreeNode<int>(30);
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    // TODO delete tree
}