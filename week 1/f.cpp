#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    stack<char> st;
    cin >> s;
    for(size_t i = 0; i < s.size(); ++i){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(not st.empty()){
                if((s[i] == ')' and st.top() == '(') || (s[i] == ']' and st.top() == '[') || (s[i] == '}' and st.top() == '{')){
                    st.pop();
                }
                else{
                    cout << "no" << endl;
                    return 0;
                }
            }
            else{
                cout << "no" << endl;
                return 0;
            }
        }
    }
    if(st.empty()){
        cout << "yes" << endl;
    }
    else{cout << "no" << endl;
    }
}