#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

void print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " : " << endl;
    if (root->left != NULL)
        cout << "L : " << root->left->data;
    if (root->left != NULL)
        cout << "R : " << root->right->data;
    print(root->left);
    print(root->right);
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data: ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        cout << "Enter left child of "<< front->data << " : ";
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        int rightChildData;
        cout << "Enter right child of "<< front->data << " : ";
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        cout << "L:";
        if (front->left != NULL)
        {
            cout << front->left->data;
            pendingNodes.push(front->left);
        }
        else 
            cout << -1;
        cout << ",R:";
        if (front->right != NULL)
        {
            cout << front->right->data;
            pendingNodes.push(front->right);
        }
        else
            cout << -1;
        cout << endl;
    }
}

int countNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 1; // because there is a root node
    int leftAns = countNode(root->left); // count from left
    int rightAns = countNode(root->right); // count from right
    return ans + leftAns + rightAns;

    // or simply
    // return 1 + countNode(root->left) + countNode(root->right);
}

void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    /*
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    */
    BinaryTreeNode<int> *root = takeInputLevelWise();
    inorder(root);
    delete root;
}