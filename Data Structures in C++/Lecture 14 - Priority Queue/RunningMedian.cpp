#include <iostream>
using namespace std;
#include <queue>
void findMedian(int *arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    maxHeap.push(arr[0]);
    cout << arr[0] << " ";
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxHeap.top())
            minHeap.push(arr[i]);
        else
            maxHeap.push(arr[i]);
        if (maxHeap.size() - minHeap.size() > 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (i % 2 == 0)
        {
            if (maxHeap.size() > minHeap.size())
                cout << maxHeap.top() << " ";
            else
                cout << minHeap.top() << " ";
        }
        else
        {
            cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    findMedian(arr, n);

    delete[] arr;
}
