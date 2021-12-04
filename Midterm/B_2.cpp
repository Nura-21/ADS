#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

//max_heap
struct heap{
    long long h[1000000];
    long long hsize;
    long long sum = 0;

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
        while(i && h[i] < h[parent(i)]){
            swap(h[i], h[parent(i)]);
            i = parent(i);
        }
    }

    void print(){
        for (long long i = 0; i < hsize; i++) 
            cout << h[i] << " ";
        
        cout << endl;
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
        if(right(i) < hsize && h[right(i)] < h[temp]){ 
            temp = right(i); 
        }   
        if(h[i] > h[temp]){
            swap(h[i], h[temp]);
            return sift_down(temp);
        }
        //if(h[i] > h[temp]){
        else return i;
    }
    void MinHeapify( long long i){
        long long l = left(i);
        long long r = right(i);
         long long smallest = i;
        if (l < hsize && h[l] < h[i])
            smallest = l;
        if (r < hsize && h[r] < h[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(h[i], h[smallest]);
            MinHeapify(smallest);
        }
    }

    void sift_up(long long i) { 
        while (h[parent(i)] < h[i]){
            swap(h[i], h[parent(i)]);
            i = parent((i));
        }
        cout << i + 1 << endl;
    }
    
    void change_val(long long i, long long x){
        h[i] += x;
        sift_up(i);
    }

    long long height(){
        return ceil(log2(hsize + 1));
    }

    
    long long extractMin(){
    	if (hsize <= 0)
            return INT_MAX;
        if (hsize == 1)
        {
            hsize--;
            return h[0];
        }

         long long root = h[0];
        h[0] = h[hsize-1];
        hsize--;
        MinHeapify(0);

        return root;
    }

};

int main(){
    int n;
    cin >> n;
    heap * hp = new heap();
    for(int i = 0; i < n; ++i){
        long long k; cin >> k;
        hp->push(k);
    }
    long long s = 0;
    while(hp->size() != 1){
        long long f = hp->extractMin();
        long long s = hp->extractMin();
        long long temp = f + s;
        hp->push(temp);
        s += temp;
    }
    cout << s;


}