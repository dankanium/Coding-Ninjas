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

Node *findMid(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL or head->next->next == NULL)
        return head;
    Node *slow = head;
    Node *fast = head->next;
    while (slow != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == NULL or fast->next == NULL)
            return slow;
    }
}

Node *sort(Node *head1, Node *head2)
{
    if (head2 == NULL)
        return head1;
    Node *finalHead = NULL;
    Node *finalTail = NULL;
    if (head1->data <= head2->data)
    {
        finalHead = head1;
        finalTail = head1;
        head1 = head1->next;
    }
    else
    {
        finalHead = head2;
        finalTail = head2;
        head2 = head2->next;
    }
    while (head1 != NULL and head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            finalTail->next = head1;
            finalTail = head1;
            head1 = head1->next;
        }
        else
        {
            finalTail->next = head2;
            finalTail = head2;
            head2 = head2->next;
        }
    }
    if (head1 == NULL)
        finalTail->next = head2;
    else
        finalTail->next = head1;
    return finalHead;
}

Node *mergeSort(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    Node *mid = findMid(head);
    Node *head1 = head;
    Node *head2 = mid->next;
    mid->next = NULL;
    Node *sorted1 = mergeSort(head1);
    Node *sorted2 = mergeSort(head2);
    Node *finalHead = sort(sorted1, sorted2);
    return finalHead;
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
		head = mergeSort(head);
		print(head);
	}

	return 0;
}