// Bubble sort - Сортировка пузырьком
// Speed O(n^2) in worst case
// Not effective algorithm

#include <iostream>
using namespace std;

void bubble_sort(int size, int a[]) // function bubble sort(size,array)
{
    bool is_sorted = false; // flag
    while (not is_sorted)   // if not sorted array we do while loop
    {
        int i = 0;           // pointer
        is_sorted = true;    // do flag true, to exit from loop next time
        while (i < size - 1) // checking whole array
        {
            if (a[i] > a[i + 1]) // if left element more than right, swap it
            {
                int temp = a[i];   // temporary variable for swap
                a[i] = a[i + 1];   // swap
                a[i + 1] = temp;   // swap
                is_sorted = false; // if there are no sorted elements, flag becomes false => we do external while again
            }
            i++; // check next elements
        }
    }
}
int main()
{
    int n;
    cin >> n; //input size of array
    int a[n];
    for (int i = 0; i < n; i++) // input array's data
        cin >> a[i];

    bubble_sort(n, a); // sorting by bubble sort (size,array)

    for (int i = 0; i < n; i++) // output array's data
        cout << a[i] << " ";

    return 0;
}