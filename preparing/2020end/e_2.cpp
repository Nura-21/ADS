#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    switch(c){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
        case 'y':
        case 'Y':
            return true;
        default:
            return false;
    }
}

void permutate(string &s){
    int mid = s.size() / 2;
    for (int i = 0; i < mid; ++i){
        if (isVowel(s[i])){
            s.erase(i, 1);
            mid--;
            i--;
        }
    }
    reverse(s.begin() + mid, s.end());
}

int main(){

    // freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    permutate(s);
    cout << s;

    return 0;
}