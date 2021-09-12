//O(n*logn)



#include <iostream>
#include <array>
using namespace std;

const int MAX_ARRAY_SIZE = 100000;

void merge_sort(int *array, int array_size)
{
    if (array_size <= 1)
        return; // base case

    int middle = array_size / 2; // do left right bounders
    int *left = array;
    int *right = array + middle;
    //Using address arithmetics: pointer + number gives shifted array begin
    int left_size = middle;
    int right_size = array_size - left_size;

    // recursion goes here:
    merge_sort(left, left_size);   // sort left array
    merge_sort(right, right_size); // sort right array

    // Merge these two already sorted parts of array:
    int *buffer = new int[array_size];
    int left_i = 0;
    int right_i = 0;
    int buffer_i = 0;
    while (left_i < left_size and right_i < right_size)
    {
        if (left[left_i] <= right[right_i])
        {
            // taking the lesser from the left part of array
            buffer[buffer_i] = left[left_i];
            left_i += 1;
            buffer_i += 1;
        }
        else
        {
            // taking the lesser from the right part of array
            buffer[buffer_i] = right[right_i];
            right_i += 1;
            buffer_i += 1;
        }
    }
    
    while (left_i < left_size)
    { // copying left elements from the left size (if there is left something)
        buffer[buffer_i] = left[left_i];
        left_i += 1;
        buffer_i += 1;
    }
    while (right_i < right_size)
    { // copying right elements from the right size (if there is right something)
        buffer[buffer_i] = right[right_i];
        right_i += 1;
        buffer_i += 1;
    }

    // copying from buffer to original array:
    for (int i = 0; i < array_size; i++)
    {
        array[i] = buffer[i];
    }
    delete[] buffer;
}

int main()
{
    int array_size;
    cin >> array_size;
    int *array = new int[array_size];
    for (int i = 0; i < array_size; i++)
        cin >> array[i];

    merge_sort(array, array_size);

    for (int i = 0; i < array_size; i++)
        cout << array[i] << ' ';

    delete[] array;
    return 0;
}