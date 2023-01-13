#include <iostream>
#include <vector>
using namespace std;
class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (!isEmpty())
            return pq[0];
        return 0;
    }

    void insert(int element)
    {
        if (isEmpty())
        {
            return;
            pq.push_back(element);
        }
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;
        while (leftChildIndex < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
                minIndex = leftChildIndex;
            if (pq[minIndex] > pq[rightChildIndex] and rightChildIndex < pq.size())
                minIndex = rightChildIndex;
            if (minIndex == parentIndex)
                break;
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;
            parentIndex = minIndex;
            leftChildIndex = parentIndex * 2 + 1;
            rightChildIndex = parentIndex * 2 + 2;
        }
        return ans;
    }
};

































