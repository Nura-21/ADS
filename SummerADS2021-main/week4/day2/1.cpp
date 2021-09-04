#include <iostream>

using namespace std;

int pf(string str){
    int res = 0;
    for(int i = 0; i < str.size() - 1; ++i){
        int len = i + 1;
        string prefix = str.substr(0, i + 1);
        string suffix = str.substr(str.size() - 1 - i, i + 1);
        if(prefix == suffix){
            res = prefix.length();
        }
    }
    return res;
}

int main(){

    string str;
    cin >> str;
    cout << str << endl;
    int n = str.size();
    int p[n];

    for(int i = 0; i < n; ++i){
        p[i] = pf(str.substr(0,i + 1));
    }

    for(int i = 0; i < n; ++i){
        cout << p[i] << " ";
    }

    return 0;
}