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

    void heapifyDown(int i)
    {
        if (leftChildIndex(i) > a.size() - 1)
        {
            cout << i + 1 << " ";
            return;
        }

        int j = leftChildIndex(i);
        if (rightChildIndex(i) < a.size() && a[rightChildIndex(i)] > a[leftChildIndex(i)])
            j = rightChildIndex(i);

        if (a[i] < a[j])
        {
            swap(a[i], a[j]);
            heapifyDown(j);
        }
        else
        {
            cout << i + 1 << " ";
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
    int getMax()
    {
        return a[0];
    }
};

int main()
{
    MaxHeap *max_heap = new MaxHeap();
    int n, t, m, i, x;
    // freopen("test1.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        max_heap->insert(t);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << max_heap->extractMax() << endl;
    }
    return 0;
}

// 6
// 12 6 8 3 4 7

// 3 12
// 3 8
// 2 7
// 1 6
// 1 4