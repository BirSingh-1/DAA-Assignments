#include<iostream>
using namespace std;

int partition(int a[],int p,int r){
	int x=a[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		if(a[j]<x){
			i++;
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	i++;
	int temp=a[i];
	a[i]=a[r];
	a[r]=temp;
	return i;
}

void quicksort(int a[],int p,int r){
	if(p<r){
		int q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

int main(){
	int a[]={2,8,7,1,3,5,6,4};
	int n=8;
	int p=0;
	int r=n-1;
	quicksort(a,p,r);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
