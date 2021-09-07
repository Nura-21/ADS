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
class Deque
{
    node * front;
    node * rear;
    ll size;
    public:
        Deque()
        {
            front = rear = NULL;
        }
        ll Size()
        {
            return size;
        }
        void push_front(ll x)
        {
            node * item = new node(x);
            if(front == NULL)
            {
                rear = front = item;
            }
            else
            {
                item->next = front;
                front->prev = item;
                front = item;
            }
            size++;
        }
        void push_back(ll x)
        {
            node * item = new node(x);
            if(front == NULL)
            {
                rear = front = item;
            }
            else
            {
                item->prev = rear;
                rear->next = item;
                rear = item;
            }
            size++;
        }
        void pop_front()
        {
            node * item = front;
            front = front->next;
            if(front == NULL)
            {
                rear = NULL;
            }
            else
            {
                front->prev = NULL;
            }
            free(item);
            size--;
        }
        void pop_back()
        {
            node * item = rear;
            rear = rear->prev;
            if(rear == NULL)
            {
                front = NULL;
            }
            else
            {
                rear->next = NULL;
            }
            free(item);
            size--;
        }
        int getFront()
        {
            if(!empty())
            {
                return front->val;
            }
            return -1;
        }
        int getBack()
        {
            if(!empty())
            {
                return rear->val;
            }
            return -1;
        }
        void clear()
        {
            rear = NULL;
            while(front!=NULL)
            {
                node * item = front;
                front = front->next;
                free(item);
            }
            size=0;
        }
        bool empty()
        {
            return front==NULL;
        }
};
Deque d;
int main()
{
    string s;
    while(cin >> s)
    {
        if(s == "push_back")
        {
            ll x;
            cin >> x;
            d.push_back(x);
            cout << "ok\n";
        }
        if(s == "push_front")
        {
            ll x;
            cin >> x;
            d.push_front(x);
            cout << "ok\n";
        }
        if(s == "pop_back")
        {
            if(!d.empty())
            {
                cout << d.getBack() << "\n";
                d.pop_back();
            }
            else
            {
                cout << "error\n";
            }
        }
        if(s == "pop_front")
        {
            if(!d.empty())
            {
                cout << d.getFront() << "\n";
                d.pop_front();
            }
            else
            {
                cout << "error\n";
            }
        }
        if(s == "front")
        {
            if(!d.empty())
            {
                cout << d.getFront() << "\n";
            }
            else
            {
                cout << "error\n";
            }
        }
        if(s == "back")
        {
            if(!d.empty())
            {
                cout << d.getBack() << "\n";
            }
            else
            {
                cout << "error\n";
            }
        }
        if(s == "size")
        {
            cout << d.Size() << "\n";
        }
        if(s == "clear")
        {
            d.clear();
            cout << "ok\n";
        }
        if(s == "exit")
        {
            cout << "bye\n";
            break;
        }
    }    
}