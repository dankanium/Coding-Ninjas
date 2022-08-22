// For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
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

Node *evenAfterOdd(Node *head)
{
	//write your code here
    if (head == NULL or head->next == NULL)
        return head;
    Node *oddHead = NULL;
    Node *evenHead = NULL;
    Node *oddTail = NULL;
    Node *evenTail = NULL;
    while (head != NULL)
    {
        if (head->data % 2 == 0) // even element
        {
            if (evenHead == NULL) // initializing even head and tail
            {
                evenHead = head;
                evenTail = head;
            }
            else // chaining next nodes
            {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }
        else // odd element
        {
            if (oddHead == NULL) // initializing odd head and tail
            {
                oddHead = head;
                oddTail = head;
            }
            else // chaining next nodes
            {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        head = head->next; // going to next nodes
    }
    if (oddHead == NULL) // if all nodes are even
        return evenHead;
    else if (evenHead == NULL) // if all nodes are odd
        return oddHead;
    evenTail->next = NULL; // terminating even node
    oddTail->next = evenHead; // chaining odd nodes to even
    return oddHead;
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

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}