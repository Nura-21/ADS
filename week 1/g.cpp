#include <iostream>
#include <string>

using namespace std;
int main(){
    string s;
    getline(cin,s);
    int ans = 0;
    for(int i = 0 ; i < s.size(); i = i + 2){
        if(s[i] == '+'){
            ans = (stoi(s.substr(i-4,i-3)) + stoi(s.substr(i-2,i-1)));
            s.replace(i-4,i+1,to_string(ans)); 
        }
        else if(s[i] == '-'){
            ans -= (stoi(s.substr(i-4,i-3)) - stoi(s.substr(i-2,i-1))); 
        }
    }
    cout<<s;

}