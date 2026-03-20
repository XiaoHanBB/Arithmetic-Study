#include <iostream>

using namespace std;

int p[201][201];
int n,k;
int x,y;
int tearx[20000];
int teary[20000];
int front,mend;
unsigned long long count;
void add(int x,int y){
	tearx[mend]=x;
	teary[mend]=y;
	mend++;	
	count++;
	p[x][y]=1;
}

int main(){
	cin>>n>>k;
	cin>>x>>y;
	add(x,y);
	for(int i=0;i<k;i++){
		int nfront=front;
		int nend=mend;
		while(nfront!=nend){
			x=tearx[nfront];
			y=teary[nfront];
			nfront++;
			if(x-1>=1&&y+2<=n&&!p[x-1][y+2]) add(x-1,y+2);
			if(x+1<=n&&y+2<=n&&!p[x+1][y+2]) add(x+1,y+2);
			if(x+2<=n&&y+1<=n&&!p[x+2][y+1]) add(x+2,y+1);
			if(x+2<=n&&y-1>=1&&!p[x+2][y-1]) add(x+2,y-1);
			if(x+1<=n&&y-2>=1&&!p[x+1][y-2]) add(x+1,y-2);
			if(x-1>=1&&y-2>=1&&!p[x-1][y-2]) add(x-1,y-2);
			if(x-2>=1&&y-1>=1&&!p[x-2][y-1]) add(x-2,y-1);
			if(x-2>=1&&y+1<=n&&!p[x-2][y+1]) add(x-2,y+1);
		}
		front=nend;
	}
	cout<<count;
	return 0;
}
