// push n
// Добавить в стек число n (значение n задается после команды). Программа должна вывести ok.
// pop
// Удалить из стека последний элемент. Программа должна вывести его значение.
// back
// Программа должна вывести значение последнего элемента, не удаляя его из стека.
// size
// Программа должна вывести количество элементов в стеке.
// clear
// Программа должна очистить стек и вывести ok.
// exit
// Программа должна вывести bye и завершить работу.

#include <bits/stdc++.h>
using namespace std;
int st[1000];
int h = 0;

void st_size()
{
    cout << h << endl;
}
void st_push(int n)
{
    st[h++] = n;
    cout << "ok" << endl;
}
void st_clear()
{
    h = 0;
    cout << "ok" << endl;
}
void st_back()
{
    if (h != 0)
        cout << st[h - 1] << endl;
    else
        cout << "error" << endl;
}
void st_pop()
{
    if (h != 0)
        cout << st[--h] << endl;
    else
        cout << "error" << endl;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "size")
            st_size();
        else if (s == "push")
        {
            int n;
            cin >> n;
            st_push(n);
        }
        else if (s == "clear")
            st_clear();
        else if (s == "exit")
        {
            cout << "bye" << endl;
            return 0;
        }
        else if (s == "back")
            st_back();
        else if (s == "pop")
            st_pop();
    }

    return 0;
}