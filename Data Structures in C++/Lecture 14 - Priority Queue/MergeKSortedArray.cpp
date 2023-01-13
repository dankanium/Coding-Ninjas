#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <bits/stdc++.h>
class triplet
{
    public:
        int element, arrIndex, eleIndex;
};
vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    /*
    vector<int> ans;
    priority_queue <triplet, vector<triplet>, greater<triplet>> pq;
    for (int i = 0; i < input.size(); i++)
    {
        triplet t;
        vector<int> *v = input[i];
        t.element = v->at(0);
        t.arrIndex = i;
        t.eleIndex = 0;
        pq.push(t);
    }
    while (!pq.empty())
    {
        triplet t = pq.top();
        ans.push_back(t.element);
        pq.pop();
        if (t.eleIndex + 1 < input[t.arrIndex]->size())
        {
            triplet a;
            a.arrIndex = t.arrIndex;
            a.eleIndex = t.eleIndex + 1;
            a.element = input[t.arrIndex]->at(t.eleIndex + 1)
            pq.push(input[t.arrIndex]->at(t.eleIndex + 1))
        }
    }
    */
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < input.size(); i++) 
    {
        for (int j = 0; j < input[i]->size(); j++)
        {
            pq.push(input[i]->at(j));
        }
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++)
    {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++)
        {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}