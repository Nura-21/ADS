#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int n;
vector<pair<int, pair<int, int>>> a;
void merge(int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    pair<int, pair<int, int>> L[n1];
    pair<int, pair<int, int>> R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[m + 1 + i];

    int uk1 = 0;
    int uk2 = 0;
    int k = l;

    while (uk1 < n1 && uk2 < n2)
    {
        if (L[uk1] <= R[uk2])
        {
            a[k] = L[uk1];
            uk1++;
        }
        else
        {
            a[k] = R[uk2];
            uk2++;
        }
        k++;
    }

    while (uk1 < n1)
    {
        a[k] = L[uk1];
        uk1++;
        k++;
    }

    while (uk2 < n2)
    {
        a[k] = R[uk2];
        uk2++;
        k++;
    }
}

void mergesort(int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}

int main()
{
    // freopen("test1.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, d, y;
        cin >> m >> d >> y;
        a.push_back(make_pair(y, make_pair(d, m)));
    }
    mergesort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i].second.second << sep << a[i].second.first << sep << a[i].first << endl;
    return 0;
}