#include<bits/stdc++.h>
using namespace std;
class Edge {
    public:
    int source;
    int dest;
    int weight;
};
bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}
int findParent(int source, int *parent) {
    if (parent[source] == source) {
        return source;
    }
    return findParent(parent[source], parent);
}
void krushkals(Edge *input, int n, int e) {
    sort(input, input + n, compare);
    Edge *output = new Edge[n - 1];
    int *parent = new int[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int inputIndex = 0;
    int outputIndex = 0;
    while (outputIndex != n - 1) {
        Edge currentEdge = input[inputIndex];
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);
        if (sourceParent != destParent) {
            output[outputIndex] = currentEdge;
            outputIndex++;
            parent[sourceParent] = destParent;      
        }
        inputIndex++;
    }
    for (int i = 0; i < n - 1; i++) {
        if (output[i].source <= output[i].dest) {
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else {
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}
int main() {
    int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e];

    for (int i = 0; i < e; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    krushkals(input, n, e);
}