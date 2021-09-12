#include <iostream> 

using namespace std;

using ll = long long;

struct node{
    ll val;
    node * next;
    node * prev;
    node(ll x ){
        val = x;
        next = NULL;
        prev = NULL;
    }
};
ll size;
struct st{
    private:
        node * tail;
    public:
    st()
    {
        tail = NULL;
    }
    int top()
    {
        if(tail != NULL)
        {
            return tail->val;
        }
        return -1;
    }
    void push(ll x)
    {
        node * item = new node(x);
        if(tail == NULL)
        {
            tail = item;
        }
        else
        {
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
    }
    void pop()
    {
        if(tail != NULL)
        {
            tail = tail->prev;
            if(tail != NULL)
            {
                tail->next = NULL;
            }
        }
    }
    bool empty()
    {
        return tail==NULL;
    }
};
st a;
int main()
{
    string s;
    while(cin >> s)
    {
        if(s == "push")
        {
            ll x;
            cin >> x;
            a.push(x);
            size++;
            cout << "ok\n";
        }
        if(s == "pop")
        {
            if(!a.empty())
            {
                cout << a.top() << "\n";
                a.pop();
                size--;
            }
            else
            {
                cout << "error\n";
            }
        }
        if(s == "back")
        {
            if(!a.empty())
            {
                cout << a.top() << "\n";
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
            while(!a.empty())
            {
                a.pop();
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