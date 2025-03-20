#include<iostream>
using namespace std;

bool binarysearch(int a[],int n,int x){
	int l=0;
	int h=n-1;
	while(l<h){
		int mid=(l+h)/2;
		if(a[mid]==x)
		return mid;
		else if(x<a[mid])
		h=mid-1;
		else l=mid+1;	
	}
}
int main(){
	int arr[]={2,5,8,12,16,23,38,56,72,91};
	int n=sizeof(arr)/sizeof(arr[0]);
	int c=binarysearch(arr,n,29);
	if(c==1)
	cout<<"no. is present";
	else cout<<"no. not present";
}
