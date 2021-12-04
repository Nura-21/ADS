#include <iostream>
#include <climits>
using namespace std;

void swap(unsigned long long *x, unsigned long long *y){
    unsigned long long temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap
{
	unsigned long long *harr;
	unsigned long long capacity;
	unsigned long long heap_size;
public:
	MinHeap(unsigned long long a){
        heap_size = 0;
        capacity = a;
    	harr = new unsigned long long[a];
    }

	void MinHeapify(unsigned long long i){
        unsigned long long l = left(i);
        unsigned long long r = right(i);
        unsigned long long smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(&harr[i], &harr[smallest]);
            MinHeapify(smallest);
        }
    }

	unsigned long long parent(unsigned long long i){
        return (i-1)/2;
    }

	unsigned long long left(unsigned long long i){
        return (2*i + 1);
    }

	unsigned long long right(unsigned long long i){
        return (2*i + 2);
    }

	unsigned long long extractMin(){
    	if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        unsigned long long root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        MinHeapify(0);

        return root;
    }

	void insertKey(unsigned long long k){
            
        if (heap_size == capacity)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        heap_size++;
        unsigned long long i = heap_size - 1;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    unsigned long long getSize(){
        return heap_size;
    }
};

int main(){

    unsigned long long n;
    unsigned long long ans = 0;
    cin >> n;
    MinHeap h(n);

    for(unsigned long long i = 0; i < n; ++i){
        unsigned long long x;
        cin >> x;
        h.insertKey(x);
    }

    while(h.getSize() != 1){
        unsigned long long first = h.extractMin();
        unsigned long long second = h.extractMin();
        unsigned long long temp = first + second;
        h.insertKey(temp);
        ans += temp;
    }

    cout << ans;

    return 0;
}