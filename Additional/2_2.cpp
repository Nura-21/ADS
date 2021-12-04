#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
typedef long long ll;
int t;
int n;
int a[maxn];
ll b[maxn];
ll m;
int main(){
    scanf("%d",&t);
    while(t--){
        m=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        for(int i=1;i<=n;i++){
            int pos=i+a[i];
            if(pos<=n){
                b[pos]=max(b[pos],b[i]+a[pos]);
            }
            m=max(m,b[i]);
        }
        printf("%lld\n",m);
    }
    return 0;
}