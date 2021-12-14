#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if (!st.empty())
            if (st.top() == s[i])
            {
                st.pop();
                continue;
            }
        st.push(s[i]);
    }
    return st.empty();
}

int main(){
    string s; cin >> s;
    cout << ((check(s)) ? "YES" : "NO") << endl;
}