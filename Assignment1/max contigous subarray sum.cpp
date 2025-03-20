#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x,y;
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
    	int temp=0;
    	for(int j=i;j<n;j++){
    		temp+=arr[j];
			if(temp>maxsum){
				maxsum=temp;
				x=i;
				y=j;
			}
		}
	}
	cout<<maxsum<<endl;
	for(int i=x;i<=y;i++){
		cout<<arr[i]<<" ";
	}
    return 0;
}


// OR

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int maxcrosssum(int a[],int l,int m,int h){
    int sum=0;
    int leftsum=INT_MIN;
    for(int i=m;i>=l;i--){
        sum+=a[i];
        if(sum>leftsum)
            leftsum=sum;
    }
    
    sum=0;
    int rightsum=INT_MIN;
    for(int i=m+1;i<=h;i++){
        sum=sum+a[i];
        if(sum>rightsum)
            rightsum=sum;
    }
    
    return(leftsum+rightsum);
}
int maxsum(int a[],int l,int h){
    if(l>h)
        return(INT_MIN);
    if(l==h)
        return(a[l]);
    int m=l+(h-l)/2;
    int leftsum=maxsum(a,l,m);
    int rightsum=maxsum(a,m+1,h);
    int crosssum=maxcrosssum(a,l,m,h);
    
    if(leftsum>crosssum && leftsum>rightsum)
        return(leftsum);
    else if(rightsum>crosssum && rightsum>leftsum)
        return(rightsum);
    else return(crosssum);
}
int main()
{
    int a[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n=sizeof(a)/sizeof(a[0]);
    int l=0;
    int h=n-1;
    cout<<maxsum(a,l,h);
}
