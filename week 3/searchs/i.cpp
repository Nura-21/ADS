#include <iostream>
#include <vector>

using namespace std;

int find_lower_left(vector<int> &v, int x) { // max a[i] <= x
    int l = -1;
    int r = (int)v.size();
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (v[m] <= x)
            l = m;
        else 
            r = m;
    }
    return l;
}

int find_lower_right(vector<int> &v, int x) { // max a[i] <= x
    int l = -1;
    int r = (int)v.size();
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (v[m] >= x)
            r = m;
        else 
            l = m;
    }
    return r;
}

pair<int, bool> find_left(vector<int> & a, int x) {
    int i = find_lower_left(a, x);
    return make_pair(i + 1,a[i]==x);
}


pair<int,bool> find_right(vector<int> &a, int x) {
    int i = find_lower_right(a, x);
    return make_pair(i + 1, a[i] == x);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    while (k--) {
        int x;
        cin >> x;
        if(find_right(v,x).second == true and find_left(v,x).second == true){
            cout << find_right(v,x).first << " ";
            cout << find_left(v,x).first << endl;}
        else{cout << "0" << endl;}
    }
}