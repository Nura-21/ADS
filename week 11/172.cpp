   #include<iostream>
#define INF 1000000000
using namespace std;
int main(){
	int n,i,j,k;
	cin>>n;
	int a[n][n];
	for(i=0;i<n;++i)
		for(j=0;j<n;++j){
			cin>>a[i][j];
			if(a[i][j]<0)a[i][j]=INF;}
	for(k=0;k<n;++k)
		for(i=0;i<n;++i)
			for(j=0;j<n;++j)
				if(a[i][j]>a[i][k]+a[k][j])
				a[i][j]=a[i][k]+a[k][j];
	k=0;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			if(a[i][j]<INF&&a[i][j]>k)
				k=a[i][j];
	cout<<k;
return 0;}   