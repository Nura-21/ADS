#include <iostream>
using namespace std;

struct my_stack{
    //capacity = 100
    //Now client can not use array or make changes in array
    private:

        int arr[100];
        int topIndex;

    public:

    my_stack(){
        topIndex = 0;
    }

    int top(){
        if(topIndex != -1){
            return arr[topIndex];
        }
        else return -1;
    }

    void push(int x){
        topIndex++;
        arr[topIndex] = x;
    }

    void pop(){
        if(topIndex != -1){topIndex--;}
    }

};

int main(){
    my_stack stack;

    int d[] = {1,10,2,3,5,4};
    int n = sizeof(d) / sizeof(int);
    
    for(int i = 0 ; i < n; ++i){
        stack.push(d[i]);
    }
    for(int i = 0 ; i < n; ++i){
        cout << stack.top() << endl;
        stack.pop();
    }

}