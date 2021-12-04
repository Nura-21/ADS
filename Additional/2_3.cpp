#include<iostream>
using namespace std;
int main(){
    bool ok=false;
    long long a,b;
    cin>>a>>b;
    long long c;
    int count=-1;
    if(a<b){
        while(b>0){
            if(b==1 and c%2==0){
         cout<<"YES"<<" "<<count;
         ok=true;
        }
        c=b;
        b=b/2;
       count++;
        }
        }
        int cnt=0;
    if(a>b){
        long long k=a/b;
        long long  f;
        while(k>0){

         if(k==1 and f%2==0){
         cout<<"YES"<<" "<<cnt;
         ok=true; 
        }
        f=k;
        k=k/2;
       cnt--;
        }
        }
        if(a==b){
            cout<<"YES"<<" "<< 0;
            ok=true;
        }
   if(ok==false){
       cout<<"NO";
   }
   
}
