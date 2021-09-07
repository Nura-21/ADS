#include <iostream>
using namespace std;
int main(){
    long long a,b,max;
    cin>>a>>b;
    max = (a > b) ? a : b;
    do
    {
        if (max % a == 0 && max % b == 0)
        {
            cout << max;
            break;
        }
        else
            ++max;
    } while (true);
}