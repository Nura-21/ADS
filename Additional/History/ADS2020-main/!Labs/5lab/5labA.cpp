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
        siftUp(a.size() - 1);
    }
    void siftUp(int i)
    {
        while (i > 0 && a[parentIndex(i)] < a[i])
        {
            swap(a[parentIndex(i)], a[i]);
            i = parentIndex(i);
        }
    }
    void siftUpCheck(int i)
    {
        while (i > 0 && a[parentIndex(i)] < a[i])
        {
            swap(a[parentIndex(i)], a[i]);
            i = parentIndex(i);
        }
        cout << i + 1 << endl;
    }

    void heapifyDown(int i)
    {
        if (leftChildIndex(i) > a.size() - 1)
            return;

        int j = leftChildIndex(i);
        if (rightChildIndex(i) < a.size() && a[rightChildIndex(i)] > a[leftChildIndex(i)])
            j = rightChildIndex(i);

        if (a[i] < a[j])
        {
            swap(a[i], a[j]);
            heapifyDown(j);
        }
    }

    int extractMax()
    {
        int root = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapifyDown(0);
        return root;
    }

    void decreaseKey(int i, int value)
    {
        a[i] -= value;
        heapifyDown(i);
    }

    void increaseKey(int i, int value)
    {
        a[i] += value;
        siftUp(i);
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
    int n, t, m, i, x;
    freopen("test1.txt", "r", stdin);
    cin >> n;
    while (n--)
    {
        cin >> t;
        max_heap->insert(t);
    }
    cin >> m;
    while (m--)
    {
        cin >> i >> x;
        max_heap->increaseKey(i - 1, x);
    }
    max_heap->print();
    return 0;
}
