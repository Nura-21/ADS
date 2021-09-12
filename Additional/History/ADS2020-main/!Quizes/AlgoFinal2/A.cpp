#include <bits/stdc++.h>
using namespace std;
deque<int> boris;
deque<int> nursik;
void boris_take()
{
    boris.push_back(boris.front());
    boris.push_back(nursik.front());
    boris.pop_front();
    nursik.pop_front();
}
void nursik_take()
{
    nursik.push_back(boris.front());
    nursik.push_back(nursik.front());
    boris.pop_front();
    nursik.pop_front();
}

bool data_fill()
{
    int t;
    for (int i = 0; i < 5; i++)
    {
        cin >> t;
        boris.push_back(t);
    }
    for (int i = 0; i < 5; i++)
    {
        cin >> t;
        nursik.push_back(t);
    }
    return true;
}

bool get_ans(int counter)
{
    if (nursik.empty())
        cout << "Boris " << counter << endl;
    else if (boris.empty())
        cout << "Nursik " << counter << endl;
    else
        cout << "blin nichya" << endl;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    data_fill();
    int counter = 0;
    while (!boris.empty() and !nursik.empty())
    {
        if (boris.front() == 0 and nursik.front() == 9)
            boris_take();
        else if (boris.front() == 9 and nursik.front() == 0)
            nursik_take();
        else if (boris.front() > nursik.front())
            boris_take();
        else if (boris.front() < nursik.front())
            nursik_take();
        if (counter >= 1000000)
            break;
        counter++;
    }
    get_ans(counter);
    return 0;
}