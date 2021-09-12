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
        cout << i + 1 << endl;
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

        if (rightChildIndex(i) < a.size() && a[leftChildIndex(i)] == a[rightChildIndex(i)])
            j = leftChildIndex(i);

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
        if (a.size() == 1)
        {
            a.pop_back();
            cout << 0 << " ";
            return root;
        }
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        heapifyDown(0);
        return root;
    }
    int getMax()
    {
        return a[0];
    }
    int getSize()
    {
        return a.size();
    }
    bool emptyHeap()
    {
        return a.empty();
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
    int n, m, ch;
    // freopen("test1.txt", "r", stdin);
    cin >> n >> m;
    while (m--)
    {
        cin >> ch;
        if (ch == 1)
        {
            if (max_heap->emptyHeap())
                cout << -1 << endl;
            else
                cout << max_heap->extractMax() << endl;
        }
        else if (ch == 2)
        {
            int t;
            cin >> t;
            if (n != max_heap->getSize())
                max_heap->insert(t);
            else
                cout << -1 << endl;
        }
        // cout << "Heap: ";
        // max_heap->print();
        // cout << endl;
    }
    max_heap->print();
    return 0;
}

// 4 7
// 1
// 2 9
// 2 4
// 2 9
// 2 9
// 2 7
// 1

// -1
// 1
// 2
// 3
// 2
// -1
// 2 9
// 9 4 9