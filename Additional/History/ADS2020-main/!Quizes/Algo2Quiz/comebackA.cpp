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
    int findMax()
    {
        a[0] -= 1;
        siftDown(0);
        return a[0];
    }
    int getSize()
    {
        return a.size();
    }
    int getMax()
    {
        return a[0];
    }
};

int main()
{
    int n, x;
    ll sum = 0;
    // freopen("test1.txt", "r", stdin);
    cin >> n >> x;
    MaxHeap max_heap(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        max_heap.insert(t);
    }
    sum += max_heap.getMax();
    for (int i = 1; i < x; i++)
        sum += max_heap.findMax();
    cout << sum;

    return 0;
}