// Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
//  'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
#include <iostream>

using namespace std;

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
Node *reverse(Node *head)
{
	if (head == NULL or head->next)
		return head;
	Node *newHead = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}
Node *kReverse(Node *head, int k)
{
	if (head == NULL or k == 0 or k == 1)
		return head;
	Node *temp = head;
	Node *tail = NULL;
	int count = k-1;
	while(count and temp != NULL)
	{
		temp = temp->next;
		count--;
	}
	Node *newTail = kReverse(temp, k);
	temp->next = NULL;
	tail = head;
	Node *newHead = reverse(head);
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
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}