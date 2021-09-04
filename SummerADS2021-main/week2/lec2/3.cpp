#include <iostream>
#include <algorithm>

#define MAXN 100

using namespace std;

struct pq{ 
private:
    int hs;
    int val[MAXN];
public:
    pq(){
        hs = 0;
    }
    int front(){
        if(hs > 0) return val[0];
        return -1;
    }

    bool find(int x, int pos){
        if(pos >= hs || val[pos] > x) return false;
        if(val[pos] == x) return true;
        return find(x, 2 * pos + 1) || find(x, 2 * pos + 2);
    }

    void enqueue(int x){
        if(!find(x, 0)){
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
    }
    void pop(){
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
};

int main(){

    pq q;
    q.enqueue(1);

    int n;
    cin >> n;

    while(n > 1){
        n--;
        q.enqueue(q.front() * 2);
        q.enqueue(q.front() * 3);
        q.enqueue(q.front() * 5);
        q.pop();
    }

    cout << q.front() << endl;

    return 0;
}