#include <iostream>

using namespace std;

typedef unsigned long long ull;
char picture[401][401];
char help[401][401];
ull z;
ull k;
int key[500000];
int t;

void decode1(int k1,int k2,int k3,int k4,int k5);
//Ë³Ê±Õë90 
void f1();
//ÄæÊ±Õë 
void f2(int u,int v,int l);
void decode2(int k1,int k2,int k3,int k4,int k5);
void printpic();
void f4(int u,int d,int l,int r);
void f3(int u,int d,int l,int r);

int main(){
    cin>>z;
    cin.get();
    for(int i=0;i<z;i++){
        for(int t=0;t<z;t++){
        	picture[i][t]=cin.get();
		}
		cin.get();
    }
    cin>>k;
    for(int i=0;i<k;i++){
    	int m;
    	cin>>m;
    	key[i]=m;
	}
	t=key[0];
	for(int i=1;i<=t;i++){
		int st=(t-i)*6+1;
		if(key[st]==1) decode1(key[st+1],key[st+2],key[st+3],key[st+4],key[st+5]);
		if(key[st]==2) decode2(key[st+1],key[st+2],key[st+3],key[st+4],key[st+5]);
	}
	printpic();
    return 0;
}
void decode1(int k1,int k2,int k3,int k4,int k5){
	for(int i=0;i<k5;i++) f1();
	for(int i=90;i<=k4;i+=90) f2(k1-1,k2-1,k3);
}
void decode2(int k1,int k2,int k3,int k4,int k5){
	if(k5==1) f3(k1-1,k2-1,k3-1,k4-1);
	if(k5==-1) f4(k1-1,k2-1,k3-1,k4-1);
}
void printpic(){
	int n=0;
	int m=0;
	for(int i=0;i<z;i++){
		if(picture[i][0]=='?') break;
		n++;
	}
	for(int i=0;i<z;i++){
		if(picture[0][i]=='?') break;
		m++;
	}
	cout<<n<<' '<<m<<endl;
	for(int i=0;i<n;i++){
		for(int t=0;t<m;t++){
			cout<<picture[i][t];
		}
		cout<<endl;
	}
}
void f2(int u,int v,int l){
	for(int i=0;i<l;i++){
		for(int t=0;t<l;t++){
			help[i][t]=picture[u+t][v+l-1-i];
		}
	}
	for(int i=0;i<l;i++){
		for(int t=0;t<l;t++){
			picture[u+i][v+t]=help[i][t];
		}
	}
}
void f1(){
	for(int i=0;i<z;i++){
		for(int t=0;t<z;t++){
			help[i][t]=picture[z-1-t][i];
		}
	}
	for(int i=0;i<z;i++){
		for(int t=0;t<z;t++){
			picture[i][t]=help[i][t];
		}
	}
}
void f3(int u,int d,int l,int r){
	int m1=u+(d-u)/2;
	for(int i=u;i<=m1;i++){
		for(int t=l;t<=r;t++){
			char temp=picture[i][t];
			picture[i][t]=picture[d+u-i][t];
			picture[d+u-i][t]=temp;
		}
	}
}
void f4(int u,int d,int l,int r){
	int m=l+(r-l)/2;
	for(int t=l;t<=m;t++){
		for(int i=u;i<=d;i++){
			char temp=picture[i][t];
			picture[i][t]=picture[i][r+l-t];
			picture[i][r+l-t]=temp;
		}
	}
}
