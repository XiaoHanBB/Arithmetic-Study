#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <climits>
int main() {
	int n = 0,m = 0;
	scanf("%d%d",&n,&m);
	int *a=(int*)malloc(sizeof(int)*(m+1));
	a[0]=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	int *dp = (int *)malloc(sizeof(int)*(n+1));
	for(int i=0;i<=n;i++) dp[i]=0;
	for(int i=1;i<=m;i++){
		for(int t = 1;t<=n;t++){
			if((t-i)>=0) dp[t]=std::max(dp[t],dp[t-i]+a[i]);
		}
	}
	printf("%d",dp[n]);	
}
