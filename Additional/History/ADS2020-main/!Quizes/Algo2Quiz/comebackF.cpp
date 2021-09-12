#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

int ans[100000];
int a[100000];
int ptr = 0;
int n;
void merge(int l, int m, int r) // Askar agai code
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
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

void mergesort(int l, int r) // Askar agai code
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}

void divAndConq(int l, int r)
{
    if (l == r)
    {
        ans[++ptr] = a[l];
        // cout << "EQUALS "
        //      << " ptr " << ptr << " L " << l << " R " << r << endl;
        return;
    }
    if (l > r)
    {
        // cout << "L>R"
        //      << " ptr " << ptr << " L " << l << " R " << r << endl;
        return;
    }
    int m = (l + r) / 2;
    ans[++ptr] = a[m];
    // cout << "Middle " << m << " ptr " << ptr << " L " << l << " R " << r << endl;
    divAndConq(l, m - 1);
    // cout << "EXIT FROM LEFT. Middle " << m << " ptr " << ptr << " L " << l << " R " << r << endl;
    divAndConq(m + 1, r);
    // cout << "EXIT FROM RIGHT. Middle " << m << " ptr " << ptr << " L " << l << " R " << r << endl;
}

int main()
{
    // freopen("test1.txt", "r", stdin);
    cin >> n;
    int m = pow(2, n);
    n = m - 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    mergesort(1, n);
    divAndConq(1, n);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}