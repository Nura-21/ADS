#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{
public:
    vector<int> a;
    int max_size;
    MaxHeap(int max_size)
    {
        this->max_size = max_size;
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
        int i = getSize() - 1;
        cout << siftUp(i) << endl;
    }
    int siftUp(int i)
    {
        if (i > 0 && a[parentIndex(i)] < a[i])
        {
            swap(a[parentIndex(i)], a[i]);
            return siftUp(parentIndex(i));
        }
        return i + 1;
    }

    int heapifyDown(int i)
    {
        if (leftChildIndex(i) > getSize() - 1)
            return i + 1;

        int j = leftChildIndex(i);
        if ((a[j] <= a[i]))
            j = i;
        if (rightChildIndex(i) < getSize() && a[rightChildIndex(i)] > a[j])
            j = rightChildIndex(i);
        if (i != j)
        {
            swap(a[i], a[j]);
            return heapifyDown(j);
        }
        return i + 1;
    }

    void deleteNode(int i)
    {
        if (i > getSize() - 1 || i < 0)
        {
            cout << -1 << endl;
            return;
        }
        if (a.size() == 1)
        {
            cout << a[i] << " ";
            a.pop_back();
            return;
        }
        cout << a[i] << endl;
        a[i] = a[getSize() - 1];
        a.pop_back();
        siftUp(i);
        heapifyDown(i);
    }
    int extractMax()
    {
        if (a.empty())
            return -1;
        int root = getMax();
        swap(a[0], a[getSize() - 1]);
        a.pop_back();
        if (getSize() == 0)
        {
            cout << 0 << " ";
            return root;
        }
        cout << heapifyDown(0) << " ";
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
    void print()
    {
        for (int i = 0; i < getSize(); i++)
        {
            cout << a[i] << " ";
        }
    }
};
int main()
{
    // freopen("test1.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    MaxHeap max_heap(n);
    while (m--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
            cout << max_heap.extractMax() << endl;
        else if (ch == 2)
        {
            int t;
            cin >> t;
            if (max_heap.getSize() == n)
            {
                cout << -1 << endl;
                continue;
            }
            max_heap.insert(t);
        }
        else if (ch == 3)
        {
            int g;
            cin >> g;
            max_heap.deleteNode(g - 1);
        }
    }
    max_heap.print();
    return 0;
}
