#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//max_heap
struct heap{
    long long h[1000000];
    long long hsize;

    long long parent(long long i){
        return (i - 1) / 2;
    }

    long long left(long long i){
        return 2 * i + 1;
    }

    long long right(long long i){
        return 2 * i + 2;
    }

    long long max(){
        return h[0];
    }

    long long min(){
        return h[hsize - 1];
    }

    long long size(){
        return hsize;
    }

    void push(long long n){
        long long i = hsize++;
        h[i] = n;
        while(i && h[i] > h[parent(i)]){
            swap(h[i], h[parent(i)]);
            i = parent(i);
        }
    }

    void print(){
        for (long long i = 0; i < hsize; i++) 
            cout << h[i] << " ";
        
        cout << endl;
    }

    //+
    long long sift_up(long long i) { 
        while (h[parent(i)] < h[i]){
            swap(h[i], h[parent(i)]);
            i = parent((i));
        }
        return i;
    }

    void build_up(){
        long long i = hsize - 1;
        while(i >= 0){
            if (h[parent(i)] < h[i])
                swap(h[parent(i)], h[i]);
            i--;
        }
    }

    //-
    long long sift_down(long long i){ 
        //exit condition
        if(left(i) > hsize - 1){
            return i;
        }
        long long temp = left(i);
        //pick max from childs
        if(right(i) < hsize && h[right(i)] > h[temp]){ 
            temp = right(i); 
        }   
        if(h[i] < h[temp]){
            swap(h[i], h[temp]);
            return sift_down(temp);
        }
        //if(h[i] > h[temp]){
        else return i;
    }

    void change_val(long long i, long long x){
        h[i] -= x;
        cout << sift_down(i) + 1 << endl;
    }

    long long height(){
        return ceil(log2(hsize + 1));
    }

    long long extractMax(){
        long long root = max();
        swap(h[0], h[hsize - 1]);
        hsize--;
        if(hsize > 0){
             sift_down(0);
        }
        return root;
    }

};

int main(){
    int n;
    cin >> n;
    heap * hp = new heap();
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        hp->push(k);
    }
    for(int i = 0; i < n; ++i){
        cout << hp->extractMax() << " ";
    }
    
}