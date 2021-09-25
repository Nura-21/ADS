#include <iostream>
#include <vector>
using namespace std;

class Heap{
    public:
    vector<long long> a;
    
    long long parent(long long i) {
        return (i - 1) / 2;
    }
    
    long long left(long long i) {
        return 2 * i + 1;
    }

    long long right(long long i) {
        return 2 * i + 2;
    }
    
    long long get_max() {
        return a[0];
    }

    void insert(long long k) {
        a.push_back(k);
    }

    void print(){
        for (long long i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        
        cout << endl;
    }

    int heapify(long long i){ 
        if(left(i) > a.size() - 1){
            return i;
        }
        int j = left(i);
        if(right(i) < a.size() && a[right(i)] > a[j]){ 
            j = right(i); 
        }   
        if(a[i] < a[j]){
            swap(a[i], a[j]);
            return heapify(j);
        }
        else //if(a[i] > a[j]){
            return i;
    }

    int extractMax() {
        int root = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0){
            cout << heapify(0) + 1 << " ";
        }
        return root;
    }
};

int main(){
    int n;
    cin >> n;
    Heap * heap = new Heap();

    for(int i = 0; i < n; i++){
        long long k;
        cin >> k;
        heap->insert(k);
    }
    for(int i = 0; i < n - 1; i++){
        cout << heap->extractMax() << endl;
    }
}