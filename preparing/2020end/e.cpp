#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    string f = "";
    for(int i = 0; i < s.size() / 2; ++i){
        if(tolower(s[i]) != 'a' and 
        tolower(s[i]) != 'e' and  
        tolower(s[i]) != 'i' and  
        tolower(s[i]) != 'o' and  
        tolower(s[i]) != 'u' and
        tolower(s[i]) != 'y'){
            f+= s[i];
        }
    }
    char c = toupper(f[0]);
    f.replace(0,1,"");
    string se = "";
    for(int i = s.size() / 2; i < s.size(); ++i){
        se = s[i] + se; 
    } 

    cout << c << f + se ;

}