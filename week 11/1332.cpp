   #include<iostream>
#define INF 1000000000
using namespace std;
int main(){
	int n,i,j,k;
	cin>>n;
	int a[n][n];
    int b[n][n];
	for(i=0;i<n;++i)
		for(j=0;j<n;++j){
			cin>>a[i][j];
            b[i][j] = a[i][j];
    }
    
	for(k=0;k<n;++k)
		for(i=0;i<n;++i)
			for(j=0;j<n;++j)
				b[i][j] = b[i][j] || (b[i][k] and b[k][j]);
	for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            if(i == j) cout << 1 << " ";
            else cout << b[i][j] << " ";
        }
        cout << endl;
    }
		    
return 0;}   