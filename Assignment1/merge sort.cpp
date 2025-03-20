#include<iostream>
using namespace std;

void merge(int a[],int p,int q,int r){
	int n1=q-p+1;
	int n2=r-q;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++){
		L[i]=a[p+i];
	}
	for(int j=0;j<n2;j++){
		R[j]=a[q+1+j];
	}
	int i=0;
	int j=0;
	int k=p;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
		}
		else{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=L[i];
			i++;
			k++;
	}
	while(j<n2){
		a[k]=R[j];
			j++;
			k++;
	}
}

void mergesort(int a[],int p,int r){
	if(p<r){
		int q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}

int main(){
	int a[]={2,8,7,1,3,5,6,4};
	int n=8;
	int p=0;
	int r=n-1;
	mergesort(a,p,r);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
