#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL; // efficient to add node at end
    while (data != -1)
    {
        Node *newNode = new Node(data); // Will not get deallocated until code is written for it
        // Node n(data);   // Can't create satically because as the scope ends, it gets deallocated
        if (head == NULL)
            head = newNode;
        else
        {
            // Not efficient as we traverse thru all nodes
            /*
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            */
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

Node* insertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while (count < i - 1 and temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
        /* OR
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
        */
    }
    return head;
}

Node *deleteNode(Node *head, int i)
{
    Node *temp = head;
    if (i == 0)
    {
        head = head->next;
        return head;
    }
    while (temp != NULL and i--)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}

void print(Node *head)
{
    Node *temp = head; // Head is safe by using this, other wise we'll change head
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    /*
    // Statically
    Node n1(1);       // Parameterized constructor, overriding default
    Node *head = &n1; // Head is pointer that points towards a Node object, thats why head pointer is of Node.
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    */

    /*
    // Dynamically
    Node *n3 = new Node(10);
    Node *head = n3;
    Node *n4 = new Node(20);
    n3->next = n4; // n4 is already a pointer
    Node *n5 = new Node(30);
    n4->next = n5;
    Node *n6 = new Node(40);
    n5->next = n6;
    Node *n7 = new Node(50);
    n6->next = n7;
    print(head);
    */

    Node *head = takeInput();
    print(head);
}