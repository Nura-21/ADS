#include <bits/stdc++.h>
using namespace std;
int main()
{
    char sign;
    int numb;
    deque<int> meat;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> sign;
        if (sign == '-')
        {
            cout << meat.front() << endl;
            meat.pop_front();
        }
        else if (sign == '+')
        {
            cin >> numb;
            meat.push_back(numb);
        }
        else if (sign == '*')
        {
            cin >> numb;
            if (meat.size() % 2 == 0)
                meat.insert(meat.begin() + meat.size() / 2, numb);
            else
                meat.insert(meat.begin() + (meat.size() / 2) + 1, numb);
        }
    }
    return 0;
}