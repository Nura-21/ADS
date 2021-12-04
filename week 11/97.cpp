#include <iostream>
#include <vector>
#include <set>
using namespace std;
 
 
int INF = 1e9;
 
 
 
 
int main() {
   int n = 0;
   cin>>n;
   int a[n][n];
   int prover = 0;
   for(int i =0 ;i<n;i++){
     for(int y =0 ;y<n;y++){
            cin>>a[i][y];
     }
   }
 
    for (int k=0; k<n; ++k)
    for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
            if (a[i][k] < INF && a[k][j] < INF)
                a[i][j] = min (a[i][j], a[i][k] + a[k][j]);
 
        int maximum = 1000001 ;
        for(int s = 0;s<n;s++){
            for(int f = 0;f<n;f++){
           //     cout<<a[s][f]<<" ";
                    if(maximum>a[s][f] && a[s][f] != 0){
                        maximum = a[s][f];
            }
        }
      //  cout<<endl;
   }
   for(int i = 0;i<n;i++){
    if(a[i][i] < 0){
        prover = -1;
    }
   }
 
   if(prover == -1){
        cout<<-1<<endl;
   }
   else{
         cout<<maximum;
   }
  return 0;
}