#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int n;
int a[100500];
string vw = "";
string cn = "";
bool isVowel(char t)
{
    return t == 'a' or t == 'e' or t == 'i' or t == 'o' or t == 'u';
}
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
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char t;
        cin >> t;
        if (isVowel(t))
            vw += t;
        else
            cn += t;
    }
    for (int i = 0; i < vw.size(); i++)
        a[i] = vw[i];
    for (int i = vw.size(); i < n; i++)
        a[i] = cn[i - vw.size()];
    mergesort(0, vw.size() - 1);
    mergesort(vw.size(), n - 1);
    for (int i = 0; i < n; i++)
        cout << (char)a[i];

    return 0;
}