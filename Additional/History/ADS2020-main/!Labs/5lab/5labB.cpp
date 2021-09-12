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
        int i = a.size() - 1;
        siftUp(i);
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
    void heapifyDownCheck(int i)
    {
        if (leftChildIndex(i) > a.size() - 1)
        {
            cout << i + 1 << endl;
            return;
        }
        int j = leftChildIndex(i);
        if (rightChildIndex(i) < a.size() && a[rightChildIndex(i)] > a[leftChildIndex(i)])
            j = rightChildIndex(i);
        if (a[i] < a[j])
        {
            swap(a[i], a[j]);
            i = j;
            heapifyDownCheck(i);
        }
        else
        {
            cout << i + 1 << endl;
        }
    }

    void decreaseKey(int i, int new_value)
    {
        a[i] -= new_value;
        heapifyDownCheck(i);
    }

    void print()
    {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
    }
};

int main()
{
    MaxHeap *max_heap = new MaxHeap();
    int n, t, m, i, x;
    // freopen("test1.txt", "r", stdin);
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
        max_heap->decreaseKey(i - 1, x);
    }
    max_heap->print();
    return 0;
}

// 6
// 12 6 8 3 4 7
// 2
// 2 5
// 1 2

// 5
// 1
// 10 4 8 3 1 7
