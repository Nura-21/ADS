#include <iostream>

using  namespace  std;

struct my_queue{
private:
    int a[100];
    int front_index = -1;
    int tail_index = -1;
public:
    void enqueue(int x){
        if(front_index == -1) front_index = 0;
        tail_index++;
        a[tail_index] = x;
    }
    int front(){
        if(front_index > tail_index) return INT_MIN;
        if(front_index == -1) return INT_MIN;
        return a[front_index];
    }
    void pop() {
        if(front_index <= tail_index) {
            front_index++;
            cout << "popped" << endl;
        }
    }
    int size() {
        if (front_index <= tail_index)
            return tail_index - front_index + 1;
        return 0;
    }
};


int main() {
    my_queue q;
    for(int i = 1; i <= 10; ++i){
        q.enqueue(i);
    }
    for(int i = 1; i <= 10; ++i){
        q.pop();
    }
    if(q.front() == INT_MIN) cout << "queue is empty!";
    else cout << q.front() << endl;

    return 0;
}
