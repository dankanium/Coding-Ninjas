#include <string>
using namespace std;
template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};
template <typename V>
class ourmap
{
    MapNode<V> **buckets;
    int size;
    int numBuckets;

    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currentCoef = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoef;
            hashCode = hashCode % numBuckets;
            currentCoef *= 37;
            currentCoef = currentCoef % numBuckets;
        }
        return hashCode % numBuckets;
    }

public:
    ourmap()
    {
        size = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
            buckets[i] = NULL;
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
            delete buckets[i];
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(string key);
    }

    V remove(string key)
    {
    }

    V getValue(string key)
    {
    }
};