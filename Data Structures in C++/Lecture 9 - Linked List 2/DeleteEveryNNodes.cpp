    // You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
    // To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
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

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if (head == NULL)
        return head;
    Node *current = head;
    if (M == 0 and N > 0) // when only delete
        return NULL;
    if (M > 0 and N == 0) // when only skip
        return head;
    while (current != NULL)
    {
        int m = M-1; // m = M-1 because current is already pointing there, i.e. current is at head
        int n = N;
        while (m--)
        {
            current = current->next; // going next node
            if (current == NULL) // go no further than scope
                return head;
        }
        while (n--)
        {
            Node *temp = current->next; // current->next because we need current, as here we are keeping it as node for traversing
            current->next = current->next->next; // skipping next node
            delete temp;
            if (current->next == NULL) // what if nodes end here
                return head;
        }
        current = current->next; // going next node
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}