#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int> first,second;
    for(int i = 0; i < 5; ++i){
        int n;
        cin >> n;
        first.push(n);
    }
    for(int i = 0; i < 5; ++i){
        int n;
        cin >> n;
        second.push(n);
    }
    int cnt = 0;
    while(cnt <= 100000 && not first.empty() && not second.empty()){
        cnt++;
        if(first.front() == 0 and second.front() == 9){
            first.push(first.front());
            first.push(second.front());
            first.pop();
            second.pop();
            continue;
        }
        if(first.front() == 9 and second.front() == 0){
            second.push(first.front());
            second.push(second.front());
            second.pop();
            first.pop();
            continue;
        }
        if(first.front() > second.front()){
            first.push(first.front());
            first.push(second.front());
            first.pop();
            second.pop();
        }
        else{
            second.push(first.front());
            second.push(second.front());
            second.pop();
            first.pop();
        }
        
    }
    if(cnt > 100000){
        cout << "botva";
    }
    else if(first.empty()){
        cout << "second " << cnt << endl;
    }
    else{
        cout << "first " << cnt  << endl;
    }
}