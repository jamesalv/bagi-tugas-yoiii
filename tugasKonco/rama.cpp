#include <stdio.h>
#include <iostream>
using namespace std;

int sum(int arr[],int n){
	if(n == 0){
		return 0;
	}
	else{
		return sum(arr,n-1) + arr[n-1];
	}
		
}
	
int main(){
	int T,i,j, arr[100];
	scanf("%d",&T);
	for(i=0;i<T;i++){
		int n;
		scanf("%d",&n);

		// Read the array input
		for (int j = 0; j < n; j++)
		{
			scanf("%d",&arr[j]);
			cin >> arr[j];
		}
		
		printf("%d\n", sum(arr,n));
	}
	return 0;
}