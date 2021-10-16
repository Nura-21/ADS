#include <iostream>

using namespace std;

struct heap{
    long long val[1000000];
    long long hs;

    heap(){
        hs = 0;
    }

    long long get_max(){
        return val[0];
    }

    long long get_min(){
        return val[hs-1];
    }

    long long size(){
        return hs;
    }

    void add(long long x){
        long long i = hs++;
        val[i] = x;
        long long p = (i - 1)/2; 
        while(i && val[i] > val[p]){
            swap(val[i], val[p]);
            i = p;
            p = (i - 1)/2; 
        }
    }

    void del(){
        val[0] = val[--hs];
        long long i = 0;
        while(2 * i + 1 < hs){
            long long c1 = 2 * i + 1;
            long long c2 = 2 * i + 2;
            long long mp = c1;
            if(c2 < hs){
                if(val[c2] > val[c1]){
                    mp = c2;
                }
            }
           
            if(val[i] < val[mp]){
                swap(val[i], val[mp]);
                i = mp;
            }else{
                break;
            }
        }
    }

    void print(){
        for(long long i = 0; i < hs; ++i){
            cout << val[i] << " ";
        }
        cout << endl;
    }
};


int main(){

    long long n; cin >> n;
    heap h;

    for(long long i = 0; i < n; ++i){
        int com; cin >> com;
        if(com == 0){
            long long k; cin >> k;
            h.add(k);
        }
        else if(h.size() != 0 and com == 1){
            cout << h.get_max() << endl; 
            h.del();}
    }
}