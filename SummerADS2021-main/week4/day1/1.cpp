#include <iostream>

using namespace std;


int f(string s){
    int sum = 0;

    for(int i = 0; i < s.size(); ++i){
        sum += int(s[i]);
    }

    return sum;
}

long long f2(string s){
    long long res = 0;

    for(int i = 0; i < s.size(); ++i){
        res += int(s[i]);
        res *= 100;
    }

    return res;
}


int main(){

    string s = "ABCDXXXX";
    string t = "ADBCXXXX";
    string u = "CTsXXXX";

    cout << f2(s) << endl;
    cout << f2(t) << endl;
    cout << f2(u) << endl;



    return 0;
}