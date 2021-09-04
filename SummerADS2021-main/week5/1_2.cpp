#include <iostream>
#include <set>

using namespace std;


int main(){

    int n, x;
    cin >> n;
    set<int> e[n];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> x;
            if( x == 1){
                e[i].insert(j);
            }
        }
    }
    
    for(int i = 0; i < n; ++i){
        cout << i + 1<< ": ";
        for(set<int> :: iterator it = e[i].begin(); it != e[i].end(); ++it){
            cout << (*it) + 1 << " ";
        }
        cout << endl;
    }

    
    int a, b;
    cin >> a >> b;

    if(e[a-1].find(b-1) != e[a-1].end()){
        cout << "YES";
    }else{
        cout << "NO";       
    }


    return 0;
}