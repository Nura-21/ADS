#include <bits/stdc++.h>

using namespace std;
int main(){
    stack<int> st;
    string s;
    int a,b;
    getline(cin,s);
    stringstream ss(s);
    string word;
    while(ss >> word){
        if(word == "+")
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a+b);
        }
        else if(word == "*")
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b*a);
        }
        else if(word == "-")
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b-a);
        }
        else if(word == "/")
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b/a);
        }
        else
            st.push(stoi(word));
    }
    cout << st.top();
}