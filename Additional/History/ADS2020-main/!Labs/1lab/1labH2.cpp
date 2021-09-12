#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> first_half;
    deque<int> second_half;
    int n, x;
    char sign;
    cin >> n;
    while (n--)
    {
        cin >> sign;
        if (sign == '+')
        {
            cin >> x;
            second_half.push_back(x);
        }
        else if (sign == '*')
        {
            cin >> x;
            second_half.push_front(x);
        }
        else if (sign == '-')
        {
            cout << first_half.front() << endl;
            first_half.pop_front();
        }
        if (second_half.size() > first_half.size())
        {
            first_half.push_back(second_half.front());
            second_half.pop_front();
        }
    }
    return 0;
}