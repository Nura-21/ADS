#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
class MaxHeap
{
public:
    vector<ll> a;
    ll maxSize;
    MaxHeap(ll maxSize)
    {
        this->maxSize = maxSize;
    }
    ll parentIndex(ll i)
    {
        return (i - 1) / 2;
    }
    ll leftChildIndex(ll i)
    {
        return 2 * i + 1;
    }
    ll rightChildIndex(ll i)
    {
        return 2 * i + 2;
    }

    void insert(ll k)
    {
        a.push_back(k);
        siftUp(getSize() - 1);
    }
    ll siftUp(ll i)
    {
        if (a[parentIndex(i)] < a[i])
        {
            swap(a[parentIndex(i)], a[i]);
            i = parentIndex(i);
            return siftUp(i);
        }
        return i + 1;
    }

    ll siftDown(ll i)
    {
        if (leftChildIndex(i) > a.size() - 1)
            return i + 1;

        ll j = leftChildIndex(i);
        if (rightChildIndex(i) < a.size() && a[rightChildIndex(i)] > a[leftChildIndex(i)])
            j = rightChildIndex(i);

        if (a[i] < a[j])
        {
            swap(a[i], a[j]);
            return siftDown(j);
        }
        return i + 1;
    }

    ll extractMax()
    {
        ll root = a[0];
        if (getSize() == 1)
        {
            a.pop_back();
            return root;
        }
        swap(a[0], a[getSize() - 1]);
        a.pop_back();
        siftDown(0);
        return root;
    }

    ll getSize()
    {
        return a.size();
    }
};

int main()
{
    // freopen("test1.txt", "r", stdin);
    ll n;
    cin >> n;
    MaxHeap max_heap(n);
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        max_heap.insert(t);
        if (i > 1)
        {
            ll mx1 = max_heap.extractMax();
            ll mx2 = max_heap.extractMax();
            ll mx3 = max_heap.extractMax();
            ll ans = mx1 * mx2 * mx3;
            cout << ans << endl;
            max_heap.insert(mx1);
            max_heap.insert(mx2);
            max_heap.insert(mx3);
        }
        else
            cout << -1 << endl;
    }

    return 0;
}