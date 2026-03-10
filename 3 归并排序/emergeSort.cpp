/*
  这个文件实现归并排序，以及解决两个归并分治问题，归并排序的递归和非递归实现均会涉及
*/
#include <cstdio>
#include <vector>

#define maxN 50001

using namespace std;
 
vector <int> arr;
vector<int> help;
int n;

void emergeForSort(int l,int m,int r);
void emergeSort1(int l,int r);


void emergeSort1(int l,int r){
	if(l==r) return;
	else{
		int m=l+(r-l)/2;
		emergeSort1(l,m);
		emergeSort1(m+1,r);
		emergeForSort(l,m,r);
	}
}
void emergeForSort(int l,int m,int r){
	int i,j,t;
	for(i=l,j=m+1,t=i;i<=m&&j<=r;){
		if(arr[i]<=arr[j]) help[t++]=arr[i++];
		else help[t++]=arr[j++];
	}
	while(i<=m) help[t++]=arr[i++];
	while(j<=r) help[t++]=arr[j++];
	for(t=l;t<=r;t++) {
	arr[t]=help[t];
	//printf("t: %d help[t]: %d\n",t,help[t]);
}
}
void emergeSort2(int l,int r){
	for(int d=1;d<=n;d*=2){
		for(int i=l;i<=r;){	
		int m=i+d-1;
		if(m>=r) break;
		int j=(i+2*d-1>r?r:i+2*d-1);
		emergeForSort(i,m,j);
		i=j+1;
	}
	}
}
int main(){
	arr.reserve(maxN);
	help.reserve(maxN);
	printf("请输入数组大小：\n"); 
	scanf("%d",&n);
	printf("请输入数组：\n");
	for(int i=0;i<n;i++){
		int m;
		scanf("%d",&m);
		arr.push_back(m);
	}
	emergeSort2(0,n-1);
	printf("排序结果如下：\n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
