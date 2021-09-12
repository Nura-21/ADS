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

    void print()
    {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
    }
};

int main()
{
    MaxHeap *max_heap = new MaxHeap();
    int n, t;
    // freopen("test1.txt", "r", stdin);
    cin >> n;
    while (n--)
    {
        cin >> t;
        max_heap->insert(t);
    }
    max_heap->print();
    return 0;
}
