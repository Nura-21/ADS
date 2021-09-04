#include <iostream>

using namespace std;


int p[1000];

void pf(string s){
    p[0] = 0;
    int n = s.size();
    for(int i = 1; i < n; ++i){
        int j = p[i-1];
        while(j > 0 && s[i] != s[j]){
            j = p[j - 1];
        }
        if(s[i] == s[j]){
            j = j + 1;
        }
        p[i] = j;
    }
}

int main(){

    string str;
    cin >> str;
    cout << str << endl;

    int n = str.size();

    pf(str);

    

    for(int i = 0; i < n; ++i){
        cout << p[i] << " ";
    }

    return 0;
}