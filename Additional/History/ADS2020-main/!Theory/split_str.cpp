#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

template <class Container>
void split_string(const string &str, Container &cont, char delim = ' ')
{
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim))
        cont.push_back(token);
}

set<int> convertToSet(vector<string> v)
{
    set<int> s;
    for (string &x : v)
        s.insert(stoi(x));
    return s;
}

int main()
{
    string first_line, second_line;
    getline(cin, first_line);
    getline(cin, second_line);
    vector<string> v1;
    vector<string> v2;
    split_string(first_line, v1);
    split_string(second_line, v2);
    set<int> s1 = convertToSet(v1);
    set<int> s2 = convertToSet(v2);
    set<int> intersection;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                     inserter(intersection, intersection.begin()));
    for (auto &item : intersection)
        cout << item << " ";
    return 0;
}