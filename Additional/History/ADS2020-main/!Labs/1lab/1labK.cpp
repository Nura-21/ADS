// Задача №310. Проверка на простоту_0
// Проверьте, является ли число простым.

// Входные данные
// Вводится одно натуральное число n не превышающее 2000000000 и не равное 1.

// Выходные данные
// Необходимо вывести  строку prime, если число простое, или composite, если число составное.

#include <bits/stdc++.h>
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
using namespace std;
int main()
{
    int n;
    cin >> n;
    isPrime(n) ? cout << "prime" : cout << "composite";
    return 0;
}