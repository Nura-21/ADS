#include <bits/stdc++.h>
using namespace std;
deque<int> dq1;
deque<int> dq2;
void dq1_take()
{
    dq1.push_back(dq1.front()); // push bottom from dq1 top card
    dq1.push_back(dq2.front()); // push bottom from dq2 top card
    dq1.pop_front();            // delete top card from dq1
    dq2.pop_front();            // delete top card from dq2
}
void dq2_take()
{
    dq2.push_back(dq1.front()); // push bottom from dq1 top card
    dq2.push_back(dq2.front()); // push bottom from dq2 top card
    dq1.pop_front();            // delete top card from dq1
    dq2.pop_front();            // delete top card from dq2
}
int main()
{
    int t;
    for (int i = 0; i < 5; i++)
    {
        cin >> t;
        dq1.push_back(t);
    }
    for (int i = 0; i < 5; i++)
    {
        cin >> t;
        dq2.push_back(t);
    }
    int howmany = 0;
    while (!dq1.empty() and !dq2.empty()) // while two deques are not empty
    {
        if (dq1.front() == 0 and dq2.front() == 9)
            dq1_take(); // dq1 takes two cards from dq2
        else if (dq1.front() == 9 and dq2.front() == 0)
            dq2_take(); // dq2 takes two cards from dq1
        else if (dq1.front() > dq2.front())
            dq1_take();
        else if (dq1.front() < dq2.front())
            dq2_take();
        if (howmany >= 1000000)
            break;
        howmany++;
    }
    if (dq2.empty())
        cout << "first " << howmany << endl;
    else if (dq1.empty())
        cout << "second " << howmany << endl;
    else
        cout << "botva" << endl;
    return 0;
}