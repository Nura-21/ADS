#include <iostream>
using namespace std;

struct my_stack{
    //1 capacity = 100
    //2 Now client can not use array or make changes in array
    //3 We do not write size of stack
    private:

        int * arr;
        int topIndex;

    public:

    my_stack(int n){
        arr = new int[n];
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
    

    int d[] = {1,10,2,3,5,4};
    int n = sizeof(d) / sizeof(int);
    
    my_stack stack(n);

    for(int i = 0 ; i < n; ++i){
        stack.push(d[i]);
    }
    for(int i = 0 ; i < n; ++i){
        cout << stack.top() << endl;
        stack.pop();
    }

}