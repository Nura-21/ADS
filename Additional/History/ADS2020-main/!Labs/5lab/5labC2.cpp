#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
class MaxHeap
{
public:
    vector<int> a;

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

    int extractMax()
    {
        int root = a[0];
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
    MaxHeap *max_heap = new MaxHeap();
    int n, t;
    // freopen("test1.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        max_heap->insert(t);
    }
    for (int i = 0; i < n - 1; i++)
        cout << max_heap->extractMax() << endl;

    return 0;
}