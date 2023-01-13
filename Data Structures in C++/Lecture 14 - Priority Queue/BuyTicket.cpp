#include <iostream>
#include <vector>
using namespace std;
#include <queue>

int buyTicket(int *arr, int n, int k)
{
    int time = 0;
    queue<int> q;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) 
    {
        q.push(i);
        pq.push(arr[i]);
    }
    while (true)
    {
        if (arr[q.front()] == pq.top())
        {
            if (k == q.front())
                return time + 1;
            time++;
            pq.pop();
        }
        q.push(q.front());
        q.pop();
    }
}
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}