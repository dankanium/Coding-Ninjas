// You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.

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

Node *deleteNode(Node *head, int i)
{
    if (head == NULL)
        return NULL;
    Node *current = head;
    Node *next = current->next;
    int count = 0;
    
    if (i == 0)
    {
        head = head->next;
        return head;
    }
    while (count < i-1 and current != NULL)
    {
        current = next;
        next = next->next;
        if (next == NULL)
            return head;
        count++;
    }
    if (current == NULL or next == NULL)
        return head;
    current->next = next->next;
    delete next;
    return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}