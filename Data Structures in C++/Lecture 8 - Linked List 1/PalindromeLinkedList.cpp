// You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = current->next;
    while (current != NULL)
    {
        current->next = prev;
        prev = current;
        current = next;
        if (current == NULL)
            return prev;
        next = next->next;
    }
}

bool isPalindrome(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    temp = head;
    for (int i = 0; i < (length - 1) / 2; i++)
    {
        temp = temp->next;
    }
    Node *halfList = temp->next;
    Node *halfHead = reverse(halfList);
    while (halfHead != NULL)
    {
        if (halfHead->data == head->data)
        {
            head = head->next;
            halfHead = halfHead->next;
        }
        else
            return false;
    }
    return true;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}