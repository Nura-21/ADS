#include <iostream>
using namespace std;
int main(){
    string command;
    getline(cin,command);
    cout << command.substr(5);
}