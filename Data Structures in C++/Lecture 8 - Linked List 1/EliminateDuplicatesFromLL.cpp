// You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.
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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    if (head == NULL)
        return NULL;
    Node *current = head;
    Node *nextNode = current->next;
    while (current != NULL)
    {
        if (current->data == nextNode->data)
        {
            Node *temp = nextNode;
            nextNode = nextNode->next;
            current->next = nextNode;
            delete temp;
            if (nextNode == NULL)
                return head;
            continue;
        }
        current = nextNode;
        nextNode = nextNode->next;
        if (nextNode == NULL)
            return head;
    }
    return head;
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
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}