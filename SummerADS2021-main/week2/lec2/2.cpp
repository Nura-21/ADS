#include <iostream>
#include <algorithm>

#define MAXN 100

using namespace std;

struct heap{ 
private:
    int hs;
    int val[MAXN];
public:
    heap(){
        hs = 0;
    }
    int get_min(){
        if(hs > 0) return val[0];
        return -1;
    }
    void add(int x){
        int pos = hs;
        val[pos] = x;
        hs++;
        int parent_pos = (pos - 1) / 2;
        while(pos > 0 && val[pos] < val[parent_pos]){
            swap(val[pos], val[parent_pos]);
            pos = parent_pos;
            parent_pos = (pos - 1) / 2;
        }
    }
    void del(){
        int pos = 0;
        val[0] = val[hs-1];
        hs--;
        while(2 * pos + 1 < hs){
            int ch1 = 2 * pos + 1;
            int ch2 = 2 * pos + 2;
            int wch = ch1;
            if(ch2 < hs && val[ch2] < val[ch1]){
                wch = ch2;
            }
            if(val[pos] > val[wch]){
                swap(val[pos],val[wch]);
                pos = wch;
            }else{
                break;
            }
        }
    }

    void print(){
        for(int i = 0; i < hs; ++i){
            cout << val[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    int a[] = {1, 6, 8, 8, 7, 12, 9, 10};
    int n = sizeof(a) / sizeof(int);
    reverse(a, a + n);

    heap h;

    for(int i = 0; i < n; ++i){
        h.add(a[i]);
        cout << "added: " << a[i] << " min: " << h.get_min() << endl;
    }

    h.print();

    for(int i = 0; i < n; ++i){
        h.del();
        h.print();
    }

    return 0;
}