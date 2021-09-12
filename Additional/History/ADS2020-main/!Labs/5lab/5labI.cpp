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

    void heapifyDown(int i)
    {
        if (leftChildIndex(i) > a.size() - 1)
            return;

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
    }
    int extractMax()
    {
        int root = a[0];
        if (a.size() == 1)
        {
            a.pop_back();
            return root;
        }
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        heapifyDown(0);
        return root;
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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        max_heap->a.push_back(t);
    }
    for (int i = 0; i < max_heap->a.size(); i++)
        max_heap->heapifyDown(n - i - 1);

    for (int i = 0; i < n; i++)
    {
        arr[i] = max_heap->extractMax();
    }
    for (int i = 0; i < n; i++)
        cout << arr[n - i - 1] << " ";

    return 0;
}
