#include <iostream>
using namespace std;
int n; 
int cnt = 0;
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        if(n1 + n2 == n and ((k != 0 and arr[k] != arr[k-1]) or k == 0)) cnt++;
        k++;
    }

    while(i < n1){
        if(n1 + n2 == n and ((k != 0 and arr[k] != arr[k-1]) or k == 0)) cnt++;
        arr[k++] = L[i++];
    }

    while(j < n2){
        if(n1 + n2 == n and ((k != 0 and arr[k] != arr[k-1]) or k == 0)) cnt++;
        arr[k++] = R[j++];
    }

}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


void printArray(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << cnt;
}