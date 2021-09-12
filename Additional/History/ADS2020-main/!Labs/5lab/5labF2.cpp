#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
class MaxHeap
{
public:
    vector<int> a;
    int maxSize;
    MaxHeap(int maxSize)
    {
        this->maxSize = maxSize;
    }
    int parentIndex(int i)
    {
        return (i - 1) / 2;
    }
    int leftChildIndex(int i)
    {
        return 2 * i + 1;
    }

    int rightChildIndex(int i)
    {
        return 2 * i + 2;
    }

    void insert(int k)
    {
        a.push_back(k);
        siftUp(getSize() - 1);
    }
    int siftUp(int i)
    {
        if (i > 0 && a[parentIndex(i)] < a[i])
        {
            swap(a[parentIndex(i)], a[i]);
            i = parentIndex(i);
            return siftUp(i);
        }
        return i + 1;
    }
    int siftDown(int i)
    {
        if (leftChildIndex(i) > a.size() - 1)
            return i + 1;

        int j = leftChildIndex(i);
        if (rightChildIndex(i) < a.size() && a[rightChildIndex(i)] > a[leftChildIndex(i)])
            j = rightChildIndex(i);

        if (a[i] < a[j])
        {
            swap(a[i], a[j]);
            return siftDown(j);
        }
        return i + 1;
    }
    int deleteNode(int i)
    {
        if (i < 0 or i > getSize() - 1)
            return -1;
        int root = a[i];
        if (getSize() == 1)
        {
            a.pop_back();
            return root;
        }
        swap(a[i], a[getSize() - 1]);
        a.pop_back();
        siftUp(i);
        siftDown(i);
        return root;
    }

    int extractMax()
    {
        if (isEmpty())
            return -1;
        int root = a[0];
        if (getSize() == 1)
        {
            a.pop_back();
            cout << 0 << " ";
            return root;
        }
        swap(a[0], a[getSize() - 1]);
        a.pop_back();
        cout << siftDown(0) << " ";
        return root;
    }

    void decreaseKey(int i, int value)
    {
        a[i] -= value;
        cout << siftDown(i) << endl;
    }

    void increaseKey(int i, int value)
    {
        a[i] += value;
        cout << siftUp(i) << endl;
    }

    void print()
    {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
    }

    int getMax()
    {
        return a[0];
    }

    int getSize()
    {
        return a.size();
    }

    bool isEmpty()
    {
        return a.empty();
    }
};

int main()
{
    int n, t;
    // freopen("test1.txt", "r", stdin);
    cin >> n;
    MaxHeap max_heap(n);
    while (n--)
    {
        cin >> t;
        max_heap.insert(t);
    }

    max_heap.print();
    return 0;
}