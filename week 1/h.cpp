#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    deque<int> dq,dq1;

    for(int i = 0; i < n; ++i){
        char com;
        int k;
        cin >> com;
        if(com == '+'){
            cin >> k;
            dq1.push_back(k);
        }
        if(com == '-'){
            cout << dq.front() << endl;
            dq.pop_front(); 
        }
        if(com == '*'){
            cin >> k;
            dq1.push_front(k);
        }
        if(dq1.size() > dq.size()){
            dq.push_back(dq1.front());
            dq1.pop_front();
        }
    }
}