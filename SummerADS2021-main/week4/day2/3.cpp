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

    string text, word;
    cin >> text >> word;

    string str = word + "#" + text;
    int n = str.size();

    pf(str);

    bool f = false;

    for(int i = 0; i < n; ++i){
        if(p[i] == word.size()){
            f = true;
            break;
        }
    }

    if(f){
        cout << "found!";
    }else{
        cout << "not found!";
    }

    return 0;
}