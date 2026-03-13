// 此文件内容为快速排序的各个版本

#include<cstdio>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

#define maxN 100001
vector<int> arr(maxN);
int n;
//first last用于荷兰卡牌问题优化
int first,last; 

void quickSort(int l,int r);
int partition(int l,int r,int x);
void myswap(int a,int b);
void printArr(void);
void quickSort2(int l,int r);
void partition2(int l,int r,int x);

//基础版本快速排序 
void quickSort(int l,int r){
	if(l>=r) return;
	srand(time(0));
	int x=l+(rand()%(r-l+1));
	int mid = partition(l,r,arr[x]);
	quickSort(l,mid);
	quickSort(mid+1,r);
}
int partition(int l,int r,int x){
	int a=l;
	int xi=0;
	for(int i=l;i<=r;i++){
		if(arr[i]<=x){
			myswap(a,i);
			if(arr[a]==x) xi=a;
			a++;
		}
	}
	myswap(a-1,xi);
	return a-1;
}
//荷兰卡牌问题优化快速排序
void quickSort2(int l,int r){
	if(l>=r) return;
	srand(time(0));
	int x=l+(rand()%(r-l+1));
	partition2(l,r,arr[x]);
	int left,right;
	left=first;
	right=last;
	quickSort2(l,left-1);
	quickSort2(right+1,r);
}
//用全局变量传递参数 
void partition2(int l,int r,int x){
	int a=l,b=r;
	for(int i=l;i<=b;i++){
		if(arr[i]<x){
			myswap(a,i);
			a++;
		}
		if(arr[i]>x){
			myswap(i,b);
			b--;
			i--;
		}
	}
	first=a;
	last=b;
}
void myswap(int a,int b){
	int temp;
	temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
void printArr(void){
	printf("\n数组内容如下：");
	for(int i=0;i<arr.size();i++){
		printf("%d ",arr[i]);
	}
	putchar('\n');
}
int main(){
	arr.clear();
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int m;
		scanf("%d",&m);
		arr.push_back(m);
	}
	printArr();
	quickSort2(0,arr.size()-1);
	printArr();
	return 0;
} 
