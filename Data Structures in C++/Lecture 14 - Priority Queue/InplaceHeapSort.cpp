#include <bits/stdc++.h>
using namespace std;
void inplaceHeapSort(int pq[], int n)
{
    // build heap in array
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    // remove elements
    int size = n;
    while (size > 1)
    {
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size - 1] = temp;
        size--;
        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;
        while (leftChildIndex < size)
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
                minIndex = leftChildIndex;
            if (pq[minIndex] > pq[rightChildIndex] and rightChildIndex < size)
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
    }
}
int main()
{
}