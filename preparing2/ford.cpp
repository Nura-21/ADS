#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void printPath(vector<int>p,int s,int t){
    vector<int>path;
    for(int v=t;v!=s;v=p[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(),path.end());
    for(auto v:path)
        cout<<v<<" ";
}


struct edge{
    int a,b,cost;
};

void Ford_Bellman(vector<edge>e,int n){
    vector<int>d(n,inf),p(n,-1);
    int s; cin>>s;//стартовая вершина
    int m = e.size();
    d[s] = 0;
    while(true){
        bool any = false;//булевая переменная проверяющая изменения на данной фазе цикла
        for(int j=0;j<m;j++){
            if(d[e[j].a]<inf)
                if(d[e[j].b]>d[e[j].a]+e[j].cost){
                    d[e[j].b] = d[e[j].a]+e[j].cost;
                    p[e[j].b] = e[j].a;
                    any = true;
                }
        }
        if(!any)//если на данной фазе не произошло ни одного изменения, то мы завершаем работу нашего цикла
            break;
    }
    int t;cin>>t;//ввод вершины до которой нам надо вывести минимальный путь в данном графе
    printPath(p,s,t);//вывод данного пути 
}

int main(){
    
}