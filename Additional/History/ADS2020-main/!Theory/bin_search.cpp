// Binary search, work with only sorted arrays
// Speed:  log2(n)

#include <iostream>
using namespace std;
int bin_search(int l, int r, int a[], int x) // binary search function(left,right,sorted array, target)
{
    if (l <= r) // condition to avoid infinity recursion etc...
    {
        int m = l + (r - l) / 2; // middle point
        if (a[m] == x)           // if target is found return 1(True) or we can return m; - index of the target
            return 1;
        if (a[m] < x)                          // if target more than middle digit
            return bin_search(m + 1, r, a, x); // return l like middle+1(next time will be new middle point) on rigth side
        return bin_search(l, m - 1, a, x);     // return right side like middle-1(next time will be new middle on left side)
    }
    return 0; // if condition failed, and there are no return 1, return 0 - there is no target in thearray
}
 
int main()
{
    int n; // size of array
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) // already sorted array
        cin >> a[i];

    int x; // target
    cin >> x;
    cout << bin_search(0, n - 1, a, x); // do function
}