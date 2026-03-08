#include <iostream>
#include <vector>

using namespace std;

int binarysearch(const vector <int> &arr,int k);
int bigone(const vector <int> &arr,int k);
int lessone(const vector <int> &arr,int k);
void sort(vector <int> &arr);
int findtop(const vector <int> &arr);
void printarr(const vector<int> &arr);

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		arr[i]=m;
	}
	cout<<arr.size()<<endl;
	printarr(arr);
	cout<<"sort arr: "<<endl;
	sort(arr);
	printarr(arr);
	cout<<"请输入二分查找的K："<<endl;
	int k,ans;
	cin>>k;
	ans=binarysearch(arr,k);
	cout<<"ans = "<<ans<<endl;
	cout<<"big one,请输入K: "<<endl;
	cin>>k;
	ans=bigone(arr,k);
	cout<<"ans = "<<ans<<endl;
	cout<<"less one ,请输入K："<<endl;
	cin>>k;
	ans=lessone(arr,k);
	cout<<"ans = "<<ans<<endl;
	return 0; 
}
int binarysearch(const vector <int> &arr,int k){
	if(arr.size()==0) return -1;
	int l=0,r=arr.size()-1,m=0,ans=-1;
	while(l<=r){
		m=l+((r-l)>>1);
		if(arr[m]==k){
			ans=m;
			r=m-1;
		}
		else if(arr[m]<k){
			l=m+1;
		}
		else {
			r=m-1;
		}
	}
	return ans;
}
int bigone(const vector <int> &arr,int k){
	if(arr.size()==0) return -1;
	int l=0,r=arr.size()-1,m=0,ans=-1;
	while(l<=r){
		m=l+((r-l)>>1);
		if(arr[m]>=k){
			ans=m;
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	return ans;
}
int lessone(const vector<int> &arr,int k){
	if(arr.size()==0) return -1;
	int l=0,r=arr.size()-1,m=0,ans=-1;
	while(l<=r){
		m=l+((r-1)>>1);
		if(arr[m]<=k){
			ans=m;
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	return ans;
}
void sort(vector<int> &arr){
	for(int i=0;i<arr.size()-1;i++){
		for(int t=0;t+i<=arr.size()-2;t++){
			if(arr[t]>arr[t+1]){
				int m=arr[t];
				arr[t]=arr[t+1];
				arr[t+1]=m;
			}
		}
	}
}
void printarr(const vector<int> &arr){
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<' ';
	}
	cout<<endl;
}
