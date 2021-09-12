#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

class Human
{
public:
    int age;
    int weight;
    string name;
    void sayName()
    {
        cout << "Name: " << name;
    }

private:
};

class Point
{
public:
    Point()
    {
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getZ()
    {
        return z;
    }
    void setZ(int zz)
    {
        z = zz;
    }

private:
    int x;
    int y;
    int z;
};

class MyClass
{
public:
    MyClass()
    {
        cout << "Const";
    }
    ~MyClass()
    {
        cout << "Destr";
    }
};

int main()
{
    Human h1;
    h1.age = 2;
    h1.name = "Alex";
    Point a(2, 3);

    return 0;
}