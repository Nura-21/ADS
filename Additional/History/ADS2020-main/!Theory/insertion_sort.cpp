// O(n^2)
// insertion sort sort

#include <iostream>
using namespace std;

void insertion_sort(int n, int a[])
{
    for (int pos = 1; pos < n; pos++)
    {
        int i = pos;
        while (i > 0 and a[i - 1] > a[i])
        {
            int temp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = temp;
            i--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insertion_sort(n, a);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}