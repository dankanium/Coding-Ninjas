#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Queue 
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    public:
    Queue()
    {
        data = new T[5];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 5;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T data)
    {
        if (size == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        this->data[nextIndex++] = data;
        nextIndex = (nextIndex + 1) % capacity; 
    }
};
int main()
{
    
}