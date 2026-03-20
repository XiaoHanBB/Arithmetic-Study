#include <iostream>

using namespace std;
typedef long double ud;

int k,u,v,n;
ud ans;
int main(){
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>u>>v>>n;
		ans=(ud)(n-u)/(ud)v;
		ans*=1000;
		int a,b;
		a=(int)(ans/100)+1;
		ans-=(a-1)*100;
		b=(int)(ans/10)+1;
		ans-=(b-1)*10;
		if(ans>=5) b++;
		cout<<a<<' '<<b<<endl;
	}
	return 0;
}
