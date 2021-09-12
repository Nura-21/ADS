#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int sumOfDays[100500];
string ans[100500];
int n;

void merge(int l, int m, int r) // Askar agai code
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    string LS[n1];
    string RS[n2];
    for (int i = 0; i < n1; i++)
        L[i] = sumOfDays[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = sumOfDays[m + 1 + i];
    for (int i = 0; i < n1; i++)
        LS[i] = ans[l + i];
    for (int i = 0; i < n2; i++)
        RS[i] = ans[m + 1 + i];

    int uk1 = 0;
    int uk2 = 0;
    int k = l;

    while (uk1 < n1 && uk2 < n2)
    {
        if (L[uk1] <= R[uk2])
        {
            sumOfDays[k] = L[uk1];
            ans[k] = LS[uk1];
            uk1++;
        }
        else
        {
            sumOfDays[k] = R[uk2];
            ans[k] = RS[uk2];
            uk2++;
        }
        k++;
    }

    while (uk1 < n1)
    {
        sumOfDays[k] = L[uk1];
        ans[k] = LS[uk1];
        uk1++;
        k++;
    }

    while (uk2 < n2)
    {
        sumOfDays[k] = R[uk2];
        ans[k] = RS[uk2];
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
    freopen("test1.txt", "r", stdin);
    cin >> n;
    string m, d, y;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> d >> y;
        int m_int = stoi(m);
        int d_int = stoi(d);
        int y_int = stoi(y);
        string date_str = "";
        date_str += to_string(m_int) + sep + to_string(d_int) + sep + to_string(y_int);
        int date_sum = 0;
        date_sum += (m_int * 30) + (d_int) + (y_int * 365);
        ans[i] = date_str;
        sumOfDays[i] = date_sum;
    }
    mergesort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}