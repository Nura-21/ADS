#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<string> ten,eleven;
    int grade;
    string name;
    while(cin >> grade){
        cin >> name;
        if(grade == 9){
            cout << grade << " " << name << endl;
        }
        if(grade == 10){
            ten.push(name);
        }
        if(grade == 11){
            eleven.push(name);
        }
    }
    while(not ten.empty() || not eleven.empty()){
        if(not ten.empty()){
            cout << "10 " << ten.front() << endl;
            ten.pop(); 
        }
        else if(not eleven.empty()){
            cout << "11 " << eleven.front() << endl;
            eleven.pop();
        }
    }
}
