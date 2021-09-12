#include <iostream> 

using namespace std;

using ll = long long;


struct node{
    ll val;
    node * next;
    node(ll x ){
        val = x;
        next = NULL;
    }
};
ll size;
struct queue{
    private:
        node * front;
        node * rear;
    public:
    queue()
    {
        front = rear = NULL;

    }
    void push(ll x)
    {
        node * item = new node(x);
        if(rear == NULL)
        {
            front = rear = item;
            return;
        }
        rear->next = item;
        rear = item;
    }
    int fr()
    {
        if(front != NULL)
        {
            return front->val;
        }
        return -1;
    }
    void pop()
    {
        if(front == NULL)
        {
            return;
        }
        node * item = front;
        front = front->next;
        if(front == NULL)
        {
            rear = NULL;
        }
        free(item);
    }
    bool empty()
    {
        return front==NULL;
    }
};
queue q;
int main()
{
    string s;
    while(cin >> s)
    {
        if(s == "push")
        {
            ll x;
            cin >> x;
            q.push(x);
            size++;
            cout << "ok\n";
        }
        if(s == "pop")
        {
            if(!q.empty())
            {
                cout << q.fr() << "\n";
                q.pop();
                size--;
            }
            else
            {
                cout << "error\n";
            }
        }
        if(s == "front")
        {
            if(!q.empty())
            {
                cout << q.fr() << "\n";
            }
            else
            {
                cout << "error\n";
            }
        }
        if(s == "size")
        {
            cout << size << "\n";
        }
        if(s == "clear")
        {
            while(!q.empty())
            {
                q.pop();
            }
            cout << "ok\n";
            size = 0;
        }
        if(s == "exit")
        {
            cout << "bye\n";
            break;
        }
    }    
}