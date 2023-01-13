#include <iostream>
using namespace std;
#include <vector>
#include <climits>
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        if (isEmpty()) {
            pq.push_back(element);
            return;
        }
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex]) {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if (isEmpty())
            return INT_MIN;
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;
        while (leftChildIndex < pq.size()) {
            int maxIndex = parentIndex;
            if (pq[maxIndex] < pq[leftChildIndex])
                maxIndex = leftChildIndex;
            if (pq[maxIndex] < pq[rightChildIndex] and rightChildIndex < pq.size())
                maxIndex = rightChildIndex;
            if (maxIndex == parentIndex)
                break;
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[maxIndex];
            pq[maxIndex] = temp;
            parentIndex = maxIndex;
            leftChildIndex = parentIndex * 2 + 1;
            rightChildIndex = parentIndex * 2 + 2;
            return ans;
        }
    }

    int getSize() {
        // Implement the getSize() function here
        if (isEmpty())
            return 0;
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        if (pq.size() == 0)
            return true;
        return false;
    }
};

void heapSort(int arr[], int n) {
    PriorityQueue pq;
    for (int i = 0; i < n; i++) {
        pq.insert(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pq.removeMax();
    }
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}