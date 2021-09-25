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
        long long i = a.size() - 1;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void heapify(){
        long long i = a.size() - 1;
        while (i >= 0){
            if (a[parent(i)] < a[i])
                swap(a[parent(i)], a[i]);
            i--;
        }
    }

    void print(){
        heapify();
        for (long long i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        
        cout << endl;
    }

    void sift_up(long long i) { 
        while (a[parent(i)] < a[i]){
            swap(a[i], a[parent(i)]);
            i = parent((i));
        }
        cout << i + 1 << endl;
    }

    int sift_down(long long i){ 
        if(left(i) > a.size() - 1){
            return i;
        }
        int j = left(i);
        if(right(i) < a.size() && a[right(i)] > a[j]){ 
            j = right(i); 
        }   
        if(a[i] < a[j]){
            swap(a[i], a[j]);
            return sift_down(j);
        }
        else //if(a[i] > a[j]){
            return i;
    }

    long long change_val(long long i, long long x){
        a[i] -= x;
        return sift_down(i) + 1;
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

    int m; cin >> m;

    for(int i = 0; i < m; i++){
        long long ind, x;
        cin >> ind >> x;
        cout << heap->change_val(ind - 1, x) << endl;
    }
    heap->print();
}